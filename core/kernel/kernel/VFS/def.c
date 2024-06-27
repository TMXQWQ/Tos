#include <inc.h>

typedef struct{
    int32_t id                  //一个文件的第id个文件(一个文件最多有4,294,967,295个属性)
    int32_t attr_id;            //attr_id:  id      meaning
                                //          ID      含义
                                //          00      无效
                                //          01      保护属性(Unix 8进制)
                                //          02      立即文件(存放小于等于64B大小的文件,如果大于64B但小于1KB的文件分成多个文件块，最多占用16个属性)
                                //          03      长文件名(不够依id往下拼接起来)
                                //          04      间接属性(指向另一个属性)
                                //          05      硬盘块地址属性(一个硬盘块有1KB/1MB)
                                //          06      间接硬盘块
    int512_t attr;
} fs_attribute;


typedef struct{
    char* name[256]         ;
    size_t size             ;        //byte
    // int protect             ;        //类似于Unix的保护属性
    uid own                 ;
    FS fs                   ;
} i_node;

typedef struct {
    File (*open)()      ;
    int (*close)()      ;
    size_t (*seed)()    ;
    File (*link)()      ;       //只支持硬链接(不是软链接)
    File (*unlink)()    ;
}fs_op;

typedef struct{
    int type_id;
    char name[255];
    fs_op ops;
} FS;

