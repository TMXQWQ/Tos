#ifndef _TUX_INC_H_
#define _TUX_INC_H_

//FLAG的值
#define FLAG_TOO_LONG   //过长
#define FLAG_E          //只执行
#define FLAG_R          //只读
#define FLAG_W          //只写
#define FLAG_WR         //读写
#define FLAG_AOPS       //所有权限(读写&执行)


typedef FLAG long;
typedef PID long;
typedef struct{
    FLAG flag;
    PID pid;
    char* data;
}SIG;
/*
    flag:   标志
    pid:    进程ID
    data:   数据
*/


long send_SIG(SIG data);
/*
    成功返回0，否则返回错误码
*/

long get_SIG(SIG* data);
/*
    成功返回0，否则返回错误码
*/

PID get_pid();
/*
    成功返回自己的PID，否则返回错误码
*/


#endif