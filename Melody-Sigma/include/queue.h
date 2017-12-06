#include<iostream>
#define MAX 99999
class queue1
{
    public:
        queue1();
        ~queue1();
        void insertion(int ITEM);
        void deletion();
        void traverse();
    protected:

    private:
        int QUE[MAX];
        int FRONT;
        int REAR;

};
