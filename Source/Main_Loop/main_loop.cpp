#include <iostream>
#include <thread>
#include "./cppTimer/CppTimerCallback.h"
#include <iomanip>

// using namespace std::chrono_literals;

uint32_t run_time = 1800;         // Test run time in seconds
uint32_t loop_time = 1;         // Loop time in seconds
float average_time = 0;         // Average delay

std::chrono::system_clock::time_point then = std::chrono::high_resolution_clock::now();

int seconds(int secs) {
    return secs * 1000000000;
}

void print_time() {
    // std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    // std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
    // std::chrono::milliseconds now2 = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch());
    // struct tm currentLocalTime;
    // localtime_r(&currentTime, &currentLocalTime);
    // char timeBuffer[80];
    // std::size_t charCount { std::strftime( timeBuffer, 80,
    //                                         "%D %T",
    //                                         &currentLocalTime)
    //                         };

    // if (charCount == 0) 
    //     return;

    // std::cout << timeBuffer << "." << std::setfill('0') << std::setw(3) << now2.count() % 1000 << std::endl;

    auto now = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = now-then;
    then = now;
    average_time += elapsed.count();
    std::cout << elapsed.count() << std::endl;
}

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

class Callback1 : public CppTimerCallback::Runnable {
	void run() {
        print_time();
		// fprintf(stdout,"\tBah! \n");
		// fflush(stdout);
	}
};

int main() {
    std::cout << "Loop test" << std::endl;
    // using_sleep_for();
    // using_sleep_until();

    // auto start = std::chrono::high_resolution_clock::now();
    // auto end = std::chrono::high_resolution_clock::now();
    // std::chrono::duration<double> diff = end-start; 
    // std::cout << diff.count();

    CppTimerCallback demoTimer1;
	Callback1 callback1;
	demoTimer1.registerEventRunnable(callback1);
	demoTimer1.start(seconds(loop_time));

    std::this_thread::sleep_for(std::chrono::seconds(run_time));
                                                                                                                                                                                                                                                                                                                             
	demoTimer1.unregisterEventRunnable();                                                                                               
        demoTimer1.stop();

    std::cout << "Average delay(ms): " << average_time * loop_time / run_time << std::endl;
    return 0;
}