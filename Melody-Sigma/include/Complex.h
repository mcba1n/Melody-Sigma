#ifndef COMPLEX_H
#define COMPLEX_H


class Complex
{
    public:
        Complex();
        Complex(double r, double i);
        virtual ~Complex();
        void setReal(double real);
        void setImag(double imag);
        double getReal();
        double getImag();
        void printComplex();

    protected:

    private:
        double imaginary;
        double real;
};

#endif // COMPLEX_H
