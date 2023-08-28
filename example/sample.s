.include "dwarf_consts.inc"
.include "dwarf_macros.inc"
.include "symbols.inc"

# typedef int MyTypeDef;
TYPEDEF int, MyTypeDef


BEGIN_DWARF

# Ensure the definition for char* is generated
# The pointer type is named p_[base_type_name]. In this case p_char.
POINTER char


# generate type definition for (assumes 32-bit code)
# struct MyStruct {
#   char *a;
#   int b;
#   MyStruct *c;
# }
BEGIN_STRUCT MyStruct, size=12
    MEMBER p_char, a, offset=0
    MEMBER int, b, offset=4
    MEMBER p_MyStruct, c, offset=8
END_STRUCT

# Ensure pointer to MyStruct is generated.
POINTER MyStruct
END_DWARF


# Begin defining symbols.
# We generate symbols in the bss segment to avoid allocating space
.bss

# declares a generic label at 0x80000100
decl_label mysym, 0x80000100

# declare a function func at 0x80000200 which is 0x100 bytes long
decl_func func, 0x80000200, 0x100

# declare an instance of MyStruct named my_struct at 0x80000300
# Note: the decl_label and VARIABLE statements don't need to be in the same file.
decl_label my_struct, 0x80000300
VARIABLE MyStruct my_struct
