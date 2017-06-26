/*
 Siddharth Rajan
 CSC 21200
 
 FILE: sequence.cpp
 CLASS IMPLEMENTED: sequence (see sequence.h for documentation)
 INVARIANT for the sequence class:
 1. The number of items in the sequence is in the member variable used.
 2. The actual items of the sequence are stored in a partially filled array. The array is a dynamic array, pointed to by the member variable data.
 3. The size of the dynamic array is in the member variable capacity.
 */

#include "sequence.h"
#include <cassert>
#include <algorithm>
using std::cin;
using std::copy;

namespace sid_raj_hw3 {
    
    // MEMBER CONSTANT
    const sequence::size_type sequence::DEFAULT_CAPACITY;
    
    // CONSTRUCTOR
    sequence::sequence(size_type initial_capacity) {
        data = new value_type[initial_capacity];
        capacity = initial_capacity;
        used = 0;
    }
    
    // CONSTANT MEMBER FUNCTIONS
    sequence::size_type sequence::count(const value_type& x) const {
        int count = 0;
        for (int i = 0; i < used; i++) {
            if (data[i] == x)
                count++;
        }
        return count;
    }
    
    sequence::size_type sequence::size() const {
        return used;
    }
    
    // ASSIGNMENT OPERATOR
    sequence& sequence::operator =(const sequence& s2) {
        value_type* new_data;
        if (this == &s2)
            return *this;
        if (capacity != s2.capacity) {
            new_data = new value_type[s2.capacity];
            delete [] data;
            data = new_data;
            capacity = s2.capacity;
        }
        used = s2.used;
        copy(s2.data, s2.data + used, data);
        return *this;
    }
    
    // MODIFICATION MEMBER FUNCTIONS
    bool sequence::erase_first(const value_type& x) {
        size_type i;
        for (i = 0; i < used; i++) {
            if (data[i] == x)
                break;
        }
        if (i == used)
            return false;
        else {
            while (i < used) {
                data[i] = data[i + 1];
                i++;
            }
            used--;
            return true;
        }
    }
    
    bool sequence::erase_last(const value_type& x) {
        size_type i;
        for (i = used - 1; i > 0; i--) {
            if (data[i] == x)
                break;
        }
        if (i == 0)
            return false;
        else {
            while (i < used) {
                data[i] = data[i + 1];
                i++;
            }
            used--;
            return true;
        }
    }
    
    bool sequence::erase_occurence(const value_type& x, const size_type& n) {
        //assert(n >= 0 && n < used);
        if (n >= used)
            return false;
        size_type i;
        size_type occur = 0;
        for (i = 0; i < used; i++) {
            if (data[i] == x)
                occur++;
            if (occur == n + 1)
                break;
        }
        if (i == used)
            return false;
        while (i < used) {
            data[i] = data[i + 1];
            i++;
        }
        used--;
        return true;
    }
    
    void sequence::erase_from(const size_type& n) {
        //assert(n < used);
        if (n >= used)
            return;
        for (size_type i = n; i < used; i++) {
            data[i] = data[i + 1];
        }
        used--;
    }
    
    void sequence::insert(const value_type& x) {
        if (used == capacity)
            reserve(used + 1);
        data[used] = x;
        used++;
    }
    
    void sequence::insert_first(const value_type& x) {
        if (used == capacity)
            reserve(used + 1);
        size_type i;
        for (i = used; i > 0; i--) {
            data[i] = data[i - 1];
        }
        data[i] = x;
        used++;
    }
    
    void sequence::insert_at(const value_type& x, const size_type& n) {
        //assert(n <= used);
        if (n > used)
            return;
        if (used == capacity)
            reserve(used + 1);
        size_type i;
        for (i = used; i > n; i--) {
            data[i] = data[i - 1];
        }
        data[i] = x;
        used++;
    }
    
    void sequence::operator +=(const sequence& s2) {
        if (used + s2.used > capacity)
            reserve(used + s2.used);
        copy(s2.data, s2.data + s2.used, data + used);
        used += s2.used;
    }
    
    void sequence::operator +=(const value_type& x) {
        insert(x);
    }
    
    void sequence::reserve(size_type new_capacity) {
        value_type *new_array;
        if (new_capacity == capacity)
            return;
        if (new_capacity < used)
            new_capacity = used;
        new_array = new value_type[new_capacity];
        copy(data, data + used, new_array);
        delete [] data;
        data = new_array;
        capacity = new_capacity;
    }
    
    // NONMEMBER FUNCTIONS
    std::ostream& operator <<(std::ostream& output, const sequence& s1) {
        for (sequence::size_type i = 0; i < s1.used; i++) {
            output << s1.data[i] << " ";
        }
        return output;
    }
    
    std::istream& operator >>(std::istream& input, sequence& s1) {
        sequence::value_type x;
        while (input >> x) {
            if (s1.used == s1.capacity)
                s1.reserve(s1.used + 1);
            s1.data[s1.used] = x;
            s1.used++;
        }
        return input;
    }
    
    bool operator ==(const sequence& s1, const sequence& s2) {
        if (s1.used == s2.used) {
            for (sequence::size_type i = 0; i < s1.used; i++) {
                if (s1.data[i] == s2.data[i])
                    continue;
                else
                    return false;
            }
            return true;
        }
        else
            return false;
    }
    
    sequence operator +(const sequence& s1, const sequence& s2) {
        sequence answer(s1.size() + s2.size());
        answer += s1;
        answer += s2;
        return answer;
    }
    
    sequence operator +(const sequence& s1, const sequence::value_type& x) {
        sequence answer(s1.size() + 1);
        answer += s1;
        answer += x;
        return answer;
    }
    
    // DESTRUCTOR
    sequence::~sequence() {
        delete [] data;
    }
}
