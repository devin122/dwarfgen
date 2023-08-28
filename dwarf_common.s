.include "dwarf_consts.inc"
.include "dwarf_macros.inc"

# generate abbreviation headers
#.section	.debug_abbrev_header,"",%progbits
.section .debug_abbrev,"",%progbits
start_abbreviations:

# common abbreviations
BEGIN_ABBREVIATIONS

    BEGIN_ABBR abbrnum=.L_abbr_cu, type=compile_unit, children=yes
        ATTRIBUTE type=name, form=string
    END_ABBR

    BEGIN_ABBR abbrnum=.L_abbr_base_type, type=base_type
        ATTRIBUTE name, string
        ATTRIBUTE encoding, data1
        ATTRIBUTE byte_size, data1
    END_ABBR

    BEGIN_ABBR abbrnum=.L_abbr_typedef,  type=typedef
        ATTRIBUTE name, string
        ATTRIBUTE type, ref4
    END_ABBR
    

    BEGIN_ABBR .L_abbr_struct, type=structure_type, children=yes
        ATTRIBUTE name, string
        ATTRIBUTE byte_size, data4
    END_ABBR
    
    BEGIN_ABBR .L_abbr_member, type=member
        ATTRIBUTE name, string
        ATTRIBUTE type, ref4
        
        # TODO: handle bitfields properly
        ATTRIBUTE data_member_location, data4
    END_ABBR
	
	BEGIN_ABBR .L_abbr_voidptr, type=pointer_type
    END_ABBR
	
	BEGIN_ABBR .L_abbr_ptr, type=pointer_type
        ATTRIBUTE type, ref4
    END_ABBR
	
	BEGIN_ABBR .L_abbr_array, type=array_type, children=yes
		ATTRIBUTE type, ref4
	END_ABBR
	
	BEGIN_ABBR .L_abbr_subrange, type=subrange_type
		ATTRIBUTE type, ref4
		ATTRIBUTE count, data2
	END_ABBR
	
	BEGIN_ABBR .L_abbr_variable, type=variable
		ATTRIBUTE name, string
		ATTRIBUTE type, ref4
		# TODO: not sure if this encoding is correct
		ATTRIBUTE external, flag_present 
		#maybe DW_AT_declaration?
		ATTRIBUTE location, exprloc
	END_ABBR


END_ABBREVIATIONS

#abbreviation footer
#.section .debug_abbrev_footer,"", %progbits
.uleb128 0,0


#compile unit header/footer
BEGIN_CU "bogus_cu" 
END_CU
