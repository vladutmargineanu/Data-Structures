/**
 * LabSD 5
 * lab5.cpp
 * Purpose: Driver program to run lab5 tasks.
 *
 * @authors Razvan Radoi, Alex Selea
 * @changes Ioana Stefan
 */

#include <fstream>
#include <iostream>

#include "hash_functions.h"
#include "hashtable.h"
#include "users_table.h"

void checkTask2() {

#ifdef DEBUG
    std::ostream& out = std::cout;
#else
    std::ofstream file;
    file.open("Out/Lab5/task2.out");
    std::ostream& out = file;
#endif

    Hashtable<int, int> my_table(10, &hashingFunction);

    my_table.put(34588, 1);
    my_table.put(3458, 2);
    my_table.put(8345, 3);
    my_table.put(13459, 4);

    int a, b, c, d;
    a = my_table.get(34588);  // 1
    b = my_table.get(3458);  // 2
    c = my_table.get(8345);  // 3
    d = my_table.get(13459);  // 4

    out << a << " " << b << " " << c << " " << d << std::endl;

    bool check1 = my_table.has_key(3458); //exista
    bool check2 = my_table.has_key(1001); //nu exista
    out << check1 << " " << check2 << std::endl;

    my_table.remove(8345);  // remove 3
    my_table.remove(1111);  // nothing to remove
    my_table.remove(13459);  // remove 4

    check1 = my_table.has_key(34588);  // true
    check2 = my_table.has_key(8345);  // false

    out << check1 << " " << check2 << std::endl;

#ifndef DEBUG
    file.close();
#endif

}

void checkTask3() {

#ifdef DEBUG
    std::ostream& out = std::cout;
#else
    std::ofstream file;
    file.open("Out/Lab5/task3.out");
    std::ostream& out = file;
#endif

    UsersTable my_table(10, &charHashingFunction);

    out << my_table.signup("Razvan", "PATRONUL") << std::endl;
    out << my_table.signup("Alex", "420blazeit") << std::endl;
    out << my_table.signup("Razvan", "@razvanra2peinstagram") << std::endl;

    out << my_table.login("Razvan", "PATRONUL") << std::endl;
    out << my_table.login("Alex", "1234") << std::endl;

    out << my_table.logout("Razvan") << std::endl;
    out << my_table.logout("Andrei") << std::endl;

    out << my_table.change_password("Alex", "420blazeit", "garda") << std::endl;
    out << my_table.change_password("Razvan", "PATRONUL1111", "Maverick") << std::endl;

#ifndef DEBUG
    file.close();
#endif

}

void checkBonus() {

#ifdef DEBUG
    std::ostream& out = std::cout;
#else
    std::ofstream file;
    file.open("Out/Lab5/bonus1.out");
    std::ostream& out = file;
#endif

    Hashtable<int, int> my_table(5, &hashingFunction);

    out << my_table.get_capacity() << std::endl;
    my_table.put(34588, 1);
    my_table.put(3458, 2);
    my_table.put(8345, 3);
    my_table.put(13459, 4);
    out << my_table.get_capacity() << std::endl;

#ifndef DEBUG
    file.close();
#endif

}

int main() {
    checkTask2();
    checkTask3();
    checkBonus();

    return 0;
}
