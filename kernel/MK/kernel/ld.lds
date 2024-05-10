OUTPUT_FORMAT("elf64-x86-64","elf64-x86-64","elf64-x86-64")
OUTPUT_ARCH(i386:x86-64)
ENTRY(__start)

SECTIONS
{
.text:
{
	_text=.;
	*(.text)
	_etext=.;
}


}

