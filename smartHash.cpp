#include "smartHash.h"
using namespace std;

Hashtable::Hashtable(int initialSize) {
    capacity = initialSize;
    table.resize(capacity);
}

void Hashtable::insert(string key, string value) {
    // Compute the index of the key in the hashtable
    int index = hash(key);

    // Insert the key-value pair into the corresponding bucket
    table[index].push_back(make_pair(key, value));
}

bool Hashtable::contains(string key) {
    // Compute the index of the key in the hashtable
    int index = hash(key);

    // Iterate over the entries in the bucket at the computed index
    for (const auto& entry : table[index]) {
        // Check if the current entry's key matches the search key
        if (entry.first == key) {
            return true;  // Key found
        }
    }

    return false;  // Key not found
}

string Hashtable::remove(string key) {
    // Compute the index of the key in the hashtable
    int index = hash(key);

    // Iterate over the entries in the bucket at the computed index
    for (auto it = table[index].begin(); it != table[index].end(); ++it) {
        // Check if the current entry's key matches the search key
        if (it->first == key) {
            string value = it->second;  // Store the value before erasing the entry
            table[index].erase(it);    // Remove the entry from the bucket
            return value;              // Return the removed value
        }
    }

    return "";  // Key not found, return an empty string
}

int Hashtable::getSize() {
    int count = 0;

    // Iterate over all buckets in the hashtable
    for (const auto& chain : table) {
        count += chain.size();  // Add the size of each bucket to the total count
    }

    return count;  // Return the total number of entries in the hashtable
}

int Hashtable::getCapacity() {
    return capacity;  // Return the capacity of the hashtable
}

int Hashtable::hash(string key) {
    int result = 0;

    // Compute the hash value by summing the ASCII values of characters in the key
    for (char character : key) {
        result += character;
    }

    return result % capacity;  // Modulo the result by the hashtable's capacity to get the index
}

const list<pair<string, string>>& Hashtable::getBucket(int index) const {
    // Return the reference to the bucket at the specified index
    return table[index];
}
