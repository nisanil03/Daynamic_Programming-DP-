#include <bits/stdc++.h>
using namespace std;
int solveUsingREcursion(vector<int> &coins, int amount)
{
    // base case
    if (amount == 0)
    {
        return 0;
    }
    if (amount < 0)
    {
        return INT_MAX;
    }
    int mini = INT_MAX;
    for (int i = 0; i < coins.size(); i++)
    {
        int ans = solveUsingREcursion(coins, amount - coins[i]);
        if (ans != INT_MAX)
        {
            mini = min(mini, 1 + ans);
        }
    }
    return mini;
}
int coinChange(vector<int> &coins, int amount)
{
    int ans = solveUsingREcursion(coins, amount);
    if (ans == INT_MAX)
        return -1;
    else
        return ans;
}
// solve memozation to hi top down bolte hai
// Top down approach
int solveMen(vector<int> &coins, int amount, vector<int> &dp)
{
    // base case
    if (amount == 0)
    {
        return 0;
    }
    // Simply mark the value that here answer won't come
    if (amount < 0)
    {
        return INT_MAX;
    }
    // Step - 3 : Check if answer already exists?
    if (dp[amount] != -1)
    {
        return dp[amount];
    }
    int mini = INT_MAX;

    for (int i = 0; i < coins.size(); i++)
    {
        int ans = solveMen(coins, amount - coins[i], dp);
        if (ans != INT_MAX)
        {
            // Update mini as we have got valid answer
            // Adding 1 so as to consider previous coin which was included
            mini = min(mini, 1 + ans);
        }
    }
    // Step 2 : Update in the dp array
    dp[amount] = mini;
    return mini;
}
// Bottom up approach
int solveTab(vector<int> &coins, int amount)
{
    // step 1: Create dp array
    vector<int> dp(amount + 1, INT_MAX);

    // step 2; reverse the flow in top down approach
    dp[0] = 0;
    for (int i = 1; i <= amount; i++)
    {
        for (int j = 0; j < coins.size(); j++)
        {
            if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX)
            {
                int ans = dp[i - coins[j]];
                dp[i] = min(dp[i], 1 + ans);
            }
        }
    }
    return dp[amount];
}
// int main()
// {
//     vector<int> coins;
//     coins.push_back(1);
//     coins.push_back(2);
//     coins.push_back(5);
//     int amount = 11;
//     cout << "Ans is " << coinChange(coins, amount) << endl;

//     return 0;
// }

// Bottom up approach
// int ans = solveTab(coins, amount);
//     if (ans == INT_MAX)
//         return -1;
//     return ans;
// }

// Top down approach
// Step 1 : Create dp array
// int main()
// {
//     vector<int> dp(amount + 1, -1);
//     int ans = solveMen(coins, amount, dp);
//     if (ans == INT_MAX)
//         return -1;
//     else
//         return ans;
// }

int main()
{
    vector<int> coins;
    coins.push_back(1);
    coins.push_back(2);
    int amount = 3;
    int ans = coinChange(coins, amount);
    cout << "Coins required = " << ans << endl;
    return 0;
}
