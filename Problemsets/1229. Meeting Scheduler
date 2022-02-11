/*
Given the availability time slots arrays slots1 and slots2 of two people and a meeting duration duration, return the earliest time slot that works for both of them and is of duration duration.

If there is no common time slot that satisfies the requirements, return an empty array.

The format of a time slot is an array of two elements [start, end] representing an inclusive time range from start to end.

It is guaranteed that no two availability slots of the same person intersect with each other. That is, for any two time slots [start1, end1] and [start2, end2] of the same person, either start1 > end2 or start2 > end1.

 

Example 1:

Input: slots1 = [[10,50],[60,120],[140,210]], slots2 = [[0,15],[60,70]], duration = 8
Output: [60,68]
Example 2:

Input: slots1 = [[10,50],[60,120],[140,210]], slots2 = [[0,15],[60,70]], duration = 12
Output: []
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());
        int i = 0, j = 0;
        int m = slots1.size(), n = slots2.size();
        while (i < m && j < n) {
            int intersectStart = max(slots1[i][0], slots2[j][0]);
            int intersectEnd = min(slots1[i][1], slots2[j][1]);
            if (intersectEnd - intersectStart >= duration)
                return {intersectStart, intersectStart + duration};

            if (slots1[i][1] < slots2[j][1])
                i++;
            else
                j++;
        }
        return {};
    }

int main()
{

    return 0;
}
