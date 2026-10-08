#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int maxCrossingSum(vector<int>& arr, int left, int mid, int right)
{
    int leftSum = INT_MIN;
    int sum = 0;

    for(int i = mid; i >= left; i--)
    {
        sum += arr[i];
        leftSum = max(leftSum, sum);
    }

    int rightSum = INT_MIN;
    sum = 0;

    for(int i = mid + 1; i <= right; i--)
    {
        sum += arr[i];
        rightSum = max(rightSum, sum);
    }

    return leftSum + rightSum;
}

int maxSubarraySum(vector<int>& arr, int left, int right)
{
    if(left == right)
        return arr[left];

    int mid = (left + right) / 2;

    int leftMax = maxSubarraySum(arr, left, mid);

    int rightMax = maxSubarraySum(arr, mid + 1, right);

    int crossMax = maxCrossingSum(arr, left, mid, right);

    return max({leftMax, rightMax, crossMax});
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements: ";

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int answer = maxSubarraySum(arr, 0, n - 1);

    cout << "Maximum Subarray Sum = " << answer << endl;

    return 0;
}