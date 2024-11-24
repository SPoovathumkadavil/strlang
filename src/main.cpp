#include "main.h"

#include "compiler/asm.h"
#include "compiler/cpu.h"
#include "lexer/tokenizer.h"
#include "utils.h"
#include <cstdio>

/* Boiler Consts */

const std::string HOME_DIR = utils::get_home_dir();
const std::string PROJECT_NAME = "storylang";
const std::string LOC_FILE = HOME_DIR + "/.loc.json";
std::string LIBRARY_DIR =
    utils::read_json_string(LOC_FILE, "library") + "/" + PROJECT_NAME;
std::string CONFIG_DIR =
    utils::read_json_string(LOC_FILE, "config") + "/" + PROJECT_NAME;

void handle_test_args(int argc, char *argv[]) {
  for (int i = 1; i < argc; i++) {
    // flags -d and -c to change dependencies and config directories
    if (std::string(argv[i]) == "-d") {
      if (i + 1 < argc) {
        LIBRARY_DIR = argv[i + 1];
      }
    }
    if (std::string(argv[i]) == "-c") {
      if (i + 1 < argc) {
        CONFIG_DIR = argv[i + 1];
      }
    }
    // alternatively use -t to set test mode and change dirs automatically
    if (std::string(argv[i]) == "-t") {
      LIBRARY_DIR = "dependencies";
      CONFIG_DIR = "config";
    }
  }
}

int main(int argc, char *argv[]) {
  handle_test_args(argc, argv);

  for (int i = 1; i < argc; i++) {
    if (std::string(argv[i]) == "-f") {
      if (i + 1 < argc) {
        std::vector<std::string> lines = utils::read_file(argv[i + 1]);
        lines = tokenizer::collapse_lines(lines);
        utils::write_file("collapsed.out", lines);
        int i = 7;
        std::vector<tokenizer::Token> ts = tokenizer::extract_tokens(lines[i]);
        // std::printf("%s\n", lines[i].c_str());
        // std::printf("Tokens (line %i):\n", i);
        // for (tokenizer::Token t : ts) {
        //   std::printf("%i - %s\n", t.type, t.literal.c_str());
        // }
        std::vector<std::string> asm_vals = to_asm(ts, cpu_architecture::ARM64);
        utils::write_file("asmtest.s", asm_vals);
      }
    }
  }

  return 0;
}
