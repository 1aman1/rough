#include <iostream>

/*
a 10 minute linked list
*/

class List
{
private:
    struct Node
    {
        int data;
        Node *next;

        Node(int x) : data(x),
                      next(nullptr) {};

        Node() = delete;
    };

    Node *head;
    int size;

public:
    List() : head(nullptr), size(0) {};

    // insert by value
    void
    insert(int);

    void
    remove();

    void
    print();

    int
    get_size();
};

int List::get_size()
{
    return size;
}

void List::remove()
{
    Node *head_hook = head;
    head = head->next;
    delete head_hook;

    --size;
}

void List::insert(int item)
{
    Node *new_node = new Node(item);

    // std::cout << "data :" << new_node->data;
    new_node->next = head;
    head = new_node;

    ++size;
}

void List::print()
{
    if (size != 0)
    {
        Node *temp = head;

        std::cout << "\nHead~ ";
        while (temp)
        {
            std::cout << temp->data << " : ";
            temp = temp->next;
        }
    }
    else
        std::cout << "\nlist empty!\n";
}

int main()
{
    List myList;

    myList.insert(1);
    myList.print();

    myList.remove();
    myList.print();

    myList.insert(2);
    myList.insert(1);
    myList.print();

    myList.remove();
    myList.print();

    myList.remove();
    myList.print();

    return 0;
}