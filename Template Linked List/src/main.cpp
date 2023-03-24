#include "template.hpp"

using namespace std;

int main()
{
    LinkedList<int> list;
    // LinkedList<char> list;

    list.insert(1, 0);
    list.insert(2, 1);
    list.insert(3, 2);
    list.insert(4, 3);
    list.insert(5, 4);
    list.insert(6, 5);

    // list.insert('a', 0);
    // list.insert('b', 1);
    // list.insert('c', 2);
    // list.insert('d', 3);
    // list.insert('e', 4);
    // list.insert('f', 5);

    cout << "List elements: ";
    list.printList(list);
    cout << endl;

    cout << "Element at position 3: "; 
    cout << list(3);
    cout << endl;
    
    list.remove(4);
    cout << "List elements after removing element at position 4: ";
    list.printList(list);
    cout << endl;

    list.clear();
    cout << "List after calling the destructor: ";
    list.printList(list);
    cout << endl;
    
    return 0;
}
