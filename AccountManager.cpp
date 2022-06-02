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

std::vector<Account> AccountManager::getAccountList()
{
	return accountList;
}

Account AccountManager::getAccount(const char* id)
{
	for (const Account& account : accountList)
	{
		if (strcmp(id, account.ID) == 0)
		{
			return account;
		}
	}

	return Account();
}

void AccountManager::setAccount(const Account& newAccount)
{
	for (Account& account : accountList)
	{
		if (strcmp(newAccount.ID, account.ID) == 0)
		{
			account = newAccount;
			return;
		}
	}

	createAccount(newAccount);
}

void AccountManager::createAccount(const Account& newAccount)
{
	accountList.push_back(newAccount);
}

void AccountManager::createAccount(const char* name, unsigned int SSN, const char* ID, const char* password)
{
	Account account;
	
	strcpy(account.name, name);
	account.SSN = SSN;
	strcpy(account.ID, ID);
	strcpy(account.password, password);
	
	createAccount(account);
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