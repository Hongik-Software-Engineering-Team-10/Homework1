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
	Account account = getAccount(ID);

	memset(account.name, NULL, MAX_STRING);
	account.SSN = 0;
	memset(account.ID, NULL, MAX_STRING);
	memset(account.password, NULL, MAX_STRING);
	

	delete &account;
}

void AccountManager::close()
{
	delete instance;
	instance = nullptr;
}