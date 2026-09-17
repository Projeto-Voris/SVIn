#ifndef BRISK_INTERNAL_HAMMING_H_
#define BRISK_INTERNAL_HAMMING_H_

#include <stdint.h>
#if defined(__ARM_NEON__) || defined(__ARM_NEON)
#include <arm_neon.h>
#elif defined(__x86_64__) || defined(_M_X64)
#include <popcntintrin.h>
#endif

namespace brisk {
namespace Hamming {

inline __attribute__((always_inline)) uint32_t Popcnt32(uint32_t value) {
#if defined(__x86_64__) || defined(_M_X64)
    return __builtin_popcount(value);
#else
    uint32_t c = 0;
    for (; value; c++) { value &= value - 1; }
    return c;
#endif
}

inline __attribute__((always_inline)) uint32_t Popcnt64(uint64_t value) {
#if defined(__x86_64__) || defined(_M_X64)
    return __builtin_popcountll(value);
#else
    uint32_t c = 0;
    for (; value; c++) { value &= value - 1; }
    return c;
#endif
}

} // namespace Hamming
} // namespace brisk

#endif // BRISK_INTERNAL_HAMMING_H_
