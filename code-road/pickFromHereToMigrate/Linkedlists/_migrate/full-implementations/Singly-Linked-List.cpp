#include <iostream>
#include <cstddef>

class List
{
private:
    struct Node
    {
        int data_;
        Node *next_;

        explicit Node(int value);
    };

    Node head; // sentinel node
    std::size_t size_;

public:
    List();
    ~List();

    List(const List &) = delete;
    List &operator=(const List &) = delete;

    [[nodiscard]]
    bool empty() const noexcept;

    [[nodiscard]]
    std::size_t size() const noexcept;

    void print() const;

    [[nodiscard]]
    bool insert(int value, std::size_t index);

    [[nodiscard]]
    bool remove(std::size_t index);
};

List::Node::Node(int value)
    : data_(value),
      next_(nullptr)
{
}

List::List()
    : head(0),
      size_(0)
{
}

List::~List()
{
    Node *current = head.next_;

    while (current)
    {
        Node *next = current->next_;
        delete current;
        current = next;
    }
}

bool List::empty() const noexcept
{
    return size_ == 0;
}

std::size_t List::size() const noexcept
{
    return size_;
}

void List::print() const
{
    if (empty())
    {
        std::cout << "List empty\n";
        return;
    }

    const Node *current = head.next_;

    std::size_t index = 1;

    while (current)
    {
        std::cout
            << '@'
            << index
            << " -> "
            << current->data_;

        current = current->next_;

        if (current)
        {
            std::cout << " :: ";
        }

        ++index;
    }

    std::cout << '\n';
}

bool List::insert(int value, std::size_t index)
{
    if (index < 1 || index > size_ + 1)
    {
        return false;
    }

    Node *previous = &head;

    for (std::size_t pos = 1; pos < index; ++pos)
    {
        previous = previous->next_;
    }

    Node *node = new Node(value);

    node->next_ = previous->next_;
    previous->next_ = node;

    ++size_;

    return true;
}

bool List::remove(std::size_t index)
{
    if (index < 1 || index > size_)
    {
        return false;
    }

    Node *previous = &head;

    for (std::size_t pos = 1; pos < index; ++pos)
    {
        previous = previous->next_;
    }

    Node *victim = previous->next_;

    previous->next_ = victim->next_;

    delete victim;

    --size_;

    return true;
}

int main()
{
    List list;

    list.insert(10, 1);
    list.insert(20, 2);
    list.insert(30, 3);

    list.print();

    list.insert(15, 2);

    list.print();

    list.remove(1);

    list.print();

    list.remove(2);

    list.print();

    std::cout
        << "size = "
        << list.size()
        << '\n';
}