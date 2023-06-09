#include "hashtable.h"
using namespace std;

Hashtable::Hashtable(int initialSize) {
    capacity = initialSize;
    values = vector<string>(capacity, "");  // Initialize the values vector with empty strings
}

void Hashtable::insert(string key, string value) {
    int index = hash(key);  // Calculate the index for the given key
    values[index] = value;  // Insert the value at the calculated index
}

bool Hashtable::contains(string key) {
    int index = hash(key);  // Calculate the index for the given key
    return values[index] != "";  // Check if the value at the calculated index is not empty
}

string Hashtable::remove(string key) {
    int index = hash(key);  // Calculate the index for the given key
    string value = values[index];  // Retrieve the value at the calculated index
    values[index] = "";  // Set the value at the calculated index to empty
    return value;  // Return the removed value
}

int Hashtable::getSize() {
    int count = 0;
    for (const string & value : values) {  // Iterate over each value in the hashtable
        if (!value.empty()) {  // Check if the value is not empty
            count++;  // Increment the count if the value is not empty
        }
    }
    return count;  // Return the count of non-empty values
}

int Hashtable::getCapacity() {
    return capacity;  // Return the capacity of the hashtable
}

int Hashtable::hash(string key) {
    int result = 0;
    for (char character : key) {  // Iterate over each character in the key
        result += character;  // Add the unicode values of characters together
    }
    return result % capacity;  // Mod the result by the capacity to get the index within the hashtable
}
