#include "PostNewProductInfoUI.h"

void PostNewProductInfoUI::startInterface(const char* ip1, const char* ip2, unsigned int& int1, unsigned int& int2) 
{
    FileIO* fio = FileIO::getInstance();
	fio->printf("3.1. 판매 의류 등록\n");
	fio->scanf("%s %s %d %d", ip1, ip2, &int1, &int2);
}
void PostNewProductInfoUI::showResult(const char* output)
{
	FileIO* fio = FileIO::getInstance();
	fio->printf("%s\n", output);
}
