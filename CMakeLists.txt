cmake_minimum_required(VERSION 3.16)
project(son-dialect)
set(CMAKE_CXX_STANDARD 17)

find_package(MLIR REQUIRED CONFIG HINTS /usr/lib/llvm-18/lib/cmake/mlir)
find_package(LLVM REQUIRED CONFIG HINTS /usr/lib/llvm-18/lib/cmake/llvm)

list(APPEND CMAKE_MODULE_PATH "${MLIR_CMAKE_DIR}")
list(APPEND CMAKE_MODULE_PATH "${LLVM_CMAKE_DIR}")

include(TableGen)
include(AddLLVM)
include(AddMLIR)

include_directories(${MLIR_INCLUDE_DIRS} ${LLVM_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/include)
add_definitions(${LLVM_DEFINITIONS})

add_subdirectory(lib)
include_directories(${CMAKE_BINARY_DIR}/lib/SoN)
include_directories(${CMAKE_BINARY_DIR}/include)
add_executable(test_add test/test_add.cpp)
target_link_libraries(test_add MLIRSoN MLIRIR MLIRSupport)
target_include_directories(test_add PRIVATE
    ${CMAKE_BINARY_DIR}/lib/SoN
)
add_executable(test_lower test/test_lower.cpp)
target_link_libraries(test_lower MLIRSoN MLIRIR MLIRSupport
    MLIRArithDialect MLIRFuncDialect MLIRTransforms)
target_include_directories(test_lower PRIVATE
    ${CMAKE_BINARY_DIR}/lib/SoN)
