#include "lambda.hpp"

// Definition //////////////////////////////////////////////////////////////////

struct App;
struct Lam;

using Var = string;
using Expr = variant<Var, recursive<App>, recursive<Lam>>;
struct App {Expr func, arg;};
struct Lam {Var var; Expr body;};

// Visualization ///////////////////////////////////////////////////////////////

string to_string(Expr expr);

string to_string(App app) {
    return concat{"(", to_string(app.func), " ", to_string(app.arg), ")"};
}

string to_string(Lam lam) {
    return concat{
        "(λ ", to_string(lam.var), " . ", to_string(lam.body), ")"
    };
}

string to_string(Expr expr) {return apply_visitor(ToString(), expr);}

// Test ////////////////////////////////////////////////////////////////////////

int main() {
    print(Var{"x"});
    print(App{"f", "x"});
    print(Lam{"x", App{"f", "x"}});

    Expr y = Lam{
        "f",
        App{
            Lam{"x", App{"f", App{"x", "x"}}},
            Lam{"x", App{"f", App{"x", "x"}}},
        }
    };
    print(y);

    return 0;
}
