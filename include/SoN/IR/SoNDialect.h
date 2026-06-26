#pragma once
#include "mlir/IR/Dialect.h"
#include "mlir/IR/OpDefinition.h"
#include "mlir/IR/Builders.h"

#include "SoNDialect.h.inc"

#define GET_OP_CLASSES
#include "SoNOps.h.inc"
