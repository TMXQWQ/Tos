#include "inc.h"

void kmm_init(mm m){
	m->create=&kmm_create;
	m->free=&kmm_free;
}

mnode kmm_create(mm m,size_t size,void* adr){
	mnode ret,tmp;
	if((mm.head)->enable!=200){
		ret.last=null;
		ret.adr=adr;
		ret.end=adr+size-1;
		ret.enable=0;
		ret.next=null;
		return ret;
	}else if((mm.head)->enable==200){
		for(int i=0;i<128;i++){
			if(((mm.head)+i)->enable!=200 && ((mm.head)+i)-next)==null{
				ret.adr=adr;
				ret.end=adr+size-1;
				ret.last=(mm.head)+i;
				ret.next=null;
				ret.enable=200;
				return ret;
			}
		}
	}
	return (mnode)-1;
}




