//
// Created by eramoss on 09/10/23.
//

#ifndef BOMBEDCORE_TIMER_H
#define BOMBEDCORE_TIMER_H
#define loop while(true)

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

    /*
     *
     * This function do not mutex variables that be passed inside block
     * Make sure in use to not commit race condition
     *
     * # Example
     *
     *   timer;
     *   std::mutex mtx;
     *
     *   timer.on_timer_reaches(20, [&mtx, &timer]() {
     *      std::lock_guard<std::mutex> lock(mtx);
     *      Timer::sleep(100);
     *   });
     * */
    void on_timer_reaches(double milliseconds, std::function<void ()> callback) {
        std::thread([this,milliseconds, callback]() {
            loop {
               if (this->elapsed() >= milliseconds) {
                   callback();
                   break;
               }
            }
        }).detach();
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

    static bool sleep(double milliseconds){
        std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<long  long >(milliseconds)));
        return true;
    }


private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start_timepoint;
};



#endif //BOMBEDCORE_TIMER_H
