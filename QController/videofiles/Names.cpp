//
// Created by eleps on 13.03.19.
//
using namespace std;
#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "Names.h"
GString         Names::videoname_multi  ( void  ){
    const gchar *directory;
    GString *filename;
    time_t timestamp;
    struct tm *timestamp_tm;
    int day, month, hour, min, second;
    directory = SAVE_FOLDER_DEFAULT;
    if(directory == NULL){ directory = g_get_tmp_dir();}
    filename = g_string_new(g_build_filename(directory, VIDEO_NAME_DEFAULT, NULL));
    timestamp=time(NULL);
    timestamp_tm=localtime(&timestamp);
    day=timestamp_tm->tm_mday;
    month=timestamp_tm->tm_mon;
    hour=timestamp_tm->tm_hour;
    min=timestamp_tm->tm_min;
    second=timestamp_tm->tm_sec;
    g_string_append_printf(filename, "%id%im%i_%i_%i_%%3d%s",day,month+1,  hour, min, second, VIDEO_NAME_SUFFIX_DEFAULT);
    g_print("%s\n",  filename->str);
    return *filename;
}
GString         Names::videoname_path  ( std::string path  ){
    const gchar *directory;
    GString *filename;
    time_t timestamp;
    struct tm *timestamp_tm;
    int day, month, hour, min, second;
    directory = path.c_str();
    filename = g_string_new(g_build_filename(directory, VIDEO_NAME_DEFAULT, NULL));
    timestamp=time(NULL);
    timestamp_tm=localtime(&timestamp);
    day=timestamp_tm->tm_mday;
    month=timestamp_tm->tm_mon;
    hour=timestamp_tm->tm_hour;
    min=timestamp_tm->tm_min;
    second=timestamp_tm->tm_sec;
    g_string_append_printf(filename, "%id%im%i_%i_%i_%%3d%s",day,month+1,  hour, min, second, VIDEO_NAME_SUFFIX_DEFAULT);
    return *filename;
}
GString         Names::videoname        (  void  ) {
    const gchar *directory;
    GString *filename;
    time_t timestamp;
    struct tm *timestamp_tm;
    int day, month, hour, min, second;
    directory = SAVE_FOLDER_DEFAULT;
    if(directory == NULL) {
        directory = g_get_tmp_dir();
    }
    filename = g_string_new(g_build_filename(directory, VIDEO_NAME_DEFAULT, NULL));
    timestamp=time(NULL);
    timestamp_tm=localtime(&timestamp);
    day=timestamp_tm->tm_mday;
    month=timestamp_tm->tm_mon;
    hour=timestamp_tm->tm_hour;
    min=timestamp_tm->tm_min;
    second=timestamp_tm->tm_sec;
    g_string_append_printf(filename, "%id%im%i_%i_%i%s",day,month+1,  hour, min, second, VIDEO_NAME_SUFFIX_DEFAULT);
    g_print("%s\n",  filename->str);
    return *filename;
}
void Names::print_info(char * message) {
    struct tm *sTm;
    char timeline_string[20];
    memset(timeline_string, 0x00, sizeof(timeline_string));
    time_t now;
    if (sizeof(message)>100){
        return;
    }
    now = time (0);
    sTm = gmtime (&now);
    strftime (timeline_string, sizeof(timeline_string), "%Y-%m-%d %H:%M:%S", sTm);
    printf ("%s %s\n", timeline_string, message);
    return;
}
GString         Names::name_model_0  (    std::string name, std::string ending    ){
    const gchar *directory;
    GString *filename;
    time_t timestamp;
    struct tm *timestamp_tm;
    int day, month, hour, min, second;
    directory = SAVE_FOLDER_DEFAULT;
    if(directory == NULL){ directory = g_get_tmp_dir();}
    filename = g_string_new(g_build_filename(directory, VIDEO_NAME_DEFAULT, NULL));
    timestamp=time(NULL);
    timestamp_tm=localtime(&timestamp);
    day=timestamp_tm->tm_mday;
    month=timestamp_tm->tm_mon;
    hour=timestamp_tm->tm_hour;
    min=timestamp_tm->tm_min;
    second=timestamp_tm->tm_sec;
    g_string_append_printf(filename, "%id%im%i_%i_%i_%%3d%s",day,month+1,  hour, min, second, VIDEO_NAME_SUFFIX_DEFAULT);
    g_print("%s\n",  filename->str);
    return *filename;
}
GString         Names::name_model_1  (     std::string name, std::string ending     ){
    const gchar *directory;
    GString *filename;
    time_t timestamp;
    struct tm *timestamp_tm;
    int day, month, hour, min, second;
    directory = SAVE_FOLDER_DEFAULT;
    if(directory == NULL){ directory = g_get_tmp_dir();}
    filename = g_string_new(g_build_filename(directory, VIDEO_NAME_DEFAULT, NULL));
    timestamp=time(NULL);
    timestamp_tm=localtime(&timestamp);
    day=timestamp_tm->tm_mday;
    month=timestamp_tm->tm_mon;
    hour=timestamp_tm->tm_hour;
    min=timestamp_tm->tm_min;
    second=timestamp_tm->tm_sec;
    g_string_append_printf(filename, "%id%im%i_%i_%i_%%3d%s",day,month+1,  hour, min, second, VIDEO_NAME_SUFFIX_DEFAULT);
    g_print("%s\n",  filename->str);
    return *filename;
}
GString         Names::name_model_2  (     std::string name, std::string ending     ){
    const gchar *directory;
    GString *filename;
    time_t timestamp;
    struct tm *timestamp_tm;
    int day, month, hour, min, second;
    directory = SAVE_FOLDER_DEFAULT;
    if(directory == NULL){ directory = g_get_tmp_dir();}
    filename = g_string_new(g_build_filename(directory, VIDEO_NAME_DEFAULT, NULL));
    timestamp=time(NULL);
    timestamp_tm=localtime(&timestamp);
    day=timestamp_tm->tm_mday;
    month=timestamp_tm->tm_mon;
    hour=timestamp_tm->tm_hour;
    min=timestamp_tm->tm_min;
    second=timestamp_tm->tm_sec;
    g_string_append_printf(filename, "%id%im%i_%i_%i_%%3d%s",day,month+1,  hour, min, second, VIDEO_NAME_SUFFIX_DEFAULT);
    g_print("%s\n",  filename->str);
    return *filename;
}
GString         Names::name_model_3  (     std::string name, std::string ending     ){
    const gchar *directory;
    GString *filename;
    time_t timestamp;
    struct tm *timestamp_tm;
    int day, month, hour, min, second;
    directory = SAVE_FOLDER_DEFAULT;
    if(directory == NULL){ directory = g_get_tmp_dir();}
    filename = g_string_new(g_build_filename(directory, VIDEO_NAME_DEFAULT, NULL));
    timestamp=time(NULL);
    timestamp_tm=localtime(&timestamp);
    day=timestamp_tm->tm_mday;
    month=timestamp_tm->tm_mon;
    hour=timestamp_tm->tm_hour;
    min=timestamp_tm->tm_min;
    second=timestamp_tm->tm_sec;
    g_string_append_printf(filename, "%id%im%i_%i_%i_%%3d%s",day,month+1,  hour, min, second, VIDEO_NAME_SUFFIX_DEFAULT);
    g_print("%s\n",  filename->str);
    return *filename;
}
GString         Names::name_model_4  (     std::string name, std::string ending     ){
    const gchar *directory;
    GString *filename;
    time_t timestamp;
    struct tm *timestamp_tm;
    int day, month, hour, min, second;
    directory = SAVE_FOLDER_DEFAULT;
    if(directory == NULL){ directory = g_get_tmp_dir();}
    filename = g_string_new(g_build_filename(directory, VIDEO_NAME_DEFAULT, NULL));
    timestamp=time(NULL);
    timestamp_tm=localtime(&timestamp);
    day=timestamp_tm->tm_mday;
    month=timestamp_tm->tm_mon;
    hour=timestamp_tm->tm_hour;
    min=timestamp_tm->tm_min;
    second=timestamp_tm->tm_sec;
    g_string_append_printf(filename, "%id%im%i_%i_%i_%%3d%s",day,month+1,  hour, min, second, VIDEO_NAME_SUFFIX_DEFAULT);
    g_print("%s\n",  filename->str);
    return *filename;
}
GString         Names::name_model_5  (     std::string name, std::string ending     ){
    const gchar *directory;
    GString *filename;
    time_t timestamp;
    struct tm *timestamp_tm;
    int day, month, hour, min, second;
    directory = SAVE_FOLDER_DEFAULT;
    if(directory == NULL){ directory = g_get_tmp_dir();}
    filename = g_string_new(g_build_filename(directory, VIDEO_NAME_DEFAULT, NULL));
    timestamp=time(NULL);
    timestamp_tm=localtime(&timestamp);
    day=timestamp_tm->tm_mday;
    month=timestamp_tm->tm_mon;
    hour=timestamp_tm->tm_hour;
    min=timestamp_tm->tm_min;
    second=timestamp_tm->tm_sec;
    g_string_append_printf(filename, "%id%im%i_%i_%i_%%3d%s",day,month+1,  hour, min, second, VIDEO_NAME_SUFFIX_DEFAULT);
    g_print("%s\n",  filename->str);
    return *filename;
}