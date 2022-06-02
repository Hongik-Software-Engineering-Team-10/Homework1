#include "AccountManager.h"

AccountManager::AccountManager() {}
AccountManager::~AccountManager() {}

AccountManager* AccountManager::instance = nullptr;

AccountManager* AccountManager::getInstance()
{
	if (instance == nullptr)
	{
		instance = new AccountManager();
	}
	return instance;
}

bool AccountManager::findAccount(const char* ID, const char* password)
{
	for (const Account& account : accountList)
	{
		if (strcmp(ID, account.ID) == 0 && strcmp(password, account.password) == 0)
		{
			return true;
		}
	}

	return false;
}

void AccountManager::createAccount(const char* name, unsigned int SSN, const char* ID, const char* password)
{
	Account account;
	
	strcpy(account.name, name);
	account.SSN = SSN;
	strcpy(account.ID, ID);
	strcpy(account.password, password);
	
	accountList.push_back(account);
}
void AccountManager::deleteAccount(const char* ID)
{
	for (int i = 0; i < accountList.size(); i++)
	{
		if (strcmp(ID, accountList[i].ID) == 0)
		{
			accountList.erase(accountList.begin() + i);
			return;
		}
	}
}

void AccountManager::close()
{
	delete instance;
	instance = nullptr;
}