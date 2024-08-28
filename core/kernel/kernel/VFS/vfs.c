#include "inc.h"




int VFS_main(){
    VFS_init();
    return 0;
}

int vfs_init(){
    mem_copy(_boot_img, rootfs_addr);
}

int vfs_file2fs(const char* path){
    
}


int vfs_open(   const char* path,
                int protect,
                uid user)
{

}




