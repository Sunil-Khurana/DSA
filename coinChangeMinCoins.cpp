#include <iostream.h>
#include <conio.h>
#define MAX_AMOUNT 100
#define INT_MAX 999

int coinChangeMin(int coins[], int n, int amount) {
    int dp[MAX_AMOUNT];

    // Initialize dp array
    for (int i = 0; i <= amount; ++i)
	dp[i] = INT_MAX;

    dp[0] = 0; // Base case

    for (i = 0; i < n; ++i) {
	int coin = coins[i];
	for (int j = coin; j <= amount; ++j) {
		if (dp[j] > dp[j - coin] + 1)
		    dp[j] = dp[j - coin] + 1;
	}
    }

    return (dp[amount] == INT_MAX) ? -1 : dp[amount];
}

int main() {
    int coins[] = {1, 2, 5};
    int n = 3;
    int amount = 11;
    clrscr();

    int minCoins = coinChangeMin(coins, n, amount);
    cout << "Minimum coins needed: " << minCoins << endl;
}

