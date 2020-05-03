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

#ifndef __TIMER_DEFS_H__
#define __TIMER_DEFS_H__

#define TIMER_CTRL0       0x8
    #define TIMER_CTRL0_INTERRUPT                1
    #define TIMER_CTRL0_INTERRUPT_SHIFT          1
    #define TIMER_CTRL0_INTERRUPT_MASK           0x1

    #define TIMER_CTRL0_ENABLE                   2
    #define TIMER_CTRL0_ENABLE_SHIFT             2
    #define TIMER_CTRL0_ENABLE_MASK              0x1

#define TIMER_CMP0        0xc
    #define TIMER_CMP0_VALUE_SHIFT               0
    #define TIMER_CMP0_VALUE_MASK                0xffffffff

#define TIMER_VAL0        0x10
    #define TIMER_VAL0_CURRENT_SHIFT             0
    #define TIMER_VAL0_CURRENT_MASK              0xffffffff

#define TIMER_CTRL1       0x14
    #define TIMER_CTRL1_INTERRUPT                1
    #define TIMER_CTRL1_INTERRUPT_SHIFT          1
    #define TIMER_CTRL1_INTERRUPT_MASK           0x1

    #define TIMER_CTRL1_ENABLE                   2
    #define TIMER_CTRL1_ENABLE_SHIFT             2
    #define TIMER_CTRL1_ENABLE_MASK              0x1

#define TIMER_CMP1        0x18
    #define TIMER_CMP1_VALUE_SHIFT               0
    #define TIMER_CMP1_VALUE_MASK                0xffffffff

#define TIMER_VAL1        0x1c
    #define TIMER_VAL1_CURRENT_SHIFT             0
    #define TIMER_VAL1_CURRENT_MASK              0xffffffff

#endif