#pragma once
#include <vector>
#include <string>
#include <cstring>
#define MAX_STRING	32

class Account
{
public:
	Account();
	Account(const Account& account);
	~Account();

	char name[MAX_STRING];
	unsigned int SSN;
	char ID[MAX_STRING];
	char password[MAX_STRING];
	std::vector<std::string> purchasedProducts;

	Account& operator=(const Account& account);
};
