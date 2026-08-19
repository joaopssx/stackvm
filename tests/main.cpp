#include <cstdio>

int main() {
    int failures = 0;

    if (failures > 0) {
        std::printf("%d test(s) failed\n", failures);
        return 1;
    }

    std::puts("ok");
    return 0;
}
