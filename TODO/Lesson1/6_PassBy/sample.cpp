/*

## Pass by reference
pi@raspberrypi:~/workspace/DataStructuresAndAlgorithms $ g++ -o ~/bin/main.o sample.cpp &&  ~/bin/main.o
9. duration=1830ms
8. duration=1867ms
7. duration=1855ms
6. duration=1828ms
5. duration=1952ms
4. duration=1932ms
3. duration=1829ms
2. duration=1931ms
1. duration=1829ms
0. duration=1827ms
-> average time = 1868ms

## Pass by value
pi@raspberrypi:~/workspace/DataStructuresAndAlgorithms $ g++ -o ~/bin/main.o sample.cpp &&  ~/bin/main.o
9. duration=16403ms
8. duration=16323ms
7. duration=16274ms
6. duration=16815ms
5. duration=17666ms
4. duration=16372ms
3. duration=16296ms
2. duration=16559ms
1. duration=16321ms
0. duration=16403ms
-> average time = 16543.2ms

## Pass by const reference
*/

#include <iostream>
#include <vector>
#include <chrono>

struct ABC {
    int a[100];
    int b[100];
};

// int stupidFunc(std::vector<ABC>& v) {    // Pass by reference
int stupidFunc(std::vector<ABC> v) {        // Pass by value
    int ans{0};
    for (int i = 0; i<v.size(); i++) {
        if (v[i].a[0] % 2 == 1) {
            ans++;
        }
    }
    return ans;
}

int main() {
    int abc{1};
    const int N{10000};
    int count{10};
    long long sum{0};

    while (count-- > 0) {
        std::vector<ABC> v{N};
        const auto start = std::chrono::high_resolution_clock::now();
        stupidFunc(v);

        const auto stop = std::chrono::high_resolution_clock::now();
        const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        std::cout << count << ". duration=" << duration.count() << "ms\n";
        sum += duration.count();
    }
    std::cout << "-> average time = " << (float)sum / 10 << "ms\n";

    return 0;
}