
#ifndef _SL_PARSER_AST_H_
#define _SL_PARSER_AST_H_

#include <string>
#include <vector>

namespace AST {

class Node {
public:
    virtual ~Node() = default;
};

class File : Node {
public:
    std::string name;
    std::vector<std::unique_ptr<Node>> body;
};

class Use : Node {
public:
    std::string chapter;
    std::string source;
};

class Chapter : Node {
public:
    std::string name;
    std::vector<std::unique_ptr<Node>> body;
};

/// @brief A parameter is defined for stages.
///        Example syntax: `.blah_blah : text(.string)::"hello"`.
///        In this case, text is the name, string is the type, and
///        "hello" is the initial value.
class Parameter : Node {
public:
    std::string name;
    std::string type;
    std::string initial_value;
};

/// @brief actual usage of Parameter node
class Argument : Node {
public:
    std::string param;
    std::string value;
};

/// @brief A stage is basically a function.
class Stage : Node {
public:
    std::string name;
    std::vector<std::unique_ptr<Parameter>> parameters;
    std::vector<std::unique_ptr<Node>> body;
};

/// @brief An expression is akin to a function call.
class Expression : Node {
public:
    std::string stage_identifier;
    std::vector<std::unique_ptr<Argument>> args; 
};

}

#endif