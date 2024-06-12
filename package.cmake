message(STATUS "Load ... package.cmake")

find_package(Boost)

message(STATUS "Boost: ${Boost_INCLUDE_DIR}")
message(STATUS "Boost: ${Boost_LIBRARIES}")

# include libraries
set(PACKAGE_INCLUDE_DIR
    ${Boost_INCLUDE_DIR}
)

# link libraries
SET(PACKAGE_LIBRARIES 
    ${Boost_LIBRARIES}
)