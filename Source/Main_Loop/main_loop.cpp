#include <iostream>
#include <thread>

// using namespace std::chrono_literals;

void using_sleep_for() {
    std::cout << "Using chrono and sleep_for()" << std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    std::chrono::seconds sec(1);
    while(1) {
        std::this_thread::sleep_for(sec);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> elapsed = end-start;
        std::cout << elapsed.count() << std::endl;
    }
}

void using_sleep_until() {
    std::cout << "Using chrono and sleep_until()" << std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    std::chrono::seconds sec(1);
    std::cout << "Sec " << sec.count();
    while(1) {
        std::this_thread::sleep_until(start + sec);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> elapsed = end-start;
        std::cout << elapsed.count() << std::endl;
    }
}

int main() {
    std::cout << "Loop test" << std::endl;
    using_sleep_for();
    // using_sleep_until();

    // auto start = std::chrono::high_resolution_clock::now();
    // auto end = std::chrono::high_resolution_clock::now();
    // std::chrono::duration<double> diff = end-start; 
    // std::cout << diff.count();
    return 0;
}