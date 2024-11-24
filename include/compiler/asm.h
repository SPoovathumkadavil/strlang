#ifndef _SL_ASM_
#define _SL_ASM_

#include "compiler/cpu.h"
#include "lexer/tokenizer.h"
#include <string>
#include <vector>

std::vector<std::string> to_asm(std::vector<tokenizer::Token> tokens,
                                cpu_architecture arch);

#endif
