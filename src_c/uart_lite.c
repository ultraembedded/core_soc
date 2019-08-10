#include "uart_lite.h"
#include "uart_lite_defs.h"

//-----------------------------------------------------------------
// Locals
//-----------------------------------------------------------------
static volatile uint32_t *m_uart;

//-----------------------------------------------------------------
// uartlite_init: Initialise UART peripheral
//-----------------------------------------------------------------
void uartlite_init(uint32_t base_addr)           
{
    uint32_t cfg = 0;
    m_uart = (volatile uint32_t *)base_addr;

    // Soft reset
    cfg += (1 << ULITE_CONTROL_RST_RX_SHIFT);
    cfg += (1 << ULITE_CONTROL_RST_TX_SHIFT);
    cfg += (1 << ULITE_CONTROL_IE_SHIFT);

    m_uart[ULITE_CONTROL/4]  = cfg;
}
//-----------------------------------------------------------------
// uartlite_putc: Polled putchar
//-----------------------------------------------------------------
int uartlite_putc(char c)
{
    // While TX FIFO full
    while (m_uart[ULITE_STATUS/4] & (1 << ULITE_STATUS_TXFULL_SHIFT))
        ;

    m_uart[ULITE_TX/4] = c;

    return 0;
}
//-----------------------------------------------------------------
// uartlite_haschar:
//-----------------------------------------------------------------
int uartlite_haschar(void)
{
    return (m_uart[ULITE_STATUS/4] & (1 << ULITE_STATUS_RXVALID_SHIFT)) != 0;
}
//-----------------------------------------------------------------
// uartlite_getchar: Read character from UART
//-----------------------------------------------------------------
int uartlite_getchar(void)
{
    if (uartlite_haschar())
        return (uint8_t)m_uart[ULITE_RX/4];
    else
        return -1;
}
