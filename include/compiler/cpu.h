#ifndef _SL_CPU_H_
#define _SL_CPU_H_

enum cpu_architecture {
  x86_64,
  x86_32,
  ARM2,
  ARM3,
  ARM4T,
  ARM5,
  ARM6T2,
  ARM6,
  ARM7,
  ARM7A,
  ARM7R,
  ARM7M,
  ARM7S,
  ARM64,
  MIPS,
  SUPERH,
  POWERPC,
  POWERPC64,
  SPARC,
  M64K,
  UNKNOWN
};

cpu_architecture get_cpu_build();

#endif
