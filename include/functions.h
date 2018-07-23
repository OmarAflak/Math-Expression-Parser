#ifndef FUNCTIONS
#define FUNCTIONS

#include <string>
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
static std::unordered_map<char, int> _op_priorities = {
    {_OP_MULTIPLY, 0},
    {_OP_POWER, 1},
    {_OP_DIVIDE, 2},
    {_OP_ADD, 3},
    {_OP_SUBTRACT, 4},
};
static std::unordered_map<char, std::string> const _op_map_functions = {
    {_OP_ADD, _ADD},
    {_OP_SUBTRACT, _SUBTRACT},
    {_OP_MULTIPLY, _MULTIPLY},
    {_OP_DIVIDE, _DIVIDE},
    {_OP_POWER, _POWER}
};

#endif
