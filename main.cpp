#include "FileIO.h"
#include "ShoppingMall.h"

#include "ProductManager.h"

int main()
{
	int menuLevel1 = 0, menuLevel2 = 0;

	FileIO* fio = FileIO::getInstance();
	ShoppingMall shoppingMall = ShoppingMall();

	//ProductManager::getInstance()->createProduct("hw", "asdf", "kk", 100, 5);

	while (true)
	{
		int ret = fio->scanf("%d %d", &menuLevel1, &menuLevel2);
		if (ret == EOF)
		{
			break;
		}

		shoppingMall.run(menuLevel1, menuLevel2);
	}

	return 0;
}