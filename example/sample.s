.include "dwarf_consts.inc"
.include "dwarf_macros.inc"

# typedef int MyTypeDef;
TYPEDEF int, MyTypeDef

# generate type definition for (assumes 32-bit code)
# struct MyStruct {
#   char *a;
#   int b;
#   MyStruct *c;
# }

# Ensure the definition for char* is generated
# Note: this is automatically done for structs
POINTER char

BEGIN_STRUCT struct1, size=4
    MEMBER int, a, offset=0
END_STRUCT
#
# BEGIN_STRUCT MyStruct, size=12
    # MEMBER p_char, a, offset=0
#    MEMBER int, b, offset=4
     # MEMBER p_MyStruct, c, offset=8
# END_STRUCT
