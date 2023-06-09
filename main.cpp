#include <iostream>
#include "hashtable.h"
#include "hashtable.cpp"

using std::cout;
using std::endl;

int main() {
    cout << "Hashtable Test" << endl << endl;

    // Create a hashtable with initial size 10
    Hashtable hashtable(10);

    // Insert key-value pairs
    hashtable.insert("key1", "value1");
    hashtable.insert("key2", "value2");
    hashtable.insert("key3", "value3");

    // Test contains function
    cout << "Contains 'key1': " << (hashtable.contains("key1") ? "true" : "false") << endl;
    cout << "Contains 'key4': " << (hashtable.contains("key4") ? "true" : "false") << endl;

    // Test getSize and getCapacity functions
    cout << "Size: " << hashtable.getSize() << "  Expected: 3" << endl;
    cout << "Capacity: " << hashtable.getCapacity() << "  Expected: 10" << endl;

    // Test remove function
    cout << "Remove 'key2': " << hashtable.remove("key2") << endl;

    // Test contains after removal
    cout << "Contains 'key2': " << (hashtable.contains("key2") ? "true" : "false") << endl;

    // Test getSize after removal
    cout << "Size: " << hashtable.getSize() <<"  Expected: 2" << endl;

    return 0;
}
