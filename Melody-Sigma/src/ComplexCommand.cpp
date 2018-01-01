#include "ComplexCommand.h"

ComplexCommand::ComplexCommand(std::string cmd)
{
    result = evaluate_handler(cmd);
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
