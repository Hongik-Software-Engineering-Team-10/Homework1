#include "WithdrawAccountUI.h"

void WithdrawAccountUI::startInterface()
{
	FileIO* fio = FileIO::getInstance();
	fio->printf("1.2. 회원탈퇴\n");
}

void WithdrawAccountUI::showResult(const char* output)
{
	FileIO* fio = FileIO::getInstance();
	fio->printf("%s\n", output);
}
