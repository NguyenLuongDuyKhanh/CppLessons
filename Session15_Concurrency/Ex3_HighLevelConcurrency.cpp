#include <iostream>
#include <thread>
#include <future>

using namespace std;

void Downloader() {
    for (int i = 0; i<10; ++i) {
        cout << ".";
        this_thread::sleep_for(300ms);
    }
}
int main() {
    cout << __cplusplus << endl; // 201703 -> C++ 17
    std::future<void> result = std::async(Downloader);
    cout << "main() threading continues execution ...";
    result.get();

    return 0;
}