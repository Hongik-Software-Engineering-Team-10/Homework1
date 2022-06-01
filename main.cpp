#include "FileIO.h"
#include "ShoppingMall.h"

int main()
{
	int menuLevel1 = 0, menuLevel2 = 0;
	bool isRunning = true;

	FileIO* fio = FileIO::getInstance();
	ShoppingMall shoppingMall = ShoppingMall();

	while (isRunning)
	{
		fio->scanf("%d %d", &menuLevel1, &menuLevel2);

		if (menuLevel1 == 6)
		{
			isRunning = false;
		}
		else
		{
			shoppingMall.run(menuLevel1, menuLevel2);
		}
	}

	fio->close();
	ProductManager::getInstance()->close();

	return 0;
}