#include "spi_lite.h"
#include "spi_lite_defs.h"

//-----------------------------------------------------------------
// Locals
//-----------------------------------------------------------------
static volatile uint32_t *m_spi;

//-----------------------------------------------------------------
// spi_delay_ns: Simple delay loop
//-----------------------------------------------------------------
static void spi_delay_ns(int delay)
{
    volatile uint32_t i=delay;
    while (i--)
        ;
}
//-----------------------------------------------------------------
// spi_init: Initialise SPI master
//-----------------------------------------------------------------
void spi_init(uint32_t base_addr)           
{
    uint32_t cfg = 0;
    m_spi = (volatile uint32_t *)base_addr;

    cfg += (1 << SPI_CR_SPE_SHIFT);
    cfg += (1 << SPI_CR_MASTER_SHIFT);
    cfg += (0 << SPI_CR_CPOL_SHIFT);
    cfg += (0 << SPI_CR_CPHA_SHIFT);
    cfg += (1 << SPI_CR_MANUAL_SS_SHIFT);
    cfg += (0 << SPI_CR_LSB_FIRST_SHIFT);

    m_spi[SPI_CR/4]  = cfg;
    m_spi[SPI_SSR/4] = ~0;

    // Soft reset
    m_spi[SPI_SRR/4] = 0x0000000A;
}
//-----------------------------------------------------------------
// spi_cs: Set chip select
//-----------------------------------------------------------------
void spi_cs(uint32_t value)
{
    spi_delay_ns(50);
    m_spi[SPI_SSR/4] = value;
    spi_delay_ns(50);
}
//-----------------------------------------------------------------
// spi_sendrecv: Send or receive a character
//-----------------------------------------------------------------
uint8_t spi_sendrecv(uint8_t data)
{
    m_spi[SPI_DTR/4] = data;

    while (!(m_spi[SPI_SR/4] & (1 << SPI_SR_TX_EMPTY_SHIFT)))
        ;

    return (uint8_t)m_spi[SPI_DRR/4];
}
//-----------------------------------------------------------------
// spi_readblock: Read a block of data from a device
//-----------------------------------------------------------------
void spi_readblock(uint8_t *ptr, int length)
{
    int i;

    for (i=0;i<length;i++)
        *ptr++ = spi_sendrecv(0xFF);
}
//-----------------------------------------------------------------
// spi_writeblock: Write a block of data to a device
//-----------------------------------------------------------------
void spi_writeblock(uint8_t *ptr, int length)
{
    int i;

    for (i=0;i<length;i++)
        spi_sendrecv(*ptr++);
}
