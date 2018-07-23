#ifndef FUNCTIONS
#define FUNCTIONS

#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

static std::string const _LDEL = "(";
static std::string const _RDEL = ")";
static std::string const _SEP = ",";

static std::string const _ADD = "add";
static std::string const _SUBTRACT = "subtract";
static std::string const _MULTIPLY = "multiply";
static std::string const _DIVIDE = "divide";
static std::string const _POWER = "pow";

static char const _OP_ADD = '+';
static char const _OP_SUBTRACT = '-';
static char const _OP_MULTIPLY = '*';
static char const _OP_DIVIDE = '/';
static char const _OP_POWER = '^';

static std::unordered_set<std::string> const _functions = {_ADD, _SUBTRACT, _MULTIPLY, _DIVIDE, _POWER};
static std::unordered_set<char> const _op_functions = {_OP_ADD, _OP_SUBTRACT, _OP_MULTIPLY, _OP_DIVIDE, _OP_POWER};
static std::vector<char> _op_priorities = {_OP_POWER, _OP_MULTIPLY, _OP_DIVIDE};
static std::unordered_map<char, std::string> const _op_map_functions = {
    {_OP_ADD, _ADD},
    {_OP_SUBTRACT, _SUBTRACT},
    {_OP_MULTIPLY, _MULTIPLY},
    {_OP_DIVIDE, _DIVIDE},
    {_OP_POWER, _POWER},
};

#endif
