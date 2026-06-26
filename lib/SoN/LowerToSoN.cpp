#include "SoN/IR/SoNDialect.h"
#include "mlir/IR/PatternMatch.h"
#include "mlir/Transforms/DialectConversion.h"
#include "mlir/Dialect/Arith/IR/Arith.h"
#include <memory>

namespace mlir {
namespace son {

struct AddiToSoNAdd : public OpRewritePattern<arith::AddIOp> {
    using OpRewritePattern::OpRewritePattern;
    LogicalResult matchAndRewrite(arith::AddIOp op,
        PatternRewriter &rewriter) const override {
        rewriter.replaceOpWithNewOp<AddOp>(
            op, op.getType(), op.getLhs(), op.getRhs());
        return success();
    }
};

struct SubiToSoNSub : public OpRewritePattern<arith::SubIOp> {
    using OpRewritePattern::OpRewritePattern;
    LogicalResult matchAndRewrite(arith::SubIOp op,
        PatternRewriter &rewriter) const override {
        rewriter.replaceOpWithNewOp<SubOp>(
            op, op.getType(), op.getLhs(), op.getRhs());
        return success();
    }
};

struct MuliToSoNMul : public OpRewritePattern<arith::MulIOp> {
    using OpRewritePattern::OpRewritePattern;
    LogicalResult matchAndRewrite(arith::MulIOp op,
        PatternRewriter &rewriter) const override {
        rewriter.replaceOpWithNewOp<MulOp>(
            op, op.getType(), op.getLhs(), op.getRhs());
        return success();
    }
};

void populateArithToSoNPatterns(RewritePatternSet &patterns) {
    patterns.add<AddiToSoNAdd, SubiToSoNSub, MuliToSoNMul>(
        patterns.getContext());
}

} // namespace son
} // namespace mlir
