#include "Command.h"

Command::Command()
{
    //ctor
}

Command::~Command()
{
    //dtor
}

// find all function names and their arguments in a string, then return them
std::vector<fContainer> Command::find_args(std::string c_string) {
    std::vector<fContainer> funcs;
    fContainer *currFunc = NULL;
    std::string temp_name;
    int temp_arg_index;
    int num_brackets = 0, num_funcs = 0, arg_len = 0;

    for (int i = 0; i < c_string.size(); i++) {
        char curr_char = c_string[i];
        char next_char = c_string[i + 1];

        // record any function names, then splice them out
        if (isalpha(curr_char)) {
            temp_name.push_back(curr_char);
            if (!isalpha(next_char)) {
                // end of a word, so a function is found
                currFunc = new fContainer;      // allocate memory for func container
                currFunc->name = temp_name;
                num_funcs++;
                temp_name.clear();
            }
        }
        // record function arguments
        if (curr_char == '(' && ++num_brackets == num_funcs) {
            temp_arg_index = i;
            arg_len = 0;
        } else if (curr_char == ')' && num_brackets > 0) {
            currFunc->arg = c_string.substr(temp_arg_index + 1, arg_len);
            funcs.push_back(*currFunc);
        } else {
            arg_len++;
        }
    }
    return funcs;
}

std::string Command::evaluate_functions(std::string c_string, std::map<std::string, method_t> m) {
    std::vector<fContainer> funcs = find_args(c_string);
    fContainer *myFunc;
    Operations ops;
    double result = NULL;

    // iterate through each function
    for (int i = 0; i < funcs.size(); i++) {
        myFunc = &funcs[i];

        // split the arg by delim
        std::vector<std::string> args;
        char str[MAX_LEN];
        strcpy(str, myFunc->arg.c_str());
        char *pch = strtok(str, ",");
        while (pch != NULL) {
            args.push_back( replace_string(pch, " ", "") );
            pch = strtok (NULL, ",");
        }

        // make the func call using mapped strings
        size_t num_args = args.size();
        func_map_t::iterator x = m.find(myFunc->name);
        if (num_args == 1) {
            result = (ops.*(x->second))( std::stof(args[0]) );
        } else if (num_args == 2) {
            result = (ops.*(x->second))( std::stof(args[0]), std::stof(args[1]) );
        } else {
            std::cout << "Too many arguments!\n" << std::endl;
        }
    }

    if (result != NULL) {
        //TODO
        //replace value into original string
    }

    return "";
}

// convert names of constants into their values for a given string
std::string Command::evaluate_constants(std::string c_string) {
    Math math;
    std::string c_string_constants;

    // convert constants into strings
    char pi_string[10], e_string[10];
    sprintf(pi_string, "%f", math.pi);
    sprintf(e_string, "%f", math.e);

    // replace for the constants
    c_string_constants = replace_string(c_string, PI, pi_string);
    c_string_constants = replace_string(c_string_constants, E, e_string);

    return c_string_constants;
}

// find and replace all instances of the needle
std::string Command::replace_string(std::string subject, const std::string& search,
                          const std::string& replace) {
    size_t pos = 0;
    while ((pos = subject.find(search, pos)) != std::string::npos) {
         subject.replace(pos, search.length(), replace);
         pos += replace.length();
    }
    return subject;
}

double Command::get_result() {
    return result;
}

double Command::evaluate_postfix(std::string postfix_string) {
    Stack<double> op_stack;
    Operations ops;
    char curr_char;

    for (int i = 0; i < postfix_string.size(); i++) {
        curr_char = postfix_string[i];

        // if the token is an operand (number), push it on the stack
        if (is_operand(curr_char)) {
            int op_len = operand_length(i, postfix_string);
            std::string op_substr = postfix_string.substr(i, op_len);   // find the operand string
            i += op_len;                                                // jump past this substring in the loop

            double item = atof(op_substr.c_str());                      // convert ASCII subtr to double
            op_stack.push(item);
        }

        // apply the operator
        if (op_stack.size() >= 2) {
                // operators with two arguments:
                double num1, num2;
                if(curr_char == '+'){
                    num1 = op_stack.pop();
                    num2 = op_stack.pop();
                    op_stack.push(ops.add(num1,num2));
                }else if(curr_char == '*'){
                    num1 = op_stack.pop();
                    num2 = op_stack.pop();
                    op_stack.push(ops.multiply(num1,num2));
                }else if(curr_char == '/'){
                    num1 = op_stack.pop();
                    num2 = op_stack.pop();
                    op_stack.push(ops.divide(num2,num1));
                }else if(curr_char == '-'){
                    num1 = op_stack.pop();
                    num2 = op_stack.pop();
                    op_stack.push(ops.substract(num2,num1));
                }else if (curr_char == '^') {
                    num1 = op_stack.pop();
                    num2 = op_stack.pop();
                    op_stack.push(ops.exponent(num2, num1));
                }
        }
        if (op_stack.size() >= 1) {
            // operators with one argument:
            double num1;
            if(curr_char == '!') {
                num1 = op_stack.pop();
                op_stack.push(ops.factorial(num1));
            }
        }
    }

    // if the stack contains only one value, return it as a final result of the calculation
    if (op_stack.size() == 1) {
        return op_stack.pop();
    } else {
        std::cout << "Error evaluating the expression" << std::endl;
        return -1;
    }
}

std::string Command::infix_to_postfix(std::string infix_string) {
    Stack<char> op_stack;
    std::string postfix;
    char curr_char;

    for (int i = 0; i < infix_string.size(); i++) {
        curr_char = infix_string[i];

        // ignore the operand delim
        if (curr_char == '\\') continue;

        // print operands as they arrive
        if (is_operand(curr_char)) {
            int op_len = operand_length(i, infix_string);
            std::string op_substr = infix_string.substr(i, op_len);     // find the operand string
            std::string op_substr_delim = op_substr.append("\\");       // add delimeter to separate operands
            postfix.append(op_substr_delim);
            i += op_len - 1;                                            // jump past this substring in the loop
            continue;
        }

        // if the stack is empty or contains left parenthesis on top, push the incoming operator onto the stack
        // if the incoming symbol is a left parenthesis, push it on the stack
        if (curr_char == '(') {
            op_stack.push(curr_char);
        }

        // if the incoming symbol is a right parenthesis, pop the stack and print the operators until you see a left parenthesis
        else if (curr_char == ')') {
            while (op_stack.get_top_item() != -1 && op_stack.get_top_item() != '(') {
                char c = op_stack.get_top_item();
                op_stack.pop();
                postfix.push_back(c);
            }

            // now remove the left bracket
            if (op_stack.get_top_item() == '(') {
                char c = op_stack.get_top_item();
                op_stack.pop();
            }
        }

        // if an operator is scanned
        else {
            while(op_stack.get_top_item() != -1 && precedence(curr_char) <= precedence(op_stack.get_top_item()))
            {
                char c = op_stack.get_top_item();
                op_stack.pop();
                postfix.push_back(c);
            }
            op_stack.push(curr_char);
        }
    }

    // at the end of the expression, pop and print all operators on the stack
    while (op_stack.get_top_item() != -1) {
        char c = op_stack.get_top_item();
        op_stack.pop();
        postfix.push_back(c);
    }
    return postfix;
}

int Command::operand_length(int pos, std::string c_string) {
    int len = 0;
    while (is_operand(c_string[pos]) || c_string[pos] == '.') {
        pos++;
        len++;
    }
    return len;
}

bool Command::is_operand(char operand) {
    if (operand >= '0' && operand <= '9') {
        return true;
    } else {
        return false;
    }
}

int Command::precedence(char op) {
    if(op == '!')
        return 4;
    else if(op == '^')
        return 3;
    else if(op == '*' || op == '/')
        return 2;
    else if(op == '+' || op == '-')
        return 1;
    else
        return -1;
}
