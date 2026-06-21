class MyLinkedList
{
private:
    struct Node
    {
        int val;
        Node *next;

        Node(int x) : val(x), next(nullptr) {}
    };

    Node *dummy;
    Node *tail;
    int size;

    Node *getPrevNode(int index)
    {
        Node *curr = dummy;

        while (index--)
        {
            curr = curr->next;
        }

        return curr;
    }

public:
    MyLinkedList()
    {
        dummy = new Node(0);
        tail = dummy;
        size = 0;
    }

    ~MyLinkedList()
    {
        Node *curr = dummy;

        while (curr)
        {
            Node *temp = curr;
            curr = curr->next;
            delete temp;
        }
    }

    int get(int index)
    {
        if (index < 0 || index >= size)
        {
            return -1;
        }

        Node *curr = dummy->next;

        while (index--)
        {
            curr = curr->next;
        }

        return curr->val;
    }

    void addAtHead(int val)
    {
        Node *newNode = new Node(val);

        newNode->next = dummy->next;
        dummy->next = newNode;

        ++size;
        if (size == 1)
        {
            tail = newNode;
        }
    }

    void addAtTail(int val)
    {
        Node *newNode = new Node(val);

        tail->next = newNode;
        tail = newNode;

        ++size;
    }

    void addAtIndex(int index, int val)
    {
        if (index < 0 || index > size)
        {
            return;
        }

        if (index == size)
        {
            addAtTail(val);
            return;
        }

        Node *prev = getPrevNode(index);

        Node *newNode = new Node(val);

        newNode->next = prev->next;
        prev->next = newNode;

        ++size;
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= size)
        {
            return;
        }

        Node *prev = getPrevNode(index);
        Node *nodeToDelete = prev->next;

        prev->next = nodeToDelete->next;

        if (nodeToDelete == tail)
        {
            tail = prev;
        }

        delete nodeToDelete;
        --size;
    }
};