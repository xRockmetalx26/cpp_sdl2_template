//
// Created by xRockmetalx
//

#include <cstdio>
#include <LoopTimer.h>

std::unique_ptr<LoopTimer> LoopTimer::instance{};

LoopTimer::LoopTimer(const int fps)
    :  fps{fps}, delta_time{nanoseconds / fps} {
    std::puts("OK LoopTimer().");
}

void LoopTimer::update() {
    time_t time_new{Clock::now().time_since_epoch().count()};
    time_t time_frame{time_new - current_time};
    current_time = time_new;
    accumulator += time_frame;
}

void LoopTimer::reset() {
    accumulator -= delta_time;
    time += delta_time;
}

bool LoopTimer::is_ready() const { return accumulator >= delta_time; }

LoopTimer& LoopTimer::new_loop_timer(const int fps) {
    if(not instance)
        instance.reset(new LoopTimer{fps});

    if(not instance) {
        std::puts("ERROR LoopTimer().");
        exit(EXIT_FAILURE);
    }

    return *instance;
}

void LoopTimer::set_fps(const int fps) {
    this->fps = fps;
    delta_time = nanoseconds / fps;
}

LoopTimer& LoopTimer::get_instance() { return *instance; }
int LoopTimer::get_fps() const { return fps; }
time_t LoopTimer::get_delta_time() const { return delta_time; }

LoopTimer::~LoopTimer() { std::puts("OK ~LoopTimer()."); }
