//
// Created by eramoss on 09/10/23.
//
#include "../src/services/Timer.h"
#include <iostream>
#include <cassert>

void test_elapsed_time() {
    Timer timer;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    double elapsed = timer.elapsed();
    assert(elapsed >= 100 && elapsed < 110);
    std::cout << "Elapsed time test passed." << std::endl;
}

void test_reset() {
    Timer timer;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    timer.reset();
    double elapsed = timer.elapsed();
    assert(elapsed < 10);
    std::cout << "Reset test passed." << std::endl;
}

void test_callback_execution() {
    bool callbackExecuted = false;
    double callbackDelay = 50.0;

    Timer::on_time_out([&callbackExecuted]() {
        callbackExecuted = true;
    }, callbackDelay);

    std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<long long>(callbackDelay + 10)));

    assert(callbackExecuted);
    std::cout << "Callback execution test passed." << std::endl;
}

int main() {
    test_elapsed_time();
    test_reset();
    test_callback_execution();

    return 0;
}
