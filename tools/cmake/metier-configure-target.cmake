# Copyright (c) 2020-2022 The Open-Transactions developers
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

include(otcommon-configure-target)
include(otcommon-define-signed-overflow)

function(metier_configure_cxx_target target_name)
  otcommon_configure_cxx_target(${target_name})
  otcommon_define_signed_overflow(${target_name})
  target_compile_definitions(metier-common PUBLIC "${QT_DEFINITIONS}")

  if(MSVC)
    target_compile_options(${target_name} PRIVATE "/EHsc")
    target_compile_definitions(
      ${target_name} PRIVATE "_ALLOW_COROUTINE_ABI_MISMATCH"
    )
  else()
    target_compile_options(
      ${target_name}
      PRIVATE
        "-Wno-extra-semi-stmt"
        "-Wno-noexcept"
        "-Wno-redundant-parens"
        "-Wno-reserved-identifier"
    )
  endif()

  if(CMAKE_CXX_COMPILER_ID
     MATCHES
     GNU
  )
    # too many false positives, mostly in standard library and third party
    # headers we can't do anything about anyway
    target_compile_options(
      ${target_name}
      PRIVATE
        "-Wno-error=null-dereference"
        "-Wno-error=stringop-overflow="
        "-Wno-error=stringop-overread"
        "-Wno-unsafe-buffer-usage"
    )
  endif()

  if(CMAKE_CXX_COMPILER_ID
     MATCHES
     Clang
  )
    target_compile_options(
      ${target_name} PRIVATE "-Wno-error=unsafe-buffer-usage"
    )
  endif()

  set_target_properties(
    "${target_name}"
    PROPERTIES
      AUTOMOC ON
      AUTOUIC ON
      AUTORCC ON
  )
endfunction()
