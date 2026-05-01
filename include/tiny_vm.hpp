#ifndef TINY_VM_HPP
#define TINY_VM_HPP

#include <vector>

enum class OpCode
{
	OP_PUSH,
	OP_ADD,
	OP_SUB,
	OP_MUL,
	OP_DIV,
	OP_PRINT,
	OP_HALT
};

struct Instruction
{
	OpCode	op;
	int		operand;
	Instruction(OpCode opcode, int value = 0): op(opcode), operand(value){}
};

class TinyVM
{
	public:
		TinyVM(const std::vector<Instruction>& program);
		void Run();

	private:
		std::vector<int>			stack_;
		std::vector<Instruction>	program_;
		std::size_t					program_count_;

		int Pop();
};

#endif
