#ifndef FUNCTIONS
#define FUNCTIONS

#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

// delimiters
static char const _LDEL = '(';
static char const _RDEL = ')';

// functions
static std::string const _EXP = "exp";
static std::string const _LOG = "log";
static std::string const _COS = "cos";
static std::string const _SIN = "sin";

static std::unordered_set<std::string> const _functions = {
    _EXP,
    _LOG,
    _COS,
    _SIN,
};

// operations
static char const _ADD = '+';
static char const _SUBTRACT = '-';
static char const _MULTIPLY = '*';
static char const _DIVIDE = '/';
static char const _POWER = '^';

static std::unordered_set<char> const _operations = {
    _ADD,
    _SUBTRACT,
    _MULTIPLY,
    _DIVIDE,
    _POWER
};
static std::vector<char> _operations_prio = {
    _POWER,
    _MULTIPLY,
    _DIVIDE
};


#endif
