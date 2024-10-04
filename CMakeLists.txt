cmake_minimum_required(VERSION 3.29)
project(AminoAcidProject)

set(CMAKE_CXX_STANDARD 20)

# Add GoogleTest
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/releases/download/v1.15.2/googletest-1.15.2.tar.gz
)
FetchContent_MakeAvailable(googletest)

# Add your source files
add_executable(AminoAcidProject
        AminoAcid.h
        AminoAcid.cpp
        ProteinSequence.h
        ProteinogenicAminoAcid.h
        ProteinSequence.cpp
        ProteinogenicAminoAcid.cpp
        tests.cpp
)

# Link GoogleTest
target_link_libraries(AminoAcidProject gtest_main)

# Enable testing
enable_testing()
add_test(NAME AminoAcidProject COMMAND AminoAcidProject)
