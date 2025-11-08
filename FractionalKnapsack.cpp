#include <iostream.h>
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Sort items by value/weight ratio in descending order
void sortItems(int weights[], int values[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        float ratio1 = (float)values[i] / weights[i];
        for (int j = i + 1; j < n; ++j) {
            float ratio2 = (float)values[j] / weights[j];
            if (ratio2 > ratio1) {
                swap(weights[i], weights[j]);
                swap(values[i], values[j]);
                ratio1 = ratio2; // update for next comparison
            }
        }
    }
}

// Greedy algorithm for Fractional Knapsack (Always optimal!)
int greedyKnapsackFractional(int weights[], int values[], int n, int W) {
    sortItems(weights, values, n);

    int totalValue = 0;
    int currentWeight = 0;

    for (int i = 0; i < n; ++i) {
        if (currentWeight + weights[i] <= W) {
            currentWeight += weights[i];
            totalValue += values[i];
        }
	else
	{
		int remainingWeight=W-currentWeight;
		totalValue += values[i] * ((float)remainingWeight / weights[i]);
		break;	
	}
    }

    return totalValue;
}

int main() {
    int weights[] = {1, 3, 4, 5};
    int values[] = {1, 4, 5, 7};
    int n = 4;
    int W = 7;

    int result = greedyKnapsackFractional(weights, values, n, W);
    cout << "Greedy Knapsack Value (Fractional) = " << result << endl;

    return 0;
}
