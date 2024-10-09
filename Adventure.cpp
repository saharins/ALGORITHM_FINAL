#include<bits/stdc++.h>
using namespace std;
#define int long long int

int sum(int n,int w,int *value,int *wt,vector<vector<int>> &dp)
{
    if(n == 0 || w == 0)
    {
        return 0;
    }
    if(dp[n][w] != -1)
    {
        return dp[n][w];
    }
    if(wt[n-1] <= w)
    {
        return dp[n][w] = max(sum(n-1,w-wt[n-1],value,wt,dp)+value[n-1],sum(n-1,w,value,wt,dp));
    }
    else
    {
        return dp[n][w] = sum(n-1,w,value,wt,dp);
    }
}
int32_t main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n,w;
        cin >> n >> w;
        int value[n],wt[n];

        for(int i =0;i<n;i++)
        {
            cin >> wt[i];
        }
        for(int i=0;i<n;i++)
        {
            cin >> value[i];
        }

        vector<vector<int>> dp(n+1,vector<int>(w+1,-1));
        cout << sum(n,w,value,wt,dp) << endl;
    }

    return 0;
}