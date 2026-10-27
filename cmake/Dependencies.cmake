# SPDX-License-Identifier: MIT
# Copyright (c) 2026 paulo-vitor-cs
set(CESEB_BOOST_ROOT "${PROJECT_SOURCE_DIR}/build/dependencies/boost_1_86_0" CACHE PATH "Verified Boost 1.86.0 source prefix")
if(NOT EXISTS "${CESEB_BOOST_ROOT}/boost/version.hpp")
  message(FATAL_ERROR "Boost 1.86.0 unavailable: set CESEB_BOOST_ROOT to the verified prefix; use the explicit acquisition script first")
endif()
file(STRINGS "${CESEB_BOOST_ROOT}/boost/version.hpp" _boost_version REGEX "^#define BOOST_VERSION [0-9]+$")
if(NOT _boost_version STREQUAL "#define BOOST_VERSION 108600")
  message(FATAL_ERROR "The approved numeric dependency is exactly Boost 1.86.0: ${_boost_version}")
endif()
add_library(ceseb_boost_headers INTERFACE)
target_include_directories(ceseb_boost_headers SYSTEM INTERFACE "${CESEB_BOOST_ROOT}")
