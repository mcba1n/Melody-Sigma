#ifndef COMPLEXCOMMAND_H
#define COMPLEXCOMMAND_H

#include <Command.h>
#include <Complex.h>

class ComplexCommand : public Command
{
    public:
        ComplexCommand(std::string cmd);
        virtual ~ComplexCommand();
        Complex get_result();

    protected:

    private:
        Complex result;
        bool is_complex(Complex z);
};

#endif // COMPLEXCOMMAND_H
