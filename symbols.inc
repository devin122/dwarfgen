.set BOGUS_SYM, IMAGE_LOAD_ADDR
.macro decl_core name:req, addr:req, type, size=0
	# gdb seems to ignore absolute symbols, so we hack it to make it relative
	# note IMAGE_START will be at  IMAGE_LOAD_ADDR , butwon't be resolved until link time
	# .set \name, (\addr - 0x80000000) + IMAGE_START
    .set \name, (\addr - IMAGE_LOAD_ADDR) + IMAGE_START
	.global \name
	
	#specify type if given
	.ifnb \type
		.type \name, \type
	.endif
	
	#specify size if given
	.if \size
		.size \name, \size
	.endif
.endm

# usage decl_func <name> <addr> [<size>]
.macro decl_func name:req, addr:req, size=0
	decl_core \name, \addr, STT_FUNC, \size
.endm

# usage decl_label <name> <addr>
.macro decl_label name:req, addr:req
	decl_core \name, \addr
.endm


.bss
IMAGE_START:

