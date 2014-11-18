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
// 0xF0000000
#define EFUSE_BASE      	(0xF0000000)
#define CONFIG_BASE      	(0xF0001000)
#define GPIO_BASE        	(0xF0002000)



/*GPIO direction control register*/
#define GPIO_DIR_NUM        10
#define GPIO_DIR_BASE       (GPIO_BASE+0x0000)
static u32 mt6516_gpio_dir_reg_addr[GPIO_DIR_NUM] =
{
    (GPIO_DIR_BASE+0x0000),
    (GPIO_DIR_BASE+0x0010),
    (GPIO_DIR_BASE+0x0020),
    (GPIO_DIR_BASE+0x0030),
    (GPIO_DIR_BASE+0x0040),
    (GPIO_DIR_BASE+0x0050),
    (GPIO_DIR_BASE+0x0060),
    (GPIO_DIR_BASE+0x0070),
    (GPIO_DIR_BASE+0x0080),
    (GPIO_DIR_BASE+0x0090)
};

/*GPIO pull enable register*/
#define GPIO_PULLEN_NUM     10
#define GPIO_PULLEN_BASE    (GPIO_BASE+0x0100)
static u32 mt6516_gpio_pullen_reg_addr[GPIO_PULLEN_NUM] =
{
    (GPIO_PULLEN_BASE+0x0000),
    (GPIO_PULLEN_BASE+0x0010),
    (GPIO_PULLEN_BASE+0x0020),
    (GPIO_PULLEN_BASE+0x0030),
    (GPIO_PULLEN_BASE+0x0040),
    (GPIO_PULLEN_BASE+0x0050),
    (GPIO_PULLEN_BASE+0x0060),
    (GPIO_PULLEN_BASE+0x0070),
    (GPIO_PULLEN_BASE+0x0080),
    (GPIO_PULLEN_BASE+0x0090)
};

/*GPIO pull selection register*/
#define GPIO_PULLSEL_NUM    10
#define GPIO_PULLSEL_BASE   (GPIO_BASE+0x0200)
static u32 mt6516_gpio_pullsel_reg_addr[GPIO_PULLSEL_NUM] =
{
    (GPIO_PULLSEL_BASE+0x0000),
    (GPIO_PULLSEL_BASE+0x0010),
    (GPIO_PULLSEL_BASE+0x0020),
    (GPIO_PULLSEL_BASE+0x0030),
    (GPIO_PULLSEL_BASE+0x0040),
    (GPIO_PULLSEL_BASE+0x0050),
    (GPIO_PULLSEL_BASE+0x0060),
    (GPIO_PULLSEL_BASE+0x0070),
    (GPIO_PULLSEL_BASE+0x0080),
    (GPIO_PULLSEL_BASE+0x0090)
};

/*GPIO pull-up/pull-down data inversion register*/
#define GPIO_DINV_NUM   10
#define GPIO_DINV_BASE  (GPIO_BASE+0x0300)
static u32 mt6516_gpio_dinv_reg_addr[GPIO_DINV_NUM] =
{
    (GPIO_DINV_BASE+0x0000),
    (GPIO_DINV_BASE+0x0010),
    (GPIO_DINV_BASE+0x0020),
    (GPIO_DINV_BASE+0x0030),
    (GPIO_DINV_BASE+0x0040),
    (GPIO_DINV_BASE+0x0050),
    (GPIO_DINV_BASE+0x0060),
    (GPIO_DINV_BASE+0x0070),
    (GPIO_DINV_BASE+0x0080),
    (GPIO_DINV_BASE+0x0090)
};

/*GPIO data output register*/
#define GPIO_DOUT_NUM   10
#define GPIO_DOUT_BASE  (GPIO_BASE+0x0400)
static u32 mt6516_gpio_dout_reg_addr[GPIO_DOUT_NUM] =
{
    (GPIO_DOUT_BASE+0x0000),
    (GPIO_DOUT_BASE+0x0010),
    (GPIO_DOUT_BASE+0x0020),
    (GPIO_DOUT_BASE+0x0030),
    (GPIO_DOUT_BASE+0x0040),
    (GPIO_DOUT_BASE+0x0050),
    (GPIO_DOUT_BASE+0x0060),
    (GPIO_DOUT_BASE+0x0070),
    (GPIO_DOUT_BASE+0x0080),
    (GPIO_DOUT_BASE+0x0090)
};

/*GPIO data input register*/
#define GPIO_DIN_NUM    10
#define GPIO_DIN_BASE   (GPIO_BASE+0x0500)
static u32 mt6516_gpio_din_reg_addr[GPIO_DIN_NUM] =
{
    (GPIO_DIN_BASE+0x0000),
    (GPIO_DIN_BASE+0x0010),
    (GPIO_DIN_BASE+0x0020),
    (GPIO_DIN_BASE+0x0030),
    (GPIO_DIN_BASE+0x0040),
    (GPIO_DIN_BASE+0x0050),
    (GPIO_DIN_BASE+0x0060),
    (GPIO_DIN_BASE+0x0070),
    (GPIO_DIN_BASE+0x0080),
    (GPIO_DIN_BASE+0x0090)
};

/*GPIO data input register*/
#define GPIO_MODE_NUM   19
#define GPIO_MODE_BASE  (GPIO_BASE+0x0600)
static u32 mt6516_gpio_mode_reg_addr[GPIO_MODE_NUM] =
{
    (GPIO_MODE_BASE+0x0000),
    (GPIO_MODE_BASE+0x0010),
    (GPIO_MODE_BASE+0x0020),
    (GPIO_MODE_BASE+0x0030),
    (GPIO_MODE_BASE+0x0040),
    (GPIO_MODE_BASE+0x0050),
    (GPIO_MODE_BASE+0x0060),
    (GPIO_MODE_BASE+0x0070),
    (GPIO_MODE_BASE+0x0080),
    (GPIO_MODE_BASE+0x0090),
    (GPIO_MODE_BASE+0x00A0),
    (GPIO_MODE_BASE+0x00B0),
    (GPIO_MODE_BASE+0x00C0),
    (GPIO_MODE_BASE+0x00D0),
    (GPIO_MODE_BASE+0x00E0),
    (GPIO_MODE_BASE+0x00F0),
    (GPIO_MODE_BASE+0x0100),
    (GPIO_MODE_BASE+0x0110),
    (GPIO_MODE_BASE+0x0120),
};

/*clock output setting*/
#define CLK_OUT_NUM     8
#define CLK_OUT_BASE    (GPIO_BASE+0x0900)
static u32 mt6516_gpio_clkout_reg_addr[CLK_OUT_NUM] =
{
    (CLK_OUT_BASE+0x0000),
    (CLK_OUT_BASE+0x0010),
    (CLK_OUT_BASE+0x0020),
    (CLK_OUT_BASE+0x0030),
    (CLK_OUT_BASE+0x0040),
    (CLK_OUT_BASE+0x0050),
    (CLK_OUT_BASE+0x0060),
    (CLK_OUT_BASE+0x0070),
};
#define RGU_BASE         	(0xF0003000)

// 0xF0020000
#define EMI_BASE         	(0xF0020000)
#define CIRQ_BASE        	(0xF0021000)
#define DMA_BASE         	(0xF0022000)
#define UART1_BASE       	(0xF0023000)
#define UART2_BASE       	(0xF0024000)
#define UART3_BASE       	(0xF0025000)
#define GPT_BASE         	(0xF0026000)
#define HDQ_BASE         	(0xF0027000)
#define KP_BASE         	(0xF0028000)
#define PWM_BASE         	(0xF0029000)
#define UART4_BASE       	(0xF002B000)
#define RTC_BASE         	(0xF002C000)
#define SEJ_base         	(0xF002D000)
#define I2C3_BASE        	(0xF002E000)
#define IRDA_BASE       	(0xF002F000)

// 0xF0030000
#define I2C_BASE        	(0xF0030000)
#define MSDC1_BASE       	(0xF0031000)
#define NFI_BASE 	      	(0xF0032000)
#define SIM_BASE 	      	(0xF0033000)
#define MSDC2_BASE       	(0xF0034000)
#define I2C2_BASE        	(0xF0035000)
#define CCIF_BASE        	(0xF0036000)
#define NFIECC_BASE      	(0xF0038000)
#define AMCONFG_BASE     	(0xF0039000)
#define AP2MD_BASE	     	(0xF003A000)
#define APVFE_BASE	     	(0xF003B000)
#define APSLP_BASE	     	(0xF003C000)
#define AUXADC_BASE	     	(0xF003D000)
#define APXGPT_BASE	     	(0xF003E000)
#define MSDC3_BASE       	(0xF003F000)

// 0xF0040000
#define CSDBG_BASE				(0xF0040000)

// 0xF0060000
#define PLL_BASE				(0xF0060000)
#define DSI_PHY_BASE            (0xF0060B00)

// 0xF0080000
#define GMC1_BASE				(0xF0080000)
#define G2D_BASE				(0xF0081000)
#define GCMQ_BASE				(0xF0082000)
#define GIFDEC_BASE				(0xF0083000)
#define IMGDMA_BASE				(0xF0084000)
#define PNGDEC_BASE				(0xF0085000)
#define MTVSPI_BASE				(0xF0087000)
#define TVCON_BASE				(0xF0088000)
#define TVENC_BASE				(0xF0089000)
#define CAM_BASE				(0xF008A000)
#define CAM_ISP_BASE				(0xF008B000)
#define BLS_BASE				(0xF008C000)
#define CRZ_BASE				(0xF008D000)
#define DRZ_BASE				(0xF008E000)
#define ASM_BASE				(0xF008F000)

// 0xF0090000
#define WT_BASE					(0xF0090000)
#define IMG_BASE				(0xF0091000)
#define GRAPH1SYS_CONFG_BASE			(0xF0092000)

// 0xF00A0000
#define GMC2_BASE				(0xF00A0000)
#define JPEG_BASE				(0xF00A1000)
#define M3D_BASE				(0xF00A2000)
#define PRZ_BASE				(0xF00A3000)
#define IMGDMA1_BASE				(0xF00A4000)
#define MP4_DEBLK_BASE		    		(0xF00A5000)
#define FAKE_ENG2_BASE				(0xF00A6000)
#define GRAPH2SYS_BASE		    		(0xF00A7000)

// 0xF00C0000
#define MP4_BASE				(0xF00C0000)
#define H264_BASE				(0xF00C1000)

// 0xF0100000
#define USB_BASE            			(0xF0100000)

// 0xF0120000
#define LCD_BASE            			(0xF0120000)

// 0xF0130000
#define DPI_BASE            			(0xF0130000)


#define CEVA_BASE        			(0xF1000000)


#define HW_VER              (CONFIG_BASE+0x0000)
#define SW_VER              (CONFIG_BASE+0x0004)
#define HW_CODE             (CONFIG_BASE+0x0008)
#define SW_MISC_L			(CONFIG_BASE+0x0010)
#define SW_MISC_H           (CONFIG_BASE+0x0014)

#define HW_MISC             (CONFIG_BASE+0x0020)
#define USB_SEL             0x00000001
#define GMC_AUTOCG        	0x00000004
#define UART1_SEL           0x00000008
#define UART2_SEL           0x00000010
#define UART3_SEL           0x00000020
#define UART4_SEL           0x00000040
#define SIM2_SEL            0x00000080
#define NFI_SEL             0x00000100
#define CEVADBG_EN        	0x00000200
#define MASK_GMC1         	0x00000400
#define MASK_GMC2         	0x00000800
#define NIRQ_MASK          	0x00001000
#define MD_BOOT_ONLY    	0x00004000

#define ARM9_FREQ_DIV       (CONFIG_BASE+0x0100)
#define SLEEP_CON           (CONFIG_BASE+0x0204)
#define MCUCLK_CON          (CONFIG_BASE+0x0208)
#define EMICLK_CON          (CONFIG_BASE+0x020c)
#define ISO_EN              (CONFIG_BASE+0x0300)
#define PWR_OFF             (CONFIG_BASE+0x0304)
#define MCU_MEM_PDN         (CONFIG_BASE+0x0308)
#define G1_MEM_PDN          (CONFIG_BASE+0x030c)
#define G2_MEM_PDN          (CONFIG_BASE+0x0310)
#define CEVA_MEM_PDN        (CONFIG_BASE+0x0314)
#define IN_ISO_EN           (CONFIG_BASE+0x0318)
#define PWR_ACK             (CONFIG_BASE+0x031c)
#define ACK_CLR             (CONFIG_BASE+0x0320)
#define APB_CON             (CONFIG_BASE+0x0404)
#define SECURITY_REG        (CONFIG_BASE+0x0408)
#define IO_DRV0             (CONFIG_BASE+0x0500)
#define IO_DRV1             (CONFIG_BASE+0x0504)
#define IC_SIZE             (CONFIG_BASE+0x0600)
#define DC_SIZE             (CONFIG_BASE+0x0604)
#define MDVCXO_OFF          (CONFIG_BASE+0x0608)

#define EMI_CON0 			(EMI_BASE+0x0000) /* Bank 0 configuration */
#define EMI_CON1 			(EMI_BASE+0x0004) /* Bank 1 configuration */
#define EMI_CON2 			(EMI_BASE+0x0008) /* Bank 2 configuration */
#define EMI_CON3 			(EMI_BASE+0x000C) /* Bank 3 configuration */
#define EMI_CON4 			(EMI_BASE+0x0010) /* Boot Mapping config  */
#define	EMI_CON5 			(EMI_BASE+0x0014)
#define SDRAM_MODE 			(EMI_BASE+0x0020)
#define SDRAM_COMD 			(EMI_BASE+0x0024)
#define SDRAM_SET 			(EMI_BASE+0x0028)

#define EMI_CONI (EMI_BASE + 0x40)       //DRAM MR/EMR
#define EMI_CONJ (EMI_BASE + 0x48)       // DRAM controller timing configuration I
#define EMI_CONK (EMI_BASE + 0x50)       // DRAM controller timing configuration II
#define EMI_CONL (EMI_BASE + 0x58)       // DRAM controller read data path configuration
#define EMI_CONM (EMI_BASE + 0x60)       // Digital DLL Control EMI_CONM
#define EMI_CONN (EMI_BASE + 0x68)
#define EMI_GENA (EMI_BASE + 0x70)
#define EMI_GENB (EMI_BASE + 0x78)
#define EMI_GENC (EMI_BASE + 0x0080)    //EMI General Control Register C
#define EMI_GEND    (EMI_BASE + 0x0088) //EMI General Control Register D
#define EMI_GENE    (EMI_BASE + 0x0090) //Modem side offset address
#define EMI_DELA     (EMI_BASE + 0x0098) //EMI In/Out Delay Line Control
#define EMI_DELB     (EMI_BASE + 0x00A0) //EMI In/Out Delay Line Control
#define EMI_DELC     (EMI_BASE + 0x00A8) //EMI In/Out Delay Line Control
#define EMI_DELD     (EMI_BASE + 0x00B0) //EMI In/Out Delay Line Control
#define EMI_DELE     (EMI_BASE + 0x00B8) //EMI In/Out Delay Line Control
#define EMI_DELF     (EMI_BASE + 0x00C0) //EMI In/Out Delay Line Control
#define EMI_DELG     (EMI_BASE + 0x00C8) //EMI In/Out Delay Line Control
#define EMI_DELH     (EMI_BASE + 0x00D0) //EMI In/Out Delay Line Control
#define EMI_DELI     (EMI_BASE + 0x00D8) //EMI In/Out Delay Line Control
#define EMI_DELJ     (EMI_BASE + 0x00E0) //EMI In/Out Delay Line Control

#define EMI_DRCT     (EMI_BASE + 0x01A0) // EMI dummy read controls
#define EMI_DQSA     (EMI_BASE + 0x01B0) // DQSI auto-tracking control for CS[0]
#define EMI_DQSB     (EMI_BASE + 0x01B8) // DQSI auto-tracking control for CS[1]
#define EMI_DQSC     (EMI_BASE + 0x01C0) // DQSI auto-tracking control for CS[2]
#define EMI_DQSD     (EMI_BASE + 0x01C8) // DQSI auto-tracking control for CS[3]
#define EMI_DQSV     (EMI_BASE + 0x01D0) // DQSI auto-tracking calibrating delay value
#define EMI_MDCL     (EMI_BASE + 0x01E0) // Modem side control register

#define EMI_GENE			(EMI_BASE+0x0090)  // Modem side master address offset registers

