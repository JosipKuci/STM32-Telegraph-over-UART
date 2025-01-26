#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "led.h"
#include "uart.h"
#include "button.h"
#include "morse_tree.h"
#include"delay.h"
int main(void)
{
	uart_tx_init();
	led_init();
	button_init();
	char* tree = (char*)malloc(31*sizeof(char));
	tree=morseTree_init();

	uint8_t BtnState = 0; //1 if not pressed, 0 if pressed (as button is pullup)
	uint8_t BtnPressCount=0;
	bool WasButtonPressed=false;

	int EmptySpaceCount=0;

	uint8_t tree_index=0; //What position in the binary tree we are currently in

	int msCount=0;

	printf("Press button to start transmission\r\n");
	while((GPIOC->IDR & 0x00002000) == 0){} //Infinite loop before we get input from USER Button
    while(1)
    {
    	delayms(1);
    	msCount++;
    	BtnState = ((GPIOC->IDR & 0x00002000) != 0);
    	if(!BtnState && !WasButtonPressed)//Sees if the button was pressed and if the button was already pressed in the interval
    	{
    		led_on();
    		WasButtonPressed=true;
    		BtnPressCount++;
    		EmptySpaceCount=0;
    	}
    	else
    	{
    		led_off();
    	}

    	if(msCount>=250)//Expects input every 250ms
    	{
    		if(!WasButtonPressed)
    		{
    			if(BtnPressCount==1 || BtnPressCount==2)
    			{
    				__io_putchar('.');
    				tree_index=goLeft(tree_index);
    			}
    			else if(BtnPressCount>=3)
    			{
    				__io_putchar('_');
    				tree_index=goRight(tree_index);
    			}
    			BtnPressCount=0;
    			EmptySpaceCount++; //Mark as empty space if no input was detected
    			if(EmptySpaceCount>=3)
    			{
    				if(tree_index<63 && tree_index!=0) // Outputs the character depending on the value of the index
    				{
    					__io_putchar(tree[tree_index]);
    				}
    				EmptySpaceCount=0;
    				tree_index=0;
    			}

    		}
    		WasButtonPressed=false;
    		msCount=0;
    	}

    }

}


