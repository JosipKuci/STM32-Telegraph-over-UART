#include "morse_tree.h"
char morse_tree[63]=
	{
			  	     	 	   	  ' ',
				  'E',    	      				'T',
		  'I',    		 'A',    		'N',    		'M',
	  'S',    'U',   'R',   'W',    'D',    'K',    'G',   'O',
	'H','V','F',' ','L',' ','P','J','B','X','C','Y','Z','Q',' ',' ',
	'5','4',' ','3',' ',' ',' ','2',' ',' ','+',' ',' ',' ',' ','1','6','=','/',' ',' ',' ',' ',' ','7',' ',' ',' ','8',' ','9','0'
	};
char* morseTree_init()
{
	return morse_tree;
}


int goLeft(int index)
{
	if(index==0)
	{
	    index+=1;
	}
	else
	{
	    index=index*2+1;
	}
	return index;
}
int goRight(int index)
{
	if(index==0)
	{
		index+=2;
	}
	else
	{
		index=index*2+2;
	}
	return index;
}
