//-----------------------------------------------------------------
//                     Basic Peripheral SoC
//                           V1.0
//                     Ultra-Embedded.com
//                     Copyright 2014-2019
//
//                 Email: admin@ultra-embedded.com
//
//                         License: GPL
// If you would like a version with a more permissive license for
// use in closed source commercial applications please contact me
// for details.
//-----------------------------------------------------------------
//
// This file is open source HDL; you can redistribute it and/or 
// modify it under the terms of the GNU General Public License as 
// published by the Free Software Foundation; either version 2 of 
// the License, or (at your option) any later version.
//
// This file is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public 
// License along with this file; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA
//-----------------------------------------------------------------

//-----------------------------------------------------------------
//                          Generated File
//-----------------------------------------------------------------

#ifndef __UART_LITE_DEFS_H__
#define __UART_LITE_DEFS_H__

#define ULITE_RX          0x0
    #define ULITE_RX_DATA_SHIFT                  0
    #define ULITE_RX_DATA_MASK                   0xff

#define ULITE_TX          0x4
    #define ULITE_TX_DATA_SHIFT                  0
    #define ULITE_TX_DATA_MASK                   0xff

#define ULITE_STATUS      0x8
    #define ULITE_STATUS_IE                      4
    #define ULITE_STATUS_IE_SHIFT                4
    #define ULITE_STATUS_IE_MASK                 0x1

    #define ULITE_STATUS_TXFULL                  3
    #define ULITE_STATUS_TXFULL_SHIFT            3
    #define ULITE_STATUS_TXFULL_MASK             0x1

    #define ULITE_STATUS_TXEMPTY                 2
    #define ULITE_STATUS_TXEMPTY_SHIFT           2
    #define ULITE_STATUS_TXEMPTY_MASK            0x1

    #define ULITE_STATUS_RXFULL                  1
    #define ULITE_STATUS_RXFULL_SHIFT            1
    #define ULITE_STATUS_RXFULL_MASK             0x1

    #define ULITE_STATUS_RXVALID                 0
    #define ULITE_STATUS_RXVALID_SHIFT           0
    #define ULITE_STATUS_RXVALID_MASK            0x1

#define ULITE_CONTROL     0xc
    #define ULITE_CONTROL_IE                     4
    #define ULITE_CONTROL_IE_SHIFT               4
    #define ULITE_CONTROL_IE_MASK                0x1

    #define ULITE_CONTROL_RST_RX                 1
    #define ULITE_CONTROL_RST_RX_SHIFT           1
    #define ULITE_CONTROL_RST_RX_MASK            0x1

    #define ULITE_CONTROL_RST_TX                 0
    #define ULITE_CONTROL_RST_TX_SHIFT           0
    #define ULITE_CONTROL_RST_TX_MASK            0x1

#endif