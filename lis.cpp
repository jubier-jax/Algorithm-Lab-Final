#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int a[1005];
int dp[1005];

int lis(int i)
{
    if(i == 0)
        return 1;

    if(dp[i] != -1)
        return dp[i];

    dp[i] = 1;

    for(int j = 0; j < i; j++)
    {
        if(a[j] < a[i])
        {
            dp[i] = max(dp[i], lis(j) + 1);
        }
    }

    return dp[i];
}

int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        dp[i] = -1;
    }

    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        ans = max(ans, lis(i));
    }

    cout << ans << endl;

    return 0;
}