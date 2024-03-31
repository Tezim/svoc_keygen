cmake_minimum_required(VERSION 3.24)
project(scvoc_keygen)

set(CMAKE_C_STANDARD 11)
include_directories(.)
link_directories(.)

add_executable(scvoc_keygen main.cpp Gen/KeyPair.h Gen/KeyPair.cpp Gen/Polynomial.cpp Gen/helpers.cpp HMAC_DRNG/sha256/sha256.h HMAC_DRNG/sha256/sha256.cpp HMAC_DRNG/hmac_sha256/hmac_sha256.h HMAC_DRNG/hmac_sha256/hmac_sha256.cpp HMAC_DRNG/hmac_drbg/hmac_drbg.h HMAC_DRNG/hmac_drbg/hmac_drbg.cpp arduino.c)
target_link_libraries(scvoc_keygen libNTL_lib.a)