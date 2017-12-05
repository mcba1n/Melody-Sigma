#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <Math.h>


class Operations : public Math
{
    public:
        Operations();
        virtual ~Operations();

        double add(double a, double b);

    protected:

    private:
};

#endif // OPERATIONS_H
