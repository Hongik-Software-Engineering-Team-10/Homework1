#include "SellDoneListUI.h"

void SellDoneListUI::startInterface()
{
    FileIO* fio = FileIO::getInstance();
	fio->printf("3.3. �Ǹ� �Ϸ� ��ǰ ��ȸ\n");
}
void SellDoneListUI::showResult(const char* output)
{
	FileIO* fio = FileIO::getInstance();
	fio->printf("%s\n", output);
}
