/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Op Definitions                                                             *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|* From: SoNOps.td                                                            *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifdef GET_OP_LIST
#undef GET_OP_LIST

::mlir::son::AddOp,
::mlir::son::EqOp,
::mlir::son::IfOp,
::mlir::son::LtOp,
::mlir::son::MulOp,
::mlir::son::PhiOp,
::mlir::son::ReturnOp,
::mlir::son::SubOp
#endif  // GET_OP_LIST

#ifdef GET_OP_CLASSES
#undef GET_OP_CLASSES


//===----------------------------------------------------------------------===//
// Local Utility Method Definitions
//===----------------------------------------------------------------------===//

namespace mlir {
namespace son {

static ::mlir::LogicalResult __mlir_ods_local_type_constraint_SoNOps0(
    ::mlir::Operation *op, ::mlir::Type type, ::llvm::StringRef valueKind,
    unsigned valueIndex) {
  if (!((::llvm::isa<::mlir::IntegerType>(type)))) {
    return op->emitOpError(valueKind) << " #" << valueIndex
        << " must be integer, but got " << type;
  }
  return ::mlir::success();
}

static ::mlir::LogicalResult __mlir_ods_local_type_constraint_SoNOps1(
    ::mlir::Operation *op, ::mlir::Type type, ::llvm::StringRef valueKind,
    unsigned valueIndex) {
  if (!((type.isSignlessInteger(1)))) {
    return op->emitOpError(valueKind) << " #" << valueIndex
        << " must be 1-bit signless integer, but got " << type;
  }
  return ::mlir::success();
}

static ::mlir::LogicalResult __mlir_ods_local_type_constraint_SoNOps2(
    ::mlir::Operation *op, ::mlir::Type type, ::llvm::StringRef valueKind,
    unsigned valueIndex) {
  if (!((::llvm::isa<::mlir::NoneType>(type)))) {
    return op->emitOpError(valueKind) << " #" << valueIndex
        << " must be none type, but got " << type;
  }
  return ::mlir::success();
}

static ::mlir::LogicalResult __mlir_ods_local_type_constraint_SoNOps3(
    ::mlir::Operation *op, ::mlir::Type type, ::llvm::StringRef valueKind,
    unsigned valueIndex) {
  if (!((true))) {
    return op->emitOpError(valueKind) << " #" << valueIndex
        << " must be any type, but got " << type;
  }
  return ::mlir::success();
}
} // namespace son
} // namespace mlir
namespace mlir {
namespace son {

//===----------------------------------------------------------------------===//
// ::mlir::son::AddOp definitions
//===----------------------------------------------------------------------===//

namespace detail {
AddOpGenericAdaptorBase::AddOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const ::mlir::EmptyProperties &properties, ::mlir::RegionRange regions) : odsAttrs(attrs), odsRegions(regions) {  if (odsAttrs)
    odsOpName.emplace("son.add", odsAttrs.getContext());
}

AddOpGenericAdaptorBase::AddOpGenericAdaptorBase(AddOp op) : AddOpGenericAdaptorBase(op->getAttrDictionary(), op.getProperties(), op->getRegions()) {}

std::pair<unsigned, unsigned> AddOpGenericAdaptorBase::getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
  return {index, 1};
}

::mlir::DictionaryAttr AddOpGenericAdaptorBase::getAttributes() {
  return odsAttrs;
}

} // namespace detail
AddOpAdaptor::AddOpAdaptor(AddOp op) : AddOpGenericAdaptor(op->getOperands(), op) {}

::mlir::LogicalResult AddOpAdaptor::verify(::mlir::Location loc) {
  return ::mlir::success();
}

std::pair<unsigned, unsigned> AddOp::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::Operation::operand_range AddOp::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(getOperation()->operand_begin(), valueRange.first),
           std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
}

::mlir::TypedValue<::mlir::IntegerType> AddOp::getLhs() {
  return ::llvm::cast<::mlir::TypedValue<::mlir::IntegerType>>(*getODSOperands(0).begin());
}

::mlir::TypedValue<::mlir::IntegerType> AddOp::getRhs() {
  return ::llvm::cast<::mlir::TypedValue<::mlir::IntegerType>>(*getODSOperands(1).begin());
}

::mlir::OpOperand &AddOp::getLhsMutable() {
  auto range = getODSOperandIndexAndLength(0);
  return getOperation()->getOpOperand(range.first);
}

::mlir::OpOperand &AddOp::getRhsMutable() {
  auto range = getODSOperandIndexAndLength(1);
  return getOperation()->getOpOperand(range.first);
}

std::pair<unsigned, unsigned> AddOp::getODSResultIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::Operation::result_range AddOp::getODSResults(unsigned index) {
  auto valueRange = getODSResultIndexAndLength(index);
  return {std::next(getOperation()->result_begin(), valueRange.first),
           std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
}

::mlir::TypedValue<::mlir::IntegerType> AddOp::getResult() {
  return ::llvm::cast<::mlir::TypedValue<::mlir::IntegerType>>(*getODSResults(0).begin());
}

void AddOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value lhs, ::mlir::Value rhs) {
  odsState.addOperands(lhs);
  odsState.addOperands(rhs);
  odsState.addTypes(result);
}

void AddOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value lhs, ::mlir::Value rhs) {
  odsState.addOperands(lhs);
  odsState.addOperands(rhs);
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void AddOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 2u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

::mlir::LogicalResult AddOp::verifyInvariantsImpl() {
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_SoNOps0(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
    auto valueGroup1 = getODSOperands(1);

    for (auto v : valueGroup1) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_SoNOps0(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_SoNOps0(*this, v.getType(), "result", index++)))
        return ::mlir::failure();
    }
  }
  return ::mlir::success();
}

::mlir::LogicalResult AddOp::verifyInvariants() {
  return verifyInvariantsImpl();
}

} // namespace son
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::son::AddOp)

namespace mlir {
namespace son {

//===----------------------------------------------------------------------===//
// ::mlir::son::EqOp definitions
//===----------------------------------------------------------------------===//

namespace detail {
EqOpGenericAdaptorBase::EqOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const ::mlir::EmptyProperties &properties, ::mlir::RegionRange regions) : odsAttrs(attrs), odsRegions(regions) {  if (odsAttrs)
    odsOpName.emplace("son.eq", odsAttrs.getContext());
}

EqOpGenericAdaptorBase::EqOpGenericAdaptorBase(EqOp op) : EqOpGenericAdaptorBase(op->getAttrDictionary(), op.getProperties(), op->getRegions()) {}

std::pair<unsigned, unsigned> EqOpGenericAdaptorBase::getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
  return {index, 1};
}

::mlir::DictionaryAttr EqOpGenericAdaptorBase::getAttributes() {
  return odsAttrs;
}

} // namespace detail
EqOpAdaptor::EqOpAdaptor(EqOp op) : EqOpGenericAdaptor(op->getOperands(), op) {}

::mlir::LogicalResult EqOpAdaptor::verify(::mlir::Location loc) {
  return ::mlir::success();
}

std::pair<unsigned, unsigned> EqOp::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::Operation::operand_range EqOp::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(getOperation()->operand_begin(), valueRange.first),
           std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
}

::mlir::TypedValue<::mlir::IntegerType> EqOp::getLhs() {
  return ::llvm::cast<::mlir::TypedValue<::mlir::IntegerType>>(*getODSOperands(0).begin());
}

::mlir::TypedValue<::mlir::IntegerType> EqOp::getRhs() {
  return ::llvm::cast<::mlir::TypedValue<::mlir::IntegerType>>(*getODSOperands(1).begin());
}

::mlir::OpOperand &EqOp::getLhsMutable() {
  auto range = getODSOperandIndexAndLength(0);
  return getOperation()->getOpOperand(range.first);
}

::mlir::OpOperand &EqOp::getRhsMutable() {
  auto range = getODSOperandIndexAndLength(1);
  return getOperation()->getOpOperand(range.first);
}

std::pair<unsigned, unsigned> EqOp::getODSResultIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::Operation::result_range EqOp::getODSResults(unsigned index) {
  auto valueRange = getODSResultIndexAndLength(index);
  return {std::next(getOperation()->result_begin(), valueRange.first),
           std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
}

::mlir::TypedValue<::mlir::IntegerType> EqOp::getResult() {
  return ::llvm::cast<::mlir::TypedValue<::mlir::IntegerType>>(*getODSResults(0).begin());
}

void EqOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value lhs, ::mlir::Value rhs) {
  odsState.addOperands(lhs);
  odsState.addOperands(rhs);
  odsState.addTypes(result);
}

void EqOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value lhs, ::mlir::Value rhs) {
  odsState.addOperands(lhs);
  odsState.addOperands(rhs);
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void EqOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 2u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

::mlir::LogicalResult EqOp::verifyInvariantsImpl() {
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_SoNOps0(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
    auto valueGroup1 = getODSOperands(1);

    for (auto v : valueGroup1) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_SoNOps0(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_SoNOps1(*this, v.getType(), "result", index++)))
        return ::mlir::failure();
    }
  }
  return ::mlir::success();
}

::mlir::LogicalResult EqOp::verifyInvariants() {
  return verifyInvariantsImpl();
}

} // namespace son
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::son::EqOp)

namespace mlir {
namespace son {

//===----------------------------------------------------------------------===//
// ::mlir::son::IfOp definitions
//===----------------------------------------------------------------------===//

namespace detail {
IfOpGenericAdaptorBase::IfOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const ::mlir::EmptyProperties &properties, ::mlir::RegionRange regions) : odsAttrs(attrs), odsRegions(regions) {  if (odsAttrs)
    odsOpName.emplace("son.if", odsAttrs.getContext());
}

IfOpGenericAdaptorBase::IfOpGenericAdaptorBase(IfOp op) : IfOpGenericAdaptorBase(op->getAttrDictionary(), op.getProperties(), op->getRegions()) {}

std::pair<unsigned, unsigned> IfOpGenericAdaptorBase::getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
  return {index, 1};
}

::mlir::DictionaryAttr IfOpGenericAdaptorBase::getAttributes() {
  return odsAttrs;
}

} // namespace detail
IfOpAdaptor::IfOpAdaptor(IfOp op) : IfOpGenericAdaptor(op->getOperands(), op) {}

::mlir::LogicalResult IfOpAdaptor::verify(::mlir::Location loc) {
  return ::mlir::success();
}

void IfOp::getAsmResultNames(::mlir::OpAsmSetValueNameFn setNameFn) {
  auto resultGroup0 = getODSResults(0);
  if (!resultGroup0.empty())
    setNameFn(*resultGroup0.begin(), "true_ctrl");
  auto resultGroup1 = getODSResults(1);
  if (!resultGroup1.empty())
    setNameFn(*resultGroup1.begin(), "false_ctrl");
}

std::pair<unsigned, unsigned> IfOp::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::Operation::operand_range IfOp::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(getOperation()->operand_begin(), valueRange.first),
           std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
}

::mlir::TypedValue<::mlir::IntegerType> IfOp::getCond() {
  return ::llvm::cast<::mlir::TypedValue<::mlir::IntegerType>>(*getODSOperands(0).begin());
}

::mlir::OpOperand &IfOp::getCondMutable() {
  auto range = getODSOperandIndexAndLength(0);
  return getOperation()->getOpOperand(range.first);
}

std::pair<unsigned, unsigned> IfOp::getODSResultIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::Operation::result_range IfOp::getODSResults(unsigned index) {
  auto valueRange = getODSResultIndexAndLength(index);
  return {std::next(getOperation()->result_begin(), valueRange.first),
           std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
}

::mlir::TypedValue<::mlir::NoneType> IfOp::getTrueCtrl() {
  return ::llvm::cast<::mlir::TypedValue<::mlir::NoneType>>(*getODSResults(0).begin());
}

::mlir::TypedValue<::mlir::NoneType> IfOp::getFalseCtrl() {
  return ::llvm::cast<::mlir::TypedValue<::mlir::NoneType>>(*getODSResults(1).begin());
}

void IfOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type true_ctrl, ::mlir::Type false_ctrl, ::mlir::Value cond) {
  odsState.addOperands(cond);
  odsState.addTypes(true_ctrl);
  odsState.addTypes(false_ctrl);
}

void IfOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value cond) {
  odsState.addOperands(cond);
  assert(resultTypes.size() == 2u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void IfOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 1u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 2u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

::mlir::LogicalResult IfOp::verifyInvariantsImpl() {
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_SoNOps1(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_SoNOps2(*this, v.getType(), "result", index++)))
        return ::mlir::failure();
    }
    auto valueGroup1 = getODSResults(1);

    for (auto v : valueGroup1) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_SoNOps2(*this, v.getType(), "result", index++)))
        return ::mlir::failure();
    }
  }
  return ::mlir::success();
}

::mlir::LogicalResult IfOp::verifyInvariants() {
  return verifyInvariantsImpl();
}

} // namespace son
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::son::IfOp)

namespace mlir {
namespace son {

//===----------------------------------------------------------------------===//
// ::mlir::son::LtOp definitions
//===----------------------------------------------------------------------===//

namespace detail {
LtOpGenericAdaptorBase::LtOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const ::mlir::EmptyProperties &properties, ::mlir::RegionRange regions) : odsAttrs(attrs), odsRegions(regions) {  if (odsAttrs)
    odsOpName.emplace("son.lt", odsAttrs.getContext());
}

LtOpGenericAdaptorBase::LtOpGenericAdaptorBase(LtOp op) : LtOpGenericAdaptorBase(op->getAttrDictionary(), op.getProperties(), op->getRegions()) {}

std::pair<unsigned, unsigned> LtOpGenericAdaptorBase::getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
  return {index, 1};
}

::mlir::DictionaryAttr LtOpGenericAdaptorBase::getAttributes() {
  return odsAttrs;
}

} // namespace detail
LtOpAdaptor::LtOpAdaptor(LtOp op) : LtOpGenericAdaptor(op->getOperands(), op) {}

::mlir::LogicalResult LtOpAdaptor::verify(::mlir::Location loc) {
  return ::mlir::success();
}

std::pair<unsigned, unsigned> LtOp::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::Operation::operand_range LtOp::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(getOperation()->operand_begin(), valueRange.first),
           std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
}

::mlir::TypedValue<::mlir::IntegerType> LtOp::getLhs() {
  return ::llvm::cast<::mlir::TypedValue<::mlir::IntegerType>>(*getODSOperands(0).begin());
}

::mlir::TypedValue<::mlir::IntegerType> LtOp::getRhs() {
  return ::llvm::cast<::mlir::TypedValue<::mlir::IntegerType>>(*getODSOperands(1).begin());
}

::mlir::OpOperand &LtOp::getLhsMutable() {
  auto range = getODSOperandIndexAndLength(0);
  return getOperation()->getOpOperand(range.first);
}

::mlir::OpOperand &LtOp::getRhsMutable() {
  auto range = getODSOperandIndexAndLength(1);
  return getOperation()->getOpOperand(range.first);
}

std::pair<unsigned, unsigned> LtOp::getODSResultIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::Operation::result_range LtOp::getODSResults(unsigned index) {
  auto valueRange = getODSResultIndexAndLength(index);
  return {std::next(getOperation()->result_begin(), valueRange.first),
           std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
}

::mlir::TypedValue<::mlir::IntegerType> LtOp::getResult() {
  return ::llvm::cast<::mlir::TypedValue<::mlir::IntegerType>>(*getODSResults(0).begin());
}

void LtOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value lhs, ::mlir::Value rhs) {
  odsState.addOperands(lhs);
  odsState.addOperands(rhs);
  odsState.addTypes(result);
}

void LtOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value lhs, ::mlir::Value rhs) {
  odsState.addOperands(lhs);
  odsState.addOperands(rhs);
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void LtOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 2u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

::mlir::LogicalResult LtOp::verifyInvariantsImpl() {
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_SoNOps0(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
    auto valueGroup1 = getODSOperands(1);

    for (auto v : valueGroup1) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_SoNOps0(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_SoNOps1(*this, v.getType(), "result", index++)))
        return ::mlir::failure();
    }
  }
  return ::mlir::success();
}

::mlir::LogicalResult LtOp::verifyInvariants() {
  return verifyInvariantsImpl();
}

} // namespace son
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::son::LtOp)

namespace mlir {
namespace son {

//===----------------------------------------------------------------------===//
// ::mlir::son::MulOp definitions
//===----------------------------------------------------------------------===//

namespace detail {
MulOpGenericAdaptorBase::MulOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const ::mlir::EmptyProperties &properties, ::mlir::RegionRange regions) : odsAttrs(attrs), odsRegions(regions) {  if (odsAttrs)
    odsOpName.emplace("son.mul", odsAttrs.getContext());
}

MulOpGenericAdaptorBase::MulOpGenericAdaptorBase(MulOp op) : MulOpGenericAdaptorBase(op->getAttrDictionary(), op.getProperties(), op->getRegions()) {}

std::pair<unsigned, unsigned> MulOpGenericAdaptorBase::getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
  return {index, 1};
}

::mlir::DictionaryAttr MulOpGenericAdaptorBase::getAttributes() {
  return odsAttrs;
}

} // namespace detail
MulOpAdaptor::MulOpAdaptor(MulOp op) : MulOpGenericAdaptor(op->getOperands(), op) {}

::mlir::LogicalResult MulOpAdaptor::verify(::mlir::Location loc) {
  return ::mlir::success();
}

std::pair<unsigned, unsigned> MulOp::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::Operation::operand_range MulOp::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(getOperation()->operand_begin(), valueRange.first),
           std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
}

::mlir::TypedValue<::mlir::IntegerType> MulOp::getLhs() {
  return ::llvm::cast<::mlir::TypedValue<::mlir::IntegerType>>(*getODSOperands(0).begin());
}

::mlir::TypedValue<::mlir::IntegerType> MulOp::getRhs() {
  return ::llvm::cast<::mlir::TypedValue<::mlir::IntegerType>>(*getODSOperands(1).begin());
}

::mlir::OpOperand &MulOp::getLhsMutable() {
  auto range = getODSOperandIndexAndLength(0);
  return getOperation()->getOpOperand(range.first);
}

::mlir::OpOperand &MulOp::getRhsMutable() {
  auto range = getODSOperandIndexAndLength(1);
  return getOperation()->getOpOperand(range.first);
}

std::pair<unsigned, unsigned> MulOp::getODSResultIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::Operation::result_range MulOp::getODSResults(unsigned index) {
  auto valueRange = getODSResultIndexAndLength(index);
  return {std::next(getOperation()->result_begin(), valueRange.first),
           std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
}

::mlir::TypedValue<::mlir::IntegerType> MulOp::getResult() {
  return ::llvm::cast<::mlir::TypedValue<::mlir::IntegerType>>(*getODSResults(0).begin());
}

void MulOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value lhs, ::mlir::Value rhs) {
  odsState.addOperands(lhs);
  odsState.addOperands(rhs);
  odsState.addTypes(result);
}

void MulOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value lhs, ::mlir::Value rhs) {
  odsState.addOperands(lhs);
  odsState.addOperands(rhs);
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void MulOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 2u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

::mlir::LogicalResult MulOp::verifyInvariantsImpl() {
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_SoNOps0(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
    auto valueGroup1 = getODSOperands(1);

    for (auto v : valueGroup1) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_SoNOps0(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_SoNOps0(*this, v.getType(), "result", index++)))
        return ::mlir::failure();
    }
  }
  return ::mlir::success();
}

::mlir::LogicalResult MulOp::verifyInvariants() {
  return verifyInvariantsImpl();
}

} // namespace son
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::son::MulOp)

namespace mlir {
namespace son {

//===----------------------------------------------------------------------===//
// ::mlir::son::PhiOp definitions
//===----------------------------------------------------------------------===//

namespace detail {
PhiOpGenericAdaptorBase::PhiOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const ::mlir::EmptyProperties &properties, ::mlir::RegionRange regions) : odsAttrs(attrs), odsRegions(regions) {  if (odsAttrs)
    odsOpName.emplace("son.phi", odsAttrs.getContext());
}

PhiOpGenericAdaptorBase::PhiOpGenericAdaptorBase(PhiOp op) : PhiOpGenericAdaptorBase(op->getAttrDictionary(), op.getProperties(), op->getRegions()) {}

std::pair<unsigned, unsigned> PhiOpGenericAdaptorBase::getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
  return {index, 1};
}

::mlir::DictionaryAttr PhiOpGenericAdaptorBase::getAttributes() {
  return odsAttrs;
}

} // namespace detail
PhiOpAdaptor::PhiOpAdaptor(PhiOp op) : PhiOpGenericAdaptor(op->getOperands(), op) {}

::mlir::LogicalResult PhiOpAdaptor::verify(::mlir::Location loc) {
  return ::mlir::success();
}

std::pair<unsigned, unsigned> PhiOp::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::Operation::operand_range PhiOp::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(getOperation()->operand_begin(), valueRange.first),
           std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
}

::mlir::Value PhiOp::getLeft() {
  return ::llvm::cast<::mlir::Value>(*getODSOperands(0).begin());
}

::mlir::Value PhiOp::getRight() {
  return ::llvm::cast<::mlir::Value>(*getODSOperands(1).begin());
}

::mlir::OpOperand &PhiOp::getLeftMutable() {
  auto range = getODSOperandIndexAndLength(0);
  return getOperation()->getOpOperand(range.first);
}

::mlir::OpOperand &PhiOp::getRightMutable() {
  auto range = getODSOperandIndexAndLength(1);
  return getOperation()->getOpOperand(range.first);
}

std::pair<unsigned, unsigned> PhiOp::getODSResultIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::Operation::result_range PhiOp::getODSResults(unsigned index) {
  auto valueRange = getODSResultIndexAndLength(index);
  return {std::next(getOperation()->result_begin(), valueRange.first),
           std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
}

::mlir::Value PhiOp::getResult() {
  return ::llvm::cast<::mlir::Value>(*getODSResults(0).begin());
}

void PhiOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value left, ::mlir::Value right) {
  odsState.addOperands(left);
  odsState.addOperands(right);
  odsState.addTypes(result);
}

void PhiOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value left, ::mlir::Value right) {
  odsState.addOperands(left);
  odsState.addOperands(right);
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void PhiOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 2u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

::mlir::LogicalResult PhiOp::verifyInvariantsImpl() {
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_SoNOps3(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
    auto valueGroup1 = getODSOperands(1);

    for (auto v : valueGroup1) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_SoNOps3(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_SoNOps3(*this, v.getType(), "result", index++)))
        return ::mlir::failure();
    }
  }
  return ::mlir::success();
}

::mlir::LogicalResult PhiOp::verifyInvariants() {
  return verifyInvariantsImpl();
}

} // namespace son
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::son::PhiOp)

namespace mlir {
namespace son {

//===----------------------------------------------------------------------===//
// ::mlir::son::ReturnOp definitions
//===----------------------------------------------------------------------===//

namespace detail {
ReturnOpGenericAdaptorBase::ReturnOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const ::mlir::EmptyProperties &properties, ::mlir::RegionRange regions) : odsAttrs(attrs), odsRegions(regions) {  if (odsAttrs)
    odsOpName.emplace("son.return", odsAttrs.getContext());
}

ReturnOpGenericAdaptorBase::ReturnOpGenericAdaptorBase(ReturnOp op) : ReturnOpGenericAdaptorBase(op->getAttrDictionary(), op.getProperties(), op->getRegions()) {}

std::pair<unsigned, unsigned> ReturnOpGenericAdaptorBase::getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
  return {index, 1};
}

::mlir::DictionaryAttr ReturnOpGenericAdaptorBase::getAttributes() {
  return odsAttrs;
}

} // namespace detail
ReturnOpAdaptor::ReturnOpAdaptor(ReturnOp op) : ReturnOpGenericAdaptor(op->getOperands(), op) {}

::mlir::LogicalResult ReturnOpAdaptor::verify(::mlir::Location loc) {
  return ::mlir::success();
}

std::pair<unsigned, unsigned> ReturnOp::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::Operation::operand_range ReturnOp::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(getOperation()->operand_begin(), valueRange.first),
           std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
}

::mlir::Value ReturnOp::getValue() {
  return ::llvm::cast<::mlir::Value>(*getODSOperands(0).begin());
}

::mlir::OpOperand &ReturnOp::getValueMutable() {
  auto range = getODSOperandIndexAndLength(0);
  return getOperation()->getOpOperand(range.first);
}

std::pair<unsigned, unsigned> ReturnOp::getODSResultIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::Operation::result_range ReturnOp::getODSResults(unsigned index) {
  auto valueRange = getODSResultIndexAndLength(index);
  return {std::next(getOperation()->result_begin(), valueRange.first),
           std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
}

void ReturnOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value value) {
  odsState.addOperands(value);
}

void ReturnOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value value) {
  odsState.addOperands(value);
  assert(resultTypes.size() == 0u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void ReturnOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 1u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 0u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

::mlir::LogicalResult ReturnOp::verifyInvariantsImpl() {
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_SoNOps3(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
  }
  return ::mlir::success();
}

::mlir::LogicalResult ReturnOp::verifyInvariants() {
  return verifyInvariantsImpl();
}

} // namespace son
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::son::ReturnOp)

namespace mlir {
namespace son {

//===----------------------------------------------------------------------===//
// ::mlir::son::SubOp definitions
//===----------------------------------------------------------------------===//

namespace detail {
SubOpGenericAdaptorBase::SubOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const ::mlir::EmptyProperties &properties, ::mlir::RegionRange regions) : odsAttrs(attrs), odsRegions(regions) {  if (odsAttrs)
    odsOpName.emplace("son.sub", odsAttrs.getContext());
}

SubOpGenericAdaptorBase::SubOpGenericAdaptorBase(SubOp op) : SubOpGenericAdaptorBase(op->getAttrDictionary(), op.getProperties(), op->getRegions()) {}

std::pair<unsigned, unsigned> SubOpGenericAdaptorBase::getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
  return {index, 1};
}

::mlir::DictionaryAttr SubOpGenericAdaptorBase::getAttributes() {
  return odsAttrs;
}

} // namespace detail
SubOpAdaptor::SubOpAdaptor(SubOp op) : SubOpGenericAdaptor(op->getOperands(), op) {}

::mlir::LogicalResult SubOpAdaptor::verify(::mlir::Location loc) {
  return ::mlir::success();
}

std::pair<unsigned, unsigned> SubOp::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::Operation::operand_range SubOp::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(getOperation()->operand_begin(), valueRange.first),
           std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
}

::mlir::TypedValue<::mlir::IntegerType> SubOp::getLhs() {
  return ::llvm::cast<::mlir::TypedValue<::mlir::IntegerType>>(*getODSOperands(0).begin());
}

::mlir::TypedValue<::mlir::IntegerType> SubOp::getRhs() {
  return ::llvm::cast<::mlir::TypedValue<::mlir::IntegerType>>(*getODSOperands(1).begin());
}

::mlir::OpOperand &SubOp::getLhsMutable() {
  auto range = getODSOperandIndexAndLength(0);
  return getOperation()->getOpOperand(range.first);
}

::mlir::OpOperand &SubOp::getRhsMutable() {
  auto range = getODSOperandIndexAndLength(1);
  return getOperation()->getOpOperand(range.first);
}

std::pair<unsigned, unsigned> SubOp::getODSResultIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::Operation::result_range SubOp::getODSResults(unsigned index) {
  auto valueRange = getODSResultIndexAndLength(index);
  return {std::next(getOperation()->result_begin(), valueRange.first),
           std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
}

::mlir::TypedValue<::mlir::IntegerType> SubOp::getResult() {
  return ::llvm::cast<::mlir::TypedValue<::mlir::IntegerType>>(*getODSResults(0).begin());
}

void SubOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value lhs, ::mlir::Value rhs) {
  odsState.addOperands(lhs);
  odsState.addOperands(rhs);
  odsState.addTypes(result);
}

void SubOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value lhs, ::mlir::Value rhs) {
  odsState.addOperands(lhs);
  odsState.addOperands(rhs);
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void SubOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 2u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

::mlir::LogicalResult SubOp::verifyInvariantsImpl() {
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_SoNOps0(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
    auto valueGroup1 = getODSOperands(1);

    for (auto v : valueGroup1) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_SoNOps0(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_SoNOps0(*this, v.getType(), "result", index++)))
        return ::mlir::failure();
    }
  }
  return ::mlir::success();
}

::mlir::LogicalResult SubOp::verifyInvariants() {
  return verifyInvariantsImpl();
}

} // namespace son
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::son::SubOp)


#endif  // GET_OP_CLASSES

