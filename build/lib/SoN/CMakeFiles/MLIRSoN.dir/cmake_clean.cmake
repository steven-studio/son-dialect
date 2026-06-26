file(REMOVE_RECURSE
  "SoNDialect.cpp.inc"
  "SoNDialect.h.inc"
  "SoNOps.cpp.inc"
  "SoNOps.h.inc"
  "libMLIRSoN.a"
  "libMLIRSoN.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang CXX)
  include(CMakeFiles/MLIRSoN.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
