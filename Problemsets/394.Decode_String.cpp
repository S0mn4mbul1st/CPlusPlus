/*
Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

 

Example 1:

Input: s = "3[a]2[bc]"
Output: "aaabcbc"
Example 2:

Input: s = "3[a2[c]]"
Output: "accaccacc"
Example 3:

Input: s = "2[abc]3[cd]ef"
Outp
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
    
    string decodeString(string s) {
        int index = 0;
        return decodeString(s, index);
    }
    
    string decodeString(const string& s, int& index) {
        string result;
        while (index < s.length() && s[index] != ']') {
            if (!isdigit(s[index]))
                result += s[index++];
            else {
                int k = 0;

                while (index < s.length() && isdigit(s[index]))
                    k = k * 10 + s[index++] - '0';  

                index++;
                string decodedString = decodeString(s, index);

                index++;        
                while (k-- > 0)
                    result += decodedString;
            }
        }
        return result;
    }
};

int main(){
    string str = "3[a]2[bc]";
    Solution *var = new Solution();
    cout << var->decodeString(str);

//Input: s = "3[a2[c]]"
//Output: "accaccacc"

    return 0;
}