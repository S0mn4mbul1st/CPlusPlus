/*
You are given two 0-indexed arrays of strings startWords and targetWords. Each string consists of lowercase English letters only.

For each string in targetWords, check if it is possible to choose a string from startWords and perform a conversion operation on it to be equal to that from targetWords.

The conversion operation is described in the following two steps:

Append any lowercase letter that is not present in the string to its end.
For example, if the string is "abc", the letters 'd', 'e', or 'y' can be added to it, but not 'a'. If 'd' is added, the resulting string will be "abcd".
Rearrange the letters of the new string in any arbitrary order.
For example, "abcd" can be rearranged to "acbd", "bacd", "cbda", and so on. Note that it can also be rearranged to "abcd" itself.
Return the number of strings in targetWords that can be obtained by performing the operations on any string of startWords.

Note that you will only be verifying if the string in targetWords can be obtained from a string in startWords by performing the operations. The strings in startWords do not actually change during this process.

 

Example 1:

Input: startWords = ["ant","act","tack"], targetWords = ["tack","act","acti"]
Output: 2
Explanation:
- In order to form targetWords[0] = "tack", we use startWords[1] = "act", append 'k' to it, and rearrange "actk" to "tack".
- There is no string in startWords that can be used to obtain targetWords[1] = "act".
  Note that "act" does exist in startWords, but we must append one letter to the string before rearranging it.
- In order to form targetWords[2] = "acti", we use startWords[1] = "act", append 'i' to it, and rearrange "acti" to "acti" itself.
Example 2:

Input: startWords = ["ab","a"], targetWords = ["abc","abcd"]
Output: 1
Explanation:
- In order to form targetWords[0] = "abc", we use startWords[0] = "ab", add 'c' to it, and rearrange it to "abc".
- There is no string in startWords that can be used to obtain targetWords[1] = "abcd".

Solution:
Generate a hash for each word in startWords using the following rule and add all generated hash into a set:
For 'a', add 1 (i.e. 1 in binary) to the hash;
For 'b', add 2 (i.e. 10 in binary) to the hash;
For 'c', add 4 (i.e. 100 in binary) to the hash;
For 'd', add 8 (i.e. 1000 in binary)to the hash;
...

For example, if the word is "abdz", then the hash is 10000000000000000000001011 in binary.

For each word in targetWords, generate a hash a using the same rule but with one character removed.
So, if the word is "abcd", we need to generate hashes for "abc", "abd", "acd", "bcd". If any of the hashes is in the set of hashes for startWords, the targetWord can be obtained.

Note: The order of characters in a word doesn't matter when generating the hash. i.e. "abc" and "cba" have the same hash 111. This avoids the sorting needed in some other solutions.
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
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<int> vis;
        for (string s : startWords) {
            int hash = 0;
            for (int i = 0; i < s.size(); i++) {
                hash += (1 << (s[i] - 'a'));
            }
            vis.insert(hash);
        }
        
        int res = 0;
        for (string s : targetWords) {
            int hash = 0;

            for (int k = 0; k < s.size(); k++) {
                hash = 0;
                for (int i = 0; i < s.size(); i++) {
                    if (i == k) continue;
                    hash += (1 << (s[i] - 'a'));
                }
                if (vis.count(hash)) {
                    res++;
                    break;
                }
            }
        }
        
        return res;
    }
};

int main(){

    return 0;
}