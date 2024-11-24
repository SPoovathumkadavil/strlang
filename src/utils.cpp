
#include "utils.h"
#include <algorithm>
#include <cctype>
#include <filesystem>
#include <fstream>
#include <regex>

namespace utils {

bool char_of_alphabet(std::string c) {
  std::regex r{"[a-zA-Z]"};
  std::smatch m;
  std::regex_search(c, m, r);
  if (m.size() > 0)
    return true;
  return false;
}

bool char_of_num(std::string c) {
  std::regex r{"[0-9]"};
  std::smatch m;
  std::regex_search(c, m, r);
  if (m.size() > 0)
    return true;
  return false;
}

// trim from start (in place)
void ltrim(std::string &s) {
  s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
            return !std::isspace(ch);
          }));
}

// trim from end (in place)
void rtrim(std::string &s) {
  s.erase(std::find_if(s.rbegin(), s.rend(),
                       [](unsigned char ch) { return !std::isspace(ch); })
              .base(),
          s.end());
}

// trim from both ends (in place)
void trim(std::string &s) {
  rtrim(s);
  ltrim(s);
}

// trim from start (copying)
std::string ltrim_copy(std::string s) {
  ltrim(s);
  return s;
}

// trim from end (copying)
std::string rtrim_copy(std::string s) {
  rtrim(s);
  return s;
}

// trim from both ends (copying)
std::string trim_copy(std::string s) {
  trim(s);
  return s;
}

// get home directory
// if HOME environment variable is not set, getpwuid() is used to get the home
// directory
std::string get_home_dir() {
  const char *homedir;
  if ((homedir = getenv("HOME")) == NULL)
    homedir = getpwuid(getuid())->pw_dir;
  return std::string(homedir);
}

// get current working directory, this is the directory where the executable is
// run from
std::string get_current_dir() { return std::filesystem::current_path(); }

std::vector<std::string> get_files_in_dir(std::string dir) {
  std::vector<std::string> files;
  for (const auto &entry : std::filesystem::directory_iterator(dir)) {
    if (!std::filesystem::is_directory(entry.path())) {
      files.push_back(entry.path());
    }
  }
  return files;
}

std::vector<std::string> get_dirs_in_dir(std::string dir) {
  std::vector<std::string> dirs;
  for (const auto &entry : std::filesystem::directory_iterator(dir)) {
    if (std::filesystem::is_directory(entry.path())) {
      dirs.push_back(entry.path());
    }
  }
  return dirs;
}

std::vector<std::string> read_file(std::string filename) {
  std::vector<std::string> lines;
  std::ifstream file(filename);
  if (file.is_open()) {
    std::string line;
    while (std::getline(file, line)) {
      lines.push_back(line);
    }
    file.close();
  }
  return lines;
}

void write_file(std::string filename, std::vector<std::string> lines) {
  std::ofstream file(filename);
  if (file.is_open()) {
    for (std::string line : lines) {
      file << line << std::endl;
    }
    file.close();
  }
}

std::string read_json_string(std::string filename, std::string key) {
  std::ifstream file(filename);
  if (file.is_open()) {
    std::string line;
    while (std::getline(file, line)) {
      if (line.find(key) != std::string::npos) {
        std::string value = line.substr(line.find(":") + 1);
        // remove leading and trailing whitespaces and quotes
        value.erase(0, value.find_first_not_of(" \t\n\r\f\v\""));
        value.erase(value.find_last_not_of(" \t\n\r\f\v\"") + 1);
        return value;
      }
    }
    file.close();
  }
  return "";
}

} // namespace utils
