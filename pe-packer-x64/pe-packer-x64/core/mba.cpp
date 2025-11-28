#include "mba.hpp"
#include "utils/utils.hpp"

using namespace asmjit;

c_mba::c_mba(c_core& g_core) : m_core(g_core){}

void c_mba::gen_math_operations() {
	switch (rand() % 4) {
	case 0:
		m_core.get_assembler()->shr(m_core.get_rand_reg(), random_value(1, 100));
		break;

	case 1:
		m_core.get_assembler()->and_(m_core.get_rand_reg(), random_value(1, 100));
		break;

	case 2:
		m_core.get_assembler()->xor_(m_core.get_rand_reg(), random_value(1, 100));
		break;

	case 3:
		m_core.get_assembler()->add(m_core.get_rand_reg(), random_value(1, 100));
		break;

	default:
		break;
	}
}

void c_mba::mba_code(c_mba::options opt) {

	int x = random_value(0, 3);
	switch (x) {

	case 0: {

		Label new_label = m_core.get_assembler()->new_label();
		gen_math_operations();

		m_core.get_assembler()->je(new_label);

		m_core.get_assembler()->mov(x86::rax, x86::rdi);
		m_core.get_assembler()->mov(x86::rbx, x86::rsi);

		m_core.get_assembler()->or_(x86::rax, x86::rbx);
		m_core.get_assembler()->push(x86::rax);

		m_core.get_assembler()->mov(x86::rax, x86::rdi);
		m_core.get_assembler()->and_(x86::rax, x86::rbx);

		m_core.get_assembler()->pop(x86::rcx);
		m_core.get_assembler()->sub(x86::rcx, x86::rax);

		m_core.get_assembler()->mov(x86::rax, x86::rcx);

		m_core.get_assembler()->push(x86::rax);
		m_core.get_assembler()->mov(x86::rbx, x86::rax);
		m_core.get_assembler()->xor_(x86::rbx, x86::rdi);

		m_core.get_assembler()->bind(new_label);

		m_core.get_assembler()->push(x86::rbp);
		m_core.get_assembler()->mov(x86::rbp, x86::rsp);
		gen_math_operations();

		m_core.get_assembler()->pop(x86::rbp);

		break;
	}

	case 1: {

		Label new_label = m_core.get_assembler()->new_label();

		gen_math_operations();

		m_core.get_assembler()->je(new_label);

		m_core.get_assembler()->mov(x86::rax, x86::rdi);
		m_core.get_assembler()->mov(x86::rbx, x86::rsi);

		m_core.get_assembler()->and_(x86::rax, x86::rbx);
		m_core.get_assembler()->push(x86::rax);

		m_core.get_assembler()->mov(x86::rax, x86::rdi);
		m_core.get_assembler()->or_(x86::rax, x86::rbx);

		m_core.get_assembler()->pop(x86::rcx);
		m_core.get_assembler()->add(x86::rcx, x86::rax);

		m_core.get_assembler()->mov(x86::rax, x86::rcx);

		m_core.get_assembler()->push(x86::rax);
		m_core.get_assembler()->mov(x86::rbx, x86::rax);
		m_core.get_assembler()->xor_(x86::rbx, x86::rdi);

		m_core.get_assembler()->bind(new_label);

		m_core.get_assembler()->push(x86::rbp);
		m_core.get_assembler()->mov(x86::rbp, x86::rsp);
		gen_math_operations();

		m_core.get_assembler()->pop(x86::rbp);

		break;
	}

	case 2: {
		Label new_label = m_core.get_assembler()->new_label();

		m_core.get_assembler()->je(new_label);

		m_core.get_assembler()->mov(x86::rax, x86::rdi);
		m_core.get_assembler()->mov(x86::rbx, x86::rsi);

		m_core.get_assembler()->xor_(x86::rax, x86::rbx);
		m_core.get_assembler()->neg(x86::rax);
		m_core.get_assembler()->push(x86::rax);

		m_core.get_assembler()->mov(x86::rax, x86::rdi);
		m_core.get_assembler()->neg(x86::rax);
		m_core.get_assembler()->and_(x86::rax, x86::rbx);

		m_core.get_assembler()->pop(x86::rcx);
		m_core.get_assembler()->add(x86::rcx, x86::rax);

		m_core.get_assembler()->mov(x86::rax, x86::rcx);

		m_core.get_assembler()->push(x86::rax);
		m_core.get_assembler()->mov(x86::rbx, x86::rax);
		m_core.get_assembler()->xor_(x86::rbx, x86::rdi);

		m_core.get_assembler()->bind(new_label);

		m_core.get_assembler()->push(x86::rbp);
		m_core.get_assembler()->mov(x86::rbp, x86::rsp);
		gen_math_operations();

		m_core.get_assembler()->pop(x86::rbp);

		break;
	}
	}
}
