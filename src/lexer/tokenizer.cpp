
#include "lexer/tokenizer.h"
#include "utils.h"
#include <cctype>
#include <stdexcept>

namespace tokenizer {

std::vector<std::string> collapse_lines(std::vector<std::string> lines) {
  std::vector<std::string> tmp;
  bool c_a = false;
  for (int i = 0; i < (int)lines.size(); i++) {
    bool c_b = false;
    std::string line = lines[i];
    if (line == "")
      continue;
    line = utils::trim_copy(line);
    if (line.at(line.length() - 1) == '\\') {
      line.erase(line.length() - 1);
      c_b = true;
    }
    if (c_a)
      tmp[tmp.size() - 1] = tmp[tmp.size() - 1] + line;
    else
      tmp.push_back(
          line); // fixme: only functions if the first line doesn't break
    c_a = c_b;
  }
  return tmp;
}

std::vector<Token> extract_tokens(std::string line) {
  // std::printf("%s\n", line.c_str());
  std::vector<Token> tokens;
  TokenType processing = TokenType::NONE;
  std::string str;
  bool capture = false;
  for (int i = 0; i < (int)line.length(); i++) {

    std::string c = line.substr(i, 1);

    switch (processing) {
    case TokenType::L_STRING:
      if (c != "\"") {
        str += c;
        continue;
      }
      break;
    default:
      break;
    }

    // alpha check
    if (utils::char_of_alphabet(c) || c == "_") {
      switch (processing) {
      case TokenType::NONE:
        processing = TokenType::IDENTIFIER;
        str = "";
        break;
      case TokenType::L_NUMBER:
        throw std::invalid_argument("Letter Provided In Number.");
        break;
      default:
        break;
      }
      // std::printf("id %s\n", c.c_str());
      str += c;
    }

    // num check
    if (utils::char_of_num(c)) {
      switch (processing) {
      case TokenType::NONE:
        processing = TokenType::L_NUMBER;
        break;
      default:
        break;
      }
      str += c;
    }

    // dot check
    if (c == ".") {
      switch (processing) {
      case TokenType::NONE:
        processing = TokenType::DOT_IDENTIFIER;
        break;
      default: // todo: specify where allowed and throw if found non-agreeable
               // items
        str += ".";
      }
    }

    // single char check
    if (c == "(") {
      switch (processing) {
      case TokenType::NONE:
        processing = TokenType::O_PARENTHESIS;
        str = "(";
        capture = true;
        break;
      case TokenType::IDENTIFIER:
      case TokenType::DOT_IDENTIFIER:
        capture = true;
        i--;
        break;
      default:
        str += c;
      }
    } else if (c == ")") {
      switch (processing) {
      case TokenType::NONE:
        processing = TokenType::C_PARENTHESIS;
        str = ")";
        capture = true;
        break;
      case TokenType::IDENTIFIER:
      case TokenType::DOT_IDENTIFIER:
        capture = true;
        i--;
        break;
      default:
        str += c;
      }
    }

    if (c == "[") {
      switch (processing) {
      case TokenType::NONE:
        processing = TokenType::O_S_BRACKET;
        str = "[";
        capture = true;
        break;
      case TokenType::IDENTIFIER:
      case TokenType::DOT_IDENTIFIER:
        capture = true;
        i--;
        break;
      default:
        str += c;
      }
    } else if (c == "]") {
      switch (processing) {
      case TokenType::NONE:
        processing = TokenType::C_S_BRACKET;
        str = "]";
        capture = true;
        break;
      case TokenType::IDENTIFIER:
      case TokenType::DOT_IDENTIFIER:
        capture = true;
        i--;
        break;
      default:
        str += c;
      }
    }

    if (c == "<") {
      switch (processing) {
      case TokenType::NONE:
        processing = TokenType::O_A_BRACKET;
        str = "<";
        capture = true;
        break;
      case TokenType::IDENTIFIER:
      case TokenType::DOT_IDENTIFIER:
        capture = true;
        i--;
        break;
      default:
        str += c;
      }
    } else if (c == ">") {
      switch (processing) {
      case TokenType::NONE:
        processing = TokenType::C_A_BRACKET;
        str = ">";
        capture = true;
        break;
      case TokenType::IDENTIFIER:
      case TokenType::DOT_IDENTIFIER:
        capture = true;
        i--;
        break;
      case TokenType::HYPHEN:
        str += ">";
        processing = TokenType::S_ARROW;
        capture = true;
        break;
      case TokenType::EQUALS:
        str += ">";
        processing = TokenType::D_ARROW;
        capture = true;
        break;
      default:
        str += c;
      }
    }

    if (c == "-") {
      switch (processing) {
      case TokenType::NONE:
        processing = TokenType::HYPHEN;
        str = c;
        break;
      case TokenType::L_NUMBER:
      case TokenType::IDENTIFIER:
      case TokenType::DOT_IDENTIFIER:
        capture = true;
        i--;
        break;
      default:
        str += c;
      }
    }

    if (c == ":") {
      switch (processing) {
      case TokenType::NONE:
        processing = TokenType::COLON;
        str = ":";
        if (i + 1 != (int)line.length()) {
          if (line.substr(i + 1, 1) != ":")
            capture = true;
          else {
            processing = TokenType::OF;
            str = "::";
            capture = true;
            i++;
          }
        }
        break;
      case TokenType::IDENTIFIER:
      case TokenType::DOT_IDENTIFIER:
        capture = true;
        i--;
        break;
      default:
        str += ":";
      }
    }

    if (c == "\"") {
      switch (processing) {
      case TokenType::NONE:
        processing = TokenType::L_STRING;
        break;
      case TokenType::L_STRING:
        capture = true;
        break;
      default:
        break;
      }
    }

    // printf("%i\n", i);
    if (c == " " || i + 1 == (int)line.length()) {
      switch (processing) {
      case TokenType::DOT_IDENTIFIER:
      case TokenType::IDENTIFIER:
      case TokenType::L_NUMBER:
        capture = true;
      default:
        break;
      }
    } else if (processing == TokenType::NONE) {
      // todo: error out?
    }

    if (capture) {
      tokens.push_back(Token{processing, str});
      capture = false;
      processing = TokenType::NONE;
      str = "";
    }
  }
  return tokens;
}

} // namespace tokenizer
