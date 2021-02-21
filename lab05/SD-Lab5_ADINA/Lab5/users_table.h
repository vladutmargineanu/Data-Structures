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

	user_details(std::string n, std::string pass, bool log) :
		name(n), password(pass), logged_in(log) {}
};

class UsersTable {
private:
	std::list<user_details> * H; // pointer to buckets
	int HMAX; // number of buckets
	unsigned int (*hash)(std::string); // pointer to hash function

public:
	UsersTable(int hmax, unsigned int (*h)(std::string)) {
		// TODO 3: initializations, use *h as hash function
		HMAX = hmax;
		hash = h;
		H = new std::list<user_details>[HMAX];
	}

	~UsersTable() {
		// TODO 3: free memory
		delete [] H;
	}

	std::string signup(std::string name, std::string password) {
		// TODO 3
		std::string message = "User ";
		int index = hash(name) % HMAX;
		std::list<user_details>::iterator it;

		message += name;

		for (it = H[index].begin(); it != H[index].end(); ++it) {
			if (it->name == name) {
				message += " already added";
				return message;
			} 
		}

		H[index].push_back(user_details(name, password, false));
		message += " successfully added";

		return message;
	}

	std::string login(std::string name, std::string password) {
		// TODO 3
		std::string message = "User ";
		int index = hash(name) % HMAX;
		std::list<user_details>::iterator it;

		message += name;

		for (it = H[index].begin(); it != H[index].end(); ++it) {
			if (it->name == name && it->password.compare(password) == 0) {
				message += " logged in successfully";
				it->logged_in = true;
				return message;
			} 
		}

		return "Username/Password incorrect";
	}

	std::string logout(std::string name) {
		// TODO 3
		int index = hash(name) % HMAX;
		std::string message = "User ";
		std::list<user_details>::iterator it;

		message += name;

		for (it = H[index].begin(); it != H[index].end(); ++it) {
			if (it->name == name) {
				message += " logged out";
				it->logged_in = false;
				return message;
			} 
		}

		return "User does not exist";
	}

	std::string change_password(std::string name, std::string oldPass, std::string newPass) {
		// TODO 3
		std::string message = "Password changed for user ";
		int index = hash(name) % HMAX;
		std::list<user_details>::iterator it;

		message += name;

		for (it = H[index].begin(); it != H[index].end(); ++it) {
			if (it->name == name) {
				if (it->password.compare(oldPass) == 0) {
					it->password = newPass;
					return message;
				} else {
					return "Could not change password";
				}
			} 
		}

		return "Could not change password";
	}
};

#endif // __USERS_TABLE__H
