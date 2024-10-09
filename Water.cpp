#include <bits/stdc++.h>
using namespace std;
#define int long long int

//#define trace(x) cout << #x << " : " << x << endl;

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].first;
            arr[i].second = i;
        }
        sort(arr.begin(), arr.end());
        int a = arr[n - 1].second, b = arr[n - 2].second;
        cout << min(a, b) << " " << max(a, b) << endl;
    }

    return 0;
}