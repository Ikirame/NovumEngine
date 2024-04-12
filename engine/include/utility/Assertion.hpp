/**
 *  @file    FlatQueue.hpp
 *  @author  Valentin Gerard (Ikirame)
 *  @date    04/12/2024
 */

#ifndef NOVUM_ENGINE_ASSERTION_HPP
#define NOVUM_ENGINE_ASSERTION_HPP

#include <iostream>

#define ASSERTIONS_ENABLED true

#if ASSERTIONS_ENABLED
// define some inline assembly that causes a break
// into the debugger -- this will be different on each
// target CPU
#define exit() { std::exit(EXIT_FAILURE); }
#define reportAssertionFailure(expr, file, line) { std::cerr << expr << " on file " << file << " at line " << line << std::endl; }
// check the expression and fail if it is false
#define CORE_ASSERT(expr) \
if (expr) { } \
else \
{ \
reportAssertionFailure(#expr, __FILE__, __LINE__); \
exit(); \
}
#else
#define CORE_ASSERT(expr) // evaluates to nothing
#endif

#endif /* NOVUM_ENGINE_ASSERTION_HPP */
