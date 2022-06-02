#include "SearchProductInfoUI.h"

void SearchProductInfoUI::startInterface(const char* input)
{
	FileIO* fio = FileIO::getInstance();
	fio->printf("4.1. 상품 정보 검색\n");
	fio->scanf("%s", input);
}

void SearchProductInfoUI::updateInterface(const char* output)
{
	FileIO* fio = FileIO::getInstance();
	fio->printf("%s\n", output);
}