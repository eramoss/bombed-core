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

void test_non_blocking_execute_callback(){
    int shared_variable;
    Timer::async_time_out([&shared_variable]() {
        shared_variable = 1;
    }, 200);

    shared_variable = 0;
    std::this_thread::sleep_for(std::chrono::milliseconds(210)); // the timer need some time to execute fn

    assert(shared_variable == 1);
    std::cout << "Non blocking callback execution test passed." << std::endl;
}


void test_mtx_on_async_time_out(){
    int shared_var = 0;
    Timer::async_time_out([&shared_var](){
        shared_var++;
        }, 20);
    Timer::async_time_out([&shared_var](){
        shared_var++;
    }, 20);
    std::this_thread::sleep_for(std::chrono::milliseconds(21)); // first async fn terminate
    assert(shared_var == 1);
    std::this_thread::sleep_for(std::chrono::milliseconds(21)); // second async fn terminate
    assert(shared_var == 2);
    std::cout << "Mutex callback execution test passed." << std::endl;
}

int main() {
    test_elapsed_time();
    test_reset();
    test_callback_execution();
    test_non_blocking_execute_callback();
    test_mtx_on_async_time_out();
    return 0;
}
