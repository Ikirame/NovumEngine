/**
 *  @file    TestApplication.h
 *  @author  Valentin Gerard (Ikirame)
 *  @date    05/02/2025
 **/

#ifndef NOVUM_ENGINE_TEST_APPLICATION_H
#define NOVUM_ENGINE_TEST_APPLICATION_H

#include <core/Application.h>

namespace novum_engine::testing
{
    class TestApplication final : public core::Application<TestApplication>
    {
    public:
        TestApplication(TestApplication const& rhs) noexcept = delete;
        TestApplication(TestApplication&& rhs) noexcept = delete;

        TestApplication& operator=(TestApplication const& rhs) noexcept = delete;
        TestApplication& operator=(TestApplication&& rhs) noexcept = delete;

    private:
        friend class Application;

        void onInit() const noexcept;
        static void onUpdate() noexcept;
        static void onUpdateUI() noexcept;
        static void onDestroy() noexcept;

        explicit TestApplication() noexcept = default;
    };
}

#endif /* NOVUM_ENGINE_TEST_APPLICATION_H */
