#include <boost/variant.hpp>
#include <string>
#include "AST/AST_Object.hpp"


typedef boost::variant<bool, float, int, std::string, AST_Object*> anything;
