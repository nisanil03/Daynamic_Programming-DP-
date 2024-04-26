// very very important for interview

#include <bits/stdc++.h>
using namespace std;
// approach no 1 . using recursion (TLE mar dega)
int solveUsingRecursion(int n, int k)
{
    // base case
    if (n == 1)
    {
        return k;
    } // TODO T.C exponencatiol

    if (n == 2)
    {
        return (k + k * (k - 1));
    }

    int ans = (solveUsingRecursion(n - 2, k) + solveUsingRecursion(n - 1, k)) * (k - 1);
    return ans;
}

// approach no 2 . top down approach
int sloveUsingMem(int n, int k, vector<int> &dp)
{
    // Base case
    if (n == 1)
    {
        return k;
    }
    if (n == 2)
    {
        return (k + k * (k - 1)); // TODO T.C o(n) //constant
    }
    // Step 3 : Check answer already exists
    if (dp[n] != -1)
    {
        return dp[n];
    }

    // Recursive call
    dp[n] = (sloveUsingMem(n - 2, k, dp) + sloveUsingMem(n - 1, k, dp)) * (k - 1);
    return dp[n];
}
// appreach no . 3  bottom down apporach (tablutation method)

int SolveUsingTab(int n, int k)
{
    // Step 1 : Create dp array
    vector<int> dp(n + 1, 0);

    // Step 2 : Observe base case of top down
    dp[1] = k;
    dp[2] = (k + k * (k - 1));

    // Step 3 : Reverse the flow of top down
    for (int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i - 2] + dp[i - 1]) * (k - 1);
    }
    return dp[n];
}

int SpaceOptimazation(int n, int k)
{
    int prev2 = k;
    int prev1(k + k * (k - 1));

    for (int i = 3; i <= n; i++)
    {
        int curr = (prev2 + prev1) * (k - 1);       // TODO T.C o(n) // o(1);

        // shifting -> yaha hi galti karunga
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
int main()
{
    int n = 4;
    int k = 3;

    // Recursive code
    // int ans = solveUsingRecursion(n, k);

    // Top down approach
    // Step 1 : Create dp array
    // vector<int> dp(n + 1, -1);
    // int ans = sloveUsingMem(n, k, dp);

    // Bottom up approach

    // int ans = SolveUsingTab( n, k);
    int ans = solveSpaceOpt(n, k);
    cout << "Colors required are " << ans << endl;

    return 0;
}



//imp question count diarrangment