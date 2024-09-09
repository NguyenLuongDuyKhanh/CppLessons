#include <iostream>
#include <list>
#include <thread>
#include <chrono>
#include <mutex>

std::list<int> g_Data;
std::mutex g_Mutex;

const int SIZE = 10000;

void Download1() {
    for (int i=0; i < SIZE; ++i) {
        g_Mutex.lock();
        g_Data.push_back(i);
        g_Mutex.unlock();
    }
}

void Download2() {
    for (int i=0; i < SIZE; ++i) {
        std::lock_guard<std::mutex> mtx(g_Mutex);
        g_Data.push_back(i);
    }
}

int main() {
    std::thread thDownloader1(Download1);
    std::thread thDownloader2(Download2);
    thDownloader1.join();
    thDownloader2.join();

    std::cout << g_Data.size() << std::endl;
    return 0;
}