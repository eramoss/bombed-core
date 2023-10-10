//
// Created by eramoss on 09/10/23.
//
#include "../src/services/Timer.h"
#include <iostream>
#include <cassert>

void test_elapsed_time() {
    Timer timer;
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    double elapsed = timer.elapsed();
    assert(elapsed >= 10 && elapsed < 11);
    std::cout << "Elapsed time test passed." << std::endl;
}

void test_reset() {
    Timer timer;
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    timer.reset();
    double elapsed = timer.elapsed();
    assert(elapsed < 1);
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
    }, 20);

    shared_variable = 0;
    std::this_thread::sleep_for(std::chrono::milliseconds(21)); // the timer need some time to execute fn

    assert(shared_variable == 1);
    std::cout << "Non blocking callback execution test passed." << std::endl;
}


void test_mtx_on_async_time_out(){
    int shared_var ;
    std::mutex mtx;
    Timer timer;

    Timer::async_time_out([&shared_var, &timer, &mtx](){
        std::unique_lock<std::mutex> lock(mtx);
        shared_var = 0;
        std::cout << "First block executed in: " << timer.elapsed() << " ms. ";
    }, 20);
    Timer::async_time_out([&shared_var, &timer, &mtx](){
        std::unique_lock<std::mutex> lock(mtx);
        shared_var = 1;
        std::cout << "Second block executed in: " << timer.elapsed() << " ms. ";
    }, 20);


    Timer::sleep(21);
    assert(shared_var == 1);
    std::cout << "Mutex callback execution test passed." << std::endl;
}

void test_sleep_timer(){
    Timer timer; // init a timer
    Timer::sleep(20);
    double elapsed = timer.elapsed();
    assert(elapsed >= 20 && elapsed < 21);
    std::cout << "Sleep test passed in: " << elapsed << " ms." << std::endl;
}

void test_on_timer_reaches() {
    int control_var = 0;
    Timer timer;
    timer.on_timer_reaches(20,[&timer, &control_var](){
        double elapsed = timer.elapsed();
        control_var = 1;
        std::cout << "On timer reaches was executed in : " << elapsed << " ms on timer." << std::endl;
    });
    Timer::sleep(5); // The timer is not reached yet
    assert(control_var == 0);
    Timer::sleep(15); // The timer already reaches 20 ms
    assert(control_var == 1);

    std::cout << "On timer reaches test passed." << std::endl;
}


void test_mtx_on_timer_reaches() {
    double time_to_execute_first_block = 0;
    double time_to_execute_second_block = 0;
    Timer timer;
    std::mutex mtx;

    timer.on_timer_reaches(19, [&mtx, &timer, &time_to_execute_first_block]() {
        std::lock_guard<std::mutex> lock(mtx);
        Timer::sleep(100);
        time_to_execute_first_block = timer.elapsed();
    });

    // This second block is blocked by mutex, and it runs after the other unlock it
    timer.on_timer_reaches(20, [&mtx, &timer, &time_to_execute_second_block]() {
        std::lock_guard<std::mutex> lock(mtx);
        Timer::sleep(100);
        time_to_execute_second_block = timer.elapsed();
    });

    Timer::sleep(220); // timer reached to both blocks
    std::cout << "first: " << time_to_execute_first_block << "  second: " << time_to_execute_second_block << "\t";
    assert(time_to_execute_first_block < time_to_execute_second_block - 100);

    std::cout << "On timer reaches used with mutex test passed." << std::endl;
}


int main() {
    test_elapsed_time();
    test_reset();
    test_callback_execution();
    test_non_blocking_execute_callback();
    test_mtx_on_async_time_out();
    test_sleep_timer();
    test_on_timer_reaches();
    test_mtx_on_timer_reaches();
    return 0;
}
