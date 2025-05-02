/**
 *  @file    TestApplication.h
 *  @author  Valentin Gerard (Ikirame)
 *  @date    05/02/2025
 **/

#ifndef NOVUM_TEST_APPLICATION
#define NOVUM_TEST_APPLICATION

#include <core/Application.h>

namespace novum_engine::testing
{
    class TestApplication final : public core::Application
    {
    public:
        TestApplication(TestApplication const& rhs) noexcept = delete;
        TestApplication(TestApplication&& rhs) noexcept = delete;

        TestApplication& operator=(TestApplication const& rhs) noexcept = delete;
        TestApplication& operator=(TestApplication&& rhs) noexcept = delete;

        static const TestApplication& getInstance()
        {
            static TestApplication instance;
            return instance;
        }

    protected:
        void onUpdate() const noexcept override;

    private:
        explicit TestApplication() noexcept;
        ~TestApplication() noexcept override;
    };
}

#endif /* NOVUM_TEST_APPLICATION */
