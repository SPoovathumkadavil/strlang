#ifndef _SL_TOKENIZER_H_
#define _SL_TOKENIZER_H_

#include <string>
#include <vector>

namespace tokenizer {

enum TokenType {
  // K_FILE,         // .file
  // K_USE,          // .use
  // K_CHAPTER,      // .chapter
  // K_BEGIN,        // .begin
  // K_END,          // .end
  // K_OUT,          // .out
  // K_SLEEP,        // .sleep
  // K_INCREMENT,    // .increment
  // K_DEFINE,       // .define
  // K_COMPARE,      // .compare
  // K_BACK,         // .back
  // K_FROM,         // .from
  IDENTIFIER,     // non-dot operators
  S_ARROW,        // ->
  D_ARROW,        // =>
  OF,             // ::
  DOT_IDENTIFIER, // .function or .variable call
  O_PARENTHESIS,  // (
  C_PARENTHESIS,  // )
  O_S_BRACKET,    // [
  C_S_BRACKET,    // ]
  O_A_BRACKET,    // <
  C_A_BRACKET,    // >
  COLON,          // :
  L_NUMBER,       // number literal
  L_STRING,       // string literal
  HYPHEN,         // -
  EQUALS,         // =
  NONE
};

struct Token {
  TokenType type;
  std::string literal;
};

/// @brief Collapse continued lines
std::vector<std::string> collapse_lines(std::vector<std::string> lines);
/// @brief Convert a line into a vector of Tokens
std::vector<Token> extract_tokens(std::string line);

} // namespace tokenizer

#endif
