#include<iostream>
#define MAX 100

class Queue
{
    public:
        Queue();
        ~Queue();
        void insertion(int ITEM);
        void deletion();
        void traverse();
    protected:

    private:
        int QUE[MAX];
        int FRONT;
        int REAR;

};
