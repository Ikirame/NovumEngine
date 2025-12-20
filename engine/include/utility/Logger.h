/**
 *  @file    Logger.h
 *  @author  Valentin Gerard (Ikirame)
 *  @date    12/10/2025
 */

#ifndef NOVUM_ENGINE_LOGGING_HPP
#define NOVUM_ENGINE_LOGGING_HPP

#include <format>
#include <string_view>

#ifdef NOVUM_ENGINE_DEBUG
#define NOVUM_ENGINE_LOG_DEBUG(msg)        novum_engine::utility::Logger::getInstance().debug(msg)
#else
#define NOVUM_ENGINE_LOG_DEBUG(msg)
#endif

#define NOVUM_ENGINE_LOG_INFO(msg)         novum_engine::utility::Logger::getInstance().info(msg)
#define NOVUM_ENGINE_LOG_WARN(msg)         novum_engine::utility::Logger::getInstance().warn(msg)
#define NOVUM_ENGINE_LOG_ERROR(msg)        novum_engine::utility::Logger::getInstance().error(msg)

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
        void debug(std::string_view msg) const noexcept;
#endif
        void info(std::string_view msg) const noexcept;
        void warn(std::string_view msg) const noexcept;
        void error(std::string_view msg) const noexcept;

    private:
        explicit Logger() noexcept;
    };
}

#endif /* NOVUM_ENGINE_LOGGING_HPP */
