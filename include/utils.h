
#ifndef _SL_UTILS_H_
#define _SL_UTILS_H_

#include <pwd.h>
#include <string>
#include <sys/types.h>
#include <unistd.h>
#include <vector>

namespace utils {

bool char_of_alphabet(std::string c);
bool char_of_num(std::string c);

void ltrim(std::string &s);
void rtrim(std::string &s);
void trim(std::string &s);
std::string ltrim_copy(std::string s);
std::string rtrim_copy(std::string s);
std::string trim_copy(std::string s);

std::string get_home_dir();
std::string get_current_dir();
std::vector<std::string> get_files_in_dir(std::string dir);
std::vector<std::string> get_dirs_in_dir(std::string dir);
std::vector<std::string> read_file(std::string filename);
void write_file(std::string filename, std::vector<std::string> lines);
std::string read_json_string(std::string filename, std::string key);

} // namespace utils

#endif
