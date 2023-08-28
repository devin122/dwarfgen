
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

	.bss  IMAGE_LOAD_ADDR :  AT(IMAGE_LOAD_ADDR)
	{

		*(.text)
		*(.data)
		*(.bss)

		/* TODO: parameterize segment size */
		. =  . + 0x640ec ;
/*		       0x800540ec*/

    } :data

	/DISCARD/ :
	{
		*(.ARM.attributes)
	}

}

