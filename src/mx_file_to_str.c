#include "libmx.h"

static int file_len(const char *file) {
    int len = 0;
    int file_desc = -1;
    char buff[1];
    if(!file)
        return -1;
    file_desc = open(file, O_RDONLY);
    if(file_desc < 0) 
        return -1;
    while(read(file_desc, buff, 1))
        len++;
    if(close(file_desc) < 0)
        return -1;
    return len;
}
char *mx_file_to_str(const char *file) {
    int file_desc = -1;
    int len = 0;
    int i = 0;
    char buff[1];
    char *target_str = NULL;
    len = file_len(file);
    if(file_len >= 0) {
        target_str = mx_strnew(len);
        if(!target_str)
            return NULL;
        file_desc = open(file, O_RDONLY);
        if(file_desc < 0)
            return NULL;
        while(read(file_desc, buff, 1))
            target_str[i++] = buff[0];
        if(close(file_desc) < 0)
            return NULL;
    }
    return target_str;
}
