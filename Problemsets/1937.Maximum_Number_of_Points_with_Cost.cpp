/*
You are given an m x n integer matrix points (0-indexed). Starting with 0 points, you want to maximize the number of points you can get from the matrix.

To gain points, you must pick one cell in each row. Picking the cell at coordinates (r, c) will add points[r][c] to your score.

However, you will lose points if you pick a cell too far from the cell that you picked in the previous row. For every two adjacent rows r and r + 1 (where 0 <= r < m - 1), picking cells at coordinates (r, c1) and (r + 1, c2) will subtract abs(c1 - c2) from your score.

Return the maximum number of points you can achieve.

abs(x) is defined as:

x for x >= 0.
-x for x < 0.
 

Example 1:
Input: points = [[1,2,3],[1,5,1],[3,1,1]]
Output: 9
Explanation:
The blue cells denote the optimal cells to pick, which have coordinates (0, 2), (1, 1), and (2, 0).
You add 3 + 5 + 3 = 11 to your score.
However, you must subtract abs(2 - 1) + abs(1 - 0) = 2 from your score.
Your final score is 11 - 2 = 9.

Example 2:
Input: points = [[1,5],[2,3],[4,2]]
Output: 11
Explanation:
The blue cells denote the optimal cells to pick, which have coordinates (0, 1), (1, 1), and (2, 0).
You add 5 + 3 + 4 = 12 to your score.
However, you must subtract abs(1 - 1) + abs(1 - 0) = 1 from your score.
Your final score is 12 - 1 = 11.
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
    long long maxPoints(vector<vector<int>>& P) {
        long long m = P.size(), n = P[0].size();
        vector<long long> pre(n);
        for (int i = 0; i < n; ++i) pre[i] = P[0][i];
        for (int i = 0; i < m - 1; ++i){
            vector<long long> lft(n, 0), rgt(n, 0), cur(n, 0);
            lft[0] = pre[0];
            rgt[n - 1] = pre[n - 1];
            for (int j = 1; j < n; ++j){
                lft[j] = max(lft[j - 1] - 1, pre[j]);
            }
            for (int j = n - 2; j >= 0; --j){
                rgt[j] = max(rgt[j + 1] - 1, pre[j]);
            }
            for (int j = 0; j < n; ++j){
                cur[j] = P[i + 1][j] + max(lft[j], rgt[j]);
            }
            pre = cur;
        }
        long long ans = 0;
        for (int i = 0; i < n; ++i)
            ans = max(ans, pre[i]);
        return ans;
    }
};


int main(){

    return 0;
}
