/**
 *  @file    Helpers.hpp
 *  @author  Valentin Gerard (Ikirame)
 *  @date    01/23/2026
 */

#ifndef NOVUM_ENGINE_HELPERS_H
#define NOVUM_ENGINE_HELPERS_H

#include <variant>

namespace novum_engine::utility::variant
{
    template <typename T, typename Variant>
    struct variant_contains;

    template <typename T, typename... Ts>
    struct variant_contains<T, std::variant<Ts...> >
            : std::bool_constant<(std::is_same_v<T, Ts> || ...)> {};

    template <typename T, typename Variant>
    inline constexpr bool variant_contains_v =
            variant_contains<T, Variant>::value;
}

#endif /* NOVUM_ENGINE_HELPERS_H */
