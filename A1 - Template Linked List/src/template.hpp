#include <cstddef>
#include <stdexcept>
#include <iostream>
using namespace std;

template <typename T>
class LinkedList
{
private:
    struct Node
    {
        T data;
        Node *next;
        Node(const T &value) : data(value), next(nullptr) {}
    };
    Node *head;
    size_t size;

public:
    LinkedList() : head{nullptr}, size{0} {}
    ~LinkedList() { clear(); }

    void insert(const T &value, size_t pos);
    void remove(size_t pos);
    T &operator()(size_t position);
    void clear();
    size_t getSize() const { return size; }
    void printList(LinkedList<T>& list);
};

template <typename T>
void LinkedList<T>::insert(const T &value, size_t pos)
{
    if (pos > size)
    {
        throw out_of_range("Position out of range");
    }
    Node *new_node = new Node(value);
    if (pos == 0)
    {
        new_node->next = head;
        head = new_node;
    }
    else
    {
        Node *prev = head;
        for (size_t i = 1; i < pos; ++i)
        {
            prev = prev->next;
        }
        new_node->next = prev->next;
        prev->next = new_node;
    }
    ++size;
}

template <typename T>
T &LinkedList<T>::operator()(size_t position)
{
    if (position >= size)
    {
        throw out_of_range("Position out of range.");
    }
    Node *current = head;
    for (size_t i = 0; i < position; ++i)
    {
        current = current->next;
    }
    return current->data;
}

template <typename T>
void LinkedList<T>::remove(size_t pos)
{
    if (pos >= size)
    {
        throw out_of_range("Position out of range");
    }
    Node *temp = nullptr;
    if (pos == 0)
    {
        temp = head;
        head = head->next;
    }
    else
    {
        Node *prev = head;
        for (size_t i = 1; i < pos; ++i)
        {
            prev = prev->next;
        }
        temp = prev->next;
        prev->next = temp->next;
    }
    delete temp;
    --size;
}

template <typename T>
void LinkedList<T>::clear()
{
    while (head)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    size = 0;
}

template <typename T>
void LinkedList<T>::printList(LinkedList<T>& list)
{
    for (size_t i = 0; i < list.getSize(); ++i)
    {
        cout << list(i) << " ";
    }
}