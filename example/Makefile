# path to dwarfgen
DWARFGEN_DIR := ..

# path to the build object directory
OBJ_DIR := objs

# Address where the target binary is loaded
IMAGE_LOAD_ADDR := 0x80000000

include $(DWARFGEN_DIR)/include.mk

AS := clang
LD := ld

ARCH_FLAGS :=
ASFLAGS := $(ARCH_FLAGS) -I $(DWARFGEN_DIR) -Wa,-defsym,IMAGE_LOAD_ADDR=$(IMAGE_LOAD_ADDR)
LDFLAGS := -z defs --defsym IMAGE_LOAD_ADDR=$(IMAGE_LOAD_ADDR)


LINKER_SCRIPT := debuginfo.ld
SYMBOL_FILE := debuginfo.elf

OBJS := sample.o symbols.o
OBJS := $(patsubst %,$(OBJ_DIR)/%, $(OBJS))


.DEFAULT_GOAL := all
.PHONY: all clean

all: $(SYMBOL_FILE)

clean:
	rm -f $(DWARF_OBJS) $(DWARFGEN_OBJS)

$(OBJS): $(DWARFGEN_INCLUDES)

$(SYMBOL_FILE): $(OBJS) $(DWARFGEN_OBJS) $(LINKER_SCRIPT)
	$(LD) $(LDFLAGS) -T $(LINKER_SCRIPT) -o $@   $(filter-out $(LINKER_SCRIPT),$^) -M > debuginfo.map

# TODO: this is inelegant, but I'm not familiar enough with make to know how to do it better
$(OBJ_DIR)/core/%.o: $(DWARFGEN_DIR)/%.s
	$(AS) $(ASFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: %.s
	$(AS) $(ASFLAGS) -c $< -o $@
