#include <iostream>
#include <utility>
#include <thread>
#include <chrono>
#include <functional>
#include <atomic>
#include <mutex>
 
std::mutex mtx;
void f1(int n)
{
    for (int i = 0; i < 5; ++i) {
        if (mtx.try_lock()) {
            std::cout << "Thread " << n << " executing\n";
            mtx.unlock();
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}
 
void f2(int& n)
{
    for (int i = 0; i < 5; ++i) {
        if (mtx.try_lock()) {
            std::cout << "Thread 2 executing\n";
            mtx.unlock();
        }
        ++n;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

void print_block (int n, char c) {
    // critical section (exclusive access to std::cout signaled by lifetime of lck):
    // std::unique_lock is the same
    std::lock_guard<std::mutex> lck (mtx);
    for (int i=0; i<n; ++i) { std::cout << c; }
        std::cout << '\n';
}
 
int main()
{
    /*int n = 0;
    std::thread t1; // t1 is not a thread
    std::thread t2(f1, n + 1); // pass by value
    std::thread t3(f2, std::ref(n)); // pass by reference
    std::thread t4(std::move(t3)); // t4 is now running f2(). t3 is no longer a thread
    std::cout << "create complete\n";
    t2.join();
    t4.join();
    std::cout << "Final value of n is " << n << '\n';*/
    std::thread th1 (print_block,50,'*');
    std::thread th2 (print_block,50,'$');

    th1.join();
    th2.join();
    return 0;
}