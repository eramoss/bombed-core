//
// Created by eramoss on 09/10/23.
//

#ifndef BOMBEDCORE_TIMER_H
#define BOMBEDCORE_TIMER_H

#include "functional"
#include "thread"
#include "mutex"
#include "iostream"
#include "chrono"

class Timer {
public:
    Timer() : start_timepoint(std::chrono::high_resolution_clock::now()) {}
    ~Timer() = default;

    void reset() {
        start_timepoint = std::chrono::high_resolution_clock::now();
    }

    double elapsed() const {
        auto end_timepoint = std::chrono::high_resolution_clock::now();
        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(start_timepoint).time_since_epoch().count();
        auto end = std::chrono::time_point_cast<std::chrono::microseconds>(end_timepoint).time_since_epoch().count();

        return static_cast<double>(end - start) * 0.001; // Convert to milliseconds
    }

    static void on_time_out(std::function<void()> callback, double milliseconds) {
        std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<long long>(milliseconds)));
        callback();
    }

    static void async_time_out(std::function<void()> callback, double milliseconds) {
        static std::mutex mtx;
        std::thread([callback, milliseconds]() {
            std::unique_lock<std::mutex> lock(mtx);

            std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<long long>(milliseconds)));
            callback();
        }).detach();
    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start_timepoint;
};



#endif //BOMBEDCORE_TIMER_H
