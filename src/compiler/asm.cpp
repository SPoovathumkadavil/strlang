
#include "compiler/asm.h"
#include "lexer/tokenizer.h"

std::vector<std::string> to_asm(std::vector<tokenizer::Token> tokens,
                                cpu_architecture arch) {
  std::vector<std::string> out;

  // asm preamble
  switch (arch) {
  case ARM64:
    out.push_back(".global _start");
    out.push_back(".align 2");
    out.push_back("_start:");
    out.push_back("\tjmp _main");
    out.push_back("\tmov x0, #0");
    out.push_back("\tmov x16, #1");
    out.push_back("\tsvc 0");
    break;
  default:
    break;
  }

  for (tokenizer::Token token : tokens) {
  }

  return out;
}
