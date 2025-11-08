#include <iostream.h>
#include <conio.h>

#define N 100
#define MAX_SUM 100
#define TRUE 1
#define FALSE 0

int arr[N] = {3, 2, 5, 3,1, 8};  // Example
int dp[N + 1][MAX_SUM + 1];
int chosen[N];  // Marks elements used in first subset

int canPartition(int n)
{
	int total = 0,i,j,k;
	for (i = 0; i < n; i++)
		total += arr[i];

	if (total % 2 != 0)
		return FALSE;

	int target = total / 2;

    // Initialize DP
	for (i = 0; i <= n; i++)
		dp[i][0] = TRUE;
	for ( j = 1; j <= target; j++)
		dp[0][j] = FALSE;

	for ( i = 1; i <= n; i++)
	{
		for ( j = 1; j <= target; j++)
		{
			if (arr[i - 1] <= j)
				dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
			else
				dp[i][j] = dp[i - 1][j];
			cout<<dp[i][j]<<"  ";
		}
		cout<<endl;
	}

    // If partition not possible
	if (!dp[n][target])
		return FALSE;

    // Trace back to find one subset
	i = n, j = target;
	for ( k = 0; k < n; k++)
		chosen[k] = FALSE;

	while (i > 0 && j > 0)
	{
		if (j >= arr[i - 1] && dp[i - 1][j - arr[i - 1]])
		{
			// Element included
			chosen[i - 1] = TRUE;
			j -= arr[i - 1];
			i--;
		}
		else
		{
			i--;
		}
	}

    // Print subsets
	cout << "Subset 1: ";
	for ( k = 0; k < n; k++)
		if (chosen[k])
			cout << arr[k] << " ";
	cout << "\n";

	cout << "Subset 2: ";
	for ( k = 0; k < n; k++)
		if (!chosen[k])
			cout << arr[k] << " ";
		cout << "\n";
	return TRUE;
}

int main()
{
	int n = 6;
	clrscr();
	if (!canPartition(n))
		cout << "Cannot be partitioned into two subsets of equal sum.\n";
	return 0;
}

