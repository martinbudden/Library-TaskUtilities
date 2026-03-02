#pragma once

#include <array>
#include <cstddef>
#include <cstdint>

/*!
Debug modes match Betaflight debug modes, so they can be displayed in Betaflight Blackbox Explorer.
*/

static constexpr uint16_t DEBUG_NONE = 0;
static constexpr uint16_t DEBUG_CYCLE_TIME = 1;
static constexpr uint16_t DEBUG_BATTERY = 2;
static constexpr uint16_t DEBUG_GYRO_FILTERED = 3;
static constexpr uint16_t DEBUG_ACCELEROMETER = 4;
static constexpr uint16_t DEBUG_PIDLOOP = 5;
static constexpr uint16_t DEBUG_RC_INTERPOLATION = 6;
static constexpr uint16_t DEBUG_ANGLE_RATE = 7;
static constexpr uint16_t DEBUG_ESC_SENSOR = 8;
static constexpr uint16_t DEBUG_SCHEDULER = 9;
static constexpr uint16_t DEBUG_STACK = 10;
static constexpr uint16_t DEBUG_ESC_SENSOR_RPM = 11;
static constexpr uint16_t DEBUG_ESC_SENSOR_TEMPERATURE = 12;
static constexpr uint16_t DEBUG_ALTITUDE = 13;
static constexpr uint16_t DEBUG_FFT = 14;
static constexpr uint16_t DEBUG_FFT_TIME = 15;
static constexpr uint16_t DEBUG_FFT_FREQUENCY = 16;
static constexpr uint16_t DEBUG_RX_FRSKY_SPI = 17;
static constexpr uint16_t DEBUG_RX_SFHSS_SPI = 18;
static constexpr uint16_t DEBUG_GYRO_RAW = 19;
static constexpr uint16_t DEBUG_MULTI_GYRO_RAW = 20;
static constexpr uint16_t DEBUG_MULTI_GYRO_DIFF = 21;
static constexpr uint16_t DEBUG_MAX7456_SIGNAL = 22;
static constexpr uint16_t DEBUG_MAX7456_SPI_CLOCK = 23;
static constexpr uint16_t DEBUG_SBUS = 24;
static constexpr uint16_t DEBUG_FPORT = 25;
static constexpr uint16_t DEBUG_RANGEFINDER = 26;
static constexpr uint16_t DEBUG_RANGEFINDER_QUALITY = 27;
static constexpr uint16_t DEBUG_OPTICAL_FLOW = 28;
static constexpr uint16_t DEBUG_LIDAR_TF = 29;
static constexpr uint16_t DEBUG_ADC_INTERNAL = 30;
static constexpr uint16_t DEBUG_RUNAWAY_TAKEOFF = 31;
static constexpr uint16_t DEBUG_SDIO = 32;
static constexpr uint16_t DEBUG_CURRENT_SENSOR = 33;
static constexpr uint16_t DEBUG_USB = 34;
static constexpr uint16_t DEBUG_SMART_AUDIO = 35;
static constexpr uint16_t DEBUG_RTH = 36;
static constexpr uint16_t DEBUG_ITERM_RELAX = 37;
static constexpr uint16_t DEBUG_ACRO_TRAINER = 38;
static constexpr uint16_t DEBUG_RC_SMOOTHING = 39;
static constexpr uint16_t DEBUG_RX_SIGNAL_LOSS = 40;
static constexpr uint16_t DEBUG_RC_SMOOTHING_RATE = 41;
static constexpr uint16_t DEBUG_ANTI_GRAVITY = 42;
static constexpr uint16_t DEBUG_DYN_LPF = 43;
static constexpr uint16_t DEBUG_RX_SPEKTRUM_SPI = 44;
static constexpr uint16_t DEBUG_DSHOT_RPM_TELEMETRY = 45;
static constexpr uint16_t DEBUG_RPM_FILTER = 46;
static constexpr uint16_t DEBUG_D_MAX = 47;
static constexpr uint16_t DEBUG_AC_CORRECTION = 48;
static constexpr uint16_t DEBUG_AC_ERROR = 49;
static constexpr uint16_t DEBUG_MULTI_GYRO_SCALED = 50;
static constexpr uint16_t DEBUG_DSHOT_RPM_ERRORS = 51;
static constexpr uint16_t DEBUG_CRSF_LINK_STATISTICS_UPLINK = 52;
static constexpr uint16_t DEBUG_CRSF_LINK_STATISTICS_PWR = 53;
static constexpr uint16_t DEBUG_CRSF_LINK_STATISTICS_DOWN = 54;
static constexpr uint16_t DEBUG_BAROMETER = 55;
static constexpr uint16_t DEBUG_AUTOPILOT_ALTITUDE = 56;
static constexpr uint16_t DEBUG_DYN_IDLE = 57;
static constexpr uint16_t DEBUG_FEEDFORWARD_LIMIT = 58
static constexpr uint16_t DEBUG_FEEDFORWARD = 59;
static constexpr uint16_t DEBUG_BLACKBOX_OUTPUT = 60;
static constexpr uint16_t DEBUG_GYRO_SAMPLE = 61;
static constexpr uint16_t DEBUG_RX_TIMING = 62;
static constexpr uint16_t DEBUG_D_LPF = 63;
static constexpr uint16_t DEBUG_VTX_TRAMP = 64;
static constexpr uint16_t DEBUG_GHST = 65;
static constexpr uint16_t DEBUG_GHST_MSP = 66;
static constexpr uint16_t DEBUG_SCHEDULER_DETERMINISM = 67;
static constexpr uint16_t DEBUG_TIMING_ACCURACY = 68;
static constexpr uint16_t DEBUG_RX_EXPRESSLRS_SPI = 69;
static constexpr uint16_t DEBUG_RX_EXPRESSLRS_PHASELOCK = 70;
static constexpr uint16_t DEBUG_RX_STATE_TIME = 71;
static constexpr uint16_t DEBUG_GPS_RESCUE_VELOCITY = 72;
static constexpr uint16_t DEBUG_GPS_RESCUE_HEADING = 73;
static constexpr uint16_t DEBUG_GPS_RESCUE_TRACKING = 74;
static constexpr uint16_t DEBUG_GPS_CONNECTION = 75;
static constexpr uint16_t DEBUG_ATTITUDE = 76;
static constexpr uint16_t DEBUG_VTX_MSP = 77;
static constexpr uint16_t DEBUG_GPS_DOP = 78;
static constexpr uint16_t DEBUG_FAILSAFE = 79;
static constexpr uint16_t DEBUG_GYRO_CALIBRATION = 80;
static constexpr uint16_t DEBUG_ANGLE_MODE = 81;
static constexpr uint16_t DEBUG_ANGLE_TARGET = 82;
static constexpr uint16_t DEBUG_CURRENT_ANGLE = 83;
static constexpr uint16_t DEBUG_DSHOT_TELEMETRY_COUNTS = 84;
static constexpr uint16_t DEBUG_RPM_LIMIT = 85;
static constexpr uint16_t DEBUG_RC_STATS = 86;
static constexpr uint16_t DEBUG_MAGNETOMETER_CALIBRATION = 87;
static constexpr uint16_t DEBUG_MAG_TASK_RATE = 88;
static constexpr uint16_t DEBUG_EZLANDING = 89;
static constexpr uint16_t DEBUG_TPA = 90;
static constexpr uint16_t DEBUG_S_TERM = 91;
static constexpr uint16_t DEBUG_SPA = 92;
static constexpr uint16_t DEBUG_TASK = 93;
static constexpr uint16_t DEBUG_GIMBAL = 94;
static constexpr uint16_t DEBUG_WING_SETPOINT = 95;
static constexpr uint16_t DEBUG_AUTOPILOT_POSITION = 96;
static constexpr uint16_t DEBUG_CHIRP = 97;
static constexpr uint16_t DEBUG_COUNT = 98;


class Debug {
public:
    static constexpr size_t VALUE_COUNT = 8;
public:
    Debug() = default;

    void set_mode(uint16_t mode) { _mode = mode; }
    inline uint16_t get_mode() const { return _mode; }

    inline void set(size_t index, int16_t value) { _values[index] = value; }
    inline void set(size_t index, int8_t value) { _values[index] = static_cast<int16_t>(value); }
    inline void set(size_t index, uint8_t value) { _values[index] = static_cast<int16_t>(value); }
    inline void set(size_t index, uint16_t value) { _values[index] = static_cast<int16_t>(value); }
    inline void set(size_t index, int32_t value) { _values[index] = static_cast<int16_t>(value); }
    inline void set(size_t index, uint32_t value) { _values[index] = static_cast<int16_t>(value); }
#if defined(FRAMEWORK_TEST)
    inline void set(size_t index, long value) { _values[index] = static_cast<int16_t>(value); }
#endif

    inline void set(uint16_t mode, size_t index, int16_t value) {
        if (_mode == mode && index < VALUE_COUNT) {
            _values[index] = value;
        }
    }
    inline void set(uint16_t mode, size_t index, int8_t value) { set(mode, index, static_cast<int16_t>(value)); }
    inline void set(uint16_t mode, size_t index, uint8_t value) { set(mode, index, static_cast<int16_t>(value)); }
    inline void set(uint16_t mode, size_t index, uint16_t value) { set(mode, index, static_cast<int16_t>(value)); }
    inline void set(uint16_t mode, size_t index, int32_t value) { set(mode, index, static_cast<int16_t>(value)); }
    inline void set(uint16_t mode, size_t index, uint32_t value) { set(mode, index, static_cast<int16_t>(value)); }
#if defined(FRAMEWORK_TEST)
    inline void set(uint16_t mode, size_t index, long value) { set(mode, index, static_cast<int16_t>(value)); }
#endif

    inline int16_t get(size_t index) const { return _values[index]; }
    const std::array<int16_t, VALUE_COUNT>& getValues() const { return _values; }
private:
    std::array<int16_t, VALUE_COUNT> _values{};
    uint16_t _mode {DEBUG_NONE};
};
