#include "ComplexCommand.h"

ComplexCommand::ComplexCommand(std::string cmd)
{
    std::string cmd_funcs = evaluate_functions(cmd);
    std::string cmd_stripped = replace_string(cmd_funcs, " ", "");
    std::string cmd_consts = evaluate_constants(cmd_stripped);
    std::string postfix = infix_to_postfix(cmd_consts);
    std::cout << "POSTFIX:" << postfix << std::endl;
}

ComplexCommand::~ComplexCommand()
{
    //dtor
}

Complex ComplexCommand::get_result() {
    return result;
}

bool ComplexCommand::is_complex(Complex z) {
    if (z.getImag() == NULL) return true;
    else return false;
}
