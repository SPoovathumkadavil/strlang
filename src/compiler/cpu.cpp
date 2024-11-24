
#include "compiler/cpu.h"

cpu_architecture get_cpu_build() { // Get current architecture, detectx nearly
                                   // every architecture. Coded by Freak
#if defined(__x86_64__) || defined(_M_X64)
  return cpu_architecture::x86_64;
#elif defined(i386) || defined(__i386__) || defined(__i386) || defined(_M_IX86)
  return cpu_architecture::x86_32;
#elif defined(__ARM_ARCH_2__)
  return cpu_architecture::ARM2;
#elif defined(__ARM_ARCH_3__) || defined(__ARM_ARCH_3M__)
  return cpu_architecture::ARM3;
#elif defined(__ARM_ARCH_4T__) || defined(__TARGET_ARM_4T)
  return cpu_architecture::ARM4T;
#elif defined(__ARM_ARCH_5_) || defined(__ARM_ARCH_5E_)
  return cpu_architecture::ARM5
#elif defined(__ARM_ARCH_6T2_) || defined(__ARM_ARCH_6T2_)
  return cpu_architecture::ARM6T2;
#elif defined(__ARM_ARCH_6__) || defined(__ARM_ARCH_6J__) ||                   \
    defined(__ARM_ARCH_6K__) || defined(__ARM_ARCH_6Z__) ||                    \
    defined(__ARM_ARCH_6ZK__)
  return cpu_architecture::ARM6;
#elif defined(__ARM_ARCH_7__) || defined(__ARM_ARCH_7A__) ||                   \
    defined(__ARM_ARCH_7R__) || defined(__ARM_ARCH_7M__) ||                    \
    defined(__ARM_ARCH_7S__)
  return cpu_architecture::ARM7;
#elif defined(__ARM_ARCH_7A__) || defined(__ARM_ARCH_7R__) ||                  \
    defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7S__)
  return cpu_architecture::ARM7A;
#elif defined(__ARM_ARCH_7R__) || defined(__ARM_ARCH_7M__) ||                  \
    defined(__ARM_ARCH_7S__)
  return cpu_architecture::ARM7R;
#elif defined(__ARM_ARCH_7M__)
  return cpu_architecture::ARM7M;
#elif defined(__ARM_ARCH_7S__)
  return cpu_architecture::ARM7S;
#elif defined(__aarch64__) || defined(_M_ARM64)
  return cpu_architecture::ARM64;
#elif defined(mips) || defined(__mips__) || defined(__mips)
  return cpu_architecture::MIPS;
#elif defined(__sh__)
  return cpu_architecture::SUPERH;
#elif defined(__powerpc) || defined(__powerpc__) || defined(__powerpc64__) ||  \
    defined(__POWERPC__) || defined(__ppc__) || defined(__PPC__) ||            \
    defined(_ARCH_PPC)
  return cpu_architecture::POWERPC;
#elif defined(__PPC64__) || defined(__ppc64__) || defined(_ARCH_PPC64)
  return cpu_architecture::POWERPC64;
#elif defined(__sparc__) || defined(__sparc)
  return cpu_architecture::SPARC;
#elif defined(__m68k__)
  return cpu_architecture::M68K;
#else
  return cpu_architecture::UNKNOWN;
#endif
}
