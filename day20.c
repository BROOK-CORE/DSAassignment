#include <stdio.h>

int countZeroSumSubarrays(int arr[], int n) {
    int count = 0;
    int prefixSum = 0;
    
    // Since C doesn't have built-in hashmap, we use a simple array for demo.
    // For large numbers, a proper hash map should be used.
    int sumFreq[100000] = {0}; // assuming prefix sums are within -50000 to 50000
    int offset = 50000; // to handle negative indices

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        if (prefixSum == 0) {
            count++;
        }

        count += sumFreq[prefixSum + offset];

        sumFreq[prefixSum + offset]++;
    }

    return count;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = countZeroSumSubarrays(arr, n);
    printf("%d\n", result);

    return 0;
}