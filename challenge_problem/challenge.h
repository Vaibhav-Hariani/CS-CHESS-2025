// 3 pegs, N disks of increasing diameter. Need to move all disks from first peg
// To third peg, without stacking a larger disk on a smaller disk. 

//smallest disk is one at the top, largest is one at the bottom
#include <stdio.h>


struct peg {
    int disks[100]; 
    int number_of_disks;
} typedef peg;

//most from p1 to p2
int move_smallest_disk(peg *p1, peg *p2) {
    if (p1->number_of_disks == 0) return -1;
    int disk = p1->disks[p1->number_of_disks - 1];
    if (p2->number_of_disks > 0 && p2->disks[p2->number_of_disks - 1] < disk) {
        printf("invalid move! \n");
        return -1;
    }
    p2->disks[p2->number_of_disks] = disk;
    p2->number_of_disks++;
    p1->number_of_disks--;
    return 1;
}

void print_pegs(peg peg1, peg peg2, peg peg3, int num_disks) {
    peg pegs[3] = {peg1, peg2, peg3};
    printf("\n");
    // Print each row from top (smallest disk) to bottom (largest disk)
    for (int row = num_disks - 1; row >= 0; row--) {
        for (int p = 0; p < 3; p++) {
            int disk_index = row;
            if (disk_index < pegs[p].number_of_disks) {
                int size = pegs[p].disks[disk_index];
                for (int k = 0; k < size; k++) {
                    printf("*");
                }
            } else {
                printf("|");
            }
            printf("\t");
        }
        printf("\n");
    }
    printf("Peg 1\tPeg 2\tPeg 3\n\n");
}

