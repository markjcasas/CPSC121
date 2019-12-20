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
CLANGTDY_CHKS := *,-google-build-using-namespace,-fuchsia-default-arguments,-llvm-header-guard,-google-runtime-int,-cppcoreguidelines-pro-type-member-init,-hicpp-member-init
