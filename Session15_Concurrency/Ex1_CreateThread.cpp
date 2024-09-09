#include <iostream>
#include <list>
#include <thread>
#include <chrono>
std::list<int> g_Data;
const int SIZE = 500000;

class CustomString {
public:
    CustomString() {
        std::cout << "CustomString()" << std::endl;
    }
    CustomString(const CustomString&) {
        std::cout << "CustomString(const String&)" << std::endl;
    }
    CustomString & operator=(const CustomString&) {
        std::cout << "operator=(const String&)" << std::endl;
        return *this;
    }
    ~CustomString() {
        std::cout << "~String()" << std::endl;
    }
};
void Download(std::string file) {
    std::cout << "[Downloader] Started download " << file << std::endl;
    for (int i=0; i < SIZE; ++i) {
        g_Data.push_back(i);
    }
    std::cout << "[Downloader] Finished download" << std::endl;
}

void sampleFunction(int numbera, float numberb) {
    std::cout << "numbera " << numbera << std::endl;
    std::cout << "numberb " << numberb << std::endl;
}
int main() {
    // There is no keywords argument like this
    // sampleFunction(numbera = 1, numberb = 2); 

    // Uncomment to check how many calls to constructor
    // CustomString fileName;

    std::string fileName{"Somefilename.xyz"};

    std::cout << "[main] Started an operation" << std::endl;
    std::thread thDownloader(Download, std::ref(fileName));
    thDownloader.detach();

    std::cout << "[main] User started another operation" << std::endl;
    if (thDownloader.joinable()) {
        std::cout << "[main] The thread is joinable" << std::endl;
        thDownloader.join();
    } else {
        std::cout << "[main] The thread is not joinable" << std::endl;
    }
    // Will encounter std::system_error if join a not joinable thread
    // thDownloader.join();

    // Without this sleep, the main thread will terminate before child thread complete -> it cannot be completed
    // std::this_thread::sleep_for(std::chrono::milliseconds(5000));

    // Will encounter std::system_error if join a not joinable thread
    // thDownloader.join();

    /*
    */
    std::thread thDownloadertestDetach(Download, "Test detach file");
    thDownloadertestDetach.detach();

    return 0;
}