# Directory containing test files
TEST_PATH     := test
# Space-separated list of header files (e.g., algebra.hpp)
HEADERS       := route.hpp
# Space-separated list of implementation files (e.g., algebra.cpp)
IMPLEMS       := route.cpp
# File containing main
DRIVER        := tuffytravel.cpp
# Expected name of executable file
EXECFILE      := tuffytravel
CLANGTDY_CHKS := *,-google-build-using-namespace,-fuchsia-default-arguments,-llvm-header-guard,-cppcoreguidelines-pro-bounds-array-to-pointer-decay,-hicpp-no-array-decay,-cppcoreguidelines-pro-bounds-constant-array-index,-google-runtime-int,-cppcoreguidelines-pro-type-member-init,-hicpp-member-init,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-google-runtime-references,-hicpp-avoid-c-arrays,-cppcoreguidelines-avoid-magic-numbers,-readability-magic-numbers,-cppcoreguidelines-avoid-c-arrays,-modernize-avoid-c-arrays,-bugprone-too-small-loop-variable,-modernize-pass-by-value,-modernize-use-default-member-init,-cppcoreguidelines-owning-memory,-cppcoreguidelines-special-member-functions,-modernize-use-nodiscard,-hicpp-use-auto,-hicpp-special-member-functions,-modernize-use-auto
