#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <iostream>
using namespace std;

class Hashtable {
private:
    int capacity;  // Capacity of the hashtable
    vector<string> values;  // Vector to store values in the hashtable

    int hash(string key);  // Hash function to calculate the index for a given key

public:
    Hashtable(int initialSize);  // Constructor to initialize the hashtable with a given initial size
    void insert(string key, string value);  // Insert a key-value pair into the hashtable
    bool contains(string key);  // Check if a key exists in the hashtable
    string remove(string key);  // Remove a key-value pair from the hashtable
    int getSize();  // Get the number of non-empty elements in the hashtable
    int getCapacity();  // Get the capacity of the hashtable
};

#endif  // HASHTABLE_H
