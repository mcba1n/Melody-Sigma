#include "RealCommand.h"

RealCommand::RealCommand(std::string cmd)
{
    result = evaluate_handler(cmd).getReal();
}

RealCommand::~RealCommand()
{
    //dtor
}

double RealCommand::get_result() {
    return result;
}
