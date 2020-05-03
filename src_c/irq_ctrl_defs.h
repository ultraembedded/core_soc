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

#ifndef __IRQ_CTRL_DEFS_H__
#define __IRQ_CTRL_DEFS_H__

#define IRQ_ISR           0x0
    #define IRQ_ISR_STATUS_SHIFT                 0
    #define IRQ_ISR_STATUS_MASK                  0x7f

#define IRQ_IPR           0x4
    #define IRQ_IPR_PENDING_SHIFT                0
    #define IRQ_IPR_PENDING_MASK                 0x7f

#define IRQ_IER           0x8
    #define IRQ_IER_ENABLE_SHIFT                 0
    #define IRQ_IER_ENABLE_MASK                  0x7f

#define IRQ_IAR           0xc
    #define IRQ_IAR_ACK_SHIFT                    0
    #define IRQ_IAR_ACK_MASK                     0x7f

#define IRQ_SIE           0x10
    #define IRQ_SIE_SET_SHIFT                    0
    #define IRQ_SIE_SET_MASK                     0x7f

#define IRQ_CIE           0x14
    #define IRQ_CIE_CLR_SHIFT                    0
    #define IRQ_CIE_CLR_MASK                     0x7f

#define IRQ_IVR           0x18
    #define IRQ_IVR_VECTOR_SHIFT                 0
    #define IRQ_IVR_VECTOR_MASK                  0xffffffff

#define IRQ_MER           0x1c
    #define IRQ_MER_ME                           0
    #define IRQ_MER_ME_SHIFT                     0
    #define IRQ_MER_ME_MASK                      0x1

#endif