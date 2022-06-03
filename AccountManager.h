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

	bool signAccount(const char* ID, const char* password);
	void createAccount(const char* name, unsigned int SSN, const char* ID, const char* password);
	void deleteAccount(const char* ID);
	void purchaseProduct(const char* ID, const char* product);
	std::vector<std::string> getPurchasedList(const char* ID);
	void close();
};
