#include "SoN/IR/SoNDialect.h"
#include "SoN/IR/LowerToSoN.h"
#include "mlir/IR/PatternMatch.h"
#include "mlir/Dialect/Arith/IR/Arith.h"
#include "mlir/Dialect/Math/IR/Math.h"

namespace mlir {
namespace son {

// 整數算術
#define BINARY_INT_PATTERN(PatternName, SrcOp, DstOp) \
struct PatternName : public OpRewritePattern<SrcOp> { \
    using OpRewritePattern::OpRewritePattern; \
    LogicalResult matchAndRewrite(SrcOp op, PatternRewriter &rewriter) const override { \
        rewriter.replaceOpWithNewOp<DstOp>(op, op.getType(), op.getLhs(), op.getRhs()); \
        return success(); \
    } \
};

BINARY_INT_PATTERN(AddiToSoNAdd, arith::AddIOp, AddOp)
BINARY_INT_PATTERN(SubiToSoNSub, arith::SubIOp, SubOp)
BINARY_INT_PATTERN(MuliToSoNMul, arith::MulIOp, MulOp)
BINARY_INT_PATTERN(DivsiToSoNDiv, arith::DivSIOp, DivOp)
BINARY_INT_PATTERN(RemsiToSoNRem, arith::RemSIOp, RemOp)
BINARY_INT_PATTERN(AndiToSoNAnd, arith::AndIOp, AndOp)
BINARY_INT_PATTERN(OriToSoNOr,   arith::OrIOp,  OrOp)
BINARY_INT_PATTERN(XoriToSoNXor, arith::XOrIOp, XorOp)
BINARY_INT_PATTERN(ShliToSoNShl, arith::ShLIOp, ShlOp)
BINARY_INT_PATTERN(ShrsiToSoNShr,arith::ShRSIOp,ShrOp)

// 浮點算術
#define BINARY_FLOAT_PATTERN(PatternName, SrcOp, DstOp) \
struct PatternName : public OpRewritePattern<SrcOp> { \
    using OpRewritePattern::OpRewritePattern; \
    LogicalResult matchAndRewrite(SrcOp op, PatternRewriter &rewriter) const override { \
        rewriter.replaceOpWithNewOp<DstOp>(op, op.getType(), op.getLhs(), op.getRhs()); \
        return success(); \
    } \
};

BINARY_FLOAT_PATTERN(AddfToSoNFAdd, arith::AddFOp, FAddOp)
BINARY_FLOAT_PATTERN(SubfToSoNFSub, arith::SubFOp, FSubOp)
BINARY_FLOAT_PATTERN(MulfToSoNFMul, arith::MulFOp, FMulOp)
BINARY_FLOAT_PATTERN(DivfToSoNFDiv, arith::DivFOp, FDivOp)

struct NegfToSoNFNeg : public OpRewritePattern<arith::NegFOp> {
    using OpRewritePattern::OpRewritePattern;
    LogicalResult matchAndRewrite(arith::NegFOp op, PatternRewriter &rewriter) const override {
        rewriter.replaceOpWithNewOp<FNegOp>(op, op.getType(), op.getOperand());
        return success();
    }
};

// math unary
#define UNARY_MATH_PATTERN(PatternName, SrcOp, DstOp) \
struct PatternName : public OpRewritePattern<SrcOp> { \
    using OpRewritePattern::OpRewritePattern; \
    LogicalResult matchAndRewrite(SrcOp op, PatternRewriter &rewriter) const override { \
        rewriter.replaceOpWithNewOp<DstOp>(op, op.getType(), op.getOperand()); \
        return success(); \
    } \
};

UNARY_MATH_PATTERN(SqrtToSoN,  math::SqrtOp,  SqrtOp)
UNARY_MATH_PATTERN(ExpToSoN,   math::ExpOp,   ExpOp)
UNARY_MATH_PATTERN(SinToSoN,   math::SinOp,   SinOp)
UNARY_MATH_PATTERN(CosToSoN,   math::CosOp,   CosOp)
UNARY_MATH_PATTERN(TanhToSoN,  math::TanhOp,  TanhOp)
UNARY_MATH_PATTERN(LogToSoN,   math::LogOp,   LogOp)
UNARY_MATH_PATTERN(Log2ToSoN,  math::Log2Op,  Log2Op)
UNARY_MATH_PATTERN(AbsfToSoN,  math::AbsFOp,  AbsOp)

struct PowToSoN : public OpRewritePattern<math::PowFOp> {
    using OpRewritePattern::OpRewritePattern;
    LogicalResult matchAndRewrite(math::PowFOp op, PatternRewriter &rewriter) const override {
        rewriter.replaceOpWithNewOp<PowOp>(op, op.getType(), op.getLhs(), op.getRhs());
        return success();
    }
};

// 型別轉換
struct FptosiToSoN : public OpRewritePattern<arith::FPToSIOp> {
    using OpRewritePattern::OpRewritePattern;
    LogicalResult matchAndRewrite(arith::FPToSIOp op, PatternRewriter &rewriter) const override {
        rewriter.replaceOpWithNewOp<FP2IntOp>(op, op.getType(), op.getIn());
        return success();
    }
};

struct SitofpToSoN : public OpRewritePattern<arith::SIToFPOp> {
    using OpRewritePattern::OpRewritePattern;
    LogicalResult matchAndRewrite(arith::SIToFPOp op, PatternRewriter &rewriter) const override {
        rewriter.replaceOpWithNewOp<Int2FPOp>(op, op.getType(), op.getIn());
        return success();
    }
};

void populateArithToSoNPatterns(RewritePatternSet &patterns) {
    patterns.add<
        AddiToSoNAdd, SubiToSoNSub, MuliToSoNMul,
        DivsiToSoNDiv, RemsiToSoNRem,
        AndiToSoNAnd, OriToSoNOr, XoriToSoNXor,
        ShliToSoNShl, ShrsiToSoNShr,
        AddfToSoNFAdd, SubfToSoNFSub, MulfToSoNFMul, DivfToSoNFDiv,
        NegfToSoNFNeg,
        SqrtToSoN, ExpToSoN, SinToSoN, CosToSoN, TanhToSoN,
        LogToSoN, Log2ToSoN, AbsfToSoN, PowToSoN,
        FptosiToSoN, SitofpToSoN
    >(patterns.getContext());
}

} // namespace son
} // namespace mlir
