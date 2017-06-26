/*
 Siddharth Rajan
 CSC 21200
 
 Assignment 3
 
 FILE: sequence.h
 CLASS PROVIDED: sequence (a class for a sequence of values in a particular order)
 
 TYPEDEFS and MEMBER CONSTANTS for the sequence class:
    typedef _____ value_type
    sequence::value_type is the data type of the items in the sequence. It may be any of the C++ built-in types (int, char, etc), or a class with a default constructor, an assignment operator, and operators to test for equality (x == y) and non-equality (x != y).
 
    typedef _____ size_type
    sequence::size_type is the data type of any variable that keeps track of how many items are in a bag.
 
    static const size_type DEFAULT_CAPACITY = _____
    sequence::DEFAULT_CAPACITY is maximum number of items that a sequence can have.
 
 CONSTRUCTOR for the sequence class:
    sequence(size_type initial_capacity = DEFAULT_CAPACITY)
        Postcondition: The sequence is empty with an initial capacity given by the parameter. The insert function will work efficiently (without allocating new memory) until this capacity is reached.
 
 ASSIGNMENT OPERATOR for the sequence class:
    sequence& operator =(const sequence& s2)
        Postcondition: The elements in sequence s1 are set to be equal to the elements in sequence s2. Additional memory is allocated if needed.
 
 CONSTANT MEMBER FUNCTIONS for the sequence class:
    size_type count(const value_type& x) const
        Postcondition: The number of occurrences of x in the sequence is returned.
 
    size_type size() const
        Postcondition: The total number of elements in the sequence is returned.
 
 MODIFICATION MEMBER FUNCTIONS for the sequence class:
    bool erase_first(const value_type& x)
        Postcondition: A boolean is returned indicating whether or not the first occurance of x was erased from the sequence.
 
    bool erase_last(const value_type& x)
        Postcondition: A boolean is returned indicating whether or not the last occurance of x was erased from the sequence.
 
    bool erase_occurence(const value_type& x, const size_type& n)
        Postcondition: A boolean is returned indicating whether or not the n + 1th occurrence of x was erased from the sequence. (n, the number of the occurrence, starts at 0.)
 
    void erase_from(const size_type& n)
        Postcondition: The element at index n of the sequence is erased.
 
    void insert(const value_type& x)
        Postcondition: x is inserted at the end of the sequence.
 
    void insert_first(const value_type& x)
        Postcondition: x is inserted at the start of the sequence.
 
    void insert_at(const value_type& x, const size_type& n)
        Postcondition: x is inserted at index n of the sequence.
 
    void operator +=(const sequence& s2)
        Postcondition: A sequence s1 is increased by the addition of the values of s2 to it.
 
    void operator +=(const value_type& x)
        Postcondition: A sequence s1 is increased by the addition of x to it.
 
    void reserve(size_type new_capacity)
        Postcondition: The sequence's current capacity is changed to the new capacity (but not less than used). The insert function will work efficiently (without allocating new memory) until the new capacity is reached.
 
 NONMEMBER FUNCTIONS for the sequence class:
    sequence operator +(const sequence& s1, const sequence& s2)
        Postcondition: The sum of s1 and s2 is returned.
 
    sequence operator +(const sequence& s1, const sequence::value_type& x)
        Postcondition: The sum of s1 and x is returned.
 
    ostream& operator <<(ostream& output, const sequence& s1)
        Postcondition: The elements of s1 are written to output, and output is the ostream that is returned.
 
    istream& operator >>(istream& input, sequence& s1)
        Postcondition: The elements of s1 are read from input, and input is the istream that is returned.
 
    bool operator ==(const sequence& s1, const sequence& s2)
        Postcondition: The return value is true if s1 and s2 are identical.
 
 VALUE SEMANTICS for the sequence class:
    The assignment operator is safe to use with sequence objects.
 */

/*
 In the main file I made a loop with one billion iterations and in the body of the loop I declared a sequence object and inserted a value in it. I ran the program and saw that the memory usage was increasing nonstop. I then added a destructor and ran the test again. This time the memory usage was constant and neither increased nor decreased. In both tests I saw that the overall energy usage was high which made my computer heat up.
 */

#ifndef sequence_h
#define sequence_h

#include <iostream>
#include <cstdlib>

namespace sid_raj_hw3 {
    
    class sequence {
    public:
        // TYPEDEFS and MEMBER CONSTANTS for the sequence class:
        typedef double value_type;
        typedef size_t size_type;
        static const size_type DEFAULT_CAPACITY = 20;
        // CONSTRUCTOR
        sequence(size_type initial_capacity = DEFAULT_CAPACITY);                      // <--done, working
        // ASSIGNMENT OPERATOR
        sequence& operator =(const sequence& s2);                                     // <--done, working
        // MODIFICATION MEMBER FUNCTIONS
        bool erase_first(const value_type& x);                                        // <--done, working
        bool erase_last(const value_type& x);                                         // <--done, working
        bool erase_occurence(const value_type& x, const size_type& n);                // <--done, working
        void erase_from(const size_type& n);                                          // <--done, working
        void insert(const value_type& x);                                             // <--done, working
        void insert_first(const value_type& x);                                       // <--done, working
        void insert_at(const value_type& x, const size_type& n);                      // <--done, working
        void operator +=(const sequence& s2);                                         // <--done, working
        void operator +=(const value_type& x);                                        // <--done, working
        void reserve(size_type new_capacity);                                         // <--done, working
        // CONSTANT MEMBER FUNCTIONS
        size_type count(const value_type& x) const;                                   // <--done, working
        size_type size() const;                                                       // <--done, working
        // FRIEND FUNCTIONS
        friend std::ostream& operator <<(std::ostream& output, const sequence& s1);   // <--done, working
        friend std::istream& operator >>(std::istream& input, sequence& s1);          // <--done, working
        friend bool operator ==(const sequence& s1, const sequence& s2);              // <--done, working
        // DESTRUCTOR
        ~sequence();                                                                  // <--done, working
    private:
        value_type *data;
        size_type used;
        size_type capacity;
    };
    
    // NONMEMBER FUNCTIONS for the sequence class
    sequence operator +(const sequence& s1, const sequence& s2);                      // <--done, working
    sequence operator +(const sequence& s1, const sequence::value_type& x);           // <--done, working
}

#endif /* sequence_h */
