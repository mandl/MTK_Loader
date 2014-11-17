/*
 *
 *
 * All Rights Reserved
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */

#ifndef _MTK_MT6223_H
#define _MTK_MT6223_H

#define MTK6223_CONFG_BASE        0x80000000  // Configuration Registers
#define MTK6223_EMI_BASE          0x80010000  // External Memory Interface
#define MTK6223_CIRQ_BASE         0x80020000  // Interrupt Controller
#define MTK6223_DMA_BASE          0x80030000  // DMA Controller
#define MTK6223_RGU_BASE          0x80040000  // Reset Generation Unit
#define MTK6223_GCU_BASE          0x80060000  // GPRS Cipher Unit
#define MTK6223_I2C_BASE          0x80070000
#define MTK6223_SWDBG_BASE        0x80090000
#define MTK6223_GPT_BASE          0x80100000
#define MTK6223_KP_BASE           0x80110000
#define MTK6223_GPIO_BASE         0x80120000
#define MTK6223_UART1_BASE        0x80130000
#define MTK6223_SIM_BASE          0x80140000
#define MTK6223_PWM_BASE          0x80150000
#define MTK6223_ALTER_BASE        0x80160000
#define MTK6223_SEJ_BASE          0x80170000
#define MTK6223_UART2_BASE        0x80180000
#define MTK6223_UART3_BASE        0x801b0000
#define MTK6223_TDMA_BASE         0x80200000
#define MTK6223_RTC_BASE          0x80210000
#define MTK6223_BSI_BASE          0x80220000
#define MTK6223_BPI_BASE          0x80230000
#define MTK6223_AFC_BASE          0x80240000
#define MTK6223_APC_BASE          0x80250000
#define MTK6223_FCS_BASE          0x80260000
#define MTK6223_AUXADC_BASE       0x80270000
#define MTK6223_DIVIDER_BASE      0x80280000
#define MTK6223_CSD_ACC_BASE      0x80290000
#define MTK6223_SHARE1_BASE       0x80300000
#define MTK6223_PATCH1_BASE       0x80310000
#define MTK6223_SHARE2_BASE       0x80320000
#define MTK6223_PATCH2_BASE       0x80330000
#define MTK6223_AFE_BASE          0x80400000
#define MTK6223_BFE_BASE          0x80410000
#define MTK6223_MIXED_BASE        0x80500000  // Analog Chip Interface Controller

#define MTK6223_DMA11_FIFO 0x78000000  // Virtual FIFO DMA 11 UART1 RX / ALL UART TX
#define MTK6223_DMA12_FIFO 0x78000100  // Virtual FIFO DMA 12 UART2 RX / ALL UART TX
#define MTK6223_DMA13_FIFO 0x78000200  // Virtual FIFO DMA 13 UART3 RX / ALL UART TX
#define MTK6223_DMA14_FIFO 0x78000300  // Virtual FIFO DMA 14 ALL UART TX

// ***************  Configuration Registers   16 bit   ****************************

#define MTK6223_CONFG_HW_VERSION	(MTK6223_CONFG_BASE + 0x000)
#define MTK6223_CONFG_FW_VERSION	(MTK6223_CONFG_BASE + 0x004)
#define MTK6223_HARDWARE_CODE       (MTK6223_CONFG_BASE + 0x008)
#define MTK6223_APB_BUS_CONTROL     (MTK6223_CONFG_BASE + 0x404)
#define MTK6223_AHB_BUS_CONTROL     (MTK6223_CONFG_BASE + 0x500)

// ********************** External Memory Interface register definitions ***************

#define MTK6223_EMI_CONA		(MTK6223_EMI_BASE + 0x00)   // EMI Control Register for BANK0
#define MTK6223_EMI_CONB		(MTK6223_EMI_BASE + 0x08)	// EMI Control Register for BANK1
#define MTK6223_EMI_CONC		(MTK6223_EMI_BASE + 0x10)	// EMI Control Register for BANK2
#define MTK6223_EMI_COND		(MTK6223_EMI_BASE + 0x18)	// EMI Control Register for BANK3
#define MTK6223_EMI_CONE		(MTK6223_EMI_BASE + 0x20)	// EMI Control Register for BANK4
#define MTK6223_EMI_CONF		(MTK6223_EMI_BASE + 0x28)	// EMI Control Register for BANK5
#define MTK6223_EMI_CONG		(MTK6223_EMI_BASE + 0x30)	// EMI Control Register for BANK6
#define MTK6223_EMI_CONH		(MTK6223_EMI_BASE + 0x38)	// EMI Control Register for BANK7
#define MTK6223_EMI_REMAP		(MTK6223_EMI_BASE + 0x40)   // EMI Re-map Control Register
#define MTK6223_EMI_GEN         (MTK6223_EMI_BASE + 0x44)   // EMI General Control Register
#define MTK6223_PREFETCH_CON    (MTK6223_EMI_BASE + 0x50)   // Code Cache and Code prefetch Control Register
#define MTK6223_EMI_ADMUX       (MTK6223_EMI_BASE + 0x78)   // EMI A/D Mux Control Register

#define MTK6223_SLEEP_CON       (MTK6223_CONFG_BASE + 0x114)

//*********** set PLL **************************

// PLL Frequency Register
#define MTK6223_PLL             (MTK6223_CONFG_BASE + 0x100)
#define MTK6223_RST 			(1 << 7)
#define MTK6223_MPLLSEL_SHIFT 	(3)       // 2 Using PLL Clock for MCU
#define MTK6223_DPLLSEL 		(1 << 5)  // Using PLL for DSP
#define MTK6223_DIV_CTRL_SHIFT  (13)       // 6 = 105 Mhz ( Div_CTRL+2) * 13Mhz

// Clock Control Register
#define MTK6223_CLK_CON             (MTK6223_CONFG_BASE + 0x110)
#define MTK6223_CLKSQ_DIV2_DSP (1 << 0)  // Divider not bypassed
#define MTK6223_CLKSQ_DIV2_MCU (1 << 1)  // Divider not bypassed

// MCU Clock Control Register
#define MTK6223_MCUCLK_CON          (MTK6223_CONFG_BASE + 0x118)
#define MTK6223_MCU_FSEL_SHIFT (0)       // 3 52MHz
#define MTK6223_SRCCLK         (1<< 7)   // 1 26MHz  (TCVCXO) frequency identifier.
#define MTK6223_ARM_FSEL_SHIFT (8)       // 3 52MHz

// DSP Clock Control Register
#define MTK6223_DSPCLK_CON          (MTK6223_CONFG_BASE + 0x11C)
#define MTK6223_DSP1_FSEL_SHIFT (0) // 7 = 104MHz
#define MTK6223_DSP2_FSEL_SHIFT (4) // 7 = 104MHz

// ******************   DMA *****************************************************************

enum mtk623_dma_reg
{

  MTK6223_DMA_SRC = 0x00,
  MTK6223_DMA_DST = 0x04,
  MTK6223_DMA_WPPT = 0x08,
  MTK6223_DMA_WPTO = 0x0C,

  MTK6223_DMA_COUNT = 0x10,
  MTK6223_DMA_CON = 0x14, // config
  MTK6223_DMA_START = 0x18,
  MTK6223_DMA_INTSTA = 0x1c,
  MTK6223_DMA_ACKINT = 0x20,
  MTK6223_DMA_RLCT = 0x24,
  MTK6223_DMA_LIMITER = 0x28,
  MTK6223_DMA_PGMADDR = 0x2c, // FIFO address in memory

  MTK6223_DMA_WRPTR = 0x30, // read only
  MTK6223_DMA_RDPTR = 0x34, // read only
  MTK6223_DMA_FFCNT = 0x38, // FIFO count
  MTK6223_DMA_FFSTA = 0x3C, // FIFO status
  MTK6223_DMA_ALTLEN = 0x40,
  MTK6223_DMA_FFSIZE = 0x44
// FIFO size

};

#define MTK6223_DMA_GLBSTA                 (MTK6223_DMA_BASE+0x0000)     // Read only
#define MTK6223_DMA_GLBLIMITER             (MTK6223_DMA_BASE+0x0028)
#define	MTK6223_DMA_SRC(x)                 (MTK6223_DMA_BASE+MTK6223_DMA_SRC   + (0x0100*(x)))
#define	MTK6223_DMA_DST(x)                 (MTK6223_DMA_BASE+MTK6223_DMA_DST   + (0x0100*(x)))
#define	MTK6223_DMA_WPPT(x)                (MTK6223_DMA_BASE+MTK6223_DMA_WPPT  + (0x0100*(x)))
#define	MTK6223_DMA_WPTO(x)                (MTK6223_DMA_BASE+MTK6223_DMA_WPTO  + (0x0100*(x)))
#define	MTK6223_DMA_COUNT(x)               (MTK6223_DMA_BASE+MTK6223_DMA_COUNT + (0x0100*(x)))   // FIFO RX/TX threshold
#define	MTK6223_DMA_CON(x)                 (MTK6223_DMA_BASE+MTK6223_DMA_CON   + (0x0100*(x)))
#define	MTK6223_DMA_CON_SIZE_SHIFT  (0)       // 0 = Byte 1 = Half Word  2 = Word
#define	MTK6223_DMA_CON_SINC         (1<<2)   // source increment
#define	MTK6223_DMA_CON_DINC         (1<<3)   // destination increment
#define	MTK6223_DMA_CON_DREQ         (1<<4)   // 1 Hardware handshake management
#define	MTK6223_DMA_CON_B2W          (1<<5)
#define	MTK6223_DMA_CON_BURST_SHIFT  (8)
#define	MTK6223_DMA_CON_ITEN         (1<<15)  // Interrupt enable
#define	MTK6223_DMA_CON_WPSD         (1<<16)
#define	MTK6223_DMA_CON_WPEN         (1<<17)
#define	MTK6223_DMA_CON_DIR          (1<<18)  // WRITE = 1 -> FIFO DMA is RX FIFO.
#define	MTK6223_DMA_CON_MAS_SHIFT    (20)     // Master selection
#define	MTK6223_DMA_CON_MAS_UART1_TX (0x8)
#define	MTK6223_DMA_CON_MAS_UART1_RX (0x9)
#define	MTK6223_DMA_CON_MAS_UART2_TX (0xA)
#define	MTK6223_DMA_CON_MAS_UART2_RX (0xB)

#define	MTK6223_DMA_START(x)               (MTK6223_DMA_BASE+MTK6223_DMA_START+(0x0100*(x)))
#define	MTK6223_DMA_START_STR  (1<<15)   // start the DMA
#define	MTK6223_DMA_INTSTA(x)              (MTK6223_DMA_BASE+MTK6223_DMA_INTSTA+(0x0100*(x)))
#define	MTK6223_DMA_ACKINT(x)              (MTK6223_DMA_BASE+0x0020+(0x0100*(x)))
#define	MTK6223_DMA_RLCT(x)                (MTK6223_DMA_BASE+0x0024+(0x0100*(x)))
#define	MTK6223_DMA_LIMITER(x)             (MTK6223_DMA_BASE+0x0028+(0x0100*(x)))
#define	MTK6223_DMA_PGMADDR(x)             (MTK6223_DMA_BASE+0x002c+(0x0100*(x)))

// Virtual FiFo
#define MTK6223_DMA_WRPTR(x)               (MTK6223_DMA_BASE+MTK6223_DMA_WRPTR+(0x0100*(x))) // read only
#define MTK6223_DMA_RDPTR(x)               (MTK6223_DMA_BASE+MTK6223_DMA_RDPTR+(0x0100*(x))) // read only
#define MTK6223_DMA_FFCNT(x)               (MTK6223_DMA_BASE+MTK6223_DMA_FFCNT+(0x0100*(x)))
#define MTK6223_DMA_FFSTA(x)               (MTK6223_DMA_BASE+MTK6223_DMA_FFSTA+(0x0100*(x)))
#define MTK6223_FFSTA_FULL  (1 << 0)
#define MTK6223_FFSTA_EMPTY (1 << 1)

#define MTK6223_DMA_ALTLEN(x)              (MTK6223_DMA_BASE+MTK6223_DMA_ALTLEN+(0x0100*(x)))
#define MTK6223_DMA_FFSIZE(x)              (MTK6223_DMA_BASE+MTK6223_DMA_FFSIZE+(0x0100*(x)))

// ******************   Software Power Control ***********************************************

#define MTK6223_PDN_CON0		(MTK6223_CONFG_BASE + 0x300) // Power Down Control 0 Register
#define MTK6223_PDN_CON1		(MTK6223_CONFG_BASE + 0x304) // Power Down Control 1 Register
#define MTK6223_PDN_CON2		(MTK6223_CONFG_BASE + 0x308) // Power Down Control 2 Register
#define MTK6223_PDN_CON3		(MTK6223_CONFG_BASE + 0x30c) // Power Down Control 3 Register
#define MTK6223_PDN_SET0		(MTK6223_CONFG_BASE + 0x310)
#define MTK6223_PDN_SET1		(MTK6223_CONFG_BASE + 0x314)
#define MTK6223_PDN_SET2		(MTK6223_CONFG_BASE + 0x318)
#define MTK6223_PDN_SET3		(MTK6223_CONFG_BASE + 0x31C)

#define MTK6223_PDN_CLR0		(MTK6223_CONFG_BASE + 0x320) // Power Down Clear 0 Register
#define MTK6223_PDN_DMA 		( 1 << 0)
#define MTK6223_PDN_GCU 		( 1 << 2)
#define MTK6223_PDN_WAVETABLE  	( 1 << 3)
#define MTK6223_PDN_FIXME 		( 1 << 5)
#define MTK6223_PDN_IRDMA 		( 1 << 6)
#define MTK6223_PDN_CLKSQ 		( 1 << 11)
#define MTK6223_PDN_MCU_DIV2 	( 1 << 12)
#define MTK6223_PDN_PLL 		( 1 << 13)
#define MTK6223_PDN_DSP_DIV2 	( 1 << 15)

#define MTK6223_PDN_CLR1			(MTK6223_CONFG_BASE + 0x324) // Power Down Clear 1 Register
#define MTK6223_PDN_GPT   	( 1 << 0)
#define MTK6223_PDN_KP		( 1 << 1)
#define MTK6223_PDN_GPIO	( 1 << 2)
#define MTK6223_PDN_UART1	( 1 << 3)
#define MTK6223_PDN_SIM		( 1 << 4)
#define MTK6223_PDN_PWM		( 1 << 5)
#define MTK6223_PDN_ALTER	( 1 << 6)
#define MTK6223_PDN_LCD		( 1 << 7)
#define MTK6223_PDN_UART2	( 1 << 8)
#define MTK6223_PDN_PWM2	( 1 << 10)
#define MTK6223_PDN_SWDBG	( 1 << 11)
#define MTK6223_PDN_UART3	( 1 << 14)

#define MTK6223_PDN_CLR2			(MTK6223_CONFG_BASE + 0x328) // Power Down Clear 2 Register
#define MTK6223_PDN_TDMA ( 1 << 0)   // TDMA clock ( ungate clock )
#define MTK6223_PDN_RTC  ( 1 << 1)   // RTC clock
#define MTK6223_PDN_BSI  ( 1 << 2)   // serial base band
#define MTK6223_PDN_BPI  ( 1 << 3)   // Parallel base band control
#define MTK6223_PDN_AFC  ( 1 << 4)
#define MTK6223_PDN_APC  ( 1 << 5)
#define MTK6223_PDN_FCS  ( 1 << 6)
#define MTK6223_PDN_AUXAD ( 1 << 7)
#define MTK6223_PDN_VAFE ( 1 << 8)   // voice audio front end
#define MTK6223_PDN_BFE  ( 1 << 9)   // base band
#define MTK6223_PDN_GCC  ( 1 << 10)
#define MTK6223_PDN_DIV  ( 1 << 11)
#define MTK6223_PDN_AAFE ( 1 << 12)   // audio front End
#define MTK6223_PDN_SCCB ( 1 << 13)
#define MTK6223_PDN_BBRX ( 1 << 14)
#define MTK6223_PDN_GMSK ( 1 << 15)

#define MTK6223_SLEEP_CON     (MTK6223_CONFG_BASE + 0x114)
#define MTK6223_SLEEP_CON_MCU        ( 1 << 0 )
#define MTK6223_SLEEP_CON_AHB        ( 1 << 1 )
#define MTK6223_SLEEP_CON_PDN_DSP1   ( 1 << 2 ) // DSP Clock off
#define MTK6223_SLEEP_CON_PDN_DSP2   ( 1 << 3 )

// *****************  Interrupt Controller  ***************

#define MTK6223_IRQ_SEL0            (MTK6223_CIRQ_BASE + 0x000)  // IRQ 12345
#define MTK6223_IRQ_SEL1            (MTK6223_CIRQ_BASE + 0x004)
#define MTK6223_IRQ_SEL2            (MTK6223_CIRQ_BASE + 0x008)
#define MTK6223_IRQ_SEL3            (MTK6223_CIRQ_BASE + 0x00C)
#define MTK6223_IRQ_SEL4            (MTK6223_CIRQ_BASE + 0x010)
#define MTK6223_IRQ_SEL5            (MTK6223_CIRQ_BASE + 0x014)
#define MTK6223_IRQ_FIQ_SEL         (MTK6223_CIRQ_BASE + 0x018)

// IRQ Number in IRQ_STA2
#define MTK6223_IRQ_MFIQ          0x00
#define MTK6223_IRQ_TDMA_CTIRQ1   0x01
#define MTK6223_IRQ_TDMA_CTIRQ2   0x02
#define MTK6223_IRQ_DSP1_to_CPU   (0x03)
#define MTK6223_IRQ_SIM           (0x04)
#define MTK6223_IRQ_DMA           0x05
#define MTK6223_IRQ_TDMA          0x06    // From Slow Clock Unit ?
#define MTK6223_IRQ_UART1         0x07
#define MTK6223_IRQ_KeyPad        0x08
#define MTK6223_IRQ_UART2         0x09
#define MTK6223_IRQ_GPTimer       0x0A
#define MTK6223_IRQ_EINT          0x0B
#define MTK6223_IRQ_RTC           0x0E
#define MTK6223_IRQ_LCD           0x10
#define MTK6223_IRQ_UART3         0x11
#define MTK6223_IRQ_MIRQ          0x12
#define MTK6223_IRQ_WDT           0x13
#define MTK6223_IRQ_SWDBG         0x14
#define MTK6223_IRQ_I2C           0x1b
#define MTK6223_IRQ_DSP2_to_CPU   0x1f

#define MTK6223_IRQ_MASK            (MTK6223_CIRQ_BASE + 0x01C)  // IRQ Mask Register 32 bit
#define MTK6223_IRQ_MASK_CLR        (MTK6223_CIRQ_BASE + 0x020)  // IRQ Mask Clear Register 32 bit
#define MTK6223_IRQ_MASK_SET        (MTK6223_CIRQ_BASE + 0x024)  // IRQ Mask SET Register 32 bit enable IRQ
#define MTK6223_IRQ_STA             (MTK6223_CIRQ_BASE + 0x028)  // IRQ Source Status Register 1 = IRQ active
#define MTK6223_IRQ_EOI             (MTK6223_CIRQ_BASE + 0x02C)  // IRQ End of Interrupt Register
#define MTK6223_IRQ_SENS            (MTK6223_CIRQ_BASE + 0x030)
#define MTK6223_IRQ_SOFT            (MTK6223_CIRQ_BASE + 0x034)   // For IRQ DEBUG
#define MTK6223_FIQ_CON				(MTK6223_CIRQ_BASE + 0x038)  // FIQ Control Register
#define MTK6223_FIQ_EOI             (MTK6223_CIRQ_BASE + 0x03C) // FIQ End of Interrupt Register
#define MTK6223_IRQ_STA2            (MTK6223_CIRQ_BASE + 0x040) // Binary Coded Value of IRQ_STATUS
#define MTK6223_IRQ_STA2_STSA_SHIFT  (0)
#define MTK6223_IRQ_STA2_NOIRQ       (1<<8)
#define MTK6223_IRQ_EOI2            (MTK6223_CIRQ_BASE + 0x044) // Binary Coded Value of IRQ_EOI IRQ
// external IRQ
#define MTK6223_EINT_STA            (MTK6223_CIRQ_BASE + 0x100) // EINT Status Register
#define MTK6223_EINT0               (1 << 0)
#define MTK6223_EINT1               (1 << 1)
#define MTK6223_EINT2               (1 << 2)
#define MTK6223_EINT3               (1 << 3)
#define MTK6223_EINT4               (1 << 4)
#define MTK6223_EINT5               (1 << 5)
#define MTK6223_EINT6               (1 << 6)
#define MTK6223_EINT7               (1 << 7)

#define MTK6223_EINT_MASK           (MTK6223_CIRQ_BASE + 0x104) // EINT Mask Register
#define MTK6223_EINT_MASK_CLR       (MTK6223_CIRQ_BASE + 0x108) // EINT Mask Disable Register
#define MTK6223_EINT_MASK_SET        (MTK6223_CIRQ_BASE + 0x10C) // EINT Mask Enable Register
#define MTK6223_EINT_INTACK         (MTK6223_CIRQ_BASE + 0x110) // EINT Interrupt Acknowledge Register
#define MTK6223_EINT_SENS           (MTK6223_CIRQ_BASE + 0x114) // EINT Sensitive Register
#define MTK6223_EINT0_CON           (MTK6223_CIRQ_BASE + 0x120) // EINT0 De-bounce Control Register
#define MTK6223_EINT1_CON           (MTK6223_CIRQ_BASE + 0x130) // EINT1 De-bounce Control Register
#define MTK6223_EINT2_CON           (MTK6223_CIRQ_BASE + 0x140) // EINT2 De-bounce Control Register
#define MTK6223_EINT3_CON           (MTK6223_CIRQ_BASE + 0x150) // EINT3 De-bounce Control Register
#define MTK6223_EINT4_CON           (MTK6223_CIRQ_BASE + 0x160) // EINT4 De-bounce Control Register
#define MTK6223_EINT5_CON           (MTK6223_CIRQ_BASE + 0x170) // EINT5 De-bounce Control Register
#define MTK6223_EINT6_CON           (MTK6223_CIRQ_BASE + 0x180) // EINT6 De-bounce Control Register
#define MTK6223_EINT7_CON           (MTK6223_CIRQ_BASE + 0x190) // EINT7 De-bounce Control Register
#define MTK6223_EINT_CON_CNT_SHIFT  (0)       // Debounce duration in terms of numbers of 32KHz clock cycles
#define MTK6223_EINT_CON_POL        (1 << 11) // Positive polarity
#define MTK6223_EINT_CON_EN         (1 << 15) // Debounce control circuit enable

//* ********************  Key Pad        ********************************************************

#define MTK6223_KP_STA				( MTK6223_KP_BASE + 0x000 ) // Keypad status
#define MTK6223_KP_LOW_KEY			( MTK6223_KP_BASE + 0x004 ) // Keypad scanning output, the lower 16 keys
#define MTK6223_KP_MID_KEY			( MTK6223_KP_BASE + 0x008 ) // Keypad scanning output, the medium 16 keys
#define MTK6223_KP_HIGH_KEY			( MTK6223_KP_BASE + 0x00C ) // Keypad scanning output, the higher 4 keys
#define MTK6223_KP_DEBOUNCE			( MTK6223_KP_BASE + 0x010 ) // De-bounce period setting

//******************* Reset Generation Unit ******************************************************

// Watchdog Timer Control Register 16 bit

#define MTK6223_WDT_MODE            (MTK6223_RGU_BASE + 0x000)
#define MTK6223_WDT_MODE_KEY		0x2200

#define MTK6223_DSP_RST                 (MTK6223_RGU_BASE + 0x014)  // DSP Software Reset Register

//************** GPIO ***************************************************************************

#define MTK6223_GPIO_DIR1          ( MTK6223_GPIO_BASE + 0x000)
#define MTK6223_GPIO0             ( 1 << 0)
#define MTK6223_GPIO1             ( 1 << 1)
#define MTK6223_GPIO2             ( 1 << 2)
#define MTK6223_GPIO3             ( 1 << 3)
#define MTK6223_GPIO4             ( 1 << 4)
#define MTK6223_GPIO5             ( 1 << 5)
#define MTK6223_GPIO6             ( 1 << 6)
#define MTK6223_GPIO7             ( 1 << 7)
#define MTK6223_GPIO8             ( 1 << 8)
#define MTK6223_GPIO9             ( 1 << 9)
#define MTK6223_GPIO10             ( 1 << 10)
#define MTK6223_GPIO11             ( 1 << 11)
#define MTK6223_GPIO12             ( 1 << 12)
#define MTK6223_GPIO13             ( 1 << 13)
#define MTK6223_GPIO14             ( 1 << 14)
#define MTK6223_GPIO15             ( 1 << 15)

#define MTK6223_GPIO_DIR2          ( MTK6223_GPIO_BASE + 0x010)
#define MTK6223_GPIO_DIR2_SET      ( MTK6223_GPIO_BASE + 0x010 + 0x04)
#define MTK6223_GPIO_DIR2_CLEAR    ( MTK6223_GPIO_BASE + 0x010 + 0x08)
#define MTK6223_GPIO16             ( 1 << 0)
#define MTK6223_GPIO17             ( 1 << 1)
#define MTK6223_GPIO18             ( 1 << 2)
#define MTK6223_GPIO19             ( 1 << 3)
#define MTK6223_GPIO20             ( 1 << 4)
#define MTK6223_GPIO21             ( 1 << 5)
#define MTK6223_GPIO22             ( 1 << 6)
#define MTK6223_GPIO23             ( 1 << 7)
#define MTK6223_GPIO24             ( 1 << 8)
#define MTK6223_GPIO25             ( 1 << 9)
#define MTK6223_GPIO26             ( 1 << 10)
#define MTK6223_GPIO27             ( 1 << 11)
#define MTK6223_GPIO28             ( 1 << 12)
#define MTK6223_GPIO29             ( 1 << 13)
#define MTK6223_GPIO30             ( 1 << 14)
#define MTK6223_GPIO31             ( 1 << 15)

#define MTK6223_GPIO_DIR3          ( MTK6223_GPIO_BASE + 0x020)
#define MTK6223_GPIO32             ( 1 << 0)
#define MTK6223_GPIO33             ( 1 << 1)
#define MTK6223_GPIO34             ( 1 << 2)
#define MTK6223_GPIO35             ( 1 << 3)
#define MTK6223_GPIO36             ( 1 << 4)
#define MTK6223_GPIO37             ( 1 << 5)
#define MTK6223_GPIO38             ( 1 << 6)
#define MTK6223_GPIO39             ( 1 << 7)
#define MTK6223_GPIO40             ( 1 << 8)
#define MTK6223_GPIO41             ( 1 << 9)
#define MTK6223_GPIO42             ( 1 << 10)
#define MTK6223_GPIO43             ( 1 << 11)
#define MTK6223_GPIO44             ( 1 << 12)
#define MTK6223_GPIO45             ( 1 << 13)
#define MTK6223_GPIO46             ( 1 << 14)
#define MTK6223_GPIO47             ( 1 << 15)

#define MTK6223_GPIO_DIR4          ( MTK6223_GPIO_BASE + 0x030)
#define MTK6223_GPIO48             ( 1 << 0)
#define MTK6223_GPIO49             ( 1 << 1)
#define MTK6223_GPIO50             ( 1 << 2)
#define MTK6223_GPIO51             ( 1 << 3)
#define MTK6223_GPIO52             ( 1 << 4)

#define MTK6223_GPIO_DOUT1		   ( MTK6223_GPIO_BASE + 0x0C0)  // GPIO 0-15

#define MTK6223_GPIO_DOUT2		   ( MTK6223_GPIO_BASE + 0x0D0)  // GPIO 16-31
#define MTK6223_GPIO_DOUT2_SET	   ( MTK6223_GPIO_BASE + 0x0D0 + 0x04)
#define MTK6223_GPIO_DOUT2_CLEAR   ( MTK6223_GPIO_BASE + 0x0D0 + 0x08)

#define MTK6223_GPIO_DOUT3		   ( MTK6223_GPIO_BASE + 0x0E0)
#define MTK6223_GPIO_DOUT4		   ( MTK6223_GPIO_BASE + 0x0F0)

#define MTK6223_GPIO_PULLEN4       ( MTK6223_GPIO_BASE + 0x070)

#define MTK6223_GPIO_MODE1         ( MTK6223_GPIO_BASE + 0x150)
#define MTK6223_GPIO_MODE2         ( MTK6223_GPIO_BASE + 0x160)
#define MTK6223_GPIO_MODE3         ( MTK6223_GPIO_BASE + 0x170)

#define MTK6223_GPIO_MODE4         ( MTK6223_GPIO_BASE + 0x180)
#define MTK6223_GPIO_MODE5         ( MTK6223_GPIO_BASE + 0x190)
#define MTK6223_GPIO_MODE6         ( MTK6223_GPIO_BASE + 0x1A0)
#define MTK6223_GPIO_MODE7         ( MTK6223_GPIO_BASE + 0x1B0)
// GPIO 50 LSB is inverted in read-back

// *************   Real Time Clock ******************************

#define MTK6223_RTC_BBPU			( MTK6223_RTC_BASE + 0x000)  // Baseband power up
#define MTK6223_KEY_BBPU  0x4300

#define MTK6223_RTC_AUTO (1 << 3)
#define MTK6223_RTC_BBPU_BIT (1 << 2)
#define MTK6223_RTC_WRITE_EN (1 << 1)
#define MTK6223_RTC_PWREN (1 << 0)

#define MTK6223_RTC_IRQ_STA         ( MTK6223_RTC_BASE + 0x004)     // RTC IRQ status
#define MTK6223_RTC_IRQ_EN          ( MTK6223_RTC_BASE + 0x008)     // RTC IRQ enable
#define MTK6223_ONESHOT     (1 << 2)
#define MTK6223_TC_EN       (1 << 1)
#define MTK6223_AL_EN		(1 << 0)

#define MTK6223_RTC_RTC_CII_EN		( MTK6223_RTC_BASE + 0x00C)     // Counter increment IRQ enable
#define MTK6223_1_8SECCII	( 1 << 9)
#define MTK6223_1_4SECCII 	( 1 << 8)
#define MTK6223_1_2SECCII 	( 1 << 7)
#define MTK6223_YEACII 		( 1 << 6)
#define MTK6223_MTHCII 		( 1 << 5)
#define MTK6223_DOWCII 		( 1 << 4)
#define MTK6223_DOMCII 		( 1 << 3)
#define MTK6223_HOUCII 		( 1 << 2)
#define MTK6223_MINCII 		( 1 << 1)
#define MTK6223_SECCII		( 1 << 0)

#define MTK6223_RTC_RTC_AL_MASK		( MTK6223_RTC_BASE + 0x010)    // RTC alarm mask
#define MTK6223_YEA_MSK  	( 1 << 6)
#define MTK6223_MTH_MSK		( 1 << 5)
#define MTK6223_DOW_MSK		( 1 << 4)
#define MTK6223_DOM_MSK		( 1 << 3)
#define MTK6223_HOU_MSK 	( 1 << 2)
#define MTK6223_MIN_MSK		( 1 << 1)
#define MTK6223_SEC_MSK 	( 1 << 0)

#define MTK6223_RTC_TC_SEC			( MTK6223_RTC_BASE + 0x014)
#define MTK6223_RTC_TC_MIN  		( MTK6223_RTC_BASE + 0x018)    // RTC minutes time counter register
#define MTK6223_RTC_TC_HOU			( MTK6223_RTC_BASE + 0x01C)
#define MTK6223_RTC_TC_DOM			( MTK6223_RTC_BASE + 0x020)
#define MTK6223_RTC_TC_DOW			( MTK6223_RTC_BASE + 0x024)
#define MTK6223_RTC_TC_MTH			( MTK6223_RTC_BASE + 0x028)
#define MTK6223_RTC_TC_YEA			( MTK6223_RTC_BASE + 0x02C)
#define MTK6223_RTC_AL_SEC			( MTK6223_RTC_BASE + 0x030)
#define MTK6223_RTC_AL_MIN			( MTK6223_RTC_BASE + 0x034)
#define MTK6223_RTC_AL_HOU			( MTK6223_RTC_BASE + 0x038)
#define MTK6223_RTC_AL_DOM			( MTK6223_RTC_BASE + 0x03C)
#define MTK6223_RTC_AL_DOW			( MTK6223_RTC_BASE + 0x040)
#define MTK6223_RTC_AL_MTH			( MTK6223_RTC_BASE + 0x044)
#define MTK6223_RTC_AL_YEA			( MTK6223_RTC_BASE + 0x048)

#define MTK6223_RTC_POWERKEY1       ( MTK6223_RTC_BASE + 0x050)
#define MTK6223_RTC_POWERKEY2       ( MTK6223_RTC_BASE + 0x054)

#define MTK6223_POWERKEY1_MAGIC		0xA357
#define MTK6223_POWERKEY2_MAGIC		0x67D2

//***  General Purpose Timer   *****

// Timer 1
#define MTK6223_GPTIMER1_CON    ( MTK6223_GPT_BASE + 0x000)   // GPT1 Control register
#define MTK6223_MODE  ( 1 << 14)
#define MTK6223_EN    ( 1 << 15)

#define MTK6223_GPTIMER1_DAT   ( MTK6223_GPT_BASE + 0x004)

// Timer 2
#define MTK6223_GPTIMER2_CON   ( MTK6223_GPT_BASE + 0x008)
#define MTK6223_GPTIMER2_DAT   ( MTK6223_GPT_BASE + 0x00C)

#define MTK6223_GPTIMER_STA    ( MTK6223_GPT_BASE + 0x010)
#define MTK6223_GPT1 ( 1 << 0 )
#define MTK6223_GPT2 ( 1 << 1 )

#define MTK6223_GPTIMER1_PRESCALER ( MTK6223_GPT_BASE + 0x014)
#define MTK6223_PRESCALER_SHIFT            (0)

#define MTK6223_GPTIMER2_PRESCALER ( MTK6223_GPT_BASE + 0x018)

// Timer 3
#define MTK6223_GPTIMER3_CON       ( MTK6223_GPT_BASE + 0x01C)
#define MTK6223_GPTIMER3_DAT       ( MTK6223_GPT_BASE + 0x020)
#define MTK6223_GPTIMER3_PRESCALER ( MTK6223_GPT_BASE + 0x024)

// *********** Baseband Serial Interface ***********************************

#define MTK6223_BSI_CON				    ( MTK6223_BSI_BASE + 0x000 )       // BSI control register
#define MTK6223_BSI_CON_CLK_POL_INV		(1 << 0)
#define MTK6223_BSI_CON_CLK_SPD_52_2	((00) << 1)	/* 52/2 MHz */
#define MTK6223_BSI_CON_CLK_SPD_52_4	((01) << 1)	/* 52/4 MHz */
#define MTK6223_BSI_CON_CLK_SPD_52_6	(2 << 1)	/* 52/6 MHz */
#define MTK6223_BSI_CON_CLK_SPD_52_8	(3 << 1)	/* 52/8 MHz */
#define MTK6223_BSI_CON_IMOD			(1 << 3)
#define MTK6223_BSI_CON_EN0_LEN_SHORT	(1 << 4)
#define MTK6223_BSI_CON_EN0_POL_INV		(1 << 5)
#define MTK6223_BSI_CON_EN1_LEN_SHORT	(1 << 6)
#define MTK6223_BSI_CON_EN1_POL_INV		(1 << 7)
#define MTK6223_BSI_CON_SETENV			(1 << 8)

// BSI 0 - 39
#define MTK6223_BSI_Dx_CON(x)	(MTK6223_BSI_BASE + 0x004 + ((x) * 8))
#define MTK6223_BSI_DO_CON_EVT_ID_SHIFT   ( 0 )   // EVT_ID
#define MTK6223_BSI_DO_CON_LEN_SHIFT      ( 8 )   // LEN
#define MTK6223_BSI_DO_CON_ISB_SHIFT      ( 15 )  // ISB
/* how the length is encoded in BSI_Dx_CON */
#define MTK6223_BSI_Dx_LEN(x)		((x & 0x7f) << MTK6223_BSI_DO_CON_LEN_SHIFT)
#define MTK6223_BSI_Dx_DAT(x)	(MTK6223_BSI_BASE + 0x008 + ((x) * 8))

#define MTK6223_BSI_PAIR_NUM   (MTK6223_BSI_BASE + 0x1A4 )            // BSI data pair number

// ************  Baseband Parallel Interface ************************************************************

#define MTK6223_BPI_CON				( MTK6223_BPI_BASE + 0x000 )  // BPI control register
#define MTK6223_BPI_CON_PETEV (1 << 0)
#define MTK6223_BPI_CON_PINM0 (1 << 1)
#define MTK6223_BPI_CON_PINM1 (1 << 2)
#define MTK6223_BPI_CON_PINM2 (1 << 3)

// BPI_BUF 0 - 41
#define  MTK6223_BPI_BUF(x)	(MTK6223_BPI_BASE + 0x0004 +  ((x) * 4))

#define MTK6223_BPI_BUFI	   ( MTK6223_BPI_BASE + 0x0AC ) //  BPI pin data for immediate mode
#define MTK6223_BPI_BUFI_PO0   (1 << 0)
#define MTK6223_BPI_BUFI_PO1   (1 << 1)
#define MTK6223_BPI_BUFI_PO2   (1 << 2)
#define MTK6223_BPI_BUFI_PO3   (1 << 3)
#define MTK6223_BPI_BUFI_PO4   (1 << 4)
#define MTK6223_BPI_BUFI_PO5   (1 << 5)
#define MTK6223_BPI_BUFI_PO6   (1 << 6)
#define MTK6223_BPI_BUFI_PO7   (1 << 7)
#define MTK6223_BPI_BUFI_PO8   (1 << 8)
#define MTK6223_BPI_BUFI_PO9   (1 << 9)

// ****************  TDMA Timer **********************************************************************

// counter 0-4999 (0x1387) =  1 TDMA frame = 4.615 ms
// 156,25 Bit * 8 Burst * 4 = 5000
// 1 Bit = 3,692 µs
// 1 QBit = 0.923 us

#define MTK6223_TDMA_TQCNT 			( MTK6223_TDMA_BASE + 0x000 ) 		// Read quarter bit counter
#define MTK6223_TDMA_WRAP			( MTK6223_TDMA_BASE + 0x004 ) 		// WRAP Latched Qbit counter reset position 0x1387
#define MTK6223_TDMA_WRAPIMD		( MTK6223_TDMA_BASE + 0x008 ) 		// Direct Qbit counter reset position
#define MTK6223_TDMA_EVTVAL 		( MTK6223_TDMA_BASE + 0x00C ) 		// Event latch position (load BSI BPI
#define MTK6223_TDMA_DTIRQ_DSP 		( MTK6223_TDMA_BASE + 0x010 ) 		// software control
#define MTK6223_TDMA_CTIRQ1_MCU 	( MTK6223_TDMA_BASE + 0x014 ) 		// software control 1
#define MTK6223_TDMA_CTIRQ2_MCU 	( MTK6223_TDMA_BASE + 0x018 ) 		// software control 2
#define MTK6223_TDMA_AFC0           ( MTK6223_TDMA_BASE + 0x020)  // The 1st AFC control
#define MTK6223_TDMA_AFC1           ( MTK6223_TDMA_BASE + 0x024)  // The 2nd AFC control
#define MTK6223_TDMA_AFC2           ( MTK6223_TDMA_BASE + 0x028)  // The 3rd AFC control
#define MTK6223_TDMA_AFC3           ( MTK6223_TDMA_BASE + 0x02C)  // The 4th AFC control

// Downlink

// Data serialization of the 0 RX block switch the AD on
#define MTK6223_TDMA_BDLON0         ( MTK6223_TDMA_BASE    + 0x030)
#define MTK6223_TDMA_BDLOFF0        ( MTK6223_TDMA_BASE    + 0x034)
// Data serialization of the 1 RX block
#define MTK6223_TDMA_BDLON1         ( MTK6223_TDMA_BASE    + 0x038)
#define MTK6223_TDMA_BDLOFF1        ( MTK6223_TDMA_BASE    + 0x03C)
// Data serialization of the 2 RX block
#define MTK6223_TDMA_BDLON2         ( MTK6223_TDMA_BASE    + 0x040)
#define MTK6223_TDMA_BDLOFF2        ( MTK6223_TDMA_BASE    + 0x044)
// Data serialization of the 3 RX block
#define MTK6223_TDMA_BDLON3         ( MTK6223_TDMA_BASE    + 0x048)
#define MTK6223_TDMA_BDLOFF3        ( MTK6223_TDMA_BASE    + 0x04C)
// Data serialization of the the 4 RX block
#define MTK6223_TDMA_BDLON4         ( MTK6223_TDMA_BASE    + 0x050)
#define MTK6223_TDMA_BDLOFF4        ( MTK6223_TDMA_BASE    + 0x054)
// Data serialization of the 5th RX block
#define MTK6223_TDMA_BDLON5         ( MTK6223_TDMA_BASE    + 0x058)
#define MTK6223_TDMA_BDLOFF5        ( MTK6223_TDMA_BASE    + 0x05C)

// Uplink
#define MTK6223_TDMA_BULON0         ( MTK6223_TDMA_BASE    + 0x060)
#define MTK6223_TDMA_BULOFF0        ( MTK6223_TDMA_BASE    + 0x064)
//  Data serialization
#define MTK6223_TDMA_BULON1         ( MTK6223_TDMA_BASE   + 0x068)
#define MTK6223_TDMA_BULOFF1        ( MTK6223_TDMA_BASE   + 0x06C)
// Data serialization of the 2nd TX slot
#define MTK6223_TDMA_BULON2         ( MTK6223_TDMA_BASE   + 0x070)
#define MTK6223_TDMA_BULOFF2        ( MTK6223_TDMA_BASE   + 0x074)
// Data serialization of the 3rd TX slot
#define MTK6223_TDMA_BULON3         ( MTK6223_TDMA_BASE   + 0x078)
#define MTK6223_TDMA_BULOFF3        ( MTK6223_TDMA_BASE   + 0x07C)
// Data serialization of the 4th TX slot

// APC0 - APC6
#define MTK6223_TDMA_APC(n)	(MTK6223_TDMA_BASE + 0x090 + ((n) * 4))

// Serial Parallel Interface BSI0 - BSI 19
#define MTK6223_TDMA_BSI(n)	(MTK6223_TDMA_BASE + 0x0B0 + ((n) * 4))

// Baseband Parallel Interface BPI0 - BPI41
#define MTK6223_TDMA_BPI(n)	(MTK6223_TDMA_BASE + 0x100 + ((n) * 4))

#define MTK6223_TDMA_EVTENA0		( MTK6223_TDMA_BASE + 0x150 )
#define MTK6223_TDMA_EVTENA0_DTIRQ   (1 << 0 )   // Enable TDMA_DTIRQ
#define MTK6223_TDMA_EVTENA0_CTIRQ1  (1 << 1 )   // Enable TDMA_CTIRQn
#define MTK6223_TDMA_EVTENA0_CTIRQ2  (1 << 2 )   // Enable TDMA_CTIRQn
#define MTK6223_TDMA_EVTENA0_AFC0    (1 << 12)   // Enable TDMA_AFCn
#define MTK6223_TDMA_EVTENA0_BDL0    (1 << 6)    // Enable TDMA_BDLONn and TDMA_BDLOFFn ( Downlink )

#define MTK6223_TDMA_EVTENA1	    ( MTK6223_TDMA_BASE + 0x154 )
// APCn Enable TDMA_APCn
#define MTK6223_TDMA_EVTENA1_APC0   (1 << 0)
#define MTK6223_TDMA_EVTENA1_APC1   (1 << 1)
// BULn Enable TDMA_BULONn and TDMA_BULOFFn
#define MTK6223_TDMA_EVTENA1_BUL0   (1 << 8)
#define MTK6223_TDMA_EVTENA1_BUL1   (1 << 9)

#define MTK6223_TDMA_EVTENA2	    ( MTK6223_TDMA_BASE + 0x158 )
#define MTK6223_TDMA_EVTENA3        ( MTK6223_TDMA_BASE + 0x15C )
// 0 Disable TDMA_BSIn
// 1 Enable TDMA_BSIn
#define MTK6223_TDMA_EVTENA4        ( MTK6223_TDMA_BASE + 0x160 )
#define MTK6223_TDMA_EVTENA4_BPI0   (1 << 0)
#define MTK6223_TDMA_EVTENA4_BPI1   (1 << 1)
#define MTK6223_TDMA_EVTENA4_BPI2   (1 << 2 )

#define MTK6223_TDMA_EVTENA5        ( MTK6223_TDMA_BASE + 0x164 )
#define MTK6223_TDMA_EVTENA6        ( MTK6223_TDMA_BASE + 0x168 )
// 0 Disable TDMA_BPIn
// 1 Enable TDMA_BPIn

#define MTK6223_TDMA_EVTENA7        ( MTK6223_TDMA_BASE + 0x16C )
// 0 Disable Auxiliary ADC event
// 1 Enable Auxiliary ADC event

#define MTK6223_TDMA_WRAPOFS        ( MTK6223_TDMA_BASE + 0x170 )           // TQ Counter Offset Control Register
#define MTK6223_TDMA_REGBIAS        ( MTK6223_TDMA_BASE + 0x174 )           // Biasing Control Register
#define MTK6223_TDMA_DTXCON         ( MTK6223_TDMA_BASE + 0x180 )           // DTX Control Register
#define MTK6223_TDMA_DTXCON_DTX0    ( 1 << 0)   //  1 == disable
#define MTK6223_TDMA_DTXCON_DTX1    ( 1 << 1)
#define MTK6223_TDMA_DTXCON_DTX2    ( 1 << 2)
#define MTK6223_TDMA_DTXCON_DTX3    ( 1 << 3)

#define MTK6223_TDMA_RXCON          ( MTK6223_TDMA_BASE + 0x184 )           // Receive Interrupt Control Register
#define MTK6223_TDMA_RXCON_RXINTCNT_SHIFT  (0)
#define MTK6223_TDMA_RXCON_MOD0_REP        (1 << 10)

#define MTK6223_TDMA_BDLCON         ( MTK6223_TDMA_BASE + 0x188)            // Downlink Control Register
#define MTK6223_TDMA_BDLCON_ADCOFF_SHIFT (0)
#define MTK6223_TDMA_BDLCON_ADCON_SHIFT  (8)

#define MTK6223_TDMA_BULCON1        ( MTK6223_TDMA_BASE + 0x18C)            // Uplink Control Register 1
#define MTK6223_TDMA_BULCON1_DACOFF_SHIFT   ( 0 )
#define MTK6223_TDMA_BULCON1_DACON_SHIFT    ( 8 )

#define MTK6223_TDMA_BULCON2        ( MTK6223_TDMA_BASE + 0x190)            // Uplink Control Register 2
#define MTK6223_TDMA_BULCON2_APC_HYS_SHIFT (1 << 0)

#define MTK6223_TDMA_FB_            ( MTK6223_TDMA_BASE + 0x194)            // FLAG FB indicator
#define MTK6223_TDMA_FB_CLRI        ( MTK6223_TDMA_BASE + 0x198)            // Direct clear of FB indicator

#define MTK6223_TDMA_AUXEV0			( MTK6223_TDMA_BASE + 0x400) 			// Auxiliary ADC event 0
#define MTK6223_TDMA_AUXEV1			( MTK6223_TDMA_BASE + 0x404)            // Auxiliary ADC event 1

// Slow Clocking Unit
#define MTK6223_TDMA_SM_PAUSE_M         ( MTK6223_TDMA_BASE + 0x200 )      // 3 MSB of pause duration
#define MTK6223_TDMA_SM_PAUSE_L         ( MTK6223_TDMA_BASE + 0x204 )      // 16 LSB of pause duration
#define MTK6223_TDMA_SM_CLK_SETTLE      ( MTK6223_TDMA_BASE + 0x208 )      // Off-chip VCXO settling duration
#define MTK6223_TDMA_SM_FINAL_PAUSE_M   ( MTK6223_TDMA_BASE + 0x20C )      // 3 MSB of final pause count
#define MTK6223_TDMA_SM_FINAL_PAUSE_L   ( MTK6223_TDMA_BASE + 0x210 )      // 16 LSB of final pause count
#define MTK6223_TDMA_SM_QBIT_START TQ_  ( MTK6223_TDMA_BASE + 0x214 )      // COUNT value at the start of the pause

#define MTK6223_TDMA_SM_CON             ( MTK6223_TDMA_BASE + 0x218 )      // SM control register
#define MTK6223_TDMA_SM_CON_FM_START    ( 1 << 0)   // Initiate the frequency measurement procedure
#define MTK6223_TDMA_SM_CON_PAUSE_START ( 1 << 1)   // Initiate the pause mode procedure at the next timer wrap position

#define MTK6223_TDMA_SM_STA              ( MTK6223_TDMA_BASE + 0x21C )      //SM status register
#define MTK6223_TDMA_SM_STA_FM_RQST      ( 1 << 0)  // Frequency measurement procedure is requested
#define MTK6223_TDMA_SM_STA_FM_CPL       ( 1 << 1)  // Frequency measurement procedure is completed
#define MTK6223_TDMA_SM_STA_PAUSE_RQST   ( 1 << 4)  // Pause mode procedure is requested
#define MTK6223_TDMA_SM_STA_PAUSE_INT    ( 1 << 5)  // Asynchronous wake up from pause mode
#define MTK6223_TDMA_SM_STA_PAUSE_CPL    ( 1 << 6)  // Pause period is completed
#define MTK6223_TDMA_SM_STA_SETTLE_CPL   ( 1 << 7)  // Settling period is completed
#define MTK6223_TDMA_SM_STA_PAUSE_ABORT  ( 1 << 8) // Pause mode is aborted because of the reception of interrupt prior to entering pause mode

#define MTK6223_TDMA_SM_FM_DURATION       ( MTK6223_TDMA_BASE + 0x220 )       // 32KHz measurement duration
#define MTK6223_TDMA_SM_FM_RESULT_M       ( MTK6223_TDMA_BASE + 0x224 )     // 10 MSB of frequency measurement result
#define MTK6223_TDMA_SM_FM_RESULT_L       ( MTK6223_TDMA_BASE + 0x228 )     // 16 LSB of frequency measurement result

#define MTK6223_TDMA_SM_CNF              ( MTK6223_TDMA_BASE + 0x22C )       //SM configuration register
#define MTK6223_TDMA_SM_CNF_FM   ( 1 << 0)         // Enable interrupt generation upon completion of frequency measurement procedure
#define MTK6223_TDMA_SM_CNF_SM   ( 1 << 1)         // Enable interrupt generation upon completion of pause mode procedure
#define MTK6223_TDMA_SM_CNF_KP   ( 1 << 2)         // Enable asynchronous wake-up from pause mode by key press
#define MTK6223_TDMA_SM_CNF_EINT ( 1 << 3)         // Enable asynchronous wake-up from pause mode by external interrupt
#define MTK6223_TDMA_SM_CNF_RTC  ( 1 << 4)         // Enable asynchronous wake-up from pause mode by real time clock interrupt

#define MTK6223_TDMA_RTCCOUNT            ( MTK6223_TDMA_BASE + 0x230 )        // RTC count
#define MTK6223_TDMA_DSPROMPD            ( MTK6223_TDMA_BASE + 0x300 )        // DSP ROM power down

// ************** AUX ADC  *********************************************************************

#define MTK6223_AUXADC_CON0		   	( MTK6223_AUXADC_BASE + 0x000 )  // Auxiliary ADC control register 0
#define MTK6223_AUXADC_CON1			( MTK6223_AUXADC_BASE + 0x004 )
#define MTK6223_AUXADC_CON2         ( MTK6223_AUXADC_BASE + 0x008 )
#define MTK6223_AUXADC_CON3         ( MTK6223_AUXADC_BASE + 0x00C )

#define MTK6223_AUTOSET   (1 << 15)
#define MTK6223_PUWAIT_EN (1 << 11)

#define MTK6223_AUXADC_DAT0         ( MTK6223_AUXADC_BASE + 0x010 ) // Auxiliary ADC channel 0 register
#define MTK6223_AUXADC_DAT1         ( MTK6223_AUXADC_BASE + 0x014 )
#define MTK6223_AUXADC_DAT2	        ( MTK6223_AUXADC_BASE + 0x018 )
#define MTK6223_AUXADC_DAT3         ( MTK6223_AUXADC_BASE + 0x01C )
#define MTK6223_AUXADC_DAT4         ( MTK6223_AUXADC_BASE + 0x020 )
#define MTK6223_AUXADC_DAT5	        ( MTK6223_AUXADC_BASE + 0x024 )
#define MTK6223_AUXADC_DAT6	        ( MTK6223_AUXADC_BASE + 0x028 )
#define MTK6223_AUXADC_DAT7	        ( MTK6223_AUXADC_BASE + 0x02C )

//*******   BFE  Baseband ***************************************************************

#define MTK6223_BFE_CON             ( MTK6223_BFE_BASE + 0x000 )           // Base-band Common Control Register

#define MTK6223_BFE_STA             ( MTK6223_BFE_BASE  +0x004 )           // Base-band Common Status Register
#define MTK6223_BFE_STA_BDLEN       (1 << 0)
#define MTK6223_BFE_STA_BDLFS       (1 << 1)

#define MTK6223_RX_CFG              ( MTK6223_BFE_BASE  +0x010 )           // RX Configuration Register
#define MTK6223_SWAP                (1 << 0)    // Swap I and Q
#define MTK6223_BYPFLTR             (1 << 1)    // Bybas fir
#define MTK6223_2XFIRSEL            (1 << 2)
#define MTK6223_RX_CFG_FIRTPNO_SHIFT (4)     // Filter Tap number

#define MTK6223_RX_CON              ( MTK6223_BFE_BASE + 0x014 )           // RX Control Register
#define MTK6223_RX_CON_BLPEN_SHIFT  (0)         // The register field is for loopback configuration selection in Baseband Front End.
#define MTK6223_RX_CON_PH_ROEN_W    (1 << 2)    // Enable for I/Q pair Phase De-rotation in Wide FIR Data Path.
#define MTK6223_RX_CON_PH_ROEN_N    (1 << 3)    // Enable for I/Q pair Phase De-rotation in Narrow FIR Data Path.
#define MTK6223_RX_CON_IGAINSEL_SHIFT (4)       // RX I data Gain Compensation Select. 0.3dB/step,
#define MTK6223_RX_CON_PWR_SHFT_NO    (8)       // Power measuring Result Right Shift Number

#define MTK6223_RX_PM_CON           ( MTK6223_BFE_BASE + 0x018 )           // RX  Interference Detection Power Measurement Control Register
#define MTK6223_RX_FIR_CSID_CON     ( MTK6223_BFE_BASE + 0x01C )           // RX  FIR Coefficient Set ID Control Register
// RAM0_CS0 - RAM0_C15
#define MTK6223_RX_RAM0_CS(x)       ( MTK6223_BFE_BASE + 0x070 + ((x) *4) )  // RX  RAM0Coefficient Set 0Register
// RAM1_CS0 - RAM0_C15
#define MTK6223_RX_RAM1_CS(x)      ( MTK6223_BFE_BASE + 0x020 + ((x) *4))  // RX  RAM1 Coefficient Set 0 Register
#define MTK6223_RX_HPWR_STS         ( MTK6223_BFE_BASE + 0x0B0 )          // RX  Interference Detection HPF Power Register
#define MTK6223_RX_BPWR_STS         ( MTK6223_BFE_BASE + 0x0B4 )          // RX  Interference Detection BPF Power Register
// DSP i/O

#define MTK6223_DSPIO_ITD_H(x)    ( MTK6223_BFE_BASE + 0x743 +(((x)*4) -1)) // RX HPF ITD Power Register of Window0
#define MTK6223_DSPIO_ITD_B(x)    ( MTK6223_BFE_BASE + 0x744 +((x)*4))      // RX BPF ITD Power Register of Window0
#define MTK6223_DSPIO_RXID_RDY    ( MTK6223_BFE_BASE + 0x759 )              // RX ITD Power Measurement Ready Flag
#define MTK6223_DSPIO_RXID_RDY_0  (1<<0)
#define MTK6223_DSPIO_RXID_RDY_1  (1<<1)

// TX Path
#define MTK6223_TX_CFG                   ( MTK6223_BFE_BASE  + 0x060 ) // TX Configuration Register
#define MTK6223_TX_CFG_APNDEN            ( 1 << 0 )
#define MTK6223_TX_CFG_MDBYP             ( 1 << 4 )
#define MTK6223_TX_CFG_SGEN              ( 1 << 5 )     // SineTone generator enable 540 kHz
#define MTK6223_TX_CFG_ALL_10GEN_NORMAL  ( 0 << 6 )
#define MTK6223_TX_CFG_ALL_10GEN_DEBUG_0 ( 1 << 6 )     // GMSK modulator will generate 67.7 kHz sine tone
#define MTK6223_TX_CFG_ALL_10GEN_DEBUG_1 ( 2 << 6 )     // GMSK modulator will generate 67.7 kHz sine tone

// TX Control Register
#define MTK6223_TX_CON                 ( MTK6223_BFE_BASE  + 0x064 )
#define MTK6223_TX_CON_IQSWP           ( 1 << 0 )
#define MTK6223_TX_CON_PHSEL_SHIFT     ( 8 )

// TX I/Q Channel Offset Compensation Register
#define MTK6223_TX_OFF                  ( MTK6223_BFE_BASE  + 0x068 )
#define MTK6223_TX_OFF_I_SHIFT          (0) // Value of offset cancellation for I-channel DAC in TX mixed-signal module
#define MTK6223_TX_OFF_Q_SHIFT         (8) // Value of offset cancellation for Q-channel DAC in TX mixed-signal module

// ***      Analog Chip Interface Controller 16 bit ********************************************

// BBRX

#define MTK6223_BBRX_AC_CON   ( MTK6223_MIXED_BASE + 0x300 )    // BBRX ADC Analog-Circuit Control Register
#define MTK6223_BBRX_AC_CON_CALBIAS_SHIFT    (0)
#define MTK6223_BBRX_AC_CON_GAIN_SHIFT       (5)                // gain of DAC in BBTX mixed-signal module
#define MTK6223_BBRX_AC_CON_RSV              (7)                // ???
#define MTK6223_BBRX_AC_CON_ISEL_SHIFT       (8)                //
#define MTK6223_BBRX_AC_CON_QSEL_SHIFT       (10)               // 00 Normal mode,01 Loopback TX analog Q, 10 Loopback TX analog I, 11 Select the grounded input

// BBTX
#define MTK6223_BBTX_AC_CON0     ( MTK6223_MIXED_BASE + 0x400 ) // BBTX DAC Analog-Circuit Control Register 0
#define MTK6223_TRIMQ_SHIFT  (0)
#define MTK6223_TRIMI_SHIFT  (4)
#define MTK6223_CALRCSEL_SHIFT (8)
#define MTK6223_GAIN_SHIFT      (11)
#define MTK6223_START_CALRC_SHIFT   (14)    //  1= start calibaration   0 = stop
#define MTK6223_CALRC_DONE          (1<<15)    // cal done

#define MTK6223_BBTX_AC_CON1     ( MTK6223_MIXED_BASE + 0x404 ) // BBTX DAC Analog-Circuit Control Register 1
#define MTK6223_CMV_SHIFT          (0)
#define MTK6223_CALBIAS_SHIFT      (3)
#define MTK6223_CALRCCNT_SHIFT     (7)
#define MTK6223_FLOAFT             (1<<12)
#define MTK6223_CALRCOUT_SHIFT     (13)

#define MTK6223_BBTX_AC_CON2     ( MTK6223_MIXED_BASE + 0x408 ) // BBTX DAC Analog-Circuit Control Register 2

// **********************************   AFC DAC ******************************
#define MTK6223_AFC_AC_CON     ( MTK6223_MIXED_BASE + 0x500 ) // AFC DAC Analog-Circuit Control Register
#define MTK6223_APC_AC_CON     ( MTK6223_MIXED_BASE + 0x600 ) // APC DAC Analog-Circuit Control Register
#define MTK6223_AUX_AC_CON     ( MTK6223_MIXED_BASE + 0x700 ) // Auxiliary ADC Analog-Circuit Control Register
#define MTK6223_AUX_AC_CON_GAINEN (1<< 5)
#define MTK6223_AUX_AC_CON_SHIFT  (1<< 0)    // 5 bit bias current 2 complement format

// LDO
// Vcore, Vio, Vm LDOs  power on key
// Vtcxo Va    when baseband on

#define MTK6223_PMIC_CON0   ( MTK6223_MIXED_BASE + 0x800)    // Control LDO of VRF and test setting
#define MTK6223_PMIC_CON1   ( MTK6223_MIXED_BASE + 0x804)    // Control LDO of VCORE , VRTC, and status of VIO and VM
#define MTK6223_PMIC_CON2   ( MTK6223_MIXED_BASE + 0x808)    // Control LDO of VIO and VM
#define MTK6223_PMIC_CON3   ( MTK6223_MIXED_BASE + 0x80C)    // Control and Status of LDO of VSIM, Calibration of
#define MTK6223_PMIC_CON4   ( MTK6223_MIXED_BASE + 0x810)    // Control and Status of LDO of VCTXO and Va
#define MTK6223_PMIC_CON5   ( MTK6223_MIXED_BASE + 0x814)    // Driver Control and Charger Status
#define MTK6223_VIBR_EN (1 << 0)    // Vibrator Driver
#define MTK6223_KPLED   (1 << 1)    // Driver
#define MTK6223_RLED_EN (1 << 2)    // blue LED
#define MTK6223_GLED_EN (1 << 3)    // red LED
#define MTK6223_BLED_EN (1 << 4)    // green LED
#define MTK6223_OVP	    (1 << 10)   // Charger OV occurred
#define MTK6223_CHR_DET (1 << 11)   // Charger detected
#define MTK6223_BAT_ON  (1 << 12)   // Battery is connected
#define MTK6223_AC_DET  (1 << 13)   // AC power detected
#define MTK6223_OV      (1 << 14)   // CV mode Indication
#define MTK6223_INT_NODE_MUX_SHIFT (5)
#define MTK6223_CHRG_DIS ( 1 << 15 )

#define MTK6223_PMIC_PMIC_CON6 (MTK6223_MIXED_BASE + 0x818)

#define MTK6223_CHR_EN        (1 << 0 )
#define MTK6223_CHOFST_SHIFT  (1)
#define MTK6223_CLASS_D_SHIFT (4)
#define MTK6223_CHRON_FORCE   (1 << 7)
#define MTK6223_CHR_AUX_SHIFT (8)

/******************************* APC **********************************/

// APC 1st ramp profile 0 - 3    32 bit
#define MTK6223_APC_PF0(x)       ( MTK6223_APC_BASE + 0x000 + ((x) * 4) )  // APC 1st ramp profile
#define MTK6223_APC_PF1(x)       ( MTK6223_APC_BASE + 0x020 + ((x) * 4) )  // APC 2nd ramp profile
#define MTK6223_APC_PF_ENT0_SHIFT  (0)
#define MTK6223_APC_PF_ENT1_SHIFT  (8)
#define MTK6223_APC_PF_ENT2_SHIFT  (16)
#define MTK6223_APC_PF_ENT3_SHIFT  (24)

#define MTK6223_APC_SCAL0L       ( MTK6223_APC_BASE + 0x010 )      // APC 1st ramp profile left scaling factor
#define MTK6223_APC_SCAL0R       ( MTK6223_APC_BASE + 0x014 )      // APC 1st ramp profile right scaling factor
#define MTK6223_APC_OFFSET0      ( MTK6223_APC_BASE + 0x018 )      // APC 1st ramp profile offset value
#define MTK6223_APC_SCAL1L       ( MTK6223_APC_BASE + 0x030 )      // APC 2nd ramp profile left scaling factor
#define MTK6223_APC_SCAL1R       ( MTK6223_APC_BASE + 0x034 )      // APC 2nd ramp profile right scaling factor
#define MTK6223_APC_OFFSET1      ( MTK6223_APC_BASE + 0x038 )      // APC 2nd ramp profile offset value
#define MTK6223_APC_CON          ( MTK6223_APC_BASE + 0x0E0 )      //  APC control register
#define MTK6223_APC_CON_FPU      (1 << 0 )
#define MTK6223_APC_CON_GSM      (1 << 1 )

/********************* Audio  Front End **********************************************/

#define  MTK6223_AFE_VMCU_CON  (MTK6223_AFE_BASE+0x0000)     /* AFE Voice MCU Control Register */
#define  MTK6223_AFE_VMCU_CON_VAFEON  ( 1 << 0)

#define  MTK6223_AFE_VMCU_CON1 (MTK6223_AFE_BASE+0x000C)        /* AFE Voice Analog Circuit Control Register 1   */
#define  MTK6223_AFE_VMCU_CON2 (MTK6223_AFE_BASE +0x0010)        /* AFE Voice Analog Circuit Control Register 2   */
#define  MTK6223_AFE_VAC_DCON1 (MTK6223_AFE_BASE +0x000C)        /* AFE Voice Analog Circuit Control Register 1   */
#define  MTK6223_AFE_VDB_CON   (MTK6223_AFE_BASE +0x0014)        /* AFE Voice DAI Blue Tooth Control Register     */
#define  MTK6223_AFE_VLB_CON   (MTK6223_AFE_BASE +0x0018)        /* AFE Voice Loop-back Mode Control Register     */

#define  MTK6223_AFE_AMCU_CON0 (MTK6223_AFE_BASE +0x0020)        /* AFE Audio MCU Control Register 0gister        */
#define  MTK6223_AFE_AMCU_CON0_AAFEON    (1<<0)

#define  MTK6223_AFE_AMCU_CON1 (MTK6223_AFE_BASE +0x0024)        /* AFE Audio Control Register 1                  */
#define  MTK6223_AFE_EDI_CON   (MTK6223_AFE_BASE +0x0028)        /* AFE Audio EDI(I2S , EIAJ) Control Register    */
#define  MTK6223_AFE_AMCU_CON2 (MTK6223_AFE_BASE +0x002C)        /* AFE Audio Control Register 2                  */

#define  MTK6223_AFE_DAC_TEST  (MTK6223_AFE_BASE +0x0030)        /* AUDIO/VOICE sinewave generator and others     */
#define  MTK6223_AFE_DAC_TEST_FREQ_DIV_SHIFT    ( 0)
#define  MTK6223_AFE_DAC_TEST_AMP_DIV_SHIFT     ( 8)
#define  MTK6223_AFE_DAC_TEST_MUTE_SHIFT        (13)
#define  MTK6223_AFE_DAC_TEST_AON         (1 << 14)
#define  MTK6223_AFE_DAC_TEST_VON         (1 <<15)

#define  MTK6223_AFE_EQCOEF    (MTK6223_AFE_BASE +0x0040)        /* AFE Audio EQ Coefficients                     */
#define  MTK6223_AFE_VAGC_CON0 (MTK6223_AFE_BASE +0x0100)        /* AFE Audio AGC Control Register 0              */
#define  MTK6223_AFE_VAGC_CON1 (MTK6223_AFE_BASE +0x0104)        /* AFE Audio AGC Control Register 1              */
#define  MTK6223_AFE_VAGC_CON2 (MTK6223_AFE_BASE +0x0108)        /* AFE Audio AGC Control Register 2              */
#define  MTK6223_AFE_VAGC_CON3 (MTK6223_AFE_BASE +0x010c)        /* AFE Audio AGC Control Register 3              */
#define  MTK6223_AFE_VAGC_CON4 (MTK6223_AFE_BASE +0x0110)        /* AFE Audio AGC Control Register 4              */
#define  MTK6223_AFE_VAGC_CON5 (MTK6223_AFE_BASE +0x0114)        /* AFE Audio AGC Control Register 5              */
#define  MTK6223_AFE_VAGC_CON6 (MTK6223_AFE_BASE +0x0118)        /* AFE Audio AGC Control Register 6              */

#define  MTK6223_ACIF_AC_HW_VER (MTK6223_MIXED_BASE +0x0004)      /* Mix-signal Chip Version Control               */

#define  MTK6223_AFE_VAG_CON    (MTK6223_MIXED_BASE +0x0100)      /* AFE Voice Analog Gain Control Register        */
#define  MTK6223_AFE_VAG_CON_VDPG0_SHIFT   (4)
#define  MTK6223_AFE_VAG_CON_VUPG_SHIFT    (8)

#define  MTK6223_AFE_VAC_CON0  (MTK6223_MIXED_BASE +0x0104)      /* AFE Voice Analog-Circuit Control Register 0   */
#define  MTK6223_AFE_VAC_CON1  (MTK6223_MIXED_BASE +0x0108)      /* AFE Voice Analog-Circuit Control Register 1   */
#define  MTK6223_AFE_VAPDN_CON (MTK6223_MIXED_BASE +0x010C)      /* AFE Voice Analog Power Down Control Register  */
#define  MTK6223_AFE_VAGC_CON  (MTK6223_MIXED_BASE +0x0110)      /* AFE Voice AGC Control Register  */

#define  MTK6223_AFE_AAG_CON   (MTK6223_MIXED_BASE +0x0200)      /* AFE Audio Analog Gain Control Register        */
#define  MTK6223_AFE_AAG_CON_APGL_SHIFT  (0)
#define  MTK6223_AFE_AAG_CON_APGR_SHIFT  (4)
#define  MTK6223_AFE_AAG_CON_AMUTEL    (1<<8)
#define  MTK6223_AFE_AAG_CON_AMUTER    (1<<9)

#define  MTK6223_AFE_AAC_CON   (MTK6223_MIXED_BASE +0x0204)      /* AFE Audio Analog-Circuit Control Register     */
#define  MTK6223_AFE_AAC_CON_ABUF_SELR_SHIFT   (5)
#define  MTK6223_AFE_AAC_CON_ABUF_SELL_SHIFT   (8)
#define  MTK6223_AFE_AAC_CON_DAC_RL            (0)
#define  MTK6223_AFE_AAC_CON_DAC                (1)
#define  MTK6223_AFE_AAC_CON_voice_DAC          (2)
#define  MTK6223_AFE_AAC_CON_DAC_external_FM    (3)

#define  MTK6223_AFE_AAPDN_CON (MTK6223_MIXED_BASE +0x0208)      /* AFE Audio Analog Power Down Control Register  */
#define  MTK6223_AFE_AAC_NEW   (MTK6223_MIXED_BASE +0x020C)      /* Enhanced Audio AFE Control and Parameters     */
#define  MTK6223_AFE_AAC_NEW_MUX_SHIFT  (3)
#define  MTK6223_AFE_AAC_NEW_FM        // FM input
#define  MTK6223_AFE_AAC_NEW_FM1       // FM input
#define  MTK6223_AFE_AAC_NEW_L_DAC     // Left channel DAC
#define  MTK6223_AFE_AAC_NEW_R_DAC     // Right channel O/P

/******************************* DSP Patch Unit ******************************************/

#define MTK6223_MTK6223_PATCH1_REG   		    (MTK6223_PATCH1_BASE + 0x100) // 32 bit
#define MTK6223_MTK6223_PATCH1_PAGE(x)   		(MTK6223_PATCH1_BASE + 0x000 + ((x) * 0x10)) // 16 bit
#define MTK6223_MTK6223_PATCH1_ADD(x)     		(MTK6223_PATCH1_BASE + 0x004 + ((x) * 0x10))
#define MTK6223_MTK6223_PATCH1_INSTLOW(x)  	    (MTK6223_PATCH1_BASE + 0x008 + ((x) * 0x10))
#define MTK6223_MTK6223_PATCH1_INST_HIGH(x)  	(MTK6223_PATCH1_BASE + 0x00C + ((x) * 0x10))

#endif /* _MTK_MT6223_H */
