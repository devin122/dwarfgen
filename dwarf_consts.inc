.macro CONST name, value
    .equiv .L\name, \value
.endm

############################ DWARF CONSTANTS ##########################



##### TAGS
CONST DW_TAG_array_type,       0x01
CONST DW_TAG_entry_point,      0x03
CONST DW_TAG_enumeration_type, 0x04
CONST DW_TAG_label,            0x0a
CONST DW_TAG_member,           0x0d
CONST DW_TAG_pointer_type,     0x0f
CONST DW_TAG_compile_unit,     0x11
CONST DW_TAG_structure_type,   0x13
CONST DW_TAG_typedef,          0x16
CONST DW_TAG_union_type,       0x17
CONST DW_TAG_subrange_type,    0x21
CONST DW_TAG_base_type,        0x24
CONST DW_TAG_enumerator,       0x28
CONST DW_TAG_packed_type,      0x2d
CONST DW_TAG_subprogram,       0x2e
CONST DW_TAG_variable,         0x34


.if 0

enum
  {
    DW_TAG_class_type = 0x02,
    DW_TAG_entry_point = 0x03,
    DW_TAG_formal_parameter = 0x05,
    DW_TAG_imported_declaration = 0x08,
    /* 0x09 reserved.  */
    DW_TAG_lexical_block = 0x0b,
    DW_TAG_reference_type = 0x10,
    DW_TAG_string_type = 0x12,
    /* 0x14 reserved.  */
    DW_TAG_subroutine_type = 0x15,
    DW_TAG_unspecified_parameters = 0x18,
    DW_TAG_variant = 0x19,

    DW_TAG_module = 0x1e,
    DW_TAG_ptr_to_member_type = 0x1f,
    DW_TAG_set_type = 0x20,

    DW_TAG_const_type = 0x26,
    DW_TAG_constant = 0x27,
    ,
    DW_TAG_file_type = 0x29,
    DW_TAG_namelist = 0x2b,
    DW_TAG_namelist_item = 0x2c,

    DW_TAG_template_type_parameter = 0x2f,
    DW_TAG_template_value_parameter = 0x30,,
    DW_TAG_variant_part = 0x33,

    DW_TAG_volatile_type = 0x35,
    DW_TAG_dwarf_procedure = 0x36,
    DW_TAG_restrict_type = 0x37,
    DW_TAG_interface_type = 0x38,
    DW_TAG_namespace = 0x39,
    DW_TAG_unspecified_type = 0x3b,

    DW_TAG_condition = 0x3f,
    DW_TAG_shared_type = 0x40,
    DW_TAG_type_unit = 0x41,
    DW_TAG_rvalue_reference_type = 0x42,
    DW_TAG_coarray_type = 0x44,
    DW_TAG_generic_subrange = 0x45,
    DW_TAG_dynamic_type = 0x46,
    DW_TAG_atomic_type = 0x47,
    DW_TAG_call_site = 0x48,
    DW_TAG_call_site_parameter = 0x49,
    DW_TAG_skeleton_unit = 0x4a,
    DW_TAG_immutable_type = 0x4b,
    DW_TAG_format_label = 0x4101,
    DW_TAG_function_template = 0x4102,

    DW_TAG_GNU_template_template_param = 0x4106,
    DW_TAG_GNU_template_parameter_pack = 0x4107,
    DW_TAG_GNU_formal_parameter_pack = 0x4108,
    DW_TAG_GNU_call_site = 0x4109,
    DW_TAG_GNU_call_site_parameter = 0x410a,
  };
.endif



###### attribute types

CONST DW_AT_sibling,     0x01
CONST DW_AT_location,    0x02
CONST DW_AT_name,        0x03
CONST DW_AT_byte_size,   0x0b
# Deprecated in v4
CONST DW_AT_bit_offset,  0x0c
CONST DW_AT_bit_size,    0x0d
CONST DW_AT_low_pc,      0x11
CONST DW_AT_high_pc,     0x12
CONST DW_AT_language,    0x13
CONST DW_AT_count,       0x37
CONST DW_AT_data_member_location, 0x38
CONST DW_AT_encoding,    0x3e
CONST DW_AT_external,    0x3f
CONST DW_AT_frame_base,  0x40
CONST DW_AT_type,        0x49
CONST DW_AT_entry_pc,    0x52
CONST DW_AT_data_location, 0x50
CONST DW_AT_data_bit_offset, 0x6b


.if 0

/* DWARF attributes encodings.  */
enum
  {

    DW_AT_location = 0x02,

    DW_AT_ordering = 0x09,
    DW_AT_stmt_list = 0x10,

    /* 0x14 reserved.  */
    DW_AT_discr = 0x15,
    DW_AT_discr_value = 0x16,
    DW_AT_visibility = 0x17,
    DW_AT_string_length = 0x19,
    DW_AT_common_reference = 0x1a,
    DW_AT_comp_dir = 0x1b,
    DW_AT_const_value = 0x1c,
    DW_AT_containing_type = 0x1d,
    DW_AT_default_value = 0x1e,
    DW_AT_inline = 0x20,
    DW_AT_is_optional = 0x21,
    DW_AT_lower_bound = 0x22,
    DW_AT_producer = 0x25,
    DW_AT_prototyped = 0x27,
    DW_AT_return_addr = 0x2a,
    /* 0x2b reserved.  */
    DW_AT_start_scope = 0x2c,
    /* 0x2d reserved.  */
    DW_AT_bit_stride = 0x2e,
    DW_AT_upper_bound = 0x2f,
    DW_AT_abstract_origin = 0x31,
    DW_AT_artificial = 0x34,
    DW_AT_base_types = 0x35,
    DW_AT_calling_convention = 0x36,
    DW_AT_declaration = 0x3c,
    DW_AT_discr_list = 0x3d,
    DW_AT_identifier_case = 0x42,
    DW_AT_macro_info = 0x43, /* Deprecated in DWARF5.  */
    DW_AT_namelist_item = 0x44,
    DW_AT_priority = 0x45,
    DW_AT_segment = 0x46,
    DW_AT_specification = 0x47,
    DW_AT_static_link = 0x48,
    DW_AT_use_location = 0x4a,
    DW_AT_variable_parameter = 0x4b,
    DW_AT_virtuality = 0x4c,
    DW_AT_vtable_elem_location = 0x4d,
    DW_AT_allocated = 0x4e,
    DW_AT_associated = 0x4f,
    DW_AT_byte_stride = 0x51,
    DW_AT_use_UTF8 = 0x53,
    DW_AT_extension = 0x54,
    DW_AT_ranges = 0x55,
    DW_AT_trampoline = 0x56,
    DW_AT_description = 0x5a,
    DW_AT_binary_scale = 0x5b,
    DW_AT_decimal_scale = 0x5c,
    DW_AT_small = 0x5d,
    DW_AT_decimal_sign = 0x5e,
    DW_AT_digit_count = 0x5f,
    DW_AT_picture_string = 0x60,
    DW_AT_object_pointer = 0x64,
    DW_AT_endianity = 0x65,
    DW_AT_elemental = 0x66,
    DW_AT_pure = 0x67,
    DW_AT_recursive = 0x68,
    DW_AT_signature = 0x69,
    DW_AT_main_subprogram = 0x6a,
    DW_AT_const_expr = 0x6c,
    DW_AT_enum_class = 0x6d,
    DW_AT_linkage_name = 0x6e,
    DW_AT_string_length_bit_size = 0x6f,
    DW_AT_string_length_byte_size = 0x70,
    DW_AT_rank = 0x71,
    DW_AT_str_offsets_base = 0x72,
    DW_AT_addr_base = 0x73,
    DW_AT_rnglists_base = 0x74,
    DW_AT_dwo_name = 0x76,
    DW_AT_macros = 0x79,
    DW_AT_call_all_calls = 0x7a,
    DW_AT_call_all_source_calls = 0x7b,
    DW_AT_call_all_tail_calls = 0x7c,
    DW_AT_call_return_pc = 0x7d,
    DW_AT_call_value = 0x7e,
    DW_AT_call_origin = 0x7f,
    DW_AT_call_parameter = 0x80,
    DW_AT_call_pc = 0x81,
    DW_AT_call_tail_call = 0x82,
    DW_AT_call_target = 0x83,
    DW_AT_call_target_clobbered = 0x84,
    DW_AT_call_data_location = 0x85,
    DW_AT_call_data_value = 0x86,
    DW_AT_noreturn = 0x87,
    DW_AT_alignment = 0x88,
    DW_AT_export_symbols = 0x89,
    DW_AT_loclists_base = 0x8c,

    /* GNU extensions.  */
    DW_AT_sf_names = 0x2101,
    DW_AT_src_info = 0x2102,
    DW_AT_mac_info = 0x2103,
    DW_AT_src_coords = 0x2104,
    DW_AT_body_begin = 0x2105,
    DW_AT_body_end = 0x2106,
    DW_AT_GNU_vector = 0x2107,
    DW_AT_GNU_guarded_by = 0x2108,
    DW_AT_GNU_pt_guarded_by = 0x2109,
    DW_AT_GNU_guarded = 0x210a,
    DW_AT_GNU_pt_guarded = 0x210b,
    DW_AT_GNU_locks_excluded = 0x210c,
    DW_AT_GNU_exclusive_locks_required = 0x210d,
    DW_AT_GNU_shared_locks_required = 0x210e,
    DW_AT_GNU_odr_signature = 0x210f,
    DW_AT_GNU_template_name = 0x2110,
    DW_AT_GNU_call_site_value = 0x2111,
    DW_AT_GNU_call_site_data_value = 0x2112,
    DW_AT_GNU_call_site_target = 0x2113,
    DW_AT_GNU_call_site_target_clobbered = 0x2114,
    DW_AT_GNU_tail_call = 0x2115,
    DW_AT_GNU_all_tail_call_sites = 0x2116,
    DW_AT_GNU_all_call_sites = 0x2117,
    DW_AT_GNU_all_source_call_sites = 0x2118,
    DW_AT_GNU_locviews = 0x2137,
    DW_AT_GNU_entry_view = 0x2138,

    /* GNU Debug Fission extensions.  */
    DW_AT_GNU_dwo_name = 0x2130,
    DW_AT_GNU_dwo_id = 0x2131,
    DW_AT_GNU_ranges_base = 0x2132,
    DW_AT_GNU_addr_base = 0x2133,
    DW_AT_GNU_pubnames = 0x2134,
    DW_AT_GNU_pubtypes = 0x2135,
    /* https://gcc.gnu.org/wiki/DW_AT_GNU_numerator_denominator  */
    DW_AT_GNU_numerator = 0x2303,
    DW_AT_GNU_denominator = 0x2304,
    DW_AT_hi_user = 0x3fff
  };

.endif


########## ATE values

CONST DW_ATE_void,     0x00
CONST DW_ATE_address,  0x01
CONST DW_ATE_boolean,  0x02
CONST DW_ATE_float,    0x04
CONST DW_ATE_signed,   0x05
CONST DW_ATE_unsigned, 0x07
CONST DW_ATE_ASCII, 0x12



########## Form values
CONST DW_FORM_addr, 1
CONST DW_FORM_data2, 0x05
CONST DW_FORM_data4, 0x06
CONST DW_FORM_string, 0x08
CONST DW_FORM_strp, 0x0e
CONST DW_FORM_data1, 0x0b
CONST DW_FORM_ref4, 0x13
CONST DW_FORM_exprloc, 0x18
CONST DW_FORM_flag_present,   0x19
CONST DW_FORM_implicit_const, 0x21

CONST DW_CHILDREN_yes, 1
CONST DW_CHILDREN_no, 0


.if 0
/* DWARF form encodings.  */
enum
  {
    DW_FORM_block2 = 0x03,
    DW_FORM_block4 = 0x04,
    DW_FORM_data8 = 0x07,
    DW_FORM_string = 0x08,
    DW_FORM_block = 0x09,
    DW_FORM_block1 = 0x0a,
    DW_FORM_data1 = 0x0b,
    DW_FORM_flag = 0x0c,
    DW_FORM_sdata = 0x0d,
    DW_FORM_udata = 0x0f,
    DW_FORM_ref_addr = 0x10,
    DW_FORM_ref1 = 0x11,
    DW_FORM_ref2 = 0x12,
    DW_FORM_ref8 = 0x14,
    DW_FORM_ref_udata = 0x15,
    DW_FORM_indirect = 0x16,
    DW_FORM_sec_offset = 0x17,

    DW_FORM_strx = 0x1a,
    DW_FORM_addrx = 0x1b,
    DW_FORM_ref_sup4 = 0x1c,
    DW_FORM_strp_sup = 0x1d,
    DW_FORM_data16 = 0x1e,
    DW_FORM_line_strp = 0x1f,
    DW_FORM_ref_sig8 = 0x20,
    DW_FORM_loclistx = 0x22,
    DW_FORM_rnglistx = 0x23,
    DW_FORM_ref_sup8 = 0x24,
    DW_FORM_strx1 = 0x25,
    DW_FORM_strx2 = 0x26,
    DW_FORM_strx3 = 0x27,
    DW_FORM_strx4 = 0x28,
    DW_FORM_addrx1 = 0x29,
    DW_FORM_addrx2 = 0x2a,
    DW_FORM_addrx3 = 0x2b,
    DW_FORM_addrx4 = 0x2c,
    /* GNU Debug Fission extensions.  */
    DW_FORM_GNU_addr_index = 0x1f01,
    DW_FORM_GNU_str_index = 0x1f02,
    DW_FORM_GNU_ref_alt = 0x1f20, /* offset in alternate .debuginfo.  */
    DW_FORM_GNU_strp_alt = 0x1f21 /* offset in alternate .debug_str. */
  };
.endif




########### opcodes

CONST DW_OP_addr, 0x03
CONST DW_OP_deref, 0x06
CONST DW_OP_const1u, 0x08	;/* Unsigned 1-byte constant.  */
CONST DW_OP_const1s, 0x09	;/* Signed 1-byte constant.  */
CONST DW_OP_const2u, 0x0a	;/* Unsigned 2-byte constant.  */
CONST DW_OP_const2s, 0x0b	;/* Signed 2-byte constant.  */
CONST DW_OP_const4u, 0x0c	;/* Unsigned 4-byte constant.  */
CONST DW_OP_const4s, 0x0d	;/* Signed 4-byte constant.  */
CONST DW_OP_const8u, 0x0e	 ;/* Unsigned 8-byte constant.  */
CONST DW_OP_const8s, 0x0f	;/* Signed 8-byte constant.  */
CONST DW_OP_constu, 0x10 	;/* Unsigned LEB128 constant.  */
CONST DW_OP_consts, 0x11	;/* Signed LEB128 constant.  */
.if 0

/* DWARF location operation encodings.  */
enum
  {

    DW_OP_dup = 0x12,
    DW_OP_drop = 0x13,
    DW_OP_over = 0x14,
    DW_OP_pick = 0x15,		/* 1-byte stack index.  */
    DW_OP_swap = 0x16,
    DW_OP_rot = 0x17,
    DW_OP_xderef = 0x18,
    DW_OP_abs = 0x19,
    DW_OP_and = 0x1a,
    DW_OP_div = 0x1b,
    DW_OP_minus = 0x1c,
    DW_OP_mod = 0x1d,
    DW_OP_mul = 0x1e,
    DW_OP_neg = 0x1f,
    DW_OP_not = 0x20,
    DW_OP_or = 0x21,
    DW_OP_plus = 0x22,
    DW_OP_plus_uconst = 0x23,	/* Unsigned LEB128 addend.  */
    DW_OP_shl = 0x24,
    DW_OP_shr = 0x25,
    DW_OP_shra = 0x26,
    DW_OP_xor = 0x27,
    DW_OP_bra = 0x28,		/* Signed 2-byte constant.  */
    DW_OP_eq = 0x29,
    DW_OP_ge = 0x2a,
    DW_OP_gt = 0x2b,
    DW_OP_le = 0x2c,
    DW_OP_lt = 0x2d,
    DW_OP_ne = 0x2e,
    DW_OP_skip = 0x2f,		/* Signed 2-byte constant.  */
    DW_OP_lit0 = 0x30,		/* Literal 0.  */
    DW_OP_lit1 = 0x31,		/* Literal 1.  */
    DW_OP_lit2 = 0x32,		/* Literal 2.  */
    DW_OP_lit3 = 0x33,		/* Literal 3.  */
    DW_OP_lit4 = 0x34,		/* Literal 4.  */
    DW_OP_lit5 = 0x35,		/* Literal 5.  */
    DW_OP_lit6 = 0x36,		/* Literal 6.  */
    DW_OP_lit7 = 0x37,		/* Literal 7.  */
    DW_OP_lit8 = 0x38,		/* Literal 8.  */
    DW_OP_lit9 = 0x39,		/* Literal 9.  */
    DW_OP_lit10 = 0x3a,		/* Literal 10.  */
    DW_OP_lit11 = 0x3b,		/* Literal 11.  */
    DW_OP_lit12 = 0x3c,		/* Literal 12.  */
    DW_OP_lit13 = 0x3d,		/* Literal 13.  */
    DW_OP_lit14 = 0x3e,		/* Literal 14.  */
    DW_OP_lit15 = 0x3f,		/* Literal 15.  */
    DW_OP_lit16 = 0x40,		/* Literal 16.  */
    DW_OP_lit17 = 0x41,		/* Literal 17.  */
    DW_OP_lit18 = 0x42,		/* Literal 18.  */
    DW_OP_lit19 = 0x43,		/* Literal 19.  */
    DW_OP_lit20 = 0x44,		/* Literal 20.  */
    DW_OP_lit21 = 0x45,		/* Literal 21.  */
    DW_OP_lit22 = 0x46,		/* Literal 22.  */
    DW_OP_lit23 = 0x47,		/* Literal 23.  */
    DW_OP_lit24 = 0x48,		/* Literal 24.  */
    DW_OP_lit25 = 0x49,		/* Literal 25.  */
    DW_OP_lit26 = 0x4a,		/* Literal 26.  */
    DW_OP_lit27 = 0x4b,		/* Literal 27.  */
    DW_OP_lit28 = 0x4c,		/* Literal 28.  */
    DW_OP_lit29 = 0x4d,		/* Literal 29.  */
    DW_OP_lit30 = 0x4e,		/* Literal 30.  */
    DW_OP_lit31 = 0x4f,		/* Literal 31.  */
    DW_OP_reg0 = 0x50,		/* Register 0.  */
    DW_OP_reg1 = 0x51,		/* Register 1.  */
    DW_OP_reg2 = 0x52,		/* Register 2.  */
    DW_OP_reg3 = 0x53,		/* Register 3.  */
    DW_OP_reg4 = 0x54,		/* Register 4.  */
    DW_OP_reg5 = 0x55,		/* Register 5.  */
    DW_OP_reg6 = 0x56,		/* Register 6.  */
    DW_OP_reg7 = 0x57,		/* Register 7.  */
    DW_OP_reg8 = 0x58,		/* Register 8.  */
    DW_OP_reg9 = 0x59,		/* Register 9.  */
    DW_OP_reg10 = 0x5a,		/* Register 10.  */
    DW_OP_reg11 = 0x5b,		/* Register 11.  */
    DW_OP_reg12 = 0x5c,		/* Register 12.  */
    DW_OP_reg13 = 0x5d,		/* Register 13.  */
    DW_OP_reg14 = 0x5e,		/* Register 14.  */
    DW_OP_reg15 = 0x5f,		/* Register 15.  */
    DW_OP_reg16 = 0x60,		/* Register 16.  */
    DW_OP_reg17 = 0x61,		/* Register 17.  */
    DW_OP_reg18 = 0x62,		/* Register 18.  */
    DW_OP_reg19 = 0x63,		/* Register 19.  */
    DW_OP_reg20 = 0x64,		/* Register 20.  */
    DW_OP_reg21 = 0x65,		/* Register 21.  */
    DW_OP_reg22 = 0x66,		/* Register 22.  */
    DW_OP_reg23 = 0x67,		/* Register 24.  */
    DW_OP_reg24 = 0x68,		/* Register 24.  */
    DW_OP_reg25 = 0x69,		/* Register 25.  */
    DW_OP_reg26 = 0x6a,		/* Register 26.  */
    DW_OP_reg27 = 0x6b,		/* Register 27.  */
    DW_OP_reg28 = 0x6c,		/* Register 28.  */
    DW_OP_reg29 = 0x6d,		/* Register 29.  */
    DW_OP_reg30 = 0x6e,		/* Register 30.  */
    DW_OP_reg31 = 0x6f,		/* Register 31.  */
    DW_OP_breg0 = 0x70,		/* Base register 0.  */
    DW_OP_breg1 = 0x71,		/* Base register 1.  */
    DW_OP_breg2 = 0x72,		/* Base register 2.  */
    DW_OP_breg3 = 0x73,		/* Base register 3.  */
    DW_OP_breg4 = 0x74,		/* Base register 4.  */
    DW_OP_breg5 = 0x75,		/* Base register 5.  */
    DW_OP_breg6 = 0x76,		/* Base register 6.  */
    DW_OP_breg7 = 0x77,		/* Base register 7.  */
    DW_OP_breg8 = 0x78,		/* Base register 8.  */
    DW_OP_breg9 = 0x79,		/* Base register 9.  */
    DW_OP_breg10 = 0x7a,	/* Base register 10.  */
    DW_OP_breg11 = 0x7b,	/* Base register 11.  */
    DW_OP_breg12 = 0x7c,	/* Base register 12.  */
    DW_OP_breg13 = 0x7d,	/* Base register 13.  */
    DW_OP_breg14 = 0x7e,	/* Base register 14.  */
    DW_OP_breg15 = 0x7f,	/* Base register 15.  */
    DW_OP_breg16 = 0x80,	/* Base register 16.  */
    DW_OP_breg17 = 0x81,	/* Base register 17.  */
    DW_OP_breg18 = 0x82,	/* Base register 18.  */
    DW_OP_breg19 = 0x83,	/* Base register 19.  */
    DW_OP_breg20 = 0x84,	/* Base register 20.  */
    DW_OP_breg21 = 0x85,	/* Base register 21.  */
    DW_OP_breg22 = 0x86,	/* Base register 22.  */
    DW_OP_breg23 = 0x87,	/* Base register 23.  */
    DW_OP_breg24 = 0x88,	/* Base register 24.  */
    DW_OP_breg25 = 0x89,	/* Base register 25.  */
    DW_OP_breg26 = 0x8a,	/* Base register 26.  */
    DW_OP_breg27 = 0x8b,	/* Base register 27.  */
    DW_OP_breg28 = 0x8c,	/* Base register 28.  */
    DW_OP_breg29 = 0x8d,	/* Base register 29.  */
    DW_OP_breg30 = 0x8e,	/* Base register 30.  */
    DW_OP_breg31 = 0x8f,	/* Base register 31.  */
    DW_OP_regx = 0x90,		/* Unsigned LEB128 register.  */
    DW_OP_fbreg = 0x91,		/* Signed LEB128 offset.  */
    DW_OP_bregx = 0x92,		/* ULEB128 register followed by SLEB128 off. */
    DW_OP_piece = 0x93,		/* ULEB128 size of piece addressed. */
    DW_OP_deref_size = 0x94,	/* 1-byte size of data retrieved.  */
    DW_OP_xderef_size = 0x95,	/* 1-byte size of data retrieved.  */
    DW_OP_nop = 0x96,
    DW_OP_push_object_address = 0x97,
    DW_OP_call2 = 0x98,
    DW_OP_call4 = 0x99,
    DW_OP_call_ref = 0x9a,
    DW_OP_form_tls_address = 0x9b,/* TLS offset to address in current thread */
    DW_OP_call_frame_cfa = 0x9c,/* CFA as determined by CFI.  */
    DW_OP_bit_piece = 0x9d,	/* ULEB128 size and ULEB128 offset in bits.  */
    DW_OP_implicit_value = 0x9e, /* DW_FORM_block follows opcode.  */
    DW_OP_stack_value = 0x9f,	 /* No operands, special like DW_OP_piece.  */
    DW_OP_implicit_pointer = 0xa0,
    DW_OP_addrx = 0xa1,
    DW_OP_constx = 0xa2,
    DW_OP_entry_value = 0xa3,
    DW_OP_const_type = 0xa4,
    DW_OP_regval_type = 0xa5,
    DW_OP_deref_type = 0xa6,
    DW_OP_xderef_type = 0xa7,
    DW_OP_convert = 0xa8,
    DW_OP_reinterpret = 0xa9,
    /* GNU extensions.  */
    DW_OP_GNU_push_tls_address = 0xe0,
    DW_OP_GNU_uninit = 0xf0,
    DW_OP_GNU_encoded_addr = 0xf1,
    DW_OP_GNU_implicit_pointer = 0xf2,
    DW_OP_GNU_entry_value = 0xf3,
    DW_OP_GNU_const_type = 0xf4,
    DW_OP_GNU_regval_type = 0xf5,
    DW_OP_GNU_deref_type = 0xf6,
    DW_OP_GNU_convert = 0xf7,
    DW_OP_GNU_reinterpret = 0xf9,
    DW_OP_GNU_parameter_ref = 0xfa,
    /* GNU Debug Fission extensions.  */
    DW_OP_GNU_addr_index = 0xfb,
    DW_OP_GNU_const_index = 0xfc,
    DW_OP_GNU_variable_value = 0xfd,
    DW_OP_lo_user = 0xe0,	/* Implementation-defined range start.  */
    DW_OP_hi_user = 0xff	/* Implementation-defined range end.  */
  };
.endif
