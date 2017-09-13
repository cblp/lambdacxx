set(
    CMAKE_CXX_FLAGS
    "${CMAKE_CXX_FLAGS} -Werror -Wall -Wextra -pedantic -std=c++1z"
)

add_executable(lambdacxx lambda.cpp)
