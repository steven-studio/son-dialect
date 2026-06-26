#ifndef SON_OPS_TD
#define SON_OPS_TD

include "mlir/IR/OpBase.td"
include "mlir/IR/BuiltinTypes.td"

def SoN_Dialect : Dialect {
    let name = "son";
    let summary = "Sea-of-Nodes dialect";
    let cppNamespace = "::mlir::son";
    let useDefaultAttributePrinterParser = 0;
    let useDefaultTypePrinterParser = 0;
}

class SoN_Op<string mnemonic, list<Trait> traits = []> :
    Op<SoN_Dialect, mnemonic, traits>;

// 整數算術
def SoN_AddOp : SoN_Op<"add"> {
    let arguments = (ins AnyInteger:$lhs, AnyInteger:$rhs);
    let results = (outs AnyInteger:$result);
}
def SoN_SubOp : SoN_Op<"sub"> {
    let arguments = (ins AnyInteger:$lhs, AnyInteger:$rhs);
    let results = (outs AnyInteger:$result);
}
def SoN_MulOp : SoN_Op<"mul"> {
    let arguments = (ins AnyInteger:$lhs, AnyInteger:$rhs);
    let results = (outs AnyInteger:$result);
}
def SoN_DivOp : SoN_Op<"div"> {
    let arguments = (ins AnyInteger:$lhs, AnyInteger:$rhs);
    let results = (outs AnyInteger:$result);
}
def SoN_RemOp : SoN_Op<"rem"> {
    let arguments = (ins AnyInteger:$lhs, AnyInteger:$rhs);
    let results = (outs AnyInteger:$result);
}
def SoN_AndOp : SoN_Op<"and"> {
    let arguments = (ins AnyInteger:$lhs, AnyInteger:$rhs);
    let results = (outs AnyInteger:$result);
}
def SoN_OrOp : SoN_Op<"or"> {
    let arguments = (ins AnyInteger:$lhs, AnyInteger:$rhs);
    let results = (outs AnyInteger:$result);
}
def SoN_XorOp : SoN_Op<"xor"> {
    let arguments = (ins AnyInteger:$lhs, AnyInteger:$rhs);
    let results = (outs AnyInteger:$result);
}
def SoN_ShlOp : SoN_Op<"shl"> {
    let arguments = (ins AnyInteger:$lhs, AnyInteger:$rhs);
    let results = (outs AnyInteger:$result);
}
def SoN_ShrOp : SoN_Op<"shr"> {
    let arguments = (ins AnyInteger:$lhs, AnyInteger:$rhs);
    let results = (outs AnyInteger:$result);
}

// 浮點算術
def SoN_FAddOp : SoN_Op<"fadd"> {
    let arguments = (ins AnyFloat:$lhs, AnyFloat:$rhs);
    let results = (outs AnyFloat:$result);
}
def SoN_FSubOp : SoN_Op<"fsub"> {
    let arguments = (ins AnyFloat:$lhs, AnyFloat:$rhs);
    let results = (outs AnyFloat:$result);
}
def SoN_FMulOp : SoN_Op<"fmul"> {
    let arguments = (ins AnyFloat:$lhs, AnyFloat:$rhs);
    let results = (outs AnyFloat:$result);
}
def SoN_FDivOp : SoN_Op<"fdiv"> {
    let arguments = (ins AnyFloat:$lhs, AnyFloat:$rhs);
    let results = (outs AnyFloat:$result);
}
def SoN_FNegOp : SoN_Op<"fneg"> {
    let arguments = (ins AnyFloat:$operand);
    let results = (outs AnyFloat:$result);
}

// math unary (sqrt, exp, sin, cos, tanh, log, log2)
def SoN_SqrtOp  : SoN_Op<"sqrt">  { let arguments = (ins AnyFloat:$operand); let results = (outs AnyFloat:$result); }
def SoN_ExpOp   : SoN_Op<"exp">   { let arguments = (ins AnyFloat:$operand); let results = (outs AnyFloat:$result); }
def SoN_SinOp   : SoN_Op<"sin">   { let arguments = (ins AnyFloat:$operand); let results = (outs AnyFloat:$result); }
def SoN_CosOp   : SoN_Op<"cos">   { let arguments = (ins AnyFloat:$operand); let results = (outs AnyFloat:$result); }
def SoN_TanhOp  : SoN_Op<"tanh">  { let arguments = (ins AnyFloat:$operand); let results = (outs AnyFloat:$result); }
def SoN_LogOp   : SoN_Op<"log">   { let arguments = (ins AnyFloat:$operand); let results = (outs AnyFloat:$result); }
def SoN_Log2Op  : SoN_Op<"log2">  { let arguments = (ins AnyFloat:$operand); let results = (outs AnyFloat:$result); }
def SoN_AbsOp   : SoN_Op<"abs">   { let arguments = (ins AnyFloat:$operand); let results = (outs AnyFloat:$result); }
def SoN_PowOp   : SoN_Op<"pow">   { let arguments = (ins AnyFloat:$lhs, AnyFloat:$rhs); let results = (outs AnyFloat:$result); }

// 比較
def SoN_EqOp : SoN_Op<"eq"> { let arguments = (ins AnyType:$lhs, AnyType:$rhs); let results = (outs I1:$result); }
def SoN_NeOp : SoN_Op<"ne"> { let arguments = (ins AnyType:$lhs, AnyType:$rhs); let results = (outs I1:$result); }
def SoN_LtOp : SoN_Op<"lt"> { let arguments = (ins AnyType:$lhs, AnyType:$rhs); let results = (outs I1:$result); }
def SoN_LeOp : SoN_Op<"le"> { let arguments = (ins AnyType:$lhs, AnyType:$rhs); let results = (outs I1:$result); }
def SoN_GtOp : SoN_Op<"gt"> { let arguments = (ins AnyType:$lhs, AnyType:$rhs); let results = (outs I1:$result); }
def SoN_GeOp : SoN_Op<"ge"> { let arguments = (ins AnyType:$lhs, AnyType:$rhs); let results = (outs I1:$result); }

// 型別轉換
def SoN_TruncOp  : SoN_Op<"trunc">  { let arguments = (ins AnyType:$operand); let results = (outs AnyType:$result); }
def SoN_ExtOp    : SoN_Op<"ext">    { let arguments = (ins AnyType:$operand); let results = (outs AnyType:$result); }
def SoN_FP2IntOp : SoN_Op<"fp2int"> { let arguments = (ins AnyFloat:$operand); let results = (outs AnyInteger:$result); }
def SoN_Int2FPOp : SoN_Op<"int2fp"> { let arguments = (ins AnyInteger:$operand); let results = (outs AnyFloat:$result); }

// 控制流
def SoN_IfOp : SoN_Op<"if"> {
    let arguments = (ins I1:$cond);
    let results = (outs NoneType:$true_ctrl, NoneType:$false_ctrl);
}
def SoN_PhiOp : SoN_Op<"phi"> {
    let arguments = (ins AnyType:$left, AnyType:$right);
    let results = (outs AnyType:$result);
}
def SoN_ReturnOp : SoN_Op<"return"> {
    let arguments = (ins AnyType:$value);
}

#endif
