#include "SignOutUI.h"

void SignOutUI::startInterface()
{
	FileIO* fio = FileIO::getInstance();
	fio->printf("2.2. ·Î±×¾Æ¿ô\n");
}

void SignOutUI::showResult(const char* output)
{
	FileIO* fio = FileIO::getInstance();
	fio->printf("%s\n", output);
}
