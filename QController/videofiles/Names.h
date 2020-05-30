//
// Created by eleps on 13.03.19.
//

#ifndef GSTREAMER_NAMES_H
#define GSTREAMER_NAMES_H
#include <gst/gst.h>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>

#include <gtk/gtk.h>

#ifndef SAVE_FOLDER_DEFAULT
#define SAVE_FOLDER_DEFAULT  	 "/mnt/flash"

#define VIDEO_NAME_DEFAULT       "Video"
#define PHOTO_NAME_DEFAULT	 "Snapshot"
#define PHOTO_NAME_SUFFIX_DEFAULT ".jpeg"
#define VIDEO_NAME_SUFFIX_DEFAULT ".avi"
#endif
class Names {
private:
public:
    static  GString         videoname_multi  (    void    );
    static  GString         videoname        (  void     );
    static  GString         videoname_path  (    std::string path    );
    static  GString         snapname_path  (    std::string path    );
    static  GString         name_model_0  (    std::string name, std::string ending    );
    static  GString         name_model_1  (     std::string name, std::string ending     );
    static  GString         name_model_2  (     std::string name, std::string ending     );
    static  GString         name_model_3  (     std::string name, std::string ending     );
    static  GString         name_model_4  (     std::string name, std::string ending     );
    static  GString         name_model_5  (     std::string name, std::string ending     );
    static void print_info(char * message);
protected:
};
#endif //GSTREAMER_NAMES_H
