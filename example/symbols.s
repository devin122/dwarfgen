.include "symbols.inc"

.bss

# declares a generic label at 0x80000100
decl_label mysym 0x80000100

# declare a function func at 0x80000200 which is 0x100 bytes long
decl_func func, 0x80000200, 0x100
