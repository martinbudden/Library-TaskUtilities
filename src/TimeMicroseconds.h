#pragma once

#include <cstdint>


// time in milliseconds
typedef uint32_t time_ms32_t;
typedef uint64_t time_ms64_t;
typedef int32_t time_ms_delta_t; // 32 bits is always sufficient for time _delta
inline time_ms_delta_t time_difference_ms(time_ms32_t a, time_ms32_t b) { return static_cast<time_ms_delta_t>(static_cast<int32_t>(a) - static_cast<int32_t>(b)); }
inline time_ms_delta_t time_difference_ms(time_ms64_t a, time_ms64_t b) { return static_cast<time_ms_delta_t>(static_cast<int64_t>(a) - static_cast<int64_t>(b)); }

// time in microseconds
typedef uint32_t time_us32_t;
typedef uint64_t time_us64_t;
typedef int32_t time_us_delta_t; // 32 bits is always sufficient for time _delta
inline time_us_delta_t time_difference_us(time_us32_t a, time_us32_t b) { return static_cast<time_us_delta_t>(static_cast<int32_t>(a) - static_cast<int32_t>(b)); }
inline time_us_delta_t time_difference_us(time_us64_t a, time_us64_t b) { return static_cast<time_us_delta_t>(static_cast<int64_t>(a) - static_cast<int64_t>(b)); }


#if defined(FRAMEWORK_RPI_PICO)

#include <pico/time.h>
inline time_us32_t time_us() { return time_us_32(); }
inline time_us64_t time_us64() { return time_us_64(); }

inline time_ms32_t time_ms() { return static_cast<time_ms32_t>(time_us_64() / 1000); }
inline time_ms64_t time_ms64() { return time_us_64() / 1000; }

#elif defined(FRAMEWORK_ESPIDF)

#include <esp_timer.h>
inline time_us32_t time_us() { return static_cast<time_us32_t>(esp_timer_get_time()); }
inline time_us64_t time_us64() { return esp_timer_get_time(); }

inline time_us32_t time_ms() { return static_cast<time_us32_t>(esp_timer_get_time() / 1000); }
inline time_us64_t time_ms64() { return esp_timer_get_time() / 1000; }

#elif defined(FRAMEWORK_STM32_CUBE)

#if defined(FRAMEWORK_STM32_CUBE_F1)
#include <stm32f1xx_hal.h>
#elif defined(FRAMEWORK_STM32_CUBE_F3)
#include <stm32f3xx_hal.h>
#elif defined(FRAMEWORK_STM32_CUBE_F4)
#include <stm32f4xx_hal.h>
#elif defined(FRAMEWORK_STM32_CUBE_F7)
#include <stm32f7xx_hal.h>
#endif

inline time_us32_t time_us() { enum {msToUs = 1000}; return static_cast<time_us32_t>(HAL_GetTick()*msToUs); }
inline time_us64_t time_us64() { enum {msToUs = 1000}; return static_cast<time_us64_t>(HAL_GetTick()*msToUs); }

inline time_ms32_t time_ms() { return static_cast<time_us32_t>(HAL_GetTick()); }
inline time_ms64_t time_ms64() { return static_cast<time_us64_t>(HAL_GetTick()); }

#elif defined(FRAMEWORK_TEST)

inline time_us32_t time_us() { return 0; }
inline time_us64_t time_us64() { return 0; }

inline time_ms32_t time_ms() { return 0; }
inline time_ms64_t time_ms64() { return 0; }

#else // defaults to FRAMEWORK_ARDUINO

#if defined(FRAMEWORK_ARDUINO_ESP32)
#include <esp_timer.h>
inline time_us32_t time_us() { return static_cast<time_us32_t>(esp_timer_get_time()); }
inline time_us64_t time_us64() { return esp_timer_get_time(); }

inline time_us32_t time_ms() { return static_cast<time_us32_t>(esp_timer_get_time() / 1000); }
inline time_us64_t time_ms64() { return esp_timer_get_time() / 1000; }
#else
#include <Arduino.h>
inline time_us32_t time_us() { return micros(); } // overflows after approximately 70 minutes.
inline time_ms32_t time_ms() { return millis(); } // overflows after approximately 50 days.
#endif

#endif // FRAMEWORK
