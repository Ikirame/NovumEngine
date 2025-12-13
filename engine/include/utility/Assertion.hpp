/**
 *  @file    Assertion.hpp
 *  @author  Valentin Gerard (Ikirame)
 *  @date    04/12/2024
 */

#ifndef NOVUM_ENGINE_ASSERTION_HPP
#define NOVUM_ENGINE_ASSERTION_HPP

#include "Logging.hpp"

#ifdef NOVUM_ENGINE_DEBUG

#if defined(_MSC_VER)
#define ASSERTION_BREAK()   __debugbreak()
#elif defined(__clang__) || defined(__GNUC__)
#define ASSERTION_BREAK()   __builtin_trap()
#else
#define ASSERTION_BREAK()   std::abort()
#endif

#define NOVUM_ENGINE_ASSERT(expr, message)                                                                      \
    if (!(expr))                                                                                                \
    {                                                                                                           \
        NOVUM_ENGINE_LOG_ERROR("Assertion failed : {0} on file {1} at line {2}", message, __FILE__, __LINE__);  \
        ASSERTION_BREAK();                                                                                      \
    }
#else
#define NOVUM_ENGINE_ASSERT(expr, message)  ((void)(expr))
#endif

#endif /* NOVUM_ENGINE_ASSERTION_HPP */
