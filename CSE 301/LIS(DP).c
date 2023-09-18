
#include <stdio.h>
#include <stdlib.h>


int binarySearch(int arr[], int low, int high, int key) {
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}


int lis(int arr[], int n) {
    if (n == 0) return 0;

    int tail[n];
    int len = 1; // Length of LIS initialized with 1

    tail[0] = arr[0]; // Initialize the tail with the first element

    for (int i = 1; i < n; i++) {
        // If arr[i] is greater than the last element in tail, append it
        if (arr[i] > tail[len - 1]) {
            tail[len] = arr[i];
            len++;
        }
        // Otherwise, find the position of arr[i] in tail and replace it
        else {
            int pos = binarySearch(tail, 0, len - 1, arr[i]);
            tail[pos] = arr[i];
        }
    }

    return len;
}

int main() {
    int arr[] = {2,5,3,6,1,2,10,7,9};
    int n = sizeof(arr) / sizeof(arr[0]);

    int length = lis(arr, n);

    printf("Length of Longest Increasing Subsequence: %d\n", length);

    return 0;
}
