#include <iostream.h>
void countingSort(int arr[], int size) {
    // Step 1: Find the maximum element
    int max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max)
            max = arr[i];
    }

    // Step 2: Create count array
    int* count = new int[max + 1];
    for (int i = 0; i <= max; ++i) {
        count[i] = 0;
    }

    // Step 3: Count occurrences
    for (int i = 0; i < size; ++i) {
        count[arr[i]]++;
    }

    // Step 4: Cumulative count
    for (int i = 1; i <= max; ++i) {
        count[i]=count[i]+ count[i - 1];
    }

    // Step 5: Build output array
    int* output = new int[size];
    for (int i = size - 1; i >= 0; --i) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Step 6: Copy back to original array
    for (int i = 0; i < size; ++i) {
        arr[i] = output[i];
    }

    // Free dynamically allocated memory
    delete[] count;
    delete[] output;
}


main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    countingSort(arr, 7);

    cout << "Sorted array: ";
    for (int i = 0; i <=6 ; i++)
        cout << arr[i] << " ";

    return 0;
}

/*
Time Complexity
O(n+k)
*/



