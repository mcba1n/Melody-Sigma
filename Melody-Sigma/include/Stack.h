#ifndef STACK_H
#define STACK_H

#include <iostream>
#define MAX 100

template <class T>
class Stack
{
    public:
        Stack();
        virtual ~Stack();

        void push(T item);
        T pop();
        T get_top_item();
        bool is_empty();
        int size();

    protected:

    private:
        T arr[MAX];   // the stack array
        int top;        // index for highest item on the stack
};

template <class T>
Stack<T>::Stack() {
    top = -1;
}

template <class T>
Stack<T>::~Stack()
{
    //dtor
}

template <class T>
void Stack<T>::push(T item) {
    // check if the stack can hold another item
    if (top < MAX) {
        top++;
        arr[top] = item;
    } else {
        // stack is full
    }
}

template <class T>
T Stack<T>::pop() {
    if (!is_empty()) {
        T item = arr[top];
        //arr[top] = nullptr;
        top--;
        return item;
    } else {
        // no items in stack
        T null;
        return null;
    }
}

template <class T>
bool Stack<T>::is_empty() {
    // check if there are items in the stack
    if (top == -1) {
        return true;
    } else {
        return false;
    }
}

template <class T>
T Stack<T>::get_top_item() {
    // get the first item in the stack
    if (!is_empty()) {
        return arr[top];
    } else {
        // stack is empty
        return -1;
    }
}

template <class T>
int Stack<T>::size() {
    return top + 1;
}

#endif // STACK_H
