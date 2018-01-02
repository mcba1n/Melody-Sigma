#include<iostream>

class LinkedList
{
    public:
        LinkedList();
        ~LinkedList();
        void insertbeg(int);
        void insertend(int);
        void insertloc(int, int);
        void deletebeg();
        void deleteend();
        void deleteloc(int);
        void traverse();

    private:
        struct list1 {
            int data;
            struct list1 *next;
        };
        struct list1 *start;

    protected:


};
