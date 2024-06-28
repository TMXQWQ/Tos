#ifndef _KPI_LIB_H
#define _KPI_LIB_H
#include "inc.h"

//logs -- flags
#define _LOG_STD        0x00000000
#define _LOG_WARM       0x00000001
#define _LOG_ERROR      0x00000002


//terminal IOs lib
void logs(const char* string,int flag);



//soft IRQ
long softirq_state=0;

typedef struct{
    char name[255];
    void (*int_func)();
    void* data;
} softirq;
void set_irq_state(unsigned long state);

long get_irq_state();

long register_softirq(char* name,void);

void no_sys_call();

typedef softirq{
    .name="no_sys_call",
    .int_func=no_sys_call,
    .data=NULL
} no_sys_call;


softirq softIRQ_list[255]={
    no_sys_call,
    
};




#endif