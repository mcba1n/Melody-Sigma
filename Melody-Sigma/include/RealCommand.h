#ifndef REALCOMMAND_H
#define REALCOMMAND_H

#include <Command.h>


class RealCommand : public Command
{
    public:
        RealCommand(std::string cmd);
        virtual ~RealCommand();

    protected:

    private:
};

#endif // REALCOMMAND_H
