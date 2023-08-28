DWARFGEN_DIR := ..
OBJ_DIR := objs

include $(DWARFGEN_DIR)/include.mk

AS := clang
LD := ~/LLVM-15.0.1-Linux/bin/ld.lld

ARCH_FLAGS :=
#n-target thumbv7 -mfloat-abi=hard
ASFLAGS := $(ARCH_FLAGS) -I $(DWARFGEN_DIR)
# no
LDFLAGS := -z defs


LINKER_SCRIPT := debuginfo.ld
SYMBOL_FILE := debuginfo.elf

OBJS := sample.o
OBJS := $(patsubst %,$(OBJ_DIR)/%, $(OBJS))


.DEFAULT_GOAL := all
.PHONY: all clean

all: $(SYMBOL_FILE)

clean:
	rm -f $(DWARF_OBJS) $(DWARFGEN_OBJS)

$(OBJS): $(DWARFGEN_INCLUDES)

$(SYMBOL_FILE): $(OBJS) $(DWARFGEN_OBJS) $(LINKER_SCRIPT)
	$(LD) -zdefs -T $(LINKER_SCRIPT) -o $@   $(filter-out $(LINKER_SCRIPT),$^) -M > debuginfo.map

# TODO: this is inelegant, but I'm not familiar enough with make to know how to do it better
$(OBJ_DIR)/core/%.o: $(DWARFGEN_DIR)/%.s
	$(AS) $(ASFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: %.s
	$(AS) $(ASFLAGS) -c $< -o $@
