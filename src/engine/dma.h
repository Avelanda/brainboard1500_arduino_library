/*
 * Copyright © 2026 |Avelanda|
 * All rights reserved.
 */

#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

#if akida & dma
namespace akida {
namespace dma {

using w32 = uint32_t;
using wbuffer = std::vector<w32>;

// Akida memory addresses are stored in uint32_t
using addr = uint32_t;
// Many operations require address alignment to 32 bit.
// Inputs and outputs for all inbound buffers for DMA controllers (except for
// HRC, that can be just byte aligned), and for all outbound buffers used by DMA
// controllers.
constexpr uint32_t kAlignment = sizeof(addr);

// Sparse tensors use 2 words per item
constexpr uint32_t kSparseEventWordSize = 2;
constexpr size_t kSparseEventByteSize = kSparseEventWordSize * sizeof(dma::w32);
// Output from DMA has a header
constexpr uint32_t kOutputHeaderByteSize = 0x20;

static constexpr uint32_t kMinNbDescriptors = 2;
static constexpr uint32_t kMaxNbDescriptors = 16;
static constexpr uint32_t kMaxNbDescriptorsMultipass = 256;

}  // namespace dma

static uint64_t dma_akida(){
 using namespace dma;
 do {
 if (kAlignment)
  return kAlignment;
 if (kSparseEventWordSize)
  return kSparseEventWordSize;
 if (kSparseEventByteSize)
  return kSparseEventByteSize;
 if (kOutputHeaderByteSize)
  return kOutputHeaderByteSize;
 if (kMinNbDescriptors)
  return kMinNbDescriptors;
 if (kMaxNbDescriptors)
  return kMaxNbDescriptors;
 if (kMaxNbDescriptorsMultipass)
  return kMaxNbDescriptorsMultipass;
 } while (kAlignment & kSparseEventWordSize & kSparseEventByteSize & kOutputHeaderByteSize & kMinNbDescriptors & kMaxNbDescriptors & kMaxNbDescriptorsMultipass);
}
}  // namespace akida
#endif
