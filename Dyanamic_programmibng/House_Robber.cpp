#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // n -> represents the index of current house
    int SolveUsingRecursion(vector<int> &nums, int n)
    {
        if (n < 0)
            return 0;
        if (n == 0)
        {
            return nums[0];
        }
        // include
        int include = SolveUsingRecursion(nums, n - 2) + nums[n];

        // exclude
        int exclude = SolveUsingRecursion(nums, n - 1) + 0;

        return max(include, exclude);
    }
    int SloveusingMem(vector<int> &nums, int n, vector<int> &dp)
    {
        if (n < 0)
            return 0;
        if (n == 0)
        {
            return nums[0];
        }

        // step 3 : answer are all ready exist or not
        if (dp[n] != -1)
        {
            return dp[n];
        }

        // include
        int include = SloveusingMem(nums, n - 2, dp) + nums[n];

        // exclude
        int exclude = SloveusingMem(nums, n - 1, dp) + 0;
        // step 2 : store of answer
        dp[n] = max(include, exclude);
        return dp[n];
    }
    int SloveusingTabulation(vector<int> &nums, int n)
    {
        // step 1 create dp array
        vector<int> dp(n + 1, 0);
        // step 2 : base case
        dp[0] = nums[0];

        // step 3 :
        for (int i = 1; i <= n; i++)
        {
            int temp = 0;
            if (i - 2 >= 0)
                temp = dp[i - 2];

            int include = temp + nums[i];
            int exclude = dp[i - 1] + 0;

            dp[i] = max(include, exclude);
        }
        return dp[n];
    }
    int spaceOptimization(vector<int> &nums, int n)
    {
        int prev2 = 0;
        int prev1 = nums[0];
        // vector<int> dp(n+1 , 0);
        // dp[0] = nums[0];

        int curr = 0;
        for (int i = 1; i <= n; i++)
        {
            int temp = 0;
            if (i - 2 >= 0)
                temp = prev2;

            int include = temp + nums[i];
            int exclude = prev1 + 0;

            curr = max(include, exclude);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    int rob(vector<int> &nums)
    {
        // return SolveUsingRecursion(nums , n);
        int n = nums.size() - 1;

        // vector<int> dp( n +1 , -1);
        // //step 1:
        // return SloveusingMem(nums , n ,dp);

        //return SloveusingTabulation(nums, n);

        return spaceOptimization(nums , n);
    }
};
int main()
{

    return 0;
}