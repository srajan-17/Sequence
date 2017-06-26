/*
 Siddharth Rajan
 CSC 21200
 
 FILE: main.cpp
 This file serves as a way to test the functionality of the sequence class.
 */

#include <iostream>
#include "sequence.h"
using namespace sid_raj_hw3;
using std::cout;
using std::cin;
using std::endl;

int main() {
    
    // In this section of the code, all the implemented functions are tested.
    
    cout << "Sequence one declared." << "\n";
    sequence one;
    cout << "Size of one: " << one.size() << "\n" << endl;
    
    one.insert(12);
    cout << "one: " << one << endl;
    cout << "Size of one: " << one.size() << "\n" << endl;
    
    one.insert_first(24);
    cout << "one: " << one << endl;
    cout << "Size of one: " << one.size() << "\n" << endl;
    
    one.insert(12);
    cout << "one: " << one << endl;
    cout << "Size of one: " << one.size() << "\n" << endl;
    
    one.insert_at(45, 1);
    cout << "one: " << one << endl;
    cout << "Size of one: " << one.size() << "\n" << endl;
    
    one.insert(12);
    one.insert(56);
    one.insert(24);
    one.insert(12);
    one.insert(45);
    cout << "one: " << one << endl;
    cout << "Size of one: " << one.size() << "\n" << endl;
    
    cout << "Sequence two declared." << "\n";
    sequence two;
    two = one;
    cout << "two: " << two << endl;
    cout << "Size of two: " << two.size() << "\n" << endl;
    
    one += two;
    cout << "one (after one += two): " << one << endl;
    cout << "Size of one: " << one.size() << "\n" << endl;
    
    sequence sum_one_two;
    sum_one_two = one + two;
    cout << "one + two: " << sum_one_two << endl;
    cout << "Size of one + two: " << sum_one_two.size() << "\n" << endl;
    
    cout << "There are " << one.count(56) << " 56s in one." << "\n" << endl;
    
    cout << "Sequence three declared." << endl;
    sequence three;
    three = two;
    
    cout << "two: " << two << endl;
    cout << "three: " << three << "\n" << endl;
    
    cout << "Is one equal to two? (1 = Yes, 0 = No): " << (one == two) << endl;
    cout << "Is two equal to three? (1 = Yes, 0 = No): " << (two == three) << "\n" << endl;
    
    three += 1;
    
    cout << "three (after three += 1): " << three << "\n" << endl;
    
    sequence sum_three_23;
    sum_three_23 = three + 23;
    
    cout << "three + 23: " << sum_three_23 << "\n" << endl;
    
    cout << "two: " << two << endl;
    cout << "Size of two: " << two.size() << "\n" << endl;
    
    cout << "This is two. Now enter some values to insert into two:" << endl;
    cin >> two;
    
    cout << endl;
    
    cout << "two: " << two << endl;
    cout << "Size of two: " << two.size() << "\n" << endl;
    
    two.erase_first(45);
    cout << "two: " << two << endl;
    cout << "Size of two: " << two.size() << "\n" << endl;
    
    two.erase_last(56);
    cout << "two: " << two << endl;
    cout << "Size of two: " << two.size() << "\n" << endl;
    
    two.erase_from(4);
    cout << "two: " << two << endl;
    cout << "Size of two: " << two.size() << "\n" << endl;
    
    two.erase_occurence(12, 3);
    cout << "two: " << two << endl;
    cout << "Size of two: " << two.size() << "\n" << endl;
    
    
    // In this section of the code, the loop with one billion iterations is tested.
    
    /*for (size_t i = 0; i < 1000000000; i++) {
     sequence one;
     one.insert(12);
     cout << i << ": " << one << endl;
     }*/
    
    return 0;
}
