/*
Given an m x n integers matrix, return the length of the longest increasing path in matrix.

From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

Example 1:
Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].

Example 2:
Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

Example 3:
Input: matrix = [[1]]
Output: 1
*/

#include <bits/stdc++.h>

#define FOR(i,a,b)       for(int i=a; i<b; i++)
#define NFOR(i,a,b)      for(int i=(a-1); i>=(b); i--)
#define ll               long long int
#define ld               long long double
#define f                first
#define s                second
#define pb               push_back
#define mp               make_pair
#define max(x,y)         (x>y)?x:y
#define min(x,y)         (x<y)?x:y


const int INF = 1<<29;

using namespace std;

class Solution {
public:
    int dp[200][200]{}; // constraints are small enough that we can just set them to MAX
    int maxPath, n, m;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        maxPath = 0, n = size(matrix), m = size(matrix[0]);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                maxPath = max(maxPath, solve(matrix, i, j, -1));            
        return maxPath;
    }
    int solve(vector<vector<int>>& mat, int i, int j, int prev){
        if(i < 0 || j < 0 || i >= n || j >= m || mat[i][j] <= prev) return 0;
        if(dp[i][j]) return dp[i][j];
        return dp[i][j] = 1 + max({ solve(mat, i + 1, j, mat[i][j]),
                                    solve(mat, i - 1, j, mat[i][j]),
                                    solve(mat, i, j + 1, mat[i][j]),
                                    solve(mat, i, j - 1, mat[i][j]) });       
    }
};

int main(){


    return 0;
}