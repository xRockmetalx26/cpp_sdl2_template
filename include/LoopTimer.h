//
// Created by xRockmetalx
//

#ifndef LOOP_TIMER_H
#define LOOP_TIMER_H

#include <memory>
#include <chrono>
#include <cstdint>

class LoopTimer {
public:

    using Clock = std::chrono::high_resolution_clock;

    LoopTimer(const LoopTimer &other) = delete;
    LoopTimer(const LoopTimer &&other) = delete;
    LoopTimer& operator = (const LoopTimer &other) = delete;
    LoopTimer& operator = (const LoopTimer &&other) = delete;
    virtual ~LoopTimer();

    void update();
    void reset();
    bool is_ready() const;

    static LoopTimer& new_loop_timer(int fps = 60);
    void set_fps(int fps);

    static LoopTimer& get_instance();
    int get_fps() const;
    time_t get_delta_time() const;

private:

    explicit LoopTimer(int fps = 60);

    static std::unique_ptr<LoopTimer> instance;

    static const time_t nanoseconds = 1000000000;
    int fps;
    time_t delta_time;
    time_t time{};
    time_t current_time{Clock::now().time_since_epoch().count()};
    time_t accumulator{};
};

#endif // LOOP_TIMER_H
