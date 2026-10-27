# SPDX-License-Identifier: MIT
# Copyright (c) 2026 paulo-vitor-cs
# Configured by Packaging.cmake and executed only by install/CPack on Windows.
if(NOT "@CESEB_MSVC_REDIST_QUALIFIED@" STREQUAL "ON")
  message(FATAL_ERROR "Windows package unavailable: qualify the observed MSVC edition and its REDIST terms first")
endif()
if(NOT EXISTS "@CESEB_MSVC_REDIST_LICENSE@" OR "@CESEB_MSVC_EDITION@" STREQUAL "")
  message(FATAL_ERROR "The qualified MSVC edition and original redistribution terms must be recoverable")
endif()
set(_bin "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin")
set(_plugins "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/plugins")
# Raster Widgets do not need optional DXC; this is separate from the D3D compiler.
execute_process(COMMAND "@CESEB_QT_ROOT@/bin/windeployqt.exe" --release --no-translations
  --no-compiler-runtime --no-system-d3d-compiler --no-system-dxc-compiler --no-opengl-sw
  --dir "${_bin}" --plugindir "${_plugins}" "${_bin}/ceseb.exe"
  RESULT_VARIABLE _status OUTPUT_VARIABLE _output ERROR_VARIABLE _error)
if(NOT _status EQUAL 0)
  message(FATAL_ERROR "windeployqt failed: ${_output}\n${_error}")
endif()
set(_crt "@CMAKE_INSTALL_SYSTEM_RUNTIME_LIBS@")
if(NOT _crt)
  message(FATAL_ERROR "No qualified app-local Release CRT DLLs were identified")
endif()
foreach(_dll IN LISTS _crt)
  get_filename_component(_name "${_dll}" NAME)
  string(TOLOWER "${_name}" _lower)
  if(NOT _lower MATCHES "^(msvcp140(_1|_2|_atomic_wait|_codecvt_ids)?|vcruntime140(_1)?|concrt140)\\.dll$")
    message(FATAL_ERROR "Runtime material requires explicit review before redistribution: ${_name}")
  endif()
  file(INSTALL "${_dll}" DESTINATION "${_bin}")
endforeach()
file(INSTALL "@CESEB_MSVC_REDIST_LICENSE@" DESTINATION "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/licenses/msvc")
file(WRITE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/licenses/msvc/edition.txt" "@CESEB_MSVC_EDITION@\n")
