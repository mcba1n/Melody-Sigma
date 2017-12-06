#include "Command.h"
#include "Operations.h"

Command::Command(std::string cmd)
{
    std::string postfix = infix_to_postfix(cmd);
    std::cout << "Postfix expression: " << postfix << std::endl;
    result = evaluate_postfix(postfix);
}

Command::~Command()
{
    //dtor
}

int Command::get_result() {
    return result;
}

int Command::evaluate_postfix(std::string postfix_string) {
    Stack op_stack;
    Operations ops;
    char curr_char;

    for (int i = 0; i < postfix_string.size(); i++) {
        curr_char = postfix_string[i];

        // if the token is an operand (number), push it on the stack
        if (is_operand(curr_char)) {
            int item = curr_char - '0';     // convert ASCII to integer
            op_stack.push(item);
        }

        // apply the operator
        else if (op_stack.size() >= 2) {
                int num1 = op_stack.pop();
                // check which operator we have and pop the rest of the numbers should we need it
                if(curr_char == '+'){
                    int num2 = op_stack.pop();
                    op_stack.push(ops.add(num1,num2));
                }else if(curr_char == '*'){
                    int num2 = op_stack.pop();
                    op_stack.push(ops.multiply(num1,num2));
                }else if(curr_char == '/'){
                    int num2 = op_stack.pop();
                    op_stack.push(ops.multiply(num1,num2));
                }else if(curr_char == '-'){
                    int num2 = op_stack.pop();
                    op_stack.push(ops.substract(num1,num2));
                }else if(curr_char == '!')
                    op_stack.push(ops.factorial(num1));
                // add more here
                 else {
                    std::cout << "Invalid operator found" << std::endl;
                    return -1;
                }
        } else {
            std::cout << "Invalid number of arguments" << std::endl;
            return -1;
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
    Stack op_stack;
    std::string postfix;
    char curr_char, top_item;

    for (int i = 0; i < infix_string.size(); i++) {
        curr_char = infix_string[i];
        if (!op_stack.is_empty())   top_item = op_stack.get_top_item();
        else top_item = NULL;

        // print operands as they arrive
        if (is_operand(curr_char)) {
            postfix.push_back(curr_char);
            continue;
        }

        // if the stack is empty or contains left parenthesis on top, push the incoming operator onto the stack
        // if the incoming symbol is a left parenthesis, push it on the stack
        if (op_stack.is_empty() || top_item == '(' || curr_char == '(') {
            op_stack.push(curr_char);
        }

        // if the incoming symbol is a right parenthesis, pop the stack and print the operators until you see a left parenthesis
        else if (curr_char == ')') {
            char temp_char;
            while (true) {
                temp_char = op_stack.pop();
                if (temp_char == '(') break;
                else postfix.push_back(temp_char);
            }
        }

        // if an operator is scanned
        else {
            while(!op_stack.is_empty() && precedence(curr_char) <= precedence(top_item))
            {
                char c = op_stack.get_top_item();
                op_stack.pop();
                postfix.push_back(c);
            }
            op_stack.push(curr_char);
        }
    }

    // at the end of the expression, pop and print all operators on the stack
    while (!op_stack.is_empty()) {
        char temp_char = op_stack.pop();
        postfix.push_back(temp_char);

        // no parentheses should remain
        if (temp_char == ')' || temp_char == '(') {
            std::cout << "Bracket error" << std::endl;
            return NULL;
        }
    }
    return postfix;
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
    if(op == '^')
        return 3;
    else if(op == '*' || op == '/')
        return 2;
    else if(op == '+' || op == '-')
        return 1;
    else
        return -1;
}
