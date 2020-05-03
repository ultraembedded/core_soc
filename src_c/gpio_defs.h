//-----------------------------------------------------------------
//                     Basic Peripheral SoC
//                           V1.1
//                     Ultra-Embedded.com
//                     Copyright 2014-2020
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

#ifndef __GPIO_DEFS_H__
#define __GPIO_DEFS_H__

#define GPIO_DIRECTION    0x0
    #define GPIO_DIRECTION_OUTPUT_SHIFT          0
    #define GPIO_DIRECTION_OUTPUT_MASK           0xffffffff

#define GPIO_INPUT        0x4
    #define GPIO_INPUT_VALUE_SHIFT               0
    #define GPIO_INPUT_VALUE_MASK                0xffffffff

#define GPIO_OUTPUT       0x8
    #define GPIO_OUTPUT_DATA_SHIFT               0
    #define GPIO_OUTPUT_DATA_MASK                0xffffffff

#define GPIO_OUTPUT_SET   0xc
    #define GPIO_OUTPUT_SET_DATA_SHIFT           0
    #define GPIO_OUTPUT_SET_DATA_MASK            0xffffffff

#define GPIO_OUTPUT_CLR   0x10
    #define GPIO_OUTPUT_CLR_DATA_SHIFT           0
    #define GPIO_OUTPUT_CLR_DATA_MASK            0xffffffff

#define GPIO_INT_MASK     0x14
    #define GPIO_INT_MASK_ENABLE_SHIFT           0
    #define GPIO_INT_MASK_ENABLE_MASK            0xffffffff

#define GPIO_INT_SET      0x18
    #define GPIO_INT_SET_SW_IRQ_SHIFT            0
    #define GPIO_INT_SET_SW_IRQ_MASK             0xffffffff

#define GPIO_INT_CLR      0x1c
    #define GPIO_INT_CLR_ACK_SHIFT               0
    #define GPIO_INT_CLR_ACK_MASK                0xffffffff

#define GPIO_INT_STATUS   0x20
    #define GPIO_INT_STATUS_RAW_SHIFT            0
    #define GPIO_INT_STATUS_RAW_MASK             0xffffffff

#define GPIO_INT_LEVEL    0x24
    #define GPIO_INT_LEVEL_ACTIVE_HIGH_SHIFT     0
    #define GPIO_INT_LEVEL_ACTIVE_HIGH_MASK      0xffffffff

#define GPIO_INT_MODE     0x28
    #define GPIO_INT_MODE_EDGE_SHIFT             0
    #define GPIO_INT_MODE_EDGE_MASK              0xffffffff

#endif