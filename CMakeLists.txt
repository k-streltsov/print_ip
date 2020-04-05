cmake_minimum_required(VERSION 3.2)

IF(DEFINED ENV{TRAVIS_BUILD_NUMBER})
    project(print_ip VERSION $ENV{TRAVIS_BUILD_NUMBER})
ELSE()
    project(print_ip VERSION 1)
ENDIF()

add_executable(print_ip main.cpp)
set_target_properties(print_ip PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
)

install(TARGETS print_ip RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION}")
set(CPACK_PACKAGE_CONTACT dywedodd@gmail.com)

include(CPack)
