#include "platform/opengl/Context.h"

int	main()
{
    const novum_engine::platform::opengl::Context context;
    const auto& window = context.getWindow();

    window.render();

	return 0;
}