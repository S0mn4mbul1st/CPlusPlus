/*
There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

 

Example 1:

Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.
Example 2:

Input: cardPoints = [2,2,2], k = 2
Output: 4
Explanation: Regardless of which two cards you take, your score will always be 4.
Example 3:

Input: cardPoints = [9,7,7,9,7,7,9], k = 7
Output: 55
Explanation: You have to take all the cards. Your score is the sum of points of all cards.


Key idea: You can’t choose 2nd element from the beginning unless you have chosen the first one. Similarly, you can’t choose 2nd element from last unless you have chosen the last one.

So now just try all possible combinations. Choose 0 from the beginning and K from the last, 1 from front and K-1 from last and so on until K from beginning and 0 from behind. Maximum out of all those combinations is the answer.

image

To make it faster to find sum of first i cards, store the cumulative sum from the beginning to current index i in an array. In the similar way, store cumulative sums from the back in separate array.

How to solve exactly?

Find cumulative sum from beginning to the current index.
Find cumulative sum from behind till the current index.
If you choose i elements from front, you will need to choose k-i elements from behind.
Sum of first i elements = cumulativeSumFromFront[i],
Sum of last (k-i) elements = cumulativeSumFromBehind[K-i].
So points obtained when choosing i elements from the front = cumulativeSumFromFront[i] + cumulativeSumFromBehind[K-i]
Repeat Step 3 for all i ranging from 0 to K.
Return the maximum value of points reached.
Hope it is easy to understand.
Let me know if there is something unclear and I can fix it.

Otherwise, please upvote if you like the solution, it would be encouraging.
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
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0;
        int n = cardPoints.size();
        
        vector<int> cummulativeSumFromFront(n+1, 0);
        vector<int> cummulativeSumFromBehind(n+1, 0);
        
        sum = 0;
        for (int i=0; i<n; i++) {
            sum += cardPoints[i];
            cummulativeSumFromFront[i+1] = sum;
        }
        sum = 0;
        for (int i=n-1; i>=0; i--) {
            sum += cardPoints[i];
            cummulativeSumFromBehind[i] = sum;
        }
        
        // Reversing is optional. I reversed it so that it would be easy
        // to access sum of last (k-i) elements by just indexing at [k-i]
        // Otherwise, I would have had to index it at [n-k+i] which would
        // have made it difficult to read.
        reverse(cummulativeSumFromBehind.begin(), cummulativeSumFromBehind.end());
        
        int answer = 0;
        for(int i=0; i<=k; i++) {      
            answer = max(answer, 
                           cummulativeSumFromFront[i] // Sum of first 'i' cards.
                         + cummulativeSumFromBehind[k-i]); // Sum of last 'k-i' cards.
        }
        return answer;
    }
};

int main(){


    return 0;
}