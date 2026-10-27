# SPDX-License-Identifier: MIT
# Copyright (c) 2026 paulo-vitor-cs
cmake_minimum_required(VERSION 3.28)
if(NOT IS_DIRECTORY "${CESEB_PACKAGE_ROOT}" OR IS_SYMLINK "${CESEB_PACKAGE_ROOT}")
  message(FATAL_ERROR "UNAVAILABLE: CESEB_PACKAGE_ROOT must be an independent extracted ZIP directory")
endif()
set(failures)
foreach(relative IN ITEMS
    bin/ceseb.exe bin/Qt6Core.dll bin/Qt6Gui.dll bin/Qt6Widgets.dll
    plugins/platforms/qwindows.dll LICENSE THIRD_PARTY_NOTICES.md
    licenses/boost-LICENSE_1_0.txt licenses/googletest-LICENSE.txt
    licenses/qtbase/LICENSES/GPL-3.0-only.txt licenses/qtbase/LICENSES/LGPL-3.0-only.txt
    licenses/qtbase/sbom/qtbase-6.12.0.spdx.json
    licenses/qtbase/config_qtbase.opt licenses/qtbase/config_qtbase.summary
    licenses/source/qtbase-025bdad181de241e81bf853c8a2d7bf3d19261a9.tar.gz
    licenses/msvc/edition.txt licenses/msvc/Visual-Studio-2022-Community-License-EN.docx)
  set(path "${CESEB_PACKAGE_ROOT}/${relative}")
  if(NOT EXISTS "${path}" OR IS_DIRECTORY "${path}" OR IS_SYMLINK "${path}")
    list(APPEND failures "Missing declared runtime/material: ${relative}")
  else()
    file(SIZE "${path}" size)
    if(size EQUAL 0)
      list(APPEND failures "Empty declared runtime/material: ${relative}")
    endif()
  endif()
endforeach()
file(GLOB_RECURSE files RELATIVE "${CESEB_PACKAGE_ROOT}" LIST_DIRECTORIES false "${CESEB_PACKAGE_ROOT}/*")
foreach(relative IN LISTS files)
  get_filename_component(name "${relative}" NAME)
  string(TOLOWER "${name}" lower)
  if(lower STREQUAL "dxcompiler.dll" OR lower STREQUAL "dxil.dll")
    list(APPEND failures "Forbidden optional DXC component: ${relative}")
  endif()
endforeach()
if(failures)
  list(JOIN failures "\n" diagnostic)
  message(FATAL_ERROR "Package composition RED:\n${diagnostic}")
endif()
message(STATUS "Actual extracted Windows package has required runtime/materials and no optional DXC/DXIL")
