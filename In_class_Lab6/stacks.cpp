#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

#define MAX_SIZE 100



class Stack {
  private:
    int top;
    int arr[MAX_SIZE];

  public:
    Stack() {
      top = -1;
    }

    bool push(int x) {
      if (top >= (MAX_SIZE - 1)) {
        cout << "Error: stack overflow" << endl;
        return false;
      } else {
        arr[++top] = x;
        cout << x << " pushed to stack" << endl;
        return true;
      }
    }

    int pop() {
      if (top < 0) {
        cout << "Error: stack underflow" << endl;
        return 0;
      } else {
        int x = arr[top--];
        return x;
      }
    }

    bool isEmpty() {
      return (top < 0);
    }

    bool isFull() {
      return (top >= (MAX_SIZE - 1));
    }

    int StackTop() {
      if (isEmpty()) {
        cout << "Error: stack is empty" << endl;
        return 0;
      } else {
        return arr[top];
      }
    }

    void Display() {
      if (isEmpty()) {
        cout << "Stack is empty" << endl;
      } else {
        cout << "Elements in stack: ";
        for (int i = top; i >= 0; i--) {
          cout << arr[i] << " ";
        }
        cout << endl;
      }
    }
};

class Node {
public:
    int data;
    Node* next;

    Node(int e)
    {
        this->data = e;
        next = nullptr;
    }
};
class Linked_Stack {
private:
    Node* top;
public:
    Linked_Stack()
    {
        this->top = nullptr;
    }

    void push(int e)
    {
        Node* nextItem = new Node(e);
        nextItem->next = top;
        top = nextItem;
    }
    int pop()
    {
        if (this -> isEmpty())
        {
            throw 1;
        }
        int e = this->top->data;
        this->top = top->next;
        return e;
    }
    bool isEmpty()
    {
        if (top == nullptr)
        {
            return true;
        }
        return false;
    }
    int StackTop()
    {
        if (this->isEmpty())
        {
            throw 2;
        }
        return top->data;
    }
    void Display()
    {
        if (!this->isEmpty())
        {
            Node* thisItem = this->top;
            while (thisItem != nullptr)
            {
                cout << thisItem->data << " ";
                thisItem = thisItem->next;
            }
            cout << endl;
        }
    }
};


int main()
{
    auto start1 = high_resolution_clock::now();
    Stack s;
    s.push(8);
    s.push(10);
    s.push(5);
    s.push(11);
    s.push(15);
    s.push(23);
    s.push(6);
    s.push(18);
    s.push(20);
    s.push(17);
    s.Display();
    for (size_t i = 0; i < 5; i++)
    {
        s.pop();
    }
    s.Display();
    s.push(4);
    s.push(30);
    s.push(3);
    s.push(1);
    s.Display();

    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<chrono::nanoseconds>(end1 - start1);
    cout << "Running time of Array stack: " << duration1.count() << " ns" << endl;


    auto start = high_resolution_clock::now();

    Linked_Stack Lstack;
    Lstack.push(8);
    Lstack.push(10);
    Lstack.push(5);
    Lstack.push(11);
    Lstack.push(15);
    Lstack.push(23);
    Lstack.push(6);
    Lstack.push(18);
    Lstack.push(20);
    Lstack.push(17);
    Lstack.Display();
    for (size_t i = 0; i < 5; i++)
    {
        Lstack.pop();
    }
    Lstack.Display();
    Lstack.push(4);
    Lstack.push(30);
    Lstack.push(3);
    Lstack.push(1);
    Lstack.Display();

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<chrono::nanoseconds>(end - start);
    cout << "Running time Linked list : " << duration.count() << " ns" << endl;



}
