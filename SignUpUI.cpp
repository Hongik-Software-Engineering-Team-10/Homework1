#include "SignUpUI.h"

void SignUpUI::startInterface(const char* inputName, unsigned int& inputSSN, const char* inputID, const char* inputPW)
{
	FileIO* fio = FileIO::getInstance();
	fio->printf("1.1. 회원가입\n");
	fio->scanf("%s %d %s %s ", inputName, &inputSSN, inputID, inputPW);
}

void SignUpUI::showResult(const char* output)
{
	FileIO* fio = FileIO::getInstance();
	fio->printf("%s\n", output);
}