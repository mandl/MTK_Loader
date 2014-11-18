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
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kallsyms.h>
#include "mt6516.h"

#include "regma.h"

MODULE_LICENSE("GPL");

static int
hello_init(void)
{
  uint32_t a;
  uint32_t regval;
  int i;
  uint16_t reg;
  printk(KERN_ALERT "Hello init\n");

  a = readl(EMI_CON0);
  printk(KERN_ALERT "EMI: 0x%08x\n",a);

  reg = readw(HW_CODE);
  printk(KERN_ALERT "HW_CODE: 0x%04x\n",reg);

  reg = readw(HW_VER);
  printk(KERN_ALERT "HW_VER: 0x%04x\n",reg);

  reg = readw(SW_VER);
  printk(KERN_ALERT "SW_VER: 0x%04x\n",reg);

  reg = readw(HW_MISC);
printk(KERN_ALERT "HW_MISC: 0x%04x\n",reg);
	    writew(0x8D84, HW_MISC);

  a = readl(EMI_GENE);
  printk(KERN_ALERT "EMI_GENE: 0x%08x\n",a);

  //kallsyms_lookup_name("hello");

  //(void*) kallsyms_lookup_name_ax("nr_running");

  for (i = 0; i < GPIO_DIR_NUM; i++)
    {

      a = mt6516_gpio_dir_reg_addr[i];
      regval = readw(a);
  printk(KERN_ALERT "GPIO DIR%d: 0x%04x\n",i,regval);
}

for (i = 0; i < GPIO_MODE_NUM; i++)
{

  a = mt6516_gpio_mode_reg_addr[i];
  regval = readw(a);
printk(KERN_ALERT "GPIO MODE%d: 0x%04x\n",i,regval);
}

for (i = 0; i < CLK_OUT_NUM; i++)
{

a = mt6516_gpio_clkout_reg_addr[i];
regval = readw(a);
printk(KERN_ALERT "GPIO CLK%d: 0x%04x\n",i,regval);
}
 //writew(0x1415,mt6516_gpio_mode_reg_addr[9]);
for (i = 0; i < GPIO_PULLEN_NUM; i++)
{

a = mt6516_gpio_pullen_reg_addr[i];
regval = readw(a);
printk(KERN_ALERT "GPIO PULENK%d: 0x%04x\n",i,regval);
}

for (i = 0; i < GPIO_DOUT_NUM; i++)
{

a = mt6516_gpio_dout_reg_addr[i];
regval = readw(a);
printk(KERN_ALERT "GPIO dout%d: 0x%04x\n",i,regval);
}

a = mt6516_gpio_dout_reg_addr[7];
regval = readw(a);
regval |= (1 << 8);
writew(regval,a);




printk(KERN_ALERT "EMI_CONI 0x%08x\n", readl(EMI_CONI));
printk(KERN_ALERT "EMI_CONJ 0x%08x\n", readl(EMI_CONJ));
printk(KERN_ALERT "EMI_CONK 0x%08x\n", readl(EMI_CONK));
printk(KERN_ALERT "EMI_CONL 0x%08x\n", readl(EMI_CONL));
printk(KERN_ALERT "EMI_CONM 0x%08x\n", readl(EMI_CONM));
printk(KERN_ALERT "EMI_CONN 0x%08x\n", readl(EMI_CONN));
printk(KERN_ALERT "EMI_GENA 0x%08x\n", readl(EMI_GENA));
printk(KERN_ALERT "EMI_GENB 0x%08x\n", readl(EMI_GENB));
printk(KERN_ALERT "EMI_GENC 0x%08x\n", readl(EMI_GENC));
printk(KERN_ALERT "EMI_GEND 0x%08x\n", readl(EMI_GEND));
printk(KERN_ALERT "EMI_GENE 0x%08x\n", readl(EMI_GENE));
printk(KERN_ALERT "EMI_DELA 0x%08x\n", readl(EMI_DELA));
printk(KERN_ALERT "EMI_DELB 0x%08x\n", readl(EMI_DELB));
printk(KERN_ALERT "EMI_DELC 0x%08x\n", readl(EMI_DELC));
printk(KERN_ALERT "EMI_DELD 0x%08x\n", readl(EMI_DELD));
printk(KERN_ALERT "EMI_DELE 0x%08x\n", readl(EMI_DELE));
printk(KERN_ALERT "EMI_DELF 0x%08x\n", readl(EMI_DELF));
printk(KERN_ALERT "EMI_DELG 0x%08x\n", readl(EMI_DELG));
printk(KERN_ALERT "EMI_DELH 0x%08x\n", readl(EMI_DELH));
printk(KERN_ALERT "EMI_DELI 0x%08x\n", readl(EMI_DELI));
printk(KERN_ALERT "EMI_DELJ 0x%08x\n", readl(EMI_DELJ));

printk(KERN_ALERT "EMI_DRCT 0x%08x\n", readl(EMI_DRCT ));
printk(KERN_ALERT "EMI_DQSA 0x%08x\n", readl(EMI_DQSA ));
printk(KERN_ALERT "EMI_DQSB 0x%08x\n", readl(EMI_DQSB));
printk(KERN_ALERT "EMI_DQSC 0x%08x\n", readl(EMI_DQSC));
printk(KERN_ALERT "EMI_DQSD 0x%08x\n", readl(EMI_DQSD));
printk(KERN_ALERT "EMI_DQSV 0x%08x\n", readl(EMI_DQSV ));
printk(KERN_ALERT "EMI_MDCL 0x%08x\n", readl(EMI_MDCL ));

return 0;
}

static void
hello_exit(void)
{
printk(KERN_ALERT "Goodbye, cruel world\n");

}
module_init(hello_init);
module_exit(hello_exit);
