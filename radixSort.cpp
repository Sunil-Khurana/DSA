#include <iostream.h>
int getMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void countingSortByDigit(int arr[], int size, int exp) {
    int* output = new int[size];    // output array
    int count[10];                  // count array for digits 0–9

    // Initialize count array
    for (int i = 0; i < 10; i++)
        count[i] = 0;

    // Store count of occurrences of digits
    for (int i = 0; i < size; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that count[i] contains actual position
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array (stable sort)
    for (int i = size - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy the output array to arr[]
    for (int i = 0; i < size; i++)
        arr[i] = output[i];

    delete[] output;
}

void radixSort(int arr[], int size) {
    int max = getMax(arr, size);

    // Do counting sort for every digit (exp = 1, 10, 100, ...)
    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSortByDigit(arr, size, exp);
}

main() {
    int arr[8] = {170, 45, 75, 90, 802, 24, 2, 66};

    radixSort(arr, 8);

    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

