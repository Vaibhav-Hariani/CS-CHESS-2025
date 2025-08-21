#include "challenge.h"

int main() {
    peg peg1 = {0};
    peg peg2 = {0};
    peg peg3 = {0};
    int N = 7;
    peg1.number_of_disks = N;
    for (int i = N; i > 0; i--) {
        peg1.disks[N - i] = i;
    }
    print_pegs(peg1, peg2, peg3, N);

    int total_moves = (1 << N) - 1;
    int src = 1, dest = 3, aux = 2;
    if (N % 2 == 0) {
        int temp = dest;
        dest = aux;
        aux = temp;
    }
    for (int move = 1; move <= total_moves; move++) {
        if (move % 3 == 1) {
            move_smallest_disk(&peg1, &peg3);
        } else if (move % 3 == 2) {
            move_smallest_disk(&peg1, &peg2);
        } else {
            move_smallest_disk(&peg2, &peg3);
        }
        print_pegs(peg1, peg2, peg3, N);
    }
}
