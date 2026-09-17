#include <iostream>
#include <string>

using namespace std;

int main(){
    cout << "========================================\n";
    cout << "        Compiler / System Information\n";
    cout << "========================================\n\n";

    // Compiler
    cout << "Compiler       : ";

#if defined(__clang__)
    cout << "Clang\n";
    cout << "Compiler Ver.  : "
         << __clang_major__ << "."
         << __clang_minor__ << "."
         << __clang_patchlevel__ << "\n";

#elif defined(__GNUC__)
    cout << "GCC / GNU\n";
    cout << "Compiler Ver.  : "
         << __GNUC__ << "."
         << __GNUC_MINOR__ << "."
         << __GNUC_PATCHLEVEL__ << "\n";

#elif defined(_MSC_VER)
    cout << "Microsoft Visual C++\n";
    cout << "Compiler Ver.  : " << _MSC_VER << "\n";

#elif defined(__INTEL_COMPILER)
    cout << "Intel C++ Compiler\n";
    cout << "Compiler Ver.  : " << __INTEL_COMPILER << "\n";

#elif defined(__INTEL_LLVM_COMPILER)
    cout << "Intel oneAPI DPC++/C++ Compiler\n";
    cout << "Compiler Ver.  : " << __INTEL_LLVM_COMPILER << "\n";

#elif defined(__NVCC__)
    cout << "NVIDIA CUDA Compiler (NVCC)\n";

#else
    cout << "Unknown\n";
#endif

    // C++ standard
    cout << "\nC++ Standard   : ";

#if __cplusplus == 199711L
    cout << "C++98\n";
#elif __cplusplus == 201103L
    cout << "C++11\n";
#elif __cplusplus == 201402L
    cout << "C++14\n";
#elif __cplusplus == 201703L
    cout << "C++17\n";
#elif __cplusplus == 202002L
    cout << "C++20\n";
#elif __cplusplus == 202302L
    cout << "C++23\n";
#elif __cplusplus > 202302L
    cout << "C++26 or newer\n";
#else
    cout << "Unknown (" << __cplusplus << ")\n";
#endif

    // Architecture
    cout << "Architecture   : ";

#if defined(__x86_64__) || defined(_M_X64) || defined(_M_AMD64)
    cout << "x86-64 / AMD64\n";
#elif defined(__i386__) || defined(_M_IX86)
    cout << "x86 / 32-bit\n";
#elif defined(__aarch64__) || defined(_M_ARM64)
    cout << "ARM64 / AArch64\n";
#elif defined(__arm__) || defined(_M_ARM)
    cout << "ARM 32-bit\n";
#elif defined(__riscv) || defined(__riscv_xlen)
    cout << "RISC-V\n";
#elif defined(__powerpc64__) || defined(__ppc64__)
    cout << "PowerPC 64-bit\n";
#elif defined(__powerpc__) || defined(__ppc__)
    cout << "PowerPC\n";
#else
    cout << "Unknown\n";
#endif

    // Pointer size
    cout << "Pointer Size   : "
         << sizeof(void*) * 8 << " bits\n";

    // OS
    cout << "Operating Sys. : ";

#if defined(_WIN64)
    cout << "Windows 64-bit\n";
#elif defined(_WIN32)
    cout << "Windows 32-bit\n";
#elif defined(__linux__)
    cout << "Linux\n";
#elif defined(__APPLE__)
    cout << "macOS / Apple OS\n";
#elif defined(__FreeBSD__)
    cout << "FreeBSD\n";
#elif defined(__unix__)
    cout << "Unix\n";
#else
    cout << "Unknown\n";
#endif

    // Endianness
    cout << "Endianness     : ";

#if defined(__BYTE_ORDER__) && defined(__ORDER_LITTLE_ENDIAN__)
    #if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
        cout << "Little Endian\n";
    #elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
        cout << "Big Endian\n";
    #else
        cout << "Unknown\n";
    #endif
#else
    cout << "Not detected\n";
#endif

    // C++ compiler date
    cout << "Compiled On    : " << __DATE__ << " " << __TIME__ << "\n";

    // Debug / release
#ifdef NDEBUG
    cout << "Build Type     : Release (NDEBUG defined)\n";
#else
    cout << "Build Type     : Debug / NDEBUG not defined\n";
#endif

    cout << "\n========================================\n";

    return 0;
}