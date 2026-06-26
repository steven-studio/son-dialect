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

// 算術
def SoN_AddOp : SoN_Op<"add"> {
    let summary = "add";
    let arguments = (ins AnyInteger:$lhs, AnyInteger:$rhs);
    let results = (outs AnyInteger:$result);
}

def SoN_SubOp : SoN_Op<"sub"> {
    let summary = "subtract";
    let arguments = (ins AnyInteger:$lhs, AnyInteger:$rhs);
    let results = (outs AnyInteger:$result);
}

def SoN_MulOp : SoN_Op<"mul"> {
    let summary = "multiply";
    let arguments = (ins AnyInteger:$lhs, AnyInteger:$rhs);
    let results = (outs AnyInteger:$result);
}

// 比較
def SoN_EqOp : SoN_Op<"eq"> {
    let summary = "equal";
    let arguments = (ins AnyInteger:$lhs, AnyInteger:$rhs);
    let results = (outs I1:$result);
}

def SoN_LtOp : SoN_Op<"lt"> {
    let summary = "less than";
    let arguments = (ins AnyInteger:$lhs, AnyInteger:$rhs);
    let results = (outs I1:$result);
}

// 控制流
def SoN_IfOp : SoN_Op<"if"> {
    let summary = "if node";
    let arguments = (ins I1:$cond);
    let results = (outs NoneType:$true_ctrl, NoneType:$false_ctrl);
}

def SoN_PhiOp : SoN_Op<"phi"> {
    let summary = "phi node";
    let arguments = (ins AnyType:$left, AnyType:$right);
    let results = (outs AnyType:$result);
}

def SoN_ReturnOp : SoN_Op<"return"> {
    let summary = "return node";
    let arguments = (ins AnyType:$value);
}

#endif
