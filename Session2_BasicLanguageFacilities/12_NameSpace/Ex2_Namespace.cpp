#include <iostream>
namespace Avg {
    float Calculate(float x, float y) {
        return (x+y)/2;
    }
}

namespace Basic {
    float Calculate(float x, float y) {
        return x+y;
    }
}

namespace {
    void AFunction() {
        std::cout << "this function is in this scope only, cannot be imported by other files" << std::endl;
    }
}
int main() {
    using Avg::Calculate;
    std::cout << Calculate(3.9f, 8.2f) << std::endl;

    Basic::Calculate(8.1f, 9.2f);
    AFunction();

    return 0;
}