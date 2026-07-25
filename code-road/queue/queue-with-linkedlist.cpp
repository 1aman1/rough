#include <iostream>
using namespace std;

struct q_node
{
  int data;
  q_node *next;

  q_node(int x) : data(x), next(nullptr) {}
};

class queue
{
private:
  q_node *front;
  q_node *rear;
  size_t size;

public:
  queue()
  {
    front = rear = nullptr;
    size = 0;
  }

  ~queue()
  {
    while (front != nullptr)
    {
      q_node *temp = front;
      front = front->next;
      delete temp;
    }
    rear = nullptr;
  }

  void menu();
  void enqueue(int);
  void dequeue();
  size_t size_fn();
  void isempty();
  void display();
};

void queue::enqueue(int element)
{
  q_node *newNode = new q_node(element);

  if (front == nullptr)
  {
    front = rear = newNode;
  }
  else
  {
    rear->next = newNode;
    rear = newNode;
  }

  ++size;
}

void queue::dequeue()
{
  if (front == nullptr)
  {
    cout << "QUEUE_EMPTY\n";
    return;
  }

  q_node *temp = front;
  front = front->next;

  if (front == nullptr)
    rear = nullptr;

  delete temp;
  --size;

  cout << "Element dequeued successfully.\n";
}

size_t queue::size_fn()
{
  return size;
}

void queue::isempty()
{
  if (size == 0)
    cout << "QUEUE_EMPTY\n";
  else
    cout << "QUEUE_NOT_EMPTY, size = " << size << "\n";
}

void queue::display()
{
  if (front == nullptr)
  {
    cout << "QUEUE_EMPTY\n";
    return;
  }

  cout << "FRONT --> ";

  q_node *traverse = front;
  while (traverse != nullptr)
  {
    cout << traverse->data;
    if (traverse->next != nullptr)
      cout << " --> ";
    traverse = traverse->next;
  }

  cout << " <-- REAR\n";
}

void queue::menu()
{
  int choice, element;

  do
  {
    cout << "\n====== Queue Using Linked List ======\n";
    cout << "0. Exit\n";
    cout << "1. Enqueue\n";
    cout << "2. Dequeue\n";
    cout << "3. Display Queue\n";
    cout << "4. Queue Size\n";
    cout << "5. Is Queue Empty?\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 0:
      cout << "Exiting...\n";
      break;

    case 1:
      cout << "Enter element: ";
      cin >> element;
      enqueue(element);
      break;

    case 2:
      dequeue();
      break;

    case 3:
      display();
      break;

    case 4:
      cout << "Queue Size: " << size_fn() << "\n";
      break;

    case 5:
      isempty();
      break;

    default:
      cout << "Invalid choice! Try again.\n";
    }

  } while (choice != 0);
}

int main()
{
  queue runMyQueue;
  runMyQueue.menu();

  return 0;
}