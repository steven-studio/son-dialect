#include "SoN/IR/SoNDialect.h"
#include "mlir/IR/MLIRContext.h"
#include "mlir/IR/Builders.h"
#include "mlir/IR/BuiltinTypes.h"
#include "mlir/IR/Block.h"
#include <iostream>

int main() {
    mlir::MLIRContext ctx;
    ctx.loadDialect<mlir::son::SoNDialect>();

    mlir::OpBuilder builder(&ctx);
    auto i32 = builder.getI32Type();
    auto loc = builder.getUnknownLoc();

    mlir::Block block;
    mlir::Value lhs = block.addArgument(i32, loc);
    mlir::Value rhs = block.addArgument(i32, loc);

    builder.setInsertionPointToStart(&block);
    auto addOp = builder.create<mlir::son::AddOp>(loc, i32, lhs, rhs);

    addOp->dump();
    std::cout << "son.add op created successfully!\n";
    return 0;
}
