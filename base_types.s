.include "dwarf_consts.inc"
.include "dwarf_macros.inc"

BEGIN_DWARF


	# Types used by Ghidra
	# Note: void isn't actually a valid encoding
	# BASE_TYPE undefined1, void, 1
	# BASE_TYPE undefined2, void, 2
	# BASE_TYPE undefined4, void, 4
	# BASE_TYPE undefined8, void, 8


	BASE_TYPE char, signed, 1
	BASE_TYPE uchar, unsigned, 1

	BASE_TYPE byte, signed, 1
	BASE_TYPE short, signed, 2
	BASE_TYPE int, signed, 4
	BASE_TYPE long, signed, 4
	BASE_TYPE longlong, signed 8

	BASE_TYPE ubyte, unsigned, 1
	BASE_TYPE ushort, unsigned, 1
	BASE_TYPE uint, unsigned, 4
	BASE_TYPE ulong, unsigned, 4
	BASE_TYPE ulonglong, unsigned, 8



	TYPEDEF byte, int8_t
	TYPEDEF short, int16_t
	TYPEDEF int, int32_t
	TYPEDEF longlong, int64_t

	TYPEDEF ubyte, uint8_t
	TYPEDEF ushort, uint16_t
	TYPEDEF uint, uint32_t
	TYPEDEF ulonglong, uint64_t


	#TODO this is wrong, but a placeholder until i implement floats properly
	TYPEDEF uint32_t, float
	TYPEDEF uint64_t, double

	# void pointer is special and cant use regular pointer syntax since it doesnt have a base type
	BEGIN_TYPE_INFO p_void
		_assert_defined .L_abbr_voidptr
		.uleb128 .L_abbr_voidptr
	END_TYPE_INFO p_void

END_DWARF
