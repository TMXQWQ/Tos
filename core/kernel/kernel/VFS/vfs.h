#ifndef _VFS_H
#define _VFS_H

#include "inc.h"

void* rootfs_ram_addr;

typedef struct{
    long rootfs_addr;
    size_t size;
} super_block;

void vfs_init();

typedef struct File;

typedef struct fs_op;

typedef struct fs;



#endif