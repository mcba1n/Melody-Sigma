#ifndef REALCOMMAND_H
#define REALCOMMAND_H

#include <Command.h>


class RealCommand : public Command
{
    public:
        RealCommand(std::string cmd);
        virtual ~RealCommand();
        double get_result();

    protected:

    private:
        double result;
};

#endif // REALCOMMAND_H
