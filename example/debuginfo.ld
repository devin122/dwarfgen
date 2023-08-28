
/*ENTRY(_start)*/
PHDRS
{
	data PT_LOAD;
}

SECTIONS
{

	.debug_abbr :
	{
		*(.debug_abbr_header)
		*(.debug_abbr)
		*(.debug_abbr_footer)
	}

	.debug_info :
	{
		debug_info_base = .;
		*(.debug_info_header)
		*(.debug_info)
		*(.type_info_outofline)
		*(.debug_info_footer)
	}


	.bss  0x80000000 :  AT(0x80000000)
	{

		 *(.text)
		*(.data)
		*(.bss)

		. =  . + 0x640ec ;
/*		       0x800540ec*/

    } :data

		/DISCARD/ :
	{
		*(.ARM.attributes)
	}

}

