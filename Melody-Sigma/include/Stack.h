#ifndef STACK_H
#define STACK_H

#define MAX 100

class Stack
{
    public:
        Stack();
        virtual ~Stack();

        void push(char item);
        char pop();
        bool is_empty();
        char get_top_item();
        int size();

    protected:

    private:
        int arr[MAX];   // the stack array
        int top;        // index for highest item on the stack
};

#endif // STACK_H
