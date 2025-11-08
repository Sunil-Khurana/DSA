#include <iostream.h>
int dp[100];
void calcFibo()
{
	int i;
	dp[0]=0;
	dp[1]=1;
	for(i=2;i<=99;i++)
	{
		dp[i]=dp[i-1]+dp[i-2];
	}
}
int fibo(int n)
{
	return(dp[n]);
}
main()
{
	int n,t;
	cout<<"Enter n ";
	cin>>n;
	if(n<0 || n>99)
	{
		cout<<"Correct n is 0 to 99 \n";
		return 0;
	}
	calcFibo();
	t=fibo(n);
	cout<<"Term is "<<t;
}
