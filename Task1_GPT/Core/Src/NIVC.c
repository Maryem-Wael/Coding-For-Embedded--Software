#include "NIVC.h"

void NVIC(unsigned int position){

	if ((unsigned int)position<(unsigned int)32){
		NVIC_ISER0 |= ((unsigned  int)1 << (unsigned  int)position);
	}

	else if(position>=32 && position<63){
		NVIC_ISER1 |= ((unsigned int)1 << ((unsigned int)position - (unsigned int)32));
	}

	else{
		NVIC_ISER2 |= ((unsigned int)1 << ((unsigned int)position - (unsigned int)64));
	}
}
