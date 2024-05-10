#include include.h

int main(){
	kmm_init();
    while(1){
        __asm__ __volatile__ (\
        "nop\r\t"
        "hlt\r\t"
        );
    }
    // return 0;    //never return
}
