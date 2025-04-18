cmake_minimum_required(VERSION 3.10)
project(aed_flight)

set(CMAKE_CXX_STANDARD 17)

# Doxygen Build
find_package(Doxygen)
if(DOXYGEN_FOUND)
    set(BUILD_DOC_DIR "${CMAKE_SOURCE_DIR}/docs/output")
    if(NOT EXISTS "${BUILD_DOC_DIR}")
        file(MAKE_DIRECTORY "${BUILD_DOC_DIR}")
    endif()
    set(DOXYGEN_IN "${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile")
    set(DOXYGEN_OUT "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile")
    configure_file("${DOXYGEN_IN}" "${DOXYGEN_OUT}" @ONLY)
    message("Doxygen build started")
    add_custom_target(Doxygen ALL
            COMMAND "${DOXYGEN_EXECUTABLE}" "${DOXYGEN_OUT}"
            WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM)
else(DOXYGEN_FOUND)
    message("Doxygen needs to be installed to generate the documentation.")
endif(DOXYGEN_FOUND)

add_executable(aed_flight main.cpp
        classes/Parser.h
        classes/Parser.cpp
        classes/Utils.cpp
        classes/Airport.cpp
        classes/Airport.h
        classes/Coordinate.cpp
        classes/Coordinate.h
        classes/Airline.cpp
        classes/Airline.h
        classes/Flight.cpp
        classes/Flight.h
        classes/Graph.cpp
        classes/Graph.h
        classes/Dataset.cpp
        classes/Dataset.h
        classes/Functions.cpp
        classes/Functions.h
        classes/Menu.h
        classes/Menu.cpp
)
