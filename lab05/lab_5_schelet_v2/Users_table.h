/*#ifndef __HASHTABLE__H
#define __HASHTABLE__H
#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <string>
#include <time.h>
struct user_details {
    std::string name;
    std::string password;
    bool logged_in;
};

class UsersTable {
private:
  std::list<user_details> * H; // *H pointer la buckets de tip arraylist
  int HMAX; // nr de bucketuri
  unsigned int (*hash)(std::string); // pointer la o functie hash
public:
    UsersTable(int hmax, unsigned int (*h)(std::string)) {
      // TODO: constructor, unde *h e functia de hash
      this->HMAX = hmax;
      this->hash = h;
      H = new std::list<user_details>[HMAX];
    }

    ~UsersTable() {
      // TODO: destructor
      delete[] H;
    }

    void signup(std::string name, std::string password) {
        int hashValue = hash(name) % HMAX;
        struct user_details newUser;
        newUser.password = password;
        newUser.name = name;

        bool found = false;
        typename std::list<user_details>::iterator i;
        for(i = H[hashValue].begin(); i != H[hashValue].end(); i++) {
            if (i->name == name) {
                std::cout << "User " << name << " already added" << std::endl;
                found = true;
            }
        }
        if(!found) {
            H[hashValue].push_back(newUser);
            std::cout << "User " << name << " successfully added" << std::endl;
        }
    }

    void login(std::string name, std::string password) {
        int hashValue = hash(name) % HMAX;
        typename std::list<user_details>::iterator i;
        for(i = H[hashValue].begin(); i != H[hashValue].end(); i++) {
            if (i->name == name && i->password == password) {
                i->logged_in = true;
                std::cout << "User " << name << " logged in successfully" << std::endl;
                return;
            }
        }
        std::cout << "Username/Passowrd incorrect" << std::endl;
    }

    void logout(std::string name) {
        int hashValue = hash(name) % HMAX;
        typename std::list<user_details>::iterator i;
        for(i = H[hashValue].begin(); i != H[hashValue].end(); i++) {
            if (i->name == name) {
                i->logged_in = false;
                std::cout << "User " << name << " logged out" << std::endl;
                return;
            }
        }
        std::cout << "User does not exist" << std::endl;
    }

    void change_password(std::string name, std::string oldPass, std::string newPass) {
        int hashValue = hash(name) % HMAX;
        typename std::list<user_details>::iterator i;
        for(i = H[hashValue].begin(); i != H[hashValue].end(); i++) {
            if(i->name == name) {
                if(i->password == oldPass) {
                    i->password = newPass;
                    std::cout << "Password changed for user " << name << std::endl;
                } else {
                    std::cout << "Could not change password" << std::endl;
                }
            }
        }
    }
};
#endif
