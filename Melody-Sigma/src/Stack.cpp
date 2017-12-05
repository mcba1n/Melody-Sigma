#include "Stack.h"
#include <iostream>

Stack::Stack() {
    top = -1;
}

Stack::~Stack()
{
    //dtor
}

void Stack::push(char item) {
    // check if the stack can hold another item
    if (top < MAX) {
        top++;
        arr[top] = item;
    } else {
        std::cout << "Error: stack is full" << std::endl;
    }
}

char Stack::pop() {
    if (!is_empty()) {
        int item = arr[top];
        arr[top] = 0;
        top--;
        return item;
    } else {
        std::cout << "Error: no items in stack" << std::endl;
        return -1;
    }
}

bool Stack::is_empty() {
    // check if there are items in the stack
    if (top == -1) {
        return true;
    } else {
        return false;
    }
}

char Stack::get_top_item() {
    // get the first item in the stack
    if (!is_empty()) {
        return arr[top];
    } else {
        std::cout << "Error: stack is empty" << std::endl;
        return -1;
    }
}

int Stack::size() {
    return top + 1;
}
