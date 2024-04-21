#include include.h

int main(){
    while(1){
        __asm__ __volatile__ (\
        "nop\r\t"
        "hlt\r\t"
        );
    }
    // return 0;    //never return
}
