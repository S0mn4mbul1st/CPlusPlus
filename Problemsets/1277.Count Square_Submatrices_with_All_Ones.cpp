/*
Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

 

Example 1:

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.
Example 2:

Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.

Explanation
dp[i][j] means the size of biggest square with A[i][j] as bottom-right corner.
dp[i][j] also means the number of squares with A[i][j] as bottom-right corner.

If A[i][j] == 0, no possible square.
If A[i][j] == 1,
we compare the size of square dp[i-1][j-1], dp[i-1][j] and dp[i][j-1].
min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1 is the maximum size of square that we can find.


Complexity
Time O(MN)
Space O(1)
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
    int countSquares(vector<vector<int>>& A) {
        int res = 0;
        for (int i = 0; i < A.size(); ++i)
            for (int j = 0; j < A[0].size(); res += A[i][j++])
                if (A[i][j] && i && j)
                    A[i][j] += min({A[i - 1][j - 1], A[i - 1][j], A[i][j - 1]});
        return res;
    }
};


int main(){


    return 0;
}