# SPDX-License-Identifier: MIT
# Copyright (c) 2026 paulo-vitor-cs
cmake_minimum_required(VERSION 3.28)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
  project(ceseb_contract_tests VERSION 0.1.0 LANGUAGES CXX)
  get_filename_component(_default_source_root "${CMAKE_CURRENT_LIST_DIR}/.." ABSOLUTE)
  set(CESEB_SOURCE_ROOT "${_default_source_root}" CACHE PATH "Real project source root")
  option(CESEB_BUILD_GUI "Include the real Qt UI in standalone contract tests" OFF)
  if(NOT EXISTS "${CESEB_SOURCE_ROOT}/CMakeLists.txt" OR NOT EXISTS "${CESEB_SOURCE_ROOT}/include/ceseb/finance.hpp")
    message(FATAL_ERROR "UNAVAILABLE: real product CMake/API absent. This is a collection/configuration limitation, not behavioral RED. No substitute core is created.")
  endif()
  set(CESEB_BUILD_TESTS OFF CACHE BOOL "Prevent recursive test inclusion from the real product" FORCE)
  add_subdirectory("${CESEB_SOURCE_ROOT}" "${CMAKE_CURRENT_BINARY_DIR}/real-product")
  enable_testing()
else()
  set(CESEB_SOURCE_ROOT "${PROJECT_SOURCE_DIR}")
endif()
if(NOT TARGET ceseb_core)
  message(FATAL_ERROR "UNAVAILABLE: ceseb_core from the real product is required")
endif()
if(NOT TARGET GTest::gtest_main)
  find_package(GTest 1.17.0 EXACT CONFIG REQUIRED)
endif()

add_executable(ceseb_domain_tests
  domain/req1101_rate_kind_test.cpp
  domain/req1102_nominal_monthly_test.cpp
  domain/req1103_effective_monthly_test.cpp
  domain/req1104_annual_equivalents_test.cpp
  domain/req1105_invalid_rate_test.cpp
  domain/req1106_exact_rate_transport_test.cpp
  domain/req1201_loan_domain_test.cpp
  domain/req1202_price_ledger_test.cpp
  domain/req1203_sac_ledger_test.cpp
  domain/req1204_money_invariants_test.cpp
  domain/req1205_zero_single_ties_test.cpp
  domain/req1206_cent_admissibility_test.cpp
  domain/req1207_comparison_test.cpp
  support/financial_fixtures.hpp)
target_link_libraries(ceseb_domain_tests PRIVATE ceseb_core GTest::gtest_main)
target_compile_features(ceseb_domain_tests PRIVATE cxx_std_20)
set_target_properties(ceseb_domain_tests PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
include(GoogleTest)
gtest_discover_tests(ceseb_domain_tests DISCOVERY_MODE PRE_TEST PROPERTIES LABELS "domain")

# Operational generated checks validate selection without creating additional authored files.
set(CESEB_TEST_EXECUTABLE "$<TARGET_FILE:ceseb_domain_tests>")
set(_inventory_template [=[
execute_process(COMMAND "@CESEB_TEST_EXECUTABLE@" --gtest_list_tests RESULT_VARIABLE code OUTPUT_VARIABLE listed ERROR_VARIABLE error)
if(NOT code STREQUAL "0")
  message(FATAL_ERROR "Domain inventory unavailable: ${code}: ${error}")
endif()
foreach(id 1101 1102 1103 1104 1105 1106 1201 1202 1203 1204 1205 1206 1207)
  if(NOT listed MATCHES "(^|\n)Req${id}\\.")
    message(FATAL_ERROR "Empty/missing required domain suite Req${id}: ${listed}")
  endif()
endforeach()
message(STATUS "All thirteen required domain suites are discoverable")
]=])
string(CONFIGURE "${_inventory_template}" _inventory @ONLY)
file(GENERATE OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/domain_inventory_$<CONFIG>.cmake" CONTENT "${_inventory}")
add_test(NAME ceseb_domain_inventory COMMAND "${CMAKE_COMMAND}" -P "${CMAKE_CURRENT_BINARY_DIR}/domain_inventory_$<CONFIG>.cmake")
set_tests_properties(ceseb_domain_inventory PROPERTIES LABELS "domain;inventory")

if(CESEB_BUILD_GUI)
  if(NOT TARGET ceseb_ui)
    message(FATAL_ERROR "UNAVAILABLE: GUI contracts require the real ceseb_ui target")
  endif()
  find_package(Qt6 6.12.0 EXACT REQUIRED COMPONENTS Test Widgets)
  add_executable(ceseb_gui_tests
    gui/gui_tests.hpp gui/gui_test_main.cpp
    gui/req1211_localized_input_test.cpp
    gui/req1212_rate_presentation_test.cpp
    gui/req1213_comparison_presentation_test.cpp
    gui/req1214_state_recovery_test.cpp
    gui/req1216_inherited_palette_test.cpp)
  set_target_properties(ceseb_gui_tests PROPERTIES AUTOMOC ON RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
  target_include_directories(ceseb_gui_tests PRIVATE "${CESEB_SOURCE_ROOT}/src")
  target_link_libraries(ceseb_gui_tests PRIVATE ceseb_ui ceseb_core Qt6::Test Qt6::Widgets)
  target_compile_features(ceseb_gui_tests PRIVATE cxx_std_20)
  foreach(slot req1211_localized_input req1212_rate_presentation req1213_comparison_presentation req1214_state_recovery req1216_inherited_palette)
    add_test(NAME "${slot}" COMMAND ceseb_gui_tests "${slot}")
    set_tests_properties("${slot}" PROPERTIES LABELS "gui" RUN_SERIAL TRUE)
  endforeach()
  set(CESEB_TEST_EXECUTABLE "$<TARGET_FILE:ceseb_gui_tests>")
  set(_gui_inventory_template [=[
execute_process(COMMAND "@CESEB_TEST_EXECUTABLE@" -functions RESULT_VARIABLE code OUTPUT_VARIABLE listed ERROR_VARIABLE error)
if(NOT code STREQUAL "0")
  message(FATAL_ERROR "GUI inventory unavailable: ${code}: ${error}")
endif()
foreach(slot req1211_localized_input req1212_rate_presentation req1213_comparison_presentation req1214_state_recovery req1216_inherited_palette)
  string(FIND "${listed}" "${slot}()" position)
  if(position LESS 0)
    message(FATAL_ERROR "Empty/missing required GUI slot ${slot}: ${listed}")
  endif()
endforeach()
]=])
  string(CONFIGURE "${_gui_inventory_template}" _gui_inventory @ONLY)
  file(GENERATE OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/gui_inventory_$<CONFIG>.cmake" CONTENT "${_gui_inventory}")
  add_test(NAME ceseb_gui_inventory COMMAND "${CMAKE_COMMAND}" -P "${CMAKE_CURRENT_BINARY_DIR}/gui_inventory_$<CONFIG>.cmake")
  set_tests_properties(ceseb_gui_inventory PROPERTIES LABELS "gui;inventory" RUN_SERIAL TRUE)
endif()
