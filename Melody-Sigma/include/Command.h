#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <Stack.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <Operations.h>
#include <Math.h>

// modes
#define REAL 1
#define COMPLEX 2
#define POLY 3
#define MATRIX 4

class Command
{
    public:
        Command(std::string cmd, int md);
        virtual ~Command();
        double get_result();

    protected:

    private:
        double result;
        int mode;       // the mode of the command

        double evaluate_postfix(std::string postfix_string);
        std::string evaluate_constants(std::string c_string);
        std::string replace_string(std::string subject, const std::string& search,
                          const std::string& replace);
        std::string infix_to_postfix(std::string infix_string);
        bool is_operand(char operand);
        int precedence(char op);
        int operand_length(int pos, std::string c_string);
};

#endif // COMMAND_H
