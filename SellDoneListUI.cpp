#include "SellDoneListUI.h"

void SellDoneListUI::startInterface()
{
    FileIO* fio = FileIO::getInstance();
	fio->printf("3.3. 판매 완료 상품 조회\n");
}
void SellDoneListUI::showResult(const char* output)
{
	FileIO* fio = FileIO::getInstance();
	fio->printf("%s\n", output);
}
