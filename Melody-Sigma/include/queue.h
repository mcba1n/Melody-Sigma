#include<iostream>
#define MAX 99999
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
