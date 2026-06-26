#pragma once
#include "mlir/IR/PatternMatch.h"

namespace mlir {
namespace son {
void populateArithToSoNPatterns(RewritePatternSet &patterns);
} // namespace son
} // namespace mlir
