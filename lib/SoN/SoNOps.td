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

def SoN_AddOp : SoN_Op<"add"> {
    let summary = "add two integers";
    let arguments = (ins AnyInteger:$lhs, AnyInteger:$rhs);
    let results = (outs AnyInteger:$result);
}

#endif
