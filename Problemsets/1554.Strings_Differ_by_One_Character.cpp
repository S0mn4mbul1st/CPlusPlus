/*
Given a list of strings dict where all the strings are of the same length.

Return true if there are 2 strings that only differ by 1 character in the same index, otherwise return false.

 

Example 1:

Input: dict = ["abcd","acbd", "aacd"]
Output: true
Explanation: Strings "abcd" and "aacd" differ only by one character in the index 1.
Example 2:

Input: dict = ["ab","cd","yz"]
Output: false
Example 3:

Input: dict = ["abcd","cccc","abyd","abab"]
Output: true

First, we compute a hash for each string i in [0, n) as hash[i] = a[0] * 26 ^ (m - 1) + a[1] * 26 ^ (m - 2) + ... + a[m - 2] * 26 + a[m - 1], where n is the number of strings, and m - the number of characters in a string.

Then, we go through each character position j in [0, m), and compute a hash without that character: h = hash[i] - a[j] * 26 ^ (m - j - 1). We track h in a hash set so we can detect if there is another string with the same hash. Ideally, we should check for collisions as we are using mod to keep hashes within the integer range. Since the solution below is accepted, I am keeping it simple here.

Note that in the second loop we are going right-to-left so it's easier to compute 26 ^ (m - j - 1).

Update: added collision check to pass the newly added test case. It works if we store just one index, but I used vector<int> so it also works for "aaa_aaa" > [collision] > "aaa_aaa" cases.
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
    bool differByOne(vector<string>& d) {
    int mod = 1000000007, n = d.size(), m = d[0].size();
    vector<int> hash(n);
    for (auto i = 0; i < n; ++i)
        for (auto j = 0; j < m; ++j)
            hash[i] = (26l * hash[i] + (d[i][j] - 'a')) % mod;
    for (int j = m - 1, mult = 1; j >= 0; --j) {
        unordered_map<int, vector<int>> m;
        for (auto i = 0; i < n; ++i) {
            int h = (mod + hash[i] - (long)mult * (d[i][j] - 'a') % mod) % mod;
            auto it = m.find(h);
            if (it != end(m))
                for (int pi : it->second)
                    if (equal(begin(d[i]), begin(d[i]) + j, begin(d[pi])) 
                       && equal(begin(d[i]) + j + 1, end(d[i]), begin(d[pi]) + j + 1))
                        return true;
            m[h].push_back(i);
        }
        mult = 26l * mult % mod;
    }
    return false;
}
};


int main(){


    return 0;
}