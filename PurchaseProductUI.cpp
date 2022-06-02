#include "PurchaseProductUI.h"

void PurchaseProductUI::startInterface()
{
	FileIO* fio = FileIO::getInstance();
	fio->printf("4.2. ��ǰ ����\n");
}

void PurchaseProductUI::updateInterface(const char* output)
{
	FileIO* fio = FileIO::getInstance();
	fio->printf("%s\n", output);
}