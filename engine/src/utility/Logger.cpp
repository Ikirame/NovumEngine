/**
 *  @file    Logger.cpp
 *  @author  Valentin Gerard (Ikirame)
 *  @date    12/13/2025
 */

#ifdef NOVUM_ENGINE_DEBUG
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_DEBUG
#else
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_INFO
#endif

#include <spdlog/spdlog.h>

#include "utility/Logger.h"

novum_engine::utility::Logger::Logger() noexcept
{
#ifdef NOVUM_ENGINE_DEBUG
    spdlog::set_level(spdlog::level::debug);
#else
    spdlog::set_level(spdlog::level::info);
#endif
}

#ifdef NOVUM_ENGINE_DEBUG
void novum_engine::utility::Logger::debug(const std::string_view msg) const noexcept
{
    spdlog::debug(msg);
}
#endif

void novum_engine::utility::Logger::info(const std::string_view msg) const noexcept
{
    spdlog::info(msg);
}

void novum_engine::utility::Logger::warn(const std::string_view msg) const noexcept
{
    spdlog::warn(msg);
}

void novum_engine::utility::Logger::error(const std::string_view msg) const noexcept
{
    spdlog::error(msg);
}
