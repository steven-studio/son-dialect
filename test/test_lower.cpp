#include "SoN/IR/SoNDialect.h"
#include "SoN/IR/LowerToSoN.h"
#include "mlir/IR/MLIRContext.h"
#include "mlir/IR/Builders.h"
#include "mlir/IR/BuiltinTypes.h"
#include "mlir/IR/BuiltinOps.h"
#include "mlir/Dialect/Arith/IR/Arith.h"
#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "mlir/Transforms/GreedyPatternRewriteDriver.h"
#include <iostream>

int main() {
    mlir::MLIRContext ctx;
    ctx.loadDialect<mlir::son::SoNDialect>();
    ctx.loadDialect<mlir::arith::ArithDialect>();
    ctx.loadDialect<mlir::func::FuncDialect>();

    mlir::OpBuilder builder(&ctx);
    auto loc = builder.getUnknownLoc();
    auto i32 = builder.getI32Type();

    // 建一個 module
    auto module = mlir::ModuleOp::create(loc);
    auto funcType = builder.getFunctionType({i32, i32}, {i32});
    auto func = builder.create<mlir::func::FuncOp>(loc, "test", funcType);
    module.push_back(func);

    auto *block = func.addEntryBlock();
    builder.setInsertionPointToStart(block);
    auto a = block->getArgument(0);
    auto b = block->getArgument(1);

    auto add = builder.create<mlir::arith::AddIOp>(loc, a, b);
    builder.create<mlir::func::ReturnOp>(loc, mlir::ValueRange{add});

    std::cout << "=== Before lowering ===\n";
    module->dump();

    // 跑 lowering pass
    mlir::RewritePatternSet patterns(&ctx);
    mlir::son::populateArithToSoNPatterns(patterns);
    if (mlir::applyPatternsAndFoldGreedily(module, std::move(patterns)).failed())
        std::cerr << "lowering failed\n";

    std::cout << "=== After lowering ===\n";
    module->dump();
    return 0;
}
