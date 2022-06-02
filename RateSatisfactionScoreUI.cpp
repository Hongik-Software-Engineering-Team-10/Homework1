#include "RateSatisfactionScoreUI.h"

void RateSatisfactionScoreUI::startInterface(const char* inputString, int& inputInteger)
{
	FileIO* fio = FileIO::getInstance();
	fio->printf("4.4. 상품 정보 검색\n");
	fio->scanf("%s %d", inputString, &inputInteger);
}

void RateSatisfactionScoreUI::updateInterface(const char* outputString)
{
	FileIO* fio = FileIO::getInstance();
	fio->printf("%s\n", outputString);
}
