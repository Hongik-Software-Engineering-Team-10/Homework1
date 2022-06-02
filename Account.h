#pragma once
#include <cstring>
#define MAX_STRING	32

class Account
{
private:
	// char purchasedProducts[MAX_STRING];

public:
	Account();
	Account(const Account& account);
	~Account();

	char name[MAX_STRING];
	unsigned int SSN;
	char ID[MAX_STRING];
	char password[MAX_STRING];

	Account& operator=(const Account& account);
};

