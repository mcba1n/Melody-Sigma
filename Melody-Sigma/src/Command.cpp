#include "Command.h"

Command::Command(std::string cmd, int md)
{
    std::string cmd_stripped = replace_string(cmd, " ", "");     // strip the white spaces
    mode = md;                                                   // set the mode
    if (mode == REAL) {
        std::string cmd_consts = evaluate_constants(cmd_stripped);
        std::string postfix = infix_to_postfix(cmd_consts);
        std::cout << "postfix exp: " << postfix << std::endl;
        result = evaluate_postfix(postfix);
    } else if (mode == COMPLEX) {
    } else if (mode == POLY) {
    } else if (mode == MATRIX) {
    } else {
        std::cout << "Invalid command mode" << std::endl;
    }
}

Command::~Command()
{
    //dtor
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
