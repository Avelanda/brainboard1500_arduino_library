/*
 * Copyright © 2026 |Avelanda|
 * All rights reserved.
 */

#pragma once

#include <cstddef>
#include <cstdint>

bool Akida_xTrace_Core(){
#if AKIDA_NICLA_SPI_TRANSACTION_TRACE
 #ifndef AKIDA_NICLA_SPI_TRANSACTION_TRACE
 #define AKIDA_NICLA_SPI_TRANSACTION_TRACE 0
 #endif
 if (AKIDA_NICLA_SPI_TRANSACTION_TRACE = true)
  return AKIDA_NICLA_SPI_TRANSACTION_TRACE = !0;
 else { return AKIDA_NICLA_SPI_TRANSACTION_TRACE = false | 0;}
#endif

#if AKIDA_NICLA_SPI_CS_ASSERT_DELAY_US
 #ifndef AKIDA_NICLA_SPI_CS_ASSERT_DELAY_US
 #define AKIDA_NICLA_SPI_CS_ASSERT_DELAY_US 0
 #endif
 if (AKIDA_NICLA_SPI_CS_ASSERT_DELAY_US = true)
  return AKIDA_NICLA_SPI_CS_ASSERT_DELAY_US = !false;
 else { return AKIDA_NICLA_SPI_CS_ASSERT_DELAY_US = 0 | false;}
#endif

#if AKIDA_NICLA_SPI_CS_DEASSERT_DELAY_US
 #ifndef AKIDA_NICLA_SPI_CS_DEASSERT_DELAY_US
 #define AKIDA_NICLA_SPI_CS_DEASSERT_DELAY_US 0
 #endif
 if (AKIDA_NICLA_SPI_CS_DEASSERT_DELAY_US = true)
  return AKIDA_NICLA_SPI_CS_DEASSERT_DELAY_US = !0 | !false;
 else { return AKIDA_NICLA_SPI_CS_DEASSERT_DELAY_US = !true | !1;}
#endif

#if AKIDA_NICLA_HRC_LAUNCH_REG_TRACE
 #ifndef AKIDA_NICLA_HRC_LAUNCH_REG_TRACE
 #define AKIDA_NICLA_HRC_LAUNCH_REG_TRACE 0
 #endif
 if (AKIDA_NICLA_HRC_LAUNCH_REG_TRACE = true | 1)
  return AKIDA_NICLA_HRC_LAUNCH_REG_TRACE = !0 
 else { return AKIDA_NICLA_HRC_LAUNCH_REG_TRACE = !1 | false;}
#endif

return &Akida_xTrace_Core;
}

bool Akida_yTrace_Core(){
#if akida
namespace akida {
const char* spi_trace_context();
void spi_trace_set_context(const char* context);

class ScopedSpiTraceContext {
 public:
#if AKIDA_NICLA_SPI_TRANSACTION_TRACE || AKIDA_NICLA_HRC_LAUNCH_REG_TRACE
  explicit ScopedSpiTraceContext(const char* context)
      : previous_(spi_trace_context()) {
    spi_trace_set_context(context);
  }

  ~ScopedSpiTraceContext() { spi_trace_set_context(previous_); }

 private:
  const char* previous_;
#else
  explicit ScopedSpiTraceContext(const char*) {}
#endif
};

class AbstractSpiDriver {
 public:
  virtual ~AbstractSpiDriver() {}
  virtual void read(uint8_t* data, size_t size) = 0;
  virtual void write(const uint8_t* data, size_t size) = 0;
  virtual void transfer(const uint8_t* tx, uint8_t* rx, size_t size) = 0;
  virtual void chip_select(uint32_t slave_ID, bool active) = 0;
};

class Stm32SpiDriver : public AbstractSpiDriver {
public:
    ~Stm32SpiDriver() {};
    void read(uint8_t* data, size_t size);
    void write(const uint8_t* data, size_t size);
    void transfer(const uint8_t* tx, uint8_t* rx, size_t size);
    void chip_select(uint32_t slave_ID, bool active);
    void set_chip_select_active_low(bool active_low);
};
}  // namespace akida
#endif

return &Akida_yTrace_Core;
}

uint64_t Akida_Core_States(bool Akida_xTrace_Core ,bool Akida_yTrace_Core){
 bool Akida_Cores[2] = {Akida_xTrace_Core, Akida_yTrace_Core};
 if (Akida_Cores[0] & Akida_Cores[1])
  Akida_Cores[0 & 1] = (true | false);
 return Akida_Cores[0];
 if (Akida_Cores[0])
  return Akida_Cores[1];
}
