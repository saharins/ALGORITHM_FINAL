#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define endl "\n"
#define int long long int
vector<vector<int>> dp;
bool is_possible(int n,int *arr,int w){
    if(n == 0){
        if(w == 0){
            return true;
        }
        else return false;
    }
    if(dp[n][w] != -1){
        return dp[n][w];
    }
    if(arr[n-1] <= w){
        return dp[n][w] = (is_possible(n-1,arr,w-arr[n-1]) || is_possible(n-1,arr,w));
    }
    else{
        return dp[n][w] = is_possible(n-1,arr,w);
    }
}
signed main()
{
    fastio;
    int t;cin >> t;
    while(t--){
        int n;cin >> n;
        int arr[n],sum = 0;
        for(int i=0;i<n;i++){
            cin >> arr[i];
            sum += arr[i];
        }
        int required_sum = sum/2;
        if(sum&1){
            cout << "NO" << endl;
            continue;
        }
        else
        {
            dp.assign(n+1,vector<int>(required_sum+1,-1));
            if(is_possible(n,arr,required_sum)){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}