/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.



Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int findDuplicate(vector<int>& nums) {
    int n=nums.size()-1;
    int low=1;
    int high=n;
    int mid;
    while(low<high){
        mid=(low+high)/2;
        int count=0;
        for(int num:nums){
            if(num<=mid) count++;
        }
        if(count>mid) high=mid;
        else low=mid+1;
    }
    return low;
}

int main()
{

    return 0;
}
