#include "SignInUI.h"

void SignInUI::startInterface(const char* inputID, const char* inputPW)
{
	FileIO* fio = FileIO::getInstance();
	fio->printf("2.1. �α���\n");
	fio->scanf("%s %s", inputID, inputPW);
}

void SignInUI::showResult(const char* output)
{
	FileIO* fio = FileIO::getInstance();
	fio->printf("%s\n", output);
}
