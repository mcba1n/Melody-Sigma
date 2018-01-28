#include <iostream>

class Poly
{
    public:
        Poly();
        ~Poly();
        void first();
        void second();
        void addpoly();
        void subpoly();
        void mulpoly();
    private:
        struct POLYS{
            int coef;
            int exp;
            struct POLYS *next;
        };
        struct UN_COE_LIST{
            int exp;
            struct UN_COE_LIST *next;
        };
        struct POLYS *start;//points the first node of the first expression
        struct POLYS *begin1;//points the first node of the second expression
        struct POLYS *add;//points the first node of the resultant added polynomial
        int global_ch;
    protected:

};
