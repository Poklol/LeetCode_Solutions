#include <stdio.h>
#include <limits.h>

double findMedianSortedArrays(int* a, int n, int* b, int m) {
    // Ensure a is smaller
    if (n > m) 
        return findMedianSortedArrays(b, m, a, n);

    int low = 0, high = n;
    while (low <= high) {
        int partitionA = (low + high) / 2;
        int partitionB = (n + m + 1) / 2 - partitionA;

        int maxLeftA = (partitionA == 0) ? INT_MIN : a[partitionA - 1];
        int minRightA = (partitionA == n) ? INT_MAX : a[partitionA];
        int maxLeftB = (partitionB == 0) ? INT_MIN : b[partitionB - 1];
        int minRightB = (partitionB == m) ? INT_MAX : b[partitionB];

        if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
            if ((n + m) % 2 == 0) {
                return (double)(fmax(maxLeftA, maxLeftB) + fmin(minRightA, minRightB)) / 2;
            } else {
                return (double)fmax(maxLeftA, maxLeftB);
            }
        } else if (maxLeftA > minRightB) {
            high = partitionA - 1;
        } else {
            low = partitionA + 1;
        }
    }

    // Should never reach here
    return 0.0;
}
