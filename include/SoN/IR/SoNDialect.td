#ifndef SON_DIALECT_TD
#define SON_DIALECT_TD

include "mlir/IR/OpBase.td"
include "mlir/IR/AttrTypeBase.td"

def SoN_Dialect : Dialect {
    let name = "son";
    let summary = "Sea-of-Nodes dialect";
    let cppNamespace = "::mlir::son";
}

class SoN_Op<string mnemonic, list<Trait> traits = []> :
    Op<SoN_Dialect, mnemonic, traits>;

def SoN_AddOp : SoN_Op<"add"> {
    let summary = "Sea-of-Nodes add node";
    let arguments = (ins AnyInteger:$lhs, AnyInteger:$rhs);
    let results = (outs AnyInteger:$result);
}

#endif
