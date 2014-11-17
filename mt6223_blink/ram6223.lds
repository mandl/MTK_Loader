/*
 * Linker script for running from internal SRAM 40k on MTK 6223 phones
 *
 * This script is tailored specifically to the requirements imposed
 * on us by the Mediatek bootloader.
 *
 */
OUTPUT_FORMAT("elf32-littlearm", "elf32-littlearm", "elf32-littlearm")
OUTPUT_ARCH(arm)
ENTRY(_start)
MEMORY
{
    /* mtk-loaded binary: our text, initialized data */
    LRAM (rw) : ORIGIN = 0x40000000, LENGTH = 0x00004000
    /* mtk-loaded binary: our unitialized data, stacks, heap */
    IRAM (rw) : ORIGIN =  0x40004000, LENGTH = 0x00001000 
    /*IRAM (rw) : ORIGIN =  0x08000000 , LENGTH = 0x7FFFFFF*/
}
SECTIONS
{
    . = 0x40000000;

    /* romloader data section, contains passthru interrupt vectors */
    .mtk.loader (NOLOAD) : { . = 0x1400; } > LRAM

    /* initialization code */
    . = ALIGN(4);
    .text.start : {
        PROVIDE(_start = .);
        KEEP(*(.text.start))
        *(.text.start)
    } > LRAM

    /* code */
    . = ALIGN(4);
    .text (LOADADDR(.text.start) + SIZEOF(.text.start)) :
          AT (LOADADDR(.text.start) + SIZEOF(.text.start)) {
        /* regular code */
        *(.text*)
        /* always-in-ram code */
        *(.ramtext*)
        /* gcc voodoo */
        *(.glue_7t) *(.glue_7) *(.vfp11_veneer) *(.v4_bx)
        . = ALIGN(4);
    } > LRAM
    PROVIDE(_text_start = LOADADDR(.text));
    PROVIDE(_text_end = LOADADDR(.text) + SIZEOF(.text));

  
 

    /* read-only data */
    . = ALIGN(4);
    .rodata : {
        *(.rodata*)
        
    } > LRAM
    PROVIDE(_rodata_start = LOADADDR(.rodata));
    PROVIDE(_rodata_end = LOADADDR(.rodata) + SIZEOF(.rodata));
    
    . = ALIGN(4);
    .nvic_vector : 
    {
        *(vectors)    /* Vector table */
    } >LRAM

    /* initialized data */
    . = ALIGN(4);
    .data : {
        *(.data)
    } > LRAM
    PROVIDE(_data_start = LOADADDR(.data));
    PROVIDE(_data_end = LOADADDR(.data) + SIZEOF(.data));

    /* pic offset tables */
    . = ALIGN(4);
    .got : {
        *(.got)
        *(.got.plt) *(.igot.plt) *(.got) *(.igot)
    } > LRAM
    PROVIDE(_got_start = LOADADDR(.got));
    PROVIDE(_got_end = LOADADDR(.got) + SIZEOF(.got));

    /* uninitialized data */
    .bss (NOLOAD) : {
        . = ALIGN(4);
        __bss_start = .;
        *(.bss)
    } > IRAM
    . = ALIGN(4);
    __bss_end = .;
    PROVIDE(_bss_start = __bss_start);
    PROVIDE(_bss_end = __bss_end);

    /* end of image */
    . = ALIGN(4);
    _end = .;
    PROVIDE(end = .);
}
