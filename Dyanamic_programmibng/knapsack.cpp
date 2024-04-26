// very very important question and pattern

// imp question

// subset sum
// equal subset
// sum partition
// min subset
// sum difference

#include <bits/stdc++.h>
using namespace std;
// n here = index of last element
int solveUsingRecursion(int weight[], int value[], int index, int capacity)
{
    // base case
    if (index == 0)
    {
        if (weight[0] <= capacity)
        {
            return value[0];
        }
        else
            return 0;
    }

    // include and exclude
    int include = 0;
    if (weight[index] <= capacity)
        include = value[index] + solveUsingRecursion(weight, value, index - 1, capacity - weight[index]);

    // exclude
    int exclude = 0 + solveUsingRecursion(weight, value, index - 1, capacity);

    // answer return
    int ans = max(include, exclude);
    return ans;
}

// approach no 2 topdown // 2D dp problem
int solveUsingMem(int weight[], int value[], int index, int capacity, vector<vector<int>> &dp)
{
    // base case
    if (index == 0)
    {
        if (weight[0] <= capacity)
        {
            return value[0];
        }
        else
            return 0;
    }
    // Step 3 : Answer already exists
    if (dp[index][capacity] != -1)
    {
        return dp[index][capacity];
    }

    // include
    int include = 0;
    if (weight[index] <= capacity)
        include = value[index] + solveUsingMem(weight, value, index - 1, capacity - weight[index], dp);

    // exclude
    int exclude = 0 + solveUsingMem(weight, value, index - 1, capacity, dp);
 
    // Step 2 : Store in dp array
    dp[index][capacity] = max(include, exclude);
    return dp[index][capacity];
}
// approach 3  bottom up -> 2D DP

int solveUsingTabulation(int weight[], int value[], int n, int capacity)
{
    // stp no 1. create 2D dp array
    vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));
    // Step 2 : Observe base case of top down
    // We have to run a loop for 0th index
    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
        {
            dp[0][w] = value[0];
        }
        else
            dp[0][w] = 0;
    }

    // Step 3 : Reverse the flow of top-down
    // Replace n with index and capacity with wt
    for (int index = 1; index < n; index++)
    {
        for (int wt = 0; wt <= capacity; wt++)
        {
            // include
            int include = 0;
            if (weight[index] <= wt)
                include = value[index] + dp[index - 1][wt - weight[index]];

            int exclude = 0 + dp[index - 1][wt];
            dp[index][wt] = max(include, exclude);
        }
    }
    return dp[n - 1][capacity];
}

// approach no . 4 space optimazation

int solveUsingSpaceOptimzation_1(int weight[], int value[], int n, int capacity)
{
    // Create 2 1D arrays
    vector<int> prev(capacity + 1, 0);
    vector<int> curr(capacity + 1, 0);

    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
        {
            prev[w] = value[0];
        }
        else
            prev[w] = 0;
    }
    // Step 3 : Reverse the flow of top-down

    for (int index = 1; index < n; index++)
    {
        for (int wt = 0; wt <= capacity; wt++)
        {
            // include
            int include = 0;
            if (weight[index] <= wt)
                include = value[index] + prev[wt - weight[index]];
            // ecclude
            int exclude = 0 + prev[wt];

            // Step 2 : Store in dp array
            curr[wt] = max(include, exclude);
        }
        // Shifting logic (we can forget this)
        prev = curr;
    }
    return prev[capacity];
}
int solveUsingSpaceOptimzation_2(int weight[], int value[], int n, int capacity)
{
    // Create 1D array
    vector<int> curr(capacity + 1, 0);

    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
        {
            curr[w] = value[0];
        }
        else
            curr[w] = 0;
    }
    // Step 3 : Reverse the flow of top-down
    for (int index = 1; index < n; index++)
    {
        for (int wt = capacity; wt >= 0; wt--)
        {
            // include
            int include = 0;
            if (weight[index] <= wt)
                include = value[index] + curr[wt - weight[index]];

            // exclude
            int exclude = 0 + curr[wt];

            // Step 2 : Store in dp array
            curr[wt] = max(include, exclude);
        }
    }
    return curr[capacity];
}
int main()
{
    int weight[] = {4, 5, 1};
    int value[] = {1, 2, 3};
    int n = 3;
    int capacity = 4;

    // recursion function cell
    // int ans = solveUsingRecursion(weight, value, n - 1, capacity);

    //  memoization function cell -> topdown
    // Step 1 : Create dp array
    // Here we can stuck (Initialization part)
    // vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
    // int ans = solveUsingMem(weight, value, n - 1, capacity, dp);

    // tabluation function cell
    //  vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
    //  int ans = solveUsingTabulation(weight , value , n , capacity);

    // space optimization  1 function cell
    // int ans = solveUsingSpaceOptimzation_1(weight, value, n, capacity);

    // space optimization  2 function cell
    int ans = solveUsingSpaceOptimzation_2(weight, value, n, capacity);
    cout << "Maximum profit = " << ans << endl;

    return 0;
}