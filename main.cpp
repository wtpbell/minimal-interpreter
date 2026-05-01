#include "./include/tiny_vm.hpp"
#include <vector>

int main()
{
    std::vector<Instruction> program;

    program.push_back(Instruction(OpCode::OP_PUSH, 2));
    program.push_back(Instruction(OpCode::OP_PUSH, 3));
    program.push_back(Instruction(OpCode::OP_ADD));
    program.push_back(Instruction(OpCode::OP_PRINT));
    program.push_back(Instruction(OpCode::OP_HALT));

    TinyVM vm(program);
    vm.Run();

    return 0;
}
