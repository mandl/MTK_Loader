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

// in mem  40*1024k
#include "memory.h"
#include "delay.h"
#include "mt6223.h"
#include "stdio.h"
#include "uart.h"
#include "string.h"

#define IRQ_MASK 0x00000080
#define FIQ_MASK 0x00000040

extern uint32_t _vectors;

void __attribute__ ((interrupt("FIQ")))
FIQ_Routine()
{
}

void __attribute__ ((interrupt("SWI")))
SWI_Routine()
{
}

void __attribute__((naked))
UNDEF_Routine()
{
}

void __attribute__ ((interrupt("IRQ")))
IRQ_Routine()
{
}

void
memory_init(void)
{
  writel(0x0, MTK6223_EMI_ADMUX);

  writel(0x44894324, MTK6223_EMI_CONA);
  writel(0x44894324, MTK6223_EMI_CONB);
  writel(0xEEEEFB80, MTK6223_EMI_GEN);
  writel(0x3030107, MTK6223_PREFETCH_CON);

  // set external mem to 0x00000000
  writel(2, MTK6223_EMI_REMAP);
}

void
pll_init(void)
{

  // Power on PLL
  writew(
      MTK6223_PDN_CLKSQ | MTK6223_PDN_MCU_DIV2 | MTK6223_PDN_PLL| MTK6223_PDN_DSP_DIV2,
      MTK6223_PDN_CLR0);

  // Enable MCU clock divider
  writew(0x0002, MTK6223_CLK_CON);

  // Pll input from CLKSQ
  writew(0xc008, MTK6223_PLL);

  // Reset PLL
  writew(0xc088, MTK6223_PLL);

  // Select CLKSQ_DIV2_MCU for 13 MHz
  writew(0x0002, MTK6223_CLK_CON);

  // MCU and BUS clock 1:1
  writew(0x0303, MTK6223_MCUCLK_CON);

  // MPLL/2 and DPLL/2 enable
  writew(0x0003, MTK6223_CLK_CON);

  // wait for pll set
  delay_ms(1);

  // DPLLSEL = 0 and MPLLSEL= 2
  writew(0xC010, MTK6223_PLL);

  // DSP 1 2 Clock  105 Mhz
  //writew(7 << (MTK6223_DSP1_FSEL_SHIFT) | 7<< (MTK6223_DSP2_FSEL_SHIFT), MTK6223_DSPCLK_CON);

}

int
main(void)
{

  /* powerup the baseband */

  writew(MTK6223_POWERKEY1_MAGIC, MTK6223_RTC_POWERKEY1);
  writew(MTK6223_POWERKEY2_MAGIC, MTK6223_RTC_POWERKEY2);
  writew(
      MTK6223_KEY_BBPU | MTK6223_RTC_WRITE_EN | MTK6223_RTC_BBPU_BIT | MTK6223_RTC_AUTO,
      MTK6223_RTC_BBPU);

  // disable watchdog timer
  writew(MTK6223_WDT_MODE_KEY, MTK6223_WDT_MODE);

  // disable all IRQ
  writel(0xFFFFFFFF, MTK6223_IRQ_MASK);

  //disable EINT
  writeb(0xFF, MTK6223_EINT_MASK);

  // disable RTC IRQ
  writeb(0x00, MTK6223_RTC_IRQ_EN);

  // disable FIQ
  writel(1, MTK6223_FIQ_CON);

  //memory_init();

  pll_init();

  // copy my interrupt vectors to memory
  //memcpy(0, &_vectors, 0x38);

  uart_init(1, 0);
  uart_baudrate(1, UART_115200);

  LedGreen(1);

  uart_getchar(1);

  while (1)
    {
      printf("\n\rHW_CODE    = 0x%04x", readw(MTK6223_HARDWARE_CODE));
      printf("\n\rFW_VERSION = 0x%04x", readw(MTK6223_CONFG_FW_VERSION));
      printf("\n\rHW_VERSION = 0x%04x", readw(MTK6223_CONFG_HW_VERSION));

      LedGreen(1);
      delay_ms(1000);
      LedGreen(0);
      LedRed(1);
      delay_ms(1000);
      LedRed(0);
      LedBlue(1);
      delay_ms(1000);
      LedBlue(0);

    }

}
