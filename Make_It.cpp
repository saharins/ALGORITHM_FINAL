#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define endl "\n"
#define int long long int
vector<int> dp;
bool ans(int sum,int n)
{
    if(sum > n){
        return 0;
    }
    if(dp[sum] != -1)
    return dp[sum];
    else if(sum == n) return true;
    return dp[sum] = ans(sum+3,n) || ans(sum*2,n);
}
signed main()
{
    fastio;
    int t;cin >> t;
    while(t--){
        int n;cin >> n;
        dp.assign(n+1,-1);
        if(ans(1,n)){
            cout << "YES" << endl;
        }
        else 
        cout << "NO" << endl;
    }
    return 0;
}