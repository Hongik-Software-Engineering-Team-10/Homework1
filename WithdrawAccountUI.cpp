#include "WithdrawAccountUI.h"

void WithdrawAccountUI::startInterface()
{
	FileIO* fio = FileIO::getInstance();
	fio->printf("1.2. È¸¿øÅ»Åð\n");
}

void WithdrawAccountUI::showResult(const char* output)
{
	FileIO* fio = FileIO::getInstance();
	fio->printf("%s\n", output);
}
