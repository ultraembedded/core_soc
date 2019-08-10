#ifndef __UART_LITE_H__
#define __UART_LITE_H__

#include <stdint.h>

//-----------------------------------------------------------------
// Prototypes
//-----------------------------------------------------------------
void uartlite_init(uint32_t base_addr);
int  uartlite_putc(char c);
int  uartlite_haschar(void);
int  uartlite_getchar(void);

#endif
