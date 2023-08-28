.macro _assert_defined names:vararg
    .irp  n, \names
        .ifndef \n
            .err "undefined name \n"
        .else

        .endif
    .endr
.endm

# start sections so they have correct attributes
.section .debug_abbrev,"", %progbits
.section .debug_info,"", %progbits
#.section        .note.GNU-stack,"",@progbits

########### Abbreviation macros

.macro BEGIN_ABBREVIATIONS
    #.pushsection	.debug_abbrev,1
.endm

.macro END_ABBREVIATIONS
    #.popsection
.endm

.macro BEGIN_ABBR abbrnum:req, type:req, children=no
    _assert_defined .LDW_TAG_\type, .LDW_CHILDREN_\children
    .uleb128 \abbrnum
    .uleb128 .LDW_TAG_\type
    .byte .LDW_CHILDREN_\children
.endm

.macro END_ABBR
    .uleb128 0,0
.endm

.macro ATTRIBUTE type, form
    _assert_defined .LDW_AT_\type, .LDW_FORM_\form
    .uleb128 .LDW_AT_\type, .LDW_FORM_\form
.endm

#### Top level

.macro BEGIN_CU name
    .section	.debug_info_header, "", %progbits
    #.pushsection	.debug_info,0
	begin_cu_marker:
    .long .L_end_cu_label - . - 4
	# version
    .value	0x4
	# debug abbr offset
    #.long	start_abbreviations
	.long 0
	# addr size
    .byte	0x4

    .uleb128 .L_abbr_cu
    .string "\name"
.endm

.macro END_CU
	.section .debug_info_footer, "", %progbits
    .uleb128 0
    .L_end_cu_label:
	# TODO: multople CUs currently unsupported
.endm

.macro BEGIN_DWARF
	.pushsection .debug_info, 1
.endm

.macro END_DWARF
	.popsection
.endm
####  TYPE def


.macro BEGIN_TYPE_INFO name
	__type_info_\name:
	.weak __type_info_\name
	.type __type_info_\name,%object
	.size __type_info_\name, 1f - .

.endm

.macro END_TYPE_INFO name
	1:
.endm

.macro DECL_TYPE_INFO name
     __type_info_\name:
.endm

.macro MAKE_POINTER_alt name
	_assert_defined .L_abbr_ptr
	.ifndef __type_info_p_\name
		.pushsection .type_info_outofline
		__type_info_p_\name:
		.uleb128 .L_abbr_ptr
		.4byte __type_info_\name
		.type __type_info_p_\name, @object
		.size __type_info_p_\name, . - __type_info_p_\name
		.weak __type_info_p_\name
		.popsection
	.endif
.endm

.macro POINTER name
	_assert_defined .L_abbr_ptr

	BEGIN_TYPE_INFO p_\name
	.uleb128 .L_abbr_ptr
	.4byte __type_info_\name
	END_TYPE_INFO p_\name
.endm



.macro BASE_TYPE name, enc, size
#DW_ATE_signed
	_assert_defined .L_abbr_base_type, .LDW_ATE_\enc
	BEGIN_TYPE_INFO "\name"
		.uleb128 .L_abbr_base_type
		.string "\name"
		.byte .LDW_ATE_\enc
		.byte \size
	END_TYPE_INFO \name
.endm

# Hack to allow equivilent of "typedef struct Foo Foo;" without name clashes
# We might be able to make this work if we change the way struct encodes names
.macro CUSTOM_TYPEDEF old_name, new_name, label
    _assert_defined .L_abbr_typedef
	BEGIN_TYPE_INFO \label
		.uleb128 .L_abbr_typedef
		.string "\new_name"
		.4byte __type_info_\old_name
	END_TYPE_INFO \label
.endm

.macro TYPEDEF old_name, new_name
	CUSTOM_TYPEDEF \old_name \new_name, \new_name
.endm

.macro BEGIN_STRUCT name, size:req
	# forward declare 'typedef struct \name \name;
	CUSTOM_TYPEDEF \name, \name, _td_struct_\name

	_assert_defined .L_abbr_struct
	BEGIN_TYPE_INFO \name
	.uleb128 .L_abbr_struct
	.string "\name"
	.4byte \size
.endm

.macro MEMBER type, name, offset
    _assert_defined .L_abbr_member

    .uleb128 .L_abbr_member
    .string "\name"
    .4byte __type_info_\type
    .4byte \offset
.endm

.macro END_STRUCT
	.uleb128 0
	END_TYPE_INFO
	# hack to add implicit typedef struxt X X;
	//CUSTOM_TYPEDEF \name, \name, struct_td_\name
.endm


.macro ARRAY type, count
	_assert_defined .L_abbr_array, .L_abbr_subrange
	BEGIN_TYPE_INFO arr\count\()_\type
		.uleb128 .L_abbr_array
		.4byte __type_info_\type
		.uleb128 .L_abbr_subrange
		.4byte __type_info_\type
		.2byte \count
		.uleb128 0
	END_TYPE_INFO
.endm


# marks existing symbol with a given type
.macro VARIABLE type, name
	_assert_defined .L_abbr_variable
	.uleb128 .L_abbr_variable
	.string "\name"
	.4byte __type_info_\type
	# encode length
	.uleb128 5
	.byte .LDW_OP_addr
	.4byte \name

.endm
################################
# Forward declaration of abbreviation IDS

.equiv .L_abbr_cu, 1
.equiv .L_abbr_base_type, 2
.equiv .L_abbr_typedef, 3
.equiv .L_abbr_struct, 4
.equiv .L_abbr_member, 5
.equiv .L_abbr_voidptr, 6
.equiv .L_abbr_ptr, 7
.equiv .L_abbr_array, 8
.equiv .L_abbr_subrange, 9
.equiv .L_abbr_variable, 10




