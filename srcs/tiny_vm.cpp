#include "../include/tiny_vm.hpp"
#include <vector>
#include <stdexcept>
#include <iostream>

TinyVM::TinyVM(const std::vector<Instruction>& program)
        : program_(program), program_count_(0)
{}

void TinyVM::Run()
{
	while (program_count_ < program_.size())
	{
		const Instruction& instr = program_[program_count_];

		switch (instr.op)
		{
			case OpCode::OP_PUSH:
			{
				stack_.push_back(instr.operand);
				program_count_++;
				break;
			}
			case OpCode::OP_ADD:
			{
				int b = Pop();
				int a = Pop();
				stack_.push_back(a + b);
				program_count_++;
				break;
			}
			case OpCode::OP_SUB:
			{
				int b = Pop();
				int a = Pop();
				stack_.push_back(a - b);
				program_count_++;
				break;
			}
			case OpCode::OP_MUL:
			{
				int b = Pop();
				int a = Pop();
				stack_.push_back(a * b);
				program_count_++;
				break;
			}
			case OpCode::OP_DIV:
			{
				int b = Pop();
				int a = Pop();
				if (b == 0)
					throw std::runtime_error("division by zero");
				stack_.push_back(a / b);
				program_count_++;
				break;
			}
			case OpCode::OP_PRINT:
			{
				int value = Pop();
				std::cout << value << "\n";
				program_count_++;
				break;
			}
			case OpCode::OP_HALT:
				return ;
		}
	}
}

int TinyVM::Pop()
{
	if (stack_.empty())
		throw std::runtime_error("stack underflow");
	int value = stack_.back();
	stack_.pop_back();
	return value;
}
