
DWARFGEN_INCLUDES := $(patsubst %, $(DWARFGEN_DIR)/%, dwarf_consts.inc dwarf_macros.inc)
DWARFGEN_OBJS := $(patsubst %, $(OBJ_DIR)/core/%, base_types.o dwarf_common.o)

$(DWARFGEN_OBJS): $(DWARFGEN_INCLUDES)
