#include "inc.h"

typedef struct{
	mnode*	last	;
	mnode*	next	;
	void*	adr	;
	void*	end	;
	long	enable	;
}mnode;

typedef struct{
	mnode*	head;
	void	(*init)(mm);
	mnode*	(*create)(mm,size_t,void*);
	void*	(*free)(mm,mnode);
}mm;

void kmm_init(mm);


mnode* kmm_create(mm,size_t,void*);


void* free(mm,mnode);




