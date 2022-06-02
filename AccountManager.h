#pragma once
#include <vector>
#include "Account.h"

class AccountManager
{
private:
	AccountManager();
	~AccountManager();

	static AccountManager* instance;

	std::vector<Account> accountList;

public:
	static AccountManager* getInstance();

	std::vector<Account> getAccountList();
	Account getAccount(const char* name);
	void setAccount(const Account& newProduct);
	void createAccount(const Account& newaccount);
	void createAccount(const char* name, unsigned int SSN, const char* ID, const char* password);
	void deleteAccount(const char* ID);
	void close();
};

