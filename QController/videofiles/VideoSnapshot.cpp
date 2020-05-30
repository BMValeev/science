//
// Created by eleps on 14.03.19.
//
#include <gst/gst.h>
//#include <gst/app/app.h>
#include <cstring>
#include <cstdio>
#include <unistd.h>
#include <gtk/gtk.h>
//#include <gdk-pixbuf/gdk-pixbuf.h>

#include "Names.h"
#include "VideoApp.h"
#include "VideoSnapshot.h"
VideoSnapshot::VideoSnapshot(VideoApp* object){
    try{
        parent=object;
        memset(&SnapshotVideo, 0, sizeof(SnapshotVideo));
        sn = FALSE;
        photo_mx.unlock();
        SnapshotVideo.queue_sn = gst_element_factory_make ("queue", "queue_sn");
        SnapshotVideo.convert_sn = gst_element_factory_make ("imxg2dvideotransform", "convert_sn");
        SnapshotVideo.appsink_sn = gst_element_factory_make ("appsink", "appsink_sn");
        if ( !SnapshotVideo.queue_sn ||      !SnapshotVideo.convert_sn    || !SnapshotVideo.appsink_sn  ) {
            throw std::logic_error(std::string(__func__)+" Elements not created");
        }
        GstCaps *caps_snap;
        caps_snap = gst_caps_from_string("video/x-raw,height=720,width=1280,format=RGBx");//
        //SnapshotVideo.sn_pad = gst_element_get_static_pad (SnapshotVideo.queue_sn, "sink");
        gst_object_ref (SnapshotVideo.queue_sn);
        gst_object_ref (SnapshotVideo.convert_sn);
        gst_object_ref (SnapshotVideo.appsink_sn);

        g_object_set (SnapshotVideo.queue_sn, "flush-on-eos", 1, nullptr);
        g_object_set (SnapshotVideo.queue_sn, "leaky", 2, nullptr);
        g_object_set (SnapshotVideo.queue_sn, "silent", 1, nullptr);
        g_object_set (SnapshotVideo.queue_sn, "max-size-buffers", 1, nullptr);

        g_object_set (SnapshotVideo.appsink_sn, "async", 0, nullptr);
        g_object_set (SnapshotVideo.appsink_sn, "wait-on-eos", 0, nullptr);
        g_object_set (SnapshotVideo.appsink_sn, "sync", 1, nullptr);
        g_object_set (SnapshotVideo.appsink_sn, "max-buffers", 1, nullptr);
        g_object_set (SnapshotVideo.appsink_sn, "drop", TRUE, nullptr);


        //g_object_set (G_OBJECT(SnapshotVideo.appsink_sn), "max-lateness", 100000, nullptr);
        //g_object_set (G_OBJECT(SnapshotVideo.appsink_sn), "enable-last-sample", 0, nullptr);
        //g_object_set (G_OBJECT(SnapshotVideo.appsink_sn), "emit-signals", 1, nullptr);
        gst_bin_add_many (GST_BIN (parent->getPipeline()),SnapshotVideo.queue_sn,  SnapshotVideo.convert_sn, SnapshotVideo.appsink_sn,    nullptr);
        if (  (gst_element_link_many (parent->getTee(),SnapshotVideo.queue_sn, SnapshotVideo.convert_sn,nullptr) != TRUE) ||
              ( gst_element_link_filtered (SnapshotVideo.convert_sn, SnapshotVideo.appsink_sn, caps_snap) != TRUE)            ) {
            throw std::logic_error(std::string(__func__)+" Elements not linked");
        }
        setPointer(this);
        object->addChild("Photo", this);
        cout<<__func__<<" Initialized successfully"<<endl;
    }
    catch (exception& e) { cout << e.what() << endl; }
}
VideoSnapshot::~VideoSnapshot(){
    gst_object_unref (SnapshotVideo.queue_sn);
    gst_object_unref (SnapshotVideo.convert_sn);
    gst_object_unref (SnapshotVideo.appsink_sn);
}
bool VideoSnapshot::setPath(std::string path){
    if (path.size()==0){return true;}
    savePath=path;
    return false;
}
bool VideoSnapshot::setName(unsigned int model){
    if((model>5)){return true;}
    name_model=model;
    return false;
}
void VideoSnapshot::lockPhoto(void){ photo_mx.lock(); }
void VideoSnapshot::unlockPhoto(void){ photo_mx.unlock(); }
bool VideoSnapshot::makeSnapshot(void){
    GstPad *PhotoPad;
    std::lock_guard<std::mutex> lock(photo_mx);
    cout<<"===============> COME to snapshot" <<endl;
    if(!(parent->isEnabled())){unlockPhoto(); return true;}
    if(savePath==""){unlockPhoto(); return true;}
    PhotoPad = gst_element_get_static_pad (SnapshotVideo.appsink_sn, "sink");
    gst_pad_add_probe (PhotoPad, (GstPadProbeType) (GST_PAD_PROBE_TYPE_BLOCK | GST_PAD_PROBE_TYPE_BUFFER),
                           reinterpret_cast<GstPadProbeCallback> (&VideoSnapshot::add_photo), getPointer(), nullptr);
    cout<<"===============>  from snapshot" <<endl;
    return false;
}
GstPadProbeReturn        VideoSnapshot::add_photo (              GstPad          *pad, GstPadProbeInfo *info,gpointer _gstData ){
    VideoSnapshot* oPipeObject = reinterpret_cast<VideoSnapshot*> (_gstData);
    GstBuffer *buffer;
    oPipeObject->lockPhoto();
    gst_pad_remove_probe (pad, GST_PAD_PROBE_INFO_ID (info));
    buffer=gst_pad_probe_info_get_buffer (info);
    gst_buffer_ref(buffer);
    std::thread t1(&VideoSnapshot::addTest, oPipeObject,buffer);
    t1.detach();
    usleep(10);
    oPipeObject->unlockPhoto();
    g_print("Leave photo\n");
    return GST_PAD_PROBE_PASS;
}
void VideoSnapshot::addTest(void *user_data) {
    GstBuffer *buffer,*main_buffer;
    buffer=(GstBuffer *) user_data;
    gst_buffer_ref(buffer);
    GstMapInfo map;
    time_t timestamp;
    struct tm *timestamp_tm;
    int day, month, hour, min, second;
    unsigned int width=1280,height=720,pixelNum;
    gchar *directory;
    GString *filename;
    pixelNum=width*height;
    main_buffer=gst_buffer_new_allocate (nullptr, gst_buffer_get_size (buffer), nullptr);
    main_buffer=gst_buffer_copy (buffer);
    //printf("size is %d\n",gst_buffer_get_size (main_buffer));
    uint8_t image[pixelNum*3];
    memset(&image,0x00,sizeof(image));
    gst_buffer_map (buffer, &map, GST_MAP_READ);
    for(unsigned int i;i<=pixelNum;i++){
        image[i*3]= map.data[i*4];
        image[i*3+1]= map.data[i*4+1];
        image[i*3+2]= map.data[i*4+2];
    }
    directory =(gchar*) savePath.c_str();
    filename = g_string_new(g_build_filename(directory, PHOTO_NAME_DEFAULT, nullptr));
    timestamp=time(nullptr);
    timestamp_tm=localtime(&timestamp);
    day=timestamp_tm->tm_mday;
    month=timestamp_tm->tm_mon;
    hour=timestamp_tm->tm_hour;
    min=timestamp_tm->tm_min;
    second=timestamp_tm->tm_sec;
    g_string_append_printf(filename, "_%id_%im_%i-%i-%i%s", day, month+1,  hour, min, second, PHOTO_NAME_SUFFIX_DEFAULT);
    switch(name_model){
        case 0: Names::name_model_0("Snapshot",".jpg"); break;
        case 1: Names::name_model_1("Snapshot",".jpg"); break;
        case 2: Names::name_model_2("Snapshot",".jpg"); break;
        case 3: Names::name_model_3("Snapshot",".jpg"); break;
        case 4: Names::name_model_4("Snapshot",".jpg"); break;
        case 5: Names::name_model_5("Snapshot",".jpg"); break;
        default: Names::name_model_0("Snapshot",".jpg"); break;
    }
    GdkPixbuf *pixbuf=gdk_pixbuf_new_from_data (reinterpret_cast<guint8 *>(image), GDK_COLORSPACE_RGB,FALSE, 8, width, height, GST_ROUND_UP_4 (width * 3) , nullptr, nullptr);//GST_ROUND_UP_4 (width * 3)
    gdk_pixbuf_save (pixbuf,filename->str, "jpeg",  nullptr,nullptr);//&error,
    //g_print("Saved in %s\n",  filename->str);
    gst_buffer_unref(buffer);
    gst_buffer_unref(buffer);
    gst_buffer_unmap (main_buffer, &map);
    g_object_unref(pixbuf);
    gst_buffer_unref(main_buffer);
    //printf("Callback end\n");
    return;
}
