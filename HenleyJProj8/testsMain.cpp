// Catch2 is a header-only framework for C++ unit-tests
// https://github.com/catchorg

// This file exists to handle the inclusion of catch.hpp
// Because catch.hpp is a large file to compile, including it here first means it does not need to be recompiled
// every time the tests are modified.

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

