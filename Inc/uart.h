#ifndef UART_H
#define UART_H
#define GPIOA_ENABLE 0x00000001
#define USART2_ENABLE 0x00020000
#define SYSTEM_FREQUENCY 16000000
#define APB1_CLK SYSTEM_FREQUENCY
#define UART_BAUDRATE 115200
#define CR1_UART_AND_TX_ENABLE 0x00002008
void uart_tx_init();
#define SR_TX (1U<<7)
void uart_write();
#endif
