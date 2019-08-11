## Basic Peripheral SoC

Github:   [http://github.com/ultraembedded/core_soc](http://github.com/ultraembedded/core_soc)

A basic SoC with Timer, UART, SPI, GPIO and Interrupt Controller peripherals.

### Features
* Multi-channel timer peripheral.
* UART peripheral.
* SPI (master mode) peripheral with 8 chip selects.
* 32 I/O GPIO controller.
* Interrupt controller (combines peripheral IRQs into single IRQ).
* AXI4-Lite slave interface.

### Configuration
* Top: core_soc
* Clock: clk_i
* Reset: rst_i - Asynchronous, active high
* parameter CLK_FREQ - Clock speed (in Hz)
* parameter BAUDRATE - UART baud rate (e.g. 115200)
* parameter C_SCK_RATIO - SPI clock divider ratio for clk_i -> spi_clk_o

### Memory Map

| Range                     | Description                                         |
| ------------------------- | --------------------------------------------------- |
| 0x0000_0000 - 0x00ff_ffff | Peripheral - IRQ controller                         |
| 0x0100_0000 - 0x01ff_ffff | Peripheral - Timer                                  |
| 0x0200_0000 - 0x02ff_ffff | Peripheral - UART                                   |
| 0x0300_0000 - 0x03ff_ffff | Peripheral - SPI                                    |
| 0x0400_0000 - 0x04ff_ffff | Peripheral - GPIO                                   |

### Interrupt Sources

| Index  | Source                      |
| -------| --------------------------- |
|   0    | Peripheral - Timer          |
|   1    | Peripheral - UART           |
|   2    | Peripheral - SPI            |
|   3    | Peripheral - GPIO           |

### Peripheral Register Map

| Offset | Name | Description   |
| ------ | ---- | ------------- |
| 0x0000_0000 | IRQ_ISR | [RW] Interrupt Status Register |
| 0x0000_0004 | IRQ_IPR | [R] Interrupt Pending Register |
| 0x0000_0008 | IRQ_IER | [RW] Interrupt Enable Register |
| 0x0000_000c | IRQ_IAR | [W] Interrupt Acknowledge Register |
| 0x0000_0010 | IRQ_SIE | [W] Set Interrupt Enable bits |
| 0x0000_0014 | IRQ_CIE | [W] Clear Interrupt Enable bits |
| 0x0000_0018 | IRQ_IVR | [RW] Interrupt Vector Register |
| 0x0000_001c | IRQ_MER | [RW] Master Enable Register |
| 0x0100_0008 | TIMER_CTRL0 | [RW] Control |
| 0x0100_000c | TIMER_CMP0 | [RW] Compare value (interrupt on match) |
| 0x0100_0010 | TIMER_VAL0 | [RW] Current Value |
| 0x0100_0014 | TIMER_CTRL1 | [RW] Control |
| 0x0100_0018 | TIMER_CMP1 | [RW] Compare value (interrupt on match) |
| 0x0100_001c | TIMER_VAL1 | [RW] Current Value |
| 0x0200_0000 | ULITE_RX | [R] UART Data Register |
| 0x0200_0004 | ULITE_TX | [W] UART Data Register |
| 0x0200_0008 | ULITE_STATUS | [R] UART Status Register |
| 0x0200_000c | ULITE_CONTROL | [RW] UART Configuration Register |
| 0x0300_001c | SPI_DGIER | [RW] Device Global Interrupt Enable Register |
| 0x0300_0020 | SPI_IPISR | [RW] IP Interrupt Status Register |
| 0x0300_0028 | SPI_IPIER | [RW] IP Interrupt Enable Register |
| 0x0300_0040 | SPI_SRR | [RW] Software Reset Register |
| 0x0300_0060 | SPI_CR | [RW] SPI Control Register |
| 0x0300_0064 | SPI_SR | [R] SPI Status Register |
| 0x0300_0068 | SPI_DTR | [W] SPI Data Transmit Register |
| 0x0300_006c | SPI_DRR | [R] SPI Data Receive Register |
| 0x0300_0070 | SPI_SSR | [RW] SPI Slave Select Register |
| 0x0400_0000 | GPIO_DIRECTION | [RW] Configuration Register |
| 0x0400_0004 | GPIO_INPUT | [R] GPIO Input Status |
| 0x0400_0008 | GPIO_OUTPUT | [RW] GPIO Output Control |
| 0x0400_000c | GPIO_OUTPUT_SET | [W] GPIO Output Control Set Alias |
| 0x0400_0010 | GPIO_OUTPUT_CLR | [W] GPIO Output Control Clr Alias |
| 0x0400_0014 | GPIO_INT_MASK | [RW] GPIO Interrupt Enable Mask |
| 0x0400_0018 | GPIO_INT_SET | [W] GPIO Interrupt Set |
| 0x0400_001c | GPIO_INT_CLR | [W] GPIO Interrupt Clear |
| 0x0400_0020 | GPIO_INT_STATUS | [R] GPIO Interrupt Raw Status |
| 0x0400_0024 | GPIO_INT_LEVEL | [RW] GPIO Interrupt Level |
| 0x0400_0028 | GPIO_INT_MODE | [RW] GPIO Interrupt Mode |

### Peripheral Register Fields

##### IRQ Register: IRQ_ISR

| Bits | Name | Description    |
| ---- | ---- | -------------- |
| 3:0 | STATUS | Pending interrupt (unmasked) bitmap. |

##### IRQ Register: IRQ_IPR

| Bits | Name | Description    |
| ---- | ---- | -------------- |
| 3:0 | PENDING | Pending interrupts (masked) bitmap. |

##### IRQ Register: IRQ_IER

| Bits | Name | Description    |
| ---- | ---- | -------------- |
| 3:0 | ENABLE | Interrupt enable mask. |

##### IRQ Register: IRQ_IAR

| Bits | Name | Description    |
| ---- | ---- | -------------- |
| 3:0 | ACK | Bitmap of interrupts to acknowledge. |

##### IRQ Register: IRQ_SIE

| Bits | Name | Description    |
| ---- | ---- | -------------- |
| 3:0 | SET | Bitmap of interrupts to enable. |

##### IRQ Register: IRQ_CIE

| Bits | Name | Description    |
| ---- | ---- | -------------- |
| 3:0 | CLR | Bitmap of interrupts to disable. |

##### IRQ Register: IRQ_IVR

| Bits | Name | Description    |
| ---- | ---- | -------------- |
| 31:0 | VECTOR | Highest priority active interrupt number. |

##### IRQ Register: IRQ_MER

| Bits | Name | Description    |
| ---- | ---- | -------------- |
| 0 | ME | Master Enable |

##### Timer Register: TIMER_CTRLx

| Bits | Name | Description    |
| ---- | ---- | -------------- |
| 1 | INTERRUPT | Interrupt enable. |
| 2 | ENABLE | Timer enable. |

##### Timer Register: TIMER_CMPx

| Bits | Name | Description    |
| ---- | ---- | -------------- |
| 31:0 | VALUE | Match value. |

##### Timer Register: TIMER_VALx

| Bits | Name | Description    |
| ---- | ---- | -------------- |
| 31:0 | CURRENT | Current timer value. |

##### UART Register: ULITE_RX

| Bits | Name | Description    |
| ---- | ---- | -------------- |
| 7:0 | DATA | Date byte |

##### UART Register: ULITE_TX

| Bits | Name | Description    |
| ---- | ---- | -------------- |
| 7:0 | DATA | Date byte |

##### UART Register: ULITE_STATUS

| Bits | Name | Description    |
| ---- | ---- | -------------- |
| 4 | IE | Interrupt enabled |
| 3 | TXFULL | Transmit buffer full |
| 2 | TXEMPTY | Transmit buffer empty |
| 1 | RXFULL | Receive buffer full |
| 0 | RXVALID | Receive buffer not empty |

##### UART Register: ULITE_CONTROL

| Bits | Name | Description    |
| ---- | ---- | -------------- |
| 4 | IE | Interrupt enable |
| 1 | RST_RX | Flush Rx Buffer |
| 0 | RST_TX | Flush Tx Buffer |

##### SPI Register: SPI_DGIER

| Bits | Name | Description    |
| ---- | ---- | -------------- |
| 31 | GIE | Global interrupt enable. |

##### SPI Register: SPI_IPISR

| Bits | Name | Description    |
| ---- | ---- | -------------- |
| 2 | TX_EMPTY | Tx FIFO empty interrupt status. |

##### SPI Register: SPI_IPIER

| Bits | Name | Description    |
| ---- | ---- | -------------- |
| 2 | TX_EMPTY | Tx FIFO interrupt enable. |

##### SPI Register: SPI_SRR

| Bits | Name | Description    |
| ---- | ---- | -------------- |
| 31:0 | RESET | Software FIFO reset. |

##### SPI Register: SPI_CR

| Bits | Name | Description    |
| ---- | ---- | -------------- |
| 0 | LOOP | Loopback enable (MOSI to MISO). |
| 1 | SPE | SPI Enable. |
| 2 | MASTER | Master mode (slave mode not currently supported). |
| 3 | CPOL | Clock polarity. |
| 4 | CPHA | Clock phase. |
| 5 | TXFIFO_RST | Tx FIFO reset. |
| 6 | RXFIFO_RST | Rx FIFO reset. |
| 7 | MANUAL_SS | Manual chip select mode (auto mode not supported). |
| 8 | TRANS_INHIBIT | Transfer inhibit. |
| 9 | LSB_FIRST | Data LSB first (1) or MSB first (0). |

##### SPI Register: SPI_SR

| Bits | Name | Description    |
| ---- | ---- | -------------- |
| 0 | RX_EMPTY | Rx FIFO empty. |
| 1 | RX_FULL | Rx FIFO full. |
| 2 | TX_EMPTY | Tx FIFO empty. |
| 3 | TX_FULL | Tx FIFO full. |

##### SPI Register: SPI_DTR

| Bits | Name | Description    |
| ---- | ---- | -------------- |
| 7:0 | DATA | Date byte |

##### SPI Register: SPI_DRR

| Bits | Name | Description    |
| ---- | ---- | -------------- |
| 7:0 | DATA | Date byte |

##### SPI Register: SPI_SSR

| Bits | Name | Description    |
| ---- | ---- | -------------- |
| 0 | VALUE | Chip select value |

##### GPIO Register: GPIO_DIRECTION

| Bits | Name | Description    |
| ---- | ---- | -------------- |
| 31:0 | OUTPUT | 0 = Input, 1 = Output |

##### GPIO Register: GPIO_INPUT

| Bits | Name | Description    |
| ---- | ---- | -------------- |
| 31:0 | VALUE | Raw input status |

##### GPIO Register: GPIO_OUTPUT

| Bits | Name | Description    |
| ---- | ---- | -------------- |
| 31:0 | DATA | GPIO output value |

##### GPIO Register: GPIO_OUTPUT_SET

| Bits | Name | Description    |
| ---- | ---- | -------------- |
| 31:0 | DATA | GPIO output mask - set for high |

##### GPIO Register: GPIO_OUTPUT_CLR

| Bits | Name | Description    |
| ---- | ---- | -------------- |
| 31:0 | DATA | GPIO output mask - set for low |

##### GPIO Register: GPIO_INT_MASK

| Bits | Name | Description    |
| ---- | ---- | -------------- |
| 31:0 | ENABLE | GPIO Interrupt Enable Mask |

##### GPIO Register: GPIO_INT_SET

| Bits | Name | Description    |
| ---- | ---- | -------------- |
| 31:0 | SW_IRQ | Write 1 to assert an interrupt |

##### GPIO Register: GPIO_INT_CLR

| Bits | Name | Description    |
| ---- | ---- | -------------- |
| 31:0 | ACK | Write 1 to clear an interrupt |

##### GPIO Register: GPIO_INT_STATUS

| Bits | Name | Description    |
| ---- | ---- | -------------- |
| 31:0 | RAW | Set if interrupt active (regardless of INT_MASK) |

##### GPIO Register: GPIO_INT_LEVEL

| Bits | Name | Description    |
| ---- | ---- | -------------- |
| 31:0 | ACTIVE_HIGH | GPIO Interrupt Level - 1 = active high / rising edge, 0 = active low / falling edge |

##### GPIO Register: GPIO_INT_MODE

| Bits | Name | Description    |
| ---- | ---- | -------------- |
| 31:0 | EDGE | GPIO Interrupt Mode - 1 = edge triggered, 0 = level |

