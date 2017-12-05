#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <Stack.h>

class Command
{
    public:
        Command(std::string cmd);
        virtual ~Command();
        int get_result();

    protected:

    private:
        int result;

        int evaluate_postfix(std::string postfix_string);
        std::string infix_to_postfix(std::string infix_string);
        bool is_operand(char operand);
        int precedence(char op);
};

#endif // COMMAND_H
