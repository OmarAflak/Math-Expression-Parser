#ifndef FUNCTIONS
#define FUNCTIONS

#include <string>
#include <unordered_set>

static std::string const _LDEL = "(";
static std::string const _RDEL = ")";
static std::string const _SEP = ",";

static std::string const _ADD = "add";
static std::string const _SUBTRACT = "subtract";
static std::string const _MULTIPLY = "multiply";
static std::string const _DIVIDE = "divide";
static std::unordered_set<std::string> const _functions = {_ADD, _SUBTRACT, _MULTIPLY, _DIVIDE};

#endif
