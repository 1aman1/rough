#include <iostream>
using namespace std;

struct Node
{
  int value;
  int priority;
  Node *next;

  Node(int v, int p)
  {
    value = v;
    priority = p;
    next = NULL;
  }
};

class priorityQueue
{
private:
  Node *head;
  int _size;

public:
  priorityQueue()
  {
    head = NULL;
    _size = 0;
  }

  bool insert();
  bool pop();
  void print();
  void Size();
  void menu();
};

// Insert according to priority (smaller number = higher priority)
bool priorityQueue::insert()
{
  int value, priority;

  cout << "\nEnter value and priority: ";
  cin >> value >> priority;

  Node *newNode = new Node(value, priority);

  // Empty list or insert at beginning
  if (head == NULL || priority < head->priority)
  {
    newNode->next = head;
    head = newNode;
  }
  else
  {
    Node *curr = head;

    // Find correct position
    while (curr->next != NULL &&
           curr->next->priority <= priority)
    {
      curr = curr->next;
    }

    newNode->next = curr->next;
    curr->next = newNode;
  }

  _size++;
  return true;
}

// Remove highest priority element
bool priorityQueue::pop()
{
  if (head == NULL)
  {
    cout << "\n__QUEUE EMPTY__\n";
    return false;
  }

  Node *temp = head;
  cout << "\nDeleted: Value = " << temp->value
       << ", Priority = " << temp->priority << endl;

  head = head->next;
  delete temp;

  _size--;
  return true;
}

// Print queue
void priorityQueue::print()
{
  if (head == NULL)
  {
    cout << "\n__QUEUE EMPTY__\n";
    return;
  }

  cout << "\nPriority Queue:\n";
  cout << "------------------------\n";

  Node *curr = head;

  while (curr != NULL)
  {
    cout << "Priority: " << curr->priority
         << "  Value: " << curr->value << endl;
    curr = curr->next;
  }
}

// Display size
void priorityQueue::Size()
{
  cout << "\nQueue Size = " << _size << endl;
}

// Menu
void priorityQueue::menu()
{
  int choice;

  do
  {
    cout << "\n========== PRIORITY QUEUE ==========\n";
    cout << "1. Insert\n";
    cout << "2. Delete Highest Priority\n";
    cout << "3. Display Queue\n";
    cout << "4. Display Size\n";
    cout << "0. Exit\n";
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
      insert();
      break;

    case 2:
      pop();
      break;

    case 3:
      print();
      break;

    case 4:
      Size();
      break;

    case 0:
      cout << "\nExiting...\n";
      break;

    default:
      cout << "\nInvalid Choice!\n";
    }

  } while (choice != 0);
}

// Main
int main()
{
  priorityQueue pq;
  pq.menu();

  return 0;
}