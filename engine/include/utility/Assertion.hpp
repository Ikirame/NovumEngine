/**
 *  @file    Assertion.hpp
 *  @author  Valentin Gerard (Ikirame)
 *  @date    04/12/2024
 */

#ifndef NOVUM_ENGINE_ASSERTION_HPP
#define NOVUM_ENGINE_ASSERTION_HPP

#include <iostream>

#ifdef NOVUM_ENGINE_DEBUG

#if defined(_MSC_VER)
#define ASSERTION_BREAK()   __debugbreak()
#elif defined(__clang__) || defined(__GNUC__)
#define ASSERTION_BREAK()   __builtin_trap()
#else
#define ASSERTION_BREAK()   std::abort()
#endif

#define NOVUM_ENGINE_ASSERT(expr, message)                                                                              \
    if (!(expr))                                                                                                        \
    {                                                                                                                   \
        std::cerr << "Assertion failed: " << message << " on file " << __FILE__ << "at line" << __LINE__ << std::endl;  \
        ASSERTION_BREAK();                                                                                              \
    }
#else
#define NOVUM_ENGINE_ASSERT(expr, message)  ((void)(expr))
#endif

#endif /* NOVUM_ENGINE_ASSERTION_HPP */
