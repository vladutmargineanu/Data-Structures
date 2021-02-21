/**
 * LabSD 5
 * users_table.h
 * Purpose: Skeleton code for Users Table in exercise 3.
 *
 * @authors Razvan Radoi, Alex Selea
 * @changes Ioana Stefan
 */

#ifndef __USERS_TABLE__H
#define __USERS_TABLE__H
#include <iostream>
#include <iterator>
#include <list>
#include <string>

struct user_details {
	std::string name;
	std::string password;
	bool logged_in;
};

class UsersTable {
private:
	std::list<user_details> * H; // pointer to buckets
	int HMAX; // number of buckets
	unsigned int (*hash)(std::string); // pointer to hash function

public:
	UsersTable(int hmax, unsigned int (*h)(std::string)) {
		// TODO 3: initializations, use *h as hash function
	}

	~UsersTable() {
		// TODO 3: free memory
	}

	std::string signup(std::string name, std::string password) {
		// TODO 3
		return "Not implemented yet";
	}

	std::string login(std::string name, std::string password) {
		// TODO 3
		return "Not implemented yet";
	}

	std::string logout(std::string name) {
		// TODO 3
		return "Not implemented yet";
	}

	std::string change_password(std::string name, std::string oldPass, std::string newPass) {
		// TODO 3
		return "Not implemented yet";
	}
};

#endif // __USERS_TABLE__H
