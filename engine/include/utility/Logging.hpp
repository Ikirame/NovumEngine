/**
 *  @file    Logging.hpp
 *  @author  Valentin Gerard (Ikirame)
 *  @date    12/10/2025
 */

#ifndef NOVUM_ENGINE_LOGGING_HPP
#define NOVUM_ENGINE_LOGGING_HPP

#ifdef NOVUM_ENGINE_DEBUG
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_DEBUG
#else
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_INFO
#endif

#include "spdlog/spdlog.h"

#ifdef NOVUM_ENGINE_DEBUG
#define NOVUM_ENGINE_LOG_DEBUG(msg, ...)        novum_engine::utility::Logger::getInstance().debug(msg, ##__VA_ARGS__)
#else
#define NOVUM_ENGINE_LOG_DEBUG(msg, ...)
#endif

#define NOVUM_ENGINE_LOG_INFO(msg, ...)         novum_engine::utility::Logger::getInstance().info(msg, ##__VA_ARGS__)
#define NOVUM_ENGINE_LOG_WARN(msg, ...)         novum_engine::utility::Logger::getInstance().warn(msg, ##__VA_ARGS__)
#define NOVUM_ENGINE_LOG_ERROR(msg, ...)        novum_engine::utility::Logger::getInstance().error(msg, ##__VA_ARGS__)

namespace novum_engine::utility
{
    class Logger
    {
    public:
        Logger(Logger const& rhs) noexcept = delete;
        Logger(Logger&& rhs) noexcept = delete;

        Logger& operator=(Logger const& rhs) noexcept = delete;
        Logger& operator=(Logger&& rhs) noexcept = delete;

        static const Logger& getInstance()
        {
            static Logger instance;
            return instance;
        }

#ifdef NOVUM_ENGINE_DEBUG
        template <typename... Args>
        void debug(fmt::format_string<Args...> msg, Args&&... args) const noexcept
        {
            spdlog::debug(msg, std::forward<Args>(args)...);
        }
#endif

        template <typename... Args>
        void info(fmt::format_string<Args...> msg, Args&&... args) const noexcept
        {
            spdlog::info(msg, std::forward<Args>(args)...);
        }

        template <typename... Args>
        void warn(fmt::format_string<Args...> msg, Args&&... args) const noexcept
        {
            spdlog::warn(msg, std::forward<Args>(args)...);
        }

        template <typename... Args>
        void error(fmt::format_string<Args...> msg, Args&&... args) const noexcept
        {
            spdlog::error(msg, std::forward<Args>(args)...);
        }

    private:
        explicit Logger() noexcept
        {
#ifdef NOVUM_ENGINE_DEBUG
            spdlog::set_level(spdlog::level::debug);
#else
            spdlog::set_level(spdlog::level::info);
#endif
        }
    };
}

#endif /* NOVUM_ENGINE_LOGGING_HPP */
