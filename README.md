# Telegraph over UART
This is a program made for the Nucleo F411RE board that uses the onboard user button to generate morse code which is then decoded and displayed over the USB interface using the UART protocol

It supports all characters defined by the international Morse code standard

Data can be seen by any Serial Capture Program (I personally used RealTerm)
Baudrate is set to 115200 (can be changed in uart.h file)
There are no parity check bits and only 1 stop bit
### Note
This is NOT a faithful recreation of a telegraph, because i personally found it overwhelming to write that fast. The board expects an input every 250ms, 
if it doesn't detect it in 3 intervals, it starts reading the other letter. If i were to follow the standard, after 7 intervals (1.75 seconds) we would 
automatically go to the next word (a space symbol). So to counter this, four dashes (----) are used as a space between words

