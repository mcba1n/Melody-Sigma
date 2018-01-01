#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <Operations.h>
#include <Math.h>
#include <ctype.h>
#include <vector>
#include <cstring>

// modes
#define REAL 1
#define COMPLEX 2
#define POLY 3
#define MATRIX 4

// container for stringified functions
typedef struct fContainer {
    std::string name;
    std::string arg;
    int index;
};

#define MAX_LEN 100

class Command
{
    public:
        Command();
        virtual ~Command();

    protected:
        Complex evaluate_handler(std::string c_string);
        Complex evaluate_postfix(std::string postfix_string);
        Complex str_to_complex(std::string complx_str);
        Complex double_to_complex(double x);
        Complex function_call(std::string name, std::string arg1, std::string arg2);
        std::string evaluate_constants(std::string c_string);
        std::string evaluate_functions(std::string c_string);
        std::vector<fContainer> find_args(std::string c_string);
        std::string replace_string(std::string subject, const std::string& search,
                          const std::string& replace);
        std::string infix_to_postfix(std::string infix_string);
        bool is_operand(char operand);
        int precedence(char op);
        int operand_length(int pos, std::string c_string);
        bool is_operator(char c);

    private:

};

#endif // COMMAND_H
