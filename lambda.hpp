#ifndef LAMBDA_HPP
#define LAMBDA_HPP

#include <boost/variant.hpp>
    using boost::apply_visitor;
    using boost::get;
    template <typename T>
    using recursive = boost::recursive_wrapper<T>;
    using boost::static_visitor;
    using boost::variant;
#include <iostream>
    using std::cout;
    using std::endl;
#include <string>
    using std::string;
    using std::to_string;

struct concat {
    string result;
    concat(std::initializer_list<string> const & strings) {
        for (auto s : strings)
            result += s;
    }
    operator string() const { return result; }
};

string to_string(string s) {return s;}

template <typename T>
void print(T x) {cout << to_string(x) << endl;}

struct ToString : static_visitor<string> {
    template <typename T> string operator()(T const & x) const {
        return to_string(x);
    }
};

#endif // LAMBDA_HPP
