#include <iostream>
#include "smartHash.h"
#include "smartHash.cpp"
using namespace std;

int main() {
    cout << "Smart Hashtable Test" << endl << endl;

    // Create a hashtable with initial size 5
    Hashtable hashtable(5);

    // Insert key-value pairs
    hashtable.insert("key1", "value1"); // both are the same to test collision
    hashtable.insert("key1", "value2"); // both are the same to test collision
    hashtable.insert("key3", "value3");
    hashtable.insert("e1", "value4");
    hashtable.insert("e2", "value5");

    // Test contains function
    cout << "Contains 'key1': " << (hashtable.contains("key1") ? "true" : "false") << endl;
    cout << "Contains 'e1': " << (hashtable.contains("e1") ? "true" : "false") << endl;

    // Test getSize and getCapacity functions
    cout << "Size: " << hashtable.getSize() << "  Expected: 5" << endl;
    cout << "Capacity: " << hashtable.getCapacity() << "  Expected: 5" << endl;

    cout << endl << "Collision Handling Test:" << endl;

    // Iterate over each bucket and print its contents
    for (int i = 0; i < hashtable.getCapacity(); i++) {
        cout << "Bucket " << i << ": ";
        for (const auto& entry : hashtable.getBucket(i)) {
            cout << "(" << entry.first << ", " << entry.second << ") ";
        }
        cout << endl;
    }

    return 0;
}
