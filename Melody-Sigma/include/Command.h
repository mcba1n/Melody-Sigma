#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <Stack.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <Operations.h>
#include <Math.h>
#include <map>
#include <ctype.h>
#include <vector>
#include <cstring>

// modes
#define REAL 1
#define COMPLEX 2
#define POLY 3
#define MATRIX 4

// function pointer types
typedef double (Operations::*method_t)(double, double);
typedef double (Operations::*method_t)(double);
typedef std::map<std::string, method_t> func_map_t;

// container for stringified functions
typedef struct fContainer {
    std::string name;
    std::string arg;
};
#define MAX_LEN 100

class Command
{
    public:
        Command();
        virtual ~Command();
        double get_result();

    protected:
        double result;
        int mode;

        double evaluate_postfix(std::string postfix_string);
        std::string evaluate_constants(std::string c_string);
        std::string evaluate_functions(std::string c_string, std::map<std::string, method_t> m);
        std::vector<fContainer> find_args(std::string c_string);
        std::string replace_string(std::string subject, const std::string& search,
                          const std::string& replace);
        std::string infix_to_postfix(std::string infix_string);
        bool is_operand(char operand);
        int precedence(char op);
        int operand_length(int pos, std::string c_string);

    private:

};

#endif // COMMAND_H
