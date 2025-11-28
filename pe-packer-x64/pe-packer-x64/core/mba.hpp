#pragma once
#include "core.hpp"

class c_mba {
public:
	c_mba(c_core& g_core);
	struct options {};
	void mba_code(c_mba::options opt);
private:
	c_core& m_core;
	void gen_math_operations();
};
