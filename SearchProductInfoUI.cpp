#include "SearchProductInfoUI.h"

void SearchProductInfoUI::startInterface(const char* input)
{
	FileIO* fio = FileIO::getInstance();
	fio->printf("4.1. ��ǰ ���� �˻�\n");
	fio->scanf("%s", input);
}

void SearchProductInfoUI::showResult(const char* output)
{
	FileIO* fio = FileIO::getInstance();
	fio->printf("%s\n", output);
}
