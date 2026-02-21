#pragma once

#include <cstdint>

class TaskBase {
public:
    struct parameters_t {
        TaskBase* task;
    };
    struct task_info_t {
        void* task_handle;
        const char* name;
        uint32_t stack_depth_bytes;
        uint8_t* stack_buffer;
        uint32_t priority;
        uint32_t core;
        uint32_t task_interval_microseconds;
    };
public:
    explicit TaskBase(uint32_t task_interval_microseconds) : _task_interval_microseconds(task_interval_microseconds) {}
    TaskBase() : TaskBase(0) {}
public:
    inline void set_task_interval_microseconds(uint32_t task_interval_microseconds) { _task_interval_microseconds = task_interval_microseconds; }
    inline uint32_t get_task_interval_microseconds() const { return _task_interval_microseconds; }
    inline uint32_t get_tick_count_delta() const { return _tick_count_delta; }
    inline uint32_t get_time_microseconds_delta() const { return _time_microseconds_delta; }
    inline bool get_was_delayed() const { return _was_delayed; }
    void set_was_delayed(bool was_delayed) { _was_delayed = was_delayed; }
protected:
    uint32_t _task_interval_microseconds {0};
    uint32_t _previous_wake_time_ticks {0};
    uint32_t _tick_count_delta {0};
    uint32_t _tick_count_previous {0};
    uint32_t _time_microseconds_delta {0};
    uint32_t _time_microseconds_previous {0};
    uint32_t _was_delayed {0};
};
