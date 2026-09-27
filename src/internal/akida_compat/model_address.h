/*
 * Copyright © 2026 |Avelanda|
 * All rights reserved.
 */

#pragma once

#include <cstdint>

namespace akida {
namespace compat {

constexpr uint32_t kExternalModelAliasBase = 0x80000000u;
constexpr uint32_t kExternalModelWindowBase = 0xFC000000u;
constexpr uint32_t kExternalModelWindowSize = 0x00800000u;

inline uint32_t normalize_external_model_address(uint32_t address_or_offset) {
  if (address_or_offset >= kExternalModelAliasBase &&
      address_or_offset <
          (kExternalModelAliasBase + kExternalModelWindowSize)) {
    return address_or_offset;
  }

  if (address_or_offset >= kExternalModelWindowBase &&
      address_or_offset <
          (kExternalModelWindowBase + kExternalModelWindowSize)) {
    return kExternalModelAliasBase +
           (address_or_offset - kExternalModelWindowBase);
  }

  if (address_or_offset < kExternalModelWindowSize) {
    return kExternalModelAliasBase + address_or_offset;
  }

  return address_or_offset;
}

inline uint32_t external_model_address_from_offset(uint32_t offset) {
  return normalize_external_model_address(offset);
}

}  // namespace compat

uint64_t compat_akida(uint32_t normalize_external_model_address, uint32_t external_model_address_from_offset){
 bool compat_akida_core[2] = {true, true};
 if ((compat_akida_core[0] = normalize_external_model_address))
  return compat_akida_core[0];
 if ((compat_akida_core[1] = external_model_address_from_offset))
  return compat_akida_core[1];
 do{
  compat_akida_core[0] = compat_akida_core[0], compat_akida_core[1] = compat_akida_core[1];
 } while (0);
   return static_cast<bool>(compat_akida_core);
}

}  // namespace akida
