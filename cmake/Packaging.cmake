# SPDX-License-Identifier: MIT
# Copyright (c) 2026 paulo-vitor-cs
get_filename_component(CESEB_QT_ROOT "${Qt6_DIR}/../../.." ABSOLUTE)
set(CESEB_NOTICES_ROOT "${PROJECT_SOURCE_DIR}/build/dependencies/notices" CACHE PATH "Prepared original notices and corresponding source")
set(CESEB_MSVC_REDIST_QUALIFIED OFF CACHE BOOL "MSVC edition and REDIST materials explicitly inspected")
set(CESEB_MSVC_EDITION "" CACHE STRING "Observed licensed MSVC edition/version")
set(CESEB_MSVC_REDIST_LICENSE "" CACHE FILEPATH "Original applicable redistribution terms")
set(CMAKE_INSTALL_BINDIR bin)
set(CMAKE_INSTALL_LIBDIR lib)
set(QT_DEPLOY_LIB_DIR lib)
set(QT_DEPLOY_PLUGINS_DIR plugins)
set_target_properties(ceseb PROPERTIES INSTALL_RPATH "$ORIGIN/../lib")
install(TARGETS ceseb RUNTIME DESTINATION bin)
install(FILES packaging/qt.conf DESTINATION bin)
install(FILES LICENSE THIRD_PARTY_NOTICES.md DESTINATION licenses)
# Keep the documentation index portable between the checkout and installation.
install(FILES LICENSE THIRD_PARTY_NOTICES.md DESTINATION .)

# Historical execution records are a separate, explicit distribution input.
# A clean source checkout can build without them; install/package must receive
# the exact exported records described by docs/technical-report.md.
set(CESEB_DELIVERY_EVIDENCE_ROOT "" CACHE PATH "Export root of the documented historical execution records")
set(_delivery_evidence
  ".mikoshi/brain/sessions/1-mortgage-desktop/evidence/implementation-planning/execution.md"
  ".mikoshi/brain/sessions/1-mortgage-desktop/evidence/implementation-planning/aux-core-results.json"
  ".mikoshi/brain/sessions/1-mortgage-desktop/evidence/implementation-planning/aux-core-1.log"
  ".mikoshi/brain/sessions/1-mortgage-desktop/evidence/implementation-planning/aux-core-2.log"
  ".mikoshi/brain/sessions/1-mortgage-desktop/evidence/implementation-planning/aux-core-3.log"
  ".mikoshi/brain/sessions/1-mortgage-desktop/evidence/implementation-planning/aux-gui-ctest-offscreen.log"
  ".mikoshi/brain/sessions/1-mortgage-desktop/evidence/implementation-planning/aux-gui-ctest-offscreen.json"
  ".mikoshi/brain/sessions/1-mortgage-desktop/evidence/implementation-planning/aux-gui-ctest-xcb.log"
  ".mikoshi/brain/sessions/1-mortgage-desktop/evidence/implementation-planning/aux-gui-ctest-xcb.json"
  ".mikoshi/brain/sessions/1-mortgage-desktop/evidence/synapses/r1/dev-review.md"
  ".mikoshi/brain/sessions/1-mortgage-desktop/evidence/synapses/r1/dev/requirement-trace.json"
  ".mikoshi/brain/sessions/1-mortgage-desktop/evidence/synapses/r1/dev/execution.json"
  ".mikoshi/brain/sessions/1-mortgage-desktop/evidence/synapses/r1/dev/package-audit.json"
  ".mikoshi/brain/sessions/1-mortgage-desktop/evidence/synapses/r1/dev/package-execution.json"
  "out/review-wsl/ctest-offscreen.log"
  "out/review-wsl/ctest-offscreen.xml"
  "out/review-wsl/ctest-xcb.log"
  "out/review-wsl/ctest-xcb.xml"
  "out/review-wsl/core-isolation.log"
  "out/review-wsl/domain-details.log"
  "out/review-wsl/domain-details.xml"
)
install(CODE "
  if(NOT IS_DIRECTORY \"${CESEB_DELIVERY_EVIDENCE_ROOT}\")
    message(FATAL_ERROR \"Delivery evidence unavailable. Set CESEB_DELIVERY_EVIDENCE_ROOT to the explicit historical-record export described in docs/technical-report.md. Build-only does not require this input.\")
  endif()
")
foreach(_record IN LISTS _delivery_evidence)
  get_filename_component(_record_directory "${_record}" DIRECTORY)
  install(FILES "${CESEB_DELIVERY_EVIDENCE_ROOT}/${_record}" DESTINATION "${_record_directory}")
endforeach()

install(DIRECTORY docs/ DESTINATION docs)
install(CODE "
  if(NOT EXISTS \"${CESEB_NOTICES_ROOT}/.complete\")
    message(FATAL_ERROR \"Package notices/source unavailable. Run the explicit ThirdPartyNotices.cmake preparation first.\")
  endif()
")
install(DIRECTORY "${CESEB_NOTICES_ROOT}/" DESTINATION licenses PATTERN .complete EXCLUDE)
if(WIN32)
  set(CMAKE_INSTALL_SYSTEM_RUNTIME_LIBS_SKIP TRUE)
  set(CMAKE_INSTALL_UCRT_LIBRARIES FALSE)
  set(CMAKE_INSTALL_DEBUG_LIBRARIES FALSE)
  include(InstallRequiredSystemLibraries)
  configure_file("${CMAKE_CURRENT_LIST_DIR}/WindowsDeploy.cmake" "${CMAKE_BINARY_DIR}/WindowsDeploy.cmake" @ONLY)
  install(SCRIPT "${CMAKE_BINARY_DIR}/WindowsDeploy.cmake")
  set(CPACK_GENERATOR ZIP)
  set(CPACK_PACKAGE_FILE_NAME "ceseb-${PROJECT_VERSION}-windows-x86_64")
else()
  qt_policy(SET QTP0007 NEW)
  # Qt's INCLUDE_PLUGINS is additive. Exclude default module plugin categories
  # so a text-only Widgets app deploys its XCB platform, not unrelated SDK modules.
  file(GLOB _plugin_directories RELATIVE "${CESEB_QT_ROOT}/plugins" "${CESEB_QT_ROOT}/plugins/*")
  set(_excluded_plugin_types "")
  foreach(_type IN LISTS _plugin_directories)
    if(IS_DIRECTORY "${CESEB_QT_ROOT}/plugins/${_type}")
      list(APPEND _excluded_plugin_types "${_type}")
    endif()
  endforeach()
  qt_generate_deploy_app_script(TARGET ceseb OUTPUT_SCRIPT _deploy
    NO_TRANSLATIONS NO_COMPILER_RUNTIME INCLUDE_PLUGINS qxcb
    EXCLUDE_PLUGIN_TYPES ${_excluded_plugin_types}
    # CMake can retain plugin/../../lib in resolved paths; match the owned kit
    # prefix, not only its canonical lib spelling.
    POST_INCLUDE_REGEXES "^${CESEB_QT_ROOT}/"
    POST_EXCLUDE_REGEXES ".*")
  install(SCRIPT "${_deploy}")
  install(CODE "
    foreach(_required Core DBus Gui Widgets XcbQpa)
      if(NOT EXISTS \"\$ENV{DESTDIR}\${CMAKE_INSTALL_PREFIX}/lib/libQt6\${_required}.so.6\")
        message(FATAL_ERROR \"Private Qt dependency missing: \${_required}\")
      endif()
    endforeach()
  ")
  install(FILES packaging/ceseb.desktop DESTINATION share/applications)
  # DEB handles absolute destinations with DESTDIR; standard desktop discovery
  # searches /usr/share/applications, while the private runtime stays in /opt.
  install(FILES packaging/ceseb.desktop DESTINATION /usr/share/applications)
  set(CPACK_GENERATOR DEB)
  set(CPACK_PACKAGE_FILE_NAME "ceseb_${PROJECT_VERSION}_amd64")
  set(CPACK_PACKAGING_INSTALL_PREFIX /opt/ceseb)
  set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE amd64)
  set(CPACK_DEBIAN_PACKAGE_SECTION utils)
  # These QPA dependencies may not be installed in a development host using a
  # private SDK; keep their Ubuntu package identities explicit as well as SHLIBDEPS.
  set(CPACK_DEBIAN_PACKAGE_DEPENDS "libxcb-cursor0, libxcb-icccm4, libxcb-util1, libxcb-image0, libxcb-keysyms1, libxcb-render-util0")
  set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)
  set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS_PRIVATE_DIRS "${CESEB_QT_ROOT}/lib")
endif()
install(CODE "
  file(GLOB_RECURSE _files RELATIVE \"\$ENV{DESTDIR}\${CMAKE_INSTALL_PREFIX}\" \"\$ENV{DESTDIR}\${CMAKE_INSTALL_PREFIX}/*\")
  set(_manifest \"CESEB ${PROJECT_VERSION}\\nSource revision: ${CESEB_SOURCE_REVISION}\\n\")
  foreach(_entry IN LISTS _files)
    if(NOT _entry STREQUAL \"installed-SHA256SUMS.txt\")
      file(SHA256 \"\$ENV{DESTDIR}\${CMAKE_INSTALL_PREFIX}/\${_entry}\" _hash)
      string(APPEND _manifest \"\${_hash}  \${_entry}\\n\")
    endif()
  endforeach()
  file(WRITE \"\$ENV{DESTDIR}\${CMAKE_INSTALL_PREFIX}/installed-SHA256SUMS.txt\" \"\${_manifest}\")
")
set(CPACK_PACKAGE_NAME ceseb)
set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION}")
set(CPACK_PACKAGE_VENDOR paulo-vitor-cs)
set(CPACK_PACKAGE_CONTACT "https://github.com/paulo-vitor-cs/ceseb/issues")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Calculadora local Price e SAC")
set(CPACK_RESOURCE_FILE_LICENSE "${PROJECT_SOURCE_DIR}/LICENSE")
set(CPACK_PACKAGE_CHECKSUM SHA256)
set(CPACK_INCLUDE_TOPLEVEL_DIRECTORY OFF)
include(CPack)
