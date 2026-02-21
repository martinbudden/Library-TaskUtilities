#include <task_base.h>
#include <time_microseconds.h>

#include <array>
#include <unity.h>

void setUp()
{
}

void tearDown()
{
}

// NOLINTBEGIN(cppcoreguidelines-avoid-magic-numbers,cppcoreguidelines-pro-bounds-pointer-arithmetic,misc-const-correctness,readability-magic-numbers)
void test_task_base()
{
    enum { TASK_INTERVAL_MICROSECONDS = 5000 };
    const TaskBase task(TASK_INTERVAL_MICROSECONDS);

    TEST_ASSERT_EQUAL(TASK_INTERVAL_MICROSECONDS, task.get_task_interval_microseconds());
    TEST_ASSERT_EQUAL(0, task.get_tick_count_delta());
    TEST_ASSERT_EQUAL(0, task.get_time_microseconds_delta());

    TEST_ASSERT_EQUAL(0, time_ms());
    TEST_ASSERT_EQUAL(0, time_us());
    TEST_ASSERT_EQUAL(0, time_ms64());
    TEST_ASSERT_EQUAL(0, time_us64());
}

void test_time_microseconds()
{
    const time_ms32_t t_ms32a = 2;
    const time_ms32_t t_ms32b = 5;
    const time_ms_delta_t t_ms_delta32 = time_difference_ms(t_ms32a, t_ms32b);
    TEST_ASSERT_EQUAL(-3, t_ms_delta32);

    const time_ms64_t t_ms64a = 7;
    const time_ms64_t t_ms64b = 11;
    const time_ms_delta_t t_ms_delta64 = time_difference_ms(t_ms64a, t_ms64b);
    TEST_ASSERT_EQUAL(-4, t_ms_delta64);

    const time_us32_t t_us32a = 13;
    const time_us32_t t_us32b = 23;
    const time_us_delta_t t_us_delta32 = time_difference_us(t_us32a, t_us32b);
    TEST_ASSERT_EQUAL(-10, t_us_delta32);

    const time_us64_t t_us64a = 29;
    const time_us64_t t_us64b = 31;
    const time_us_delta_t t_us_delta64 = time_difference_us(t_us64a, t_us64b);
    TEST_ASSERT_EQUAL(-2, t_us_delta64);
}

// NOLINTEND(cppcoreguidelines-avoid-magic-numbers,cppcoreguidelines-pro-bounds-pointer-arithmetic,misc-const-correctness,readability-magic-numbers)

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
    UNITY_BEGIN();

    RUN_TEST(test_task_base);
    RUN_TEST(test_time_microseconds);

    UNITY_END();
}
