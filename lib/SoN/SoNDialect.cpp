#include "SoN/IR/SoNDialect.h"
#include "mlir/IR/Builders.h"
#include "mlir/IR/BuiltinTypes.h"

using namespace mlir;
using namespace mlir::son;

#define GET_DIALECT_DEFS
#include "SoNDialect.cpp.inc"

#define GET_OP_CLASSES
#include "SoNOps.cpp.inc"

void SoNDialect::initialize() {
    addOperations<
#define GET_OP_LIST
#include "SoNOps.cpp.inc"
    >();
}
