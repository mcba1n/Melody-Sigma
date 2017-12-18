#include <iostream>
#include "InsertionSort.h"

class SelectionSort: public InsertionSort
{
    public:
            SelectionSort();
            ~SelectionSort();
            void sel_sort(int *, int);
            void min_(int *, int, int , int &);
    private:
    protected:
};
