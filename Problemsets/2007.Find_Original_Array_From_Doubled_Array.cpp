/*
An integer array original is transformed into a doubled array changed by appending twice the value of every element in original, and then randomly shuffling the resulting array.

Given an array changed, return original if changed is a doubled array. If changed is not a doubled array, return an empty array. The elements in original may be returned in any order.

 

Example 1:

Input: changed = [1,3,4,2,6,8]
Output: [1,3,4]
Explanation: One possible original array could be [1,3,4]:
- Twice the value of 1 is 1 * 2 = 2.
- Twice the value of 3 is 3 * 2 = 6.
- Twice the value of 4 is 4 * 2 = 8.
Other original arrays could be [4,3,1] or [3,1,4].
Example 2:

Input: changed = [6,3,0,1]
Output: []
Explanation: changed is not a doubled array.
Example 3:

Input: changed = [1]
Output: []
Explanation: changed is not a doubled array.


Intuition
Copy a solution from 954. Array of Doubled Pairs

If you have any questions, feel free to ask.
If you like solution and explanations, please Upvote!

Let's see a simple case
Assume all interger are positive, for example [2,4,4,8].
We have one x = 2, we need to match it with one 2x = 4.
Then one 4 is gone, we have the other x = 4.
We need to match it with one 2x = 8.
Finaly no number left.

Why we start from 2?
Because it's the smallest and we no there is no x/2 left.
So we know we need to find 2x

Explanation
Count all numbers.
Loop all numbers on the order of its absolute.
We have counter[x] of x, so we need the same amount of 2x wo match them.
If c[x] > c[2 * x], then we return []
If c[x] <= c[2 * x], then we repeatly do c[2 * x]-- and append x to result res
Don't worry about 0, it doesn't fit the logic above but it won't break our algorithme.

In case count[0] is odd, it won't get matched in the end.

In case count[0] is even, we still have c[0] <= c[2 * 0].
And we still need to check all other numbers.
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
    vector<int> findOriginalArray(vector<int>& A) {
        if (A.size() % 2) return {};
        unordered_map<int, int> c;
        for (int a : A) c[a]++;
        vector<int> keys;
        for (auto it : c)
            keys.push_back(it.first);
        sort(keys.begin(), keys.end(), [](int i, int j) {return abs(i) < abs(j);});
        vector<int> res;
        for (int x : keys) {
            if (c[x] > c[2 * x]) return {};
            for (int i = 0; i < c[x]; ++i, c[2 * x]--)
                res.push_back(x);
        }
        return res;
    }
};


int main(){


    return 0;
}