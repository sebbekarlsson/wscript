#include <boost/variant.hpp>
#include <boost/any.hpp>
#include <string>
#include "AST/AST_Object.hpp"
#include <vector>


typedef boost::variant<
    bool,
    float,
    int,
    std::string,
    AST*,
    std::vector<boost::any>
> anything;
