#include <iostream.h>
#include <conio.h>

#define MAX_N 10   // maximum number of items
#define MAX_W 100  // maximum knapsack capacity

int dp[MAX_N + 1][MAX_W + 1];

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int weight[],int value[],int n,int W) {
    for (int i = 0; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weight[i - 1] <= w) {
                dp[i][w] = max( value[i - 1] + dp[i - 1][w - weight[i - 1]],  dp[i - 1][w] );
            } else {
                dp[i][w] = dp[i - 1][w];
	    }
	}
    }
    return dp[n][W];
}

int main() {
	int n=3, W=50;
	int weight[3]={10,20,30};
	int value[3]={60,100,120};
clrscr();
    int result = knapsack(weight,value,n,W);
    cout << "Maximum value: " << result << endl;
    return 0;
}
