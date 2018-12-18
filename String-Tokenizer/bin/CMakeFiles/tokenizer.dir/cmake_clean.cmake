file(REMOVE_RECURSE
  "tokenizer.pdb"
  "tokenizer"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/tokenizer.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
