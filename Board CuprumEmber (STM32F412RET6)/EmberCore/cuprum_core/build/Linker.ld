
# Definition of memory
MEMORY {
  FLASH : ORIGIN = 0x08000000, LENGTH = 512K
  RAM   : ORIGIN = 0x20000000, LENGTH = 256K
}

_stackOrigin = ORIGIN(RAM) + LENGTH(RAM);

# Memory map of microcontroller
SECTIONS {
  # Interrupt vector
  .isr_vector : {
    KEEP(*(.isr_vector))
  } >FLASH

  # Programm code
  .text : {
    *(.text)
    *(.text*)
    *(.glue_7)
    *(.glue_7t)
    *(.rodata)
    *(.rodata*)
  } >FLASH

  # Exeption handler
  .ARM.exidx : {
    __exidx_start = .;
    *(.ARM.exidx* .gnu.linkonce.armexidx.*)
    __exidx_end = .;
  } > FLASH

  # The ".data" origin in the FLASH stack and then moved to RAM
  _originInitdata = .;

  # Initialized variables
  .data : AT(_originInitdata) {
    _originData = .;
    *(.data)
    *(.data*)
    _endData = .;
  } > RAM

  # Not initialized variables
  .bss (NOLOAD) : {
    _originBss = .;
    *(.bss)
    *(.bss*)
    *(COMMON)
    _endBss = .;
  } > RAM
}