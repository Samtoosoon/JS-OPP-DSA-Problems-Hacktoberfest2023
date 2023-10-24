#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Stack {
public:
    Stack() {
        top = nullptr;
    }

    // Push operation to add an element to the top of the stack
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    // Pop operation to remove and return the top element of the stack
    int pop() {
        if (isEmpty()) {
            std::cerr << "Stack is empty. Cannot pop." << std::endl;
            return -1; // You can choose to return a different value or throw an exception
        }

        int poppedValue = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return poppedValue;
    }

    // Peek operation to return the top element without removing it
    int peek() {
        if (isEmpty()) {
            std::cerr << "Stack is empty. Cannot peek." << std::endl;
            return -1; // You can choose to return a different value or throw an exception
        }
        return top->data;
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

private:
    Node* top;
};

int main() {
    Stack myStack;

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    std::cout << "Top element: " << myStack.peek() << std::endl;

    myStack.pop();
    std::cout << "Top element after pop: " << myStack.peek() << std::endl;

    myStack.push(4);

    while (!myStack.isEmpty()) {
        std::cout << "Popped element: " << myStack.pop() << std::endl;
    }

    return 0;
}
