/*
Given an array nums which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays.

Write an algorithm to minimize the largest sum among these m subarrays.


Example 1:
Input: nums = [7,2,5,10,8], m = 2
Output: 18
Explanation:
There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8],
where the largest sum among the two subarrays is only 18.

Example 2:
Input: nums = [1,2,3,4,5], m = 2
Output: 9

Example 3:
Input: nums = [1,4,4], m = 3
Output: 4
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
private:
    bool doable (const vector<int>& nums, int cuts, long long max) {
        int acc = 0;
        for (int num : nums) {
            // This step is unnecessary for this problem. I didn't discard this line because I want doable function more generalized.
            if (num > max) return false;
            else if (acc + num <= max) acc += num;
            else {
                --cuts;
                acc = num;
                if (cuts < 0) return false;
            }
        }
        return true;
    }
    
public:
    int splitArray(vector<int>& nums, int m) {
        long long left = 0, right = 0;
        for (int num : nums) {
            left = max(left, (long long)num);
            right += num;
        }
        
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (doable(nums, m - 1, mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};

int main(){

    return 0;
}