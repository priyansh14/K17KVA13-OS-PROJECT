void input()
{
	LPCWSTR fname2 = L"CPU_BURST.txt";
hAppend = CreateFile(fname2, // open CPU_BURST.txt

GENERIC_WRITE, // Flag which means that file is opened for writing 

0, // This indicates that the file cant be shared.This is the security descriptor.

NULL, // Security Descriptor

OPEN_ALWAYS, // Create if not open

FILE_ATTRIBUTE_NORMAL, // normal file

NULL);
}
