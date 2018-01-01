#include "Command.h"

Command::Command()
{
    //ctor
}

Command::~Command()
{
    //dtor
}

Complex Command::evaluate_handler(std::string c_string) {
    std::string cmd_funcs = evaluate_functions(c_string);
    std::string cmd_stripped = replace_string(cmd_funcs, " ", "");
    std::string cmd_consts = evaluate_constants(cmd_stripped);
    std::string postfix = infix_to_postfix(cmd_consts);
    return evaluate_postfix(postfix);
}

// find all function names and their arguments in a string, then return them
std::vector<fContainer> Command::find_args(std::string c_string) {
    std::vector<fContainer> funcs;
    fContainer *currFunc = NULL;
    std::string temp_name;
    int temp_arg_index = 0, num_brackets = 0, num_funcs = 0, arg_len = 0;

    for (int i = 0; i < c_string.size(); i++) {
        char curr_char = c_string[i];
        char next_char = c_string[i + 1];

        // record function arguments
        if (curr_char == '(' && ++num_brackets == num_funcs) {
            temp_arg_index = i;
            arg_len = 0;
        } else if (curr_char == ')' && num_brackets == num_funcs) {
            currFunc->arg = c_string.substr(temp_arg_index + 1, arg_len);
            funcs.push_back(*currFunc);
        } else arg_len++;

        // ignore the letter 'i' with a number before it, since it is not a func name
        if (curr_char == 'i' && is_operand(c_string[i - 1])) continue;

        // record any function names, then splice them out
        if (isalpha(curr_char)) {
            temp_name.push_back(curr_char);
            if (!isalpha(next_char)) {
                // end of a word, so a function is found
                currFunc = new fContainer;                  // allocate memory for func container
                currFunc->name = temp_name;
                currFunc->index = i - temp_name.length();   // start index of func
                num_funcs++;
                temp_name.clear();
            }
        }
    }
    return funcs;
}

std::string Command::evaluate_functions(std::string c_string) {
    std::vector<fContainer> funcs = find_args(c_string);
    fContainer *myFunc;
    Operations ops;

    // return original string if no funcs found
    if (funcs.size() == 0) return c_string;

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
            pch = strtok(NULL, ",");
        }

        // make the func call
        if (args.size() == 1) args.push_back(""); // for one arg
        Complex result = function_call(myFunc->name, args[0], args[1]);
        std::string str_result = result.toString();

        // replace in original string
        int str_func_len = myFunc->name.length() + myFunc->arg.length() + 2;    // add two for the brackets
        c_string = replace_string(c_string, c_string.substr(myFunc->index + 1, str_func_len), str_result);
    }
    return c_string;
}

Complex Command::function_call(std::string name, std::string arg1, std::string arg2) {
    Operations ops;
    Complex c_arg1, c_arg2;
    c_arg1 = evaluate_handler(arg1);
    c_arg2 = evaluate_handler(arg2);
    if (name == "add") {
        return ops.add(c_arg1, c_arg2);
    } else if (name == "fib") {
        Complex z(ops.fibonacci(c_arg1.getReal()), NULL);
        return z;
    }
    // TODO: add more functions here
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

// convert a real or imag term into a Complex object
Complex Command::str_to_complex(std::string complx_str) {
    std::string str_coeff = replace_string(complx_str, "i", "");
    double coeff = atof(str_coeff.c_str());
    Complex z;
    if (complx_str.length() ==  str_coeff.length()) z.setReal(coeff);   // check if real or imag term
    else z.setImag(coeff);
    return z;
}

Complex Command::double_to_complex(double x) {
    Complex z;
    z.setReal(x);
    return z;
}

Complex Command::evaluate_postfix(std::string postfix_string) {
    std::vector<Complex> op_stack;
    Operations ops;
    char curr_char;
    Complex val;

    for (int i = 0; i < postfix_string.size(); i++) {
        curr_char = postfix_string[i];

        // if the token is an operand (number), push it on the stack
        if (is_operand(curr_char)) {
            int op_len = operand_length(i, postfix_string);
            std::string op_substr = postfix_string.substr(i, op_len);   // find the operand string
            i += op_len;                                                // jump past this substring in the loop
            Complex item = str_to_complex(op_substr);
            op_stack.push_back(item);
        } else {
            // apply the operator
            int end_index = op_stack.size() - 1;
            if (op_stack.size() >= 2) {
                    // operators with two args:
                    Complex num1 = op_stack[end_index];
                    op_stack.pop_back();
                    Complex num2 = op_stack[end_index - 1];
                    op_stack.pop_back();
                    if(curr_char == '+'){
                        val = ops.add(num1, num2);
                    }else if(curr_char == '*'){
                        val = ops.multiply(num1, num2);
                    }else if(curr_char == '/'){
                        val = ops.divide(num2, num1);
                    }else if(curr_char == '-'){
                        val = ops.substract(num2, num1);
                    }else if (curr_char == '^'){
                        // assume only real numbers make it here
                        val = double_to_complex( ops.exponent(num2.getReal(), num1.getReal()) );
                    }
                    op_stack.push_back(val);
            }
            else if (op_stack.size() >= 1) {
                // operators with one arg:
                Complex num1 = op_stack[end_index];
                op_stack.pop_back();
                if(curr_char == '!') {
                    // assume only real numbers make it here
                    val = double_to_complex( ops.factorial(num1.getReal()) );
                }
                op_stack.push_back(val);
            }
        }
    }
    return val;
}

std::string Command::infix_to_postfix(std::string infix_str) {
    std::vector<char> op_stack;
    std::string postfix;
    char curr_char;

    // trick to fix neg sign at the front and when no ops are used
    std::string infix_string = "0+";
    infix_string.append(infix_str);

    for (int i = 0; i < infix_string.size(); i++) {
        curr_char = infix_string[i];

        // ignore the operand delim
        if (curr_char == '\\') continue;

        // if an operator is scanned
        else if (is_operator(curr_char)) {
            while(!op_stack.empty() && precedence(curr_char) < precedence(op_stack.back())) {
                char c = op_stack.back();
                postfix.push_back(c);
                op_stack.pop_back();
            }
            op_stack.push_back(curr_char);
        }

        // print operands as they arrive
        else if (is_operand(curr_char)) {
            int op_len = operand_length(i, infix_string);
            std::string op_substr = infix_string.substr(i, op_len);     // find the operand string
            std::string op_substr_delim = op_substr.append("\\");       // add delimeter to separate operands
            postfix.append(op_substr_delim);
            i += op_len - 1;                                            // jump past this substring in the loop
            continue;
        }

        // if the stack is empty or contains left parenthesis on top, push the incoming operator onto the stack
        // if the incoming symbol is a left parenthesis, push it on the stack
        else if (curr_char == '(') {
            op_stack.push_back(curr_char);
        }

        // if the incoming symbol is a right parenthesis, pop the stack and print the operators until you see a left parenthesis
        else if (curr_char == ')') {
            while (!op_stack.empty() && op_stack.back() != '(') {
                char c = op_stack.back();
                op_stack.pop_back();
                postfix.push_back(c);
            }
            op_stack.pop_back();
        }
    }

    // at the end of the expression, pop and print all operators on the stack
    while (!op_stack.empty()) {
        char c = op_stack.back();
        postfix.push_back(c);
        op_stack.pop_back();
    }
    return postfix;
}

int Command::operand_length(int pos, std::string c_string) {
    int len = 0;
    while (is_operand(c_string[pos]) || c_string[pos] == '.' || c_string[pos] == 'i') {
        pos++;
        len++;
    }
    return len;
}

bool Command::is_operand(char operand) {
    if (operand >= '0' && operand <= '9') return true;
    else return false;
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

bool Command::is_operator(char c) {
	if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^') return true;
    else return false;
}
