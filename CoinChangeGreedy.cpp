#include <iostream.h>

// Sort the array in descending order (simple bubble sort)
void sortDescending(int arr[], int n) {
    for (int i = 0; i < n -1; i++) {
        for (int j = 0; j < n - i -1; j++) {
            if (arr[j] < arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Greedy coin change function
int coinChangeGreedy(int coins[], int n, int amount) {
    sortDescending(coins, n);
    
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (amount == 0) break;

        int use = amount / coins[i];  // max coins of this denomination
        count += use;
        amount -= use * coins[i];
    }

    return (amount == 0) ? count : -1;
}

int main() {
    int coins[] = {25, 10, 5, 1};
    int n = 4;
    int amount = 63;

    int result = coinChangeGreedy(coins, n, amount);
    if (result != -1)
        cout << "Minimum coins required: " << result << endl;
    else
        cout << "Change cannot be made with given coins" << endl;

    return 0;
}

