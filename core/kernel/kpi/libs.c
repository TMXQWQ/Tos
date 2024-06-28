#include "inc.h"


//soft IRQ
long softirq_state=0;

typedef struct{
    char name[255];
    void (*int_func)();
    void* data;
} softirq;
void set_irq_state(unsigned long state){
    softirq_state |= state;
}

long get_irq_state(){
    return softirq_state;
}

void register_softirq(softirq sirq){
    for(int i=0;i<255;i++){
        if(softIRQ_list[i]==no_sys_call){
            softIRQ_list[i]=sirq;
            return ;
        }
    }
    logs("[Error]softiqr_list is full!",_LOG_ERROR);
}

void unregister_softirq(char *name){
    for(int i=0;i<255;i++){
        if(!strcmp(softiqr_list[i],name)){
            softIRQ_list[i]=sirq;
            return ;
        }
    }
    logs("[Warm]There isn't any softirq called ",_LOG_WARM);
    logs(name,_LOG_WARM);
}

void no_sys_call(){
    logs("[Warm]something called no_sys_call!",_LOG_WARM);
}

typedef softirq{
    .name="no_sys_call",
    .int_func=no_sys_call,
    .data=NULL
} no_sys_call;


softirq softIRQ_list[255]={
};