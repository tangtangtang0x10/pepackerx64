#pragma once
#include "asmjit/asmjit.h"

// AsmJit兼容层 - 为旧API提供兼容性

namespace asmjit_compat {

// 检查Operand是否为寄存器
inline bool isOperandReg(const asmjit::Operand& op) {
    return op.isReg();
}

// 检查Operand是否为立即数  
inline bool isOperandImm(const asmjit::Operand& op) {
    return op.isImm();
}

// 获取代码大小
inline size_t getCodeSize(asmjit::CodeHolder* holder) {
    return holder->codeSize();
}

// 获取代码buffer指针
inline const uint8_t* getBufferData(asmjit::CodeHolder* holder) {
    asmjit::CodeBuffer& buf = holder->sectionById(0)->buffer();
    return buf.data();
}

// 创建新标签
inline asmjit::Label newLabel(asmjit::x86::Assembler* assembler) {
    return assembler->newLabel();
}

} // namespace asmjit_compat
