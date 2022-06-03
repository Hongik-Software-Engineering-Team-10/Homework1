#include "StatsUI.h"

void StatsUI::startInterface()
{
	FileIO* fio = FileIO::getInstance();
	fio->printf("5.1. 판매 상품 통계\n");
}

void StatsUI::showResult(const char* output) {}