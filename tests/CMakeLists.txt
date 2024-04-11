option(CATCH_INSTALL_DOCS OFF)
option(CATCH_INSTALL_EXTRAS OFF)
option(CATCH_BUILD_TESTING OFF)

add_subdirectory(opt/catch2 EXCLUDE_FROM_ALL)
add_subdirectory(engine EXCLUDE_FROM_ALL)