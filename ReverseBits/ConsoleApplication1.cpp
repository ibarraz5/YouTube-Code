

#include <stdio.h>


int partialReverse(int num, int i1, int i2) {
    // Ensure i1 is less than or equal to i2
    if (i1 > i2) {
        int temp = i1;
        i1 = i2;
        i2 = temp;
    }


    // Reverse bits from index i1 to i2
    for (int i = i1; i <= (i1 + i2) / 2; i++) {
        // designed to calculate the index of the bit at 
        // the opposite end of the range relative to i
        int j = i2 - (i - i1);


        // Check if the bits at position i and j are different
        if (((num >> i) & 1) != ((num >> j) & 1)) {
            // Toggle the bits at positions i and j
            num ^= (1 << i) | (1 << j);
        }
    }
    return num;
}


// Function to print the binary representation for demonstration purposes
void printBinary(int num) {
    for (int i = 4; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}


int main() {
    int num = 20;
    int i1 = 0, i2 = 2;

    printf("Original: ");
    printf("%d, binary: ", num);
    printBinary(num);


    int reversed = partialReverse(num, i1, i2);


    printf("\nReversed: ");
    printf("%d, binary: ", reversed);
    printBinary(reversed);


    return 0;
}
