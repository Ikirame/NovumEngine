#include "TestApplication.h"

int main()
{
    const novum_engine::testing::TestApplication& app =novum_engine::testing::TestApplication::getInstance();

    app.run();
}
