#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <string>
#include <list>
using namespace std;

class Hashtable {
private:
    int capacity; // The capacity of the hashtable
    vector<list<pair<string, string>>> table; // The table storing key-value pairs

    int hash(string key);  // Hash function to compute the index

public:
    Hashtable(int initialSize); // Constructor to initialize the hashtable
    void insert(string key, string value); // Insert a key-value pair into the hashtable
    bool contains(string key); // Check if the hashtable contains a key
    string remove(string key);  // Remove a key-value pair from the hashtable
    int getSize();   // Get the total number of entries in the hashtable
    int getCapacity(); // Get the capacity of the hashtable
    const list<pair<string, string>>& getBucket(int index) const;  // Get the bucket at the specified index
};

#endif  // HASHTABLE_H
