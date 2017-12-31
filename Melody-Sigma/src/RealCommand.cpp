#include "RealCommand.h"

RealCommand::RealCommand(std::string cmd)
{
    // map available strings to functions
    std::string cmd_funcs = evaluate_functions(cmd);
    std::string cmd_stripped = replace_string(cmd_funcs, " ", "");
    std::string cmd_consts = evaluate_constants(cmd_stripped);
    std::string postfix = infix_to_postfix(cmd_consts);

    std::cout << "postfix exp: " << postfix << std::endl;
    result = evaluate_postfix(postfix);
}

RealCommand::~RealCommand()
{
    //dtor
}
