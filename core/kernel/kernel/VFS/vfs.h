#ifndef _VFS_H
#define _VFS_H

#include "inc.h"

#define rootfs_ram_addr 0x114514        //可以自定义，要求  <addr<  

typedef struct{
    long rootfs_addr;
    size_t size;
} super_block;

void vfs_init();

typedef struct File;

typedef struct fs_op;

typedef struct fs;



#endif