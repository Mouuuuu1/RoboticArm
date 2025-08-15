#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "GIE_Interface.h"
#include "GIE_Register.h"

void Global_interrupt_enable(void){
	SET_BIT(SREG,7);
}
void Global_interrupt_disable(void){
	CLR_BIT(SREG,7);
}
