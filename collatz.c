#include <stdio.h>
#include <inttypes.h>

uint64_t num_iters(uint64_t x) {
    uint64_t iters = 0;

    do {
        if (x % 2) {
            // odd
            x = x * 3 + 1;
        } else {
            // even
            x /= 2;
        }

        iters++;
    } while (x != 1);

    return iters;
}

int main(void) {
    printf("Let's gooooo\n");

    uint64_t max_iters = 0;

    for (uint64_t i = 1; i < 1000000; i++) {
        uint64_t iters = num_iters(i);
        if (iters > max_iters) {
            printf("%" PRIu64 ":%" PRIu64 "\n", i, iters);
            max_iters = iters;
        }
    }

    return 0;
}
