#include "PurchaseHistoryUI.h"

void PurchaseHistoryUI::startInterface()
{
	FileIO* fio = FileIO::getInstance();
	fio->printf("4.3. 상품 구매 내역 조회\n");
}

void PurchaseHistoryUI::showResult(const char* output)
{
	FileIO* fio = FileIO::getInstance();
	fio->printf("%s\n", output);
}
