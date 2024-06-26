#ifndef _VFS_H
#define _VFS_H

#include "inc.h"



typedef struct{
    char* name[256] ;
    size_t size     ;        //byte
    int protect     ;        //类似于Unix的保护属性
    uid own         ;
} File;

typedef struct {
    File (*open)()      ;
    int (*close)()      ;
    size_t (*seed)()    ;
    File (*link)()      ;
    File (*unlink)()    ;
}fs_op;



#endif