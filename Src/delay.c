#include"delay.h"
void delayms(int ms)
{
	SysTick->LOAD=16000-1; //Decides at what frequency to increment, 16MHz

	SysTick->VAL=0; //Sets start value of counter
	SysTick->CTRL |= (1<<0);//Counter enable
	SysTick->CTRL |= (1<<2);//Select processor clock

	for(int i=0;i<ms;i++)
	{
		while((SysTick->CTRL & (1<<16))==0)
		{

		}
	}
	SysTick->CTRL=0;
}


