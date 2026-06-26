set(LLVM_TARGET_DEFINITIONS SoNOps.td)
mlir_tablegen(SoNOps.h.inc -gen-op-decls)
mlir_tablegen(SoNOps.cpp.inc -gen-op-defs)
mlir_tablegen(SoNDialect.h.inc -gen-dialect-decls -dialect=son)
mlir_tablegen(SoNDialect.cpp.inc -gen-dialect-defs -dialect=son)
add_public_tablegen_target(MLIRSoNIncGen)

add_mlir_dialect_library(MLIRSoN
    SoNDialect.cpp
    DEPENDS MLIRSoNIncGen
    LINK_LIBS PUBLIC
    MLIRIR
    MLIRSupport
)

target_include_directories(obj.MLIRSoN PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}/../../include
    ${CMAKE_BINARY_DIR}/lib/SoN
)
