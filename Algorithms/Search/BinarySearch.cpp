#include <bits/stdc++.h>

using namespace std;

int binarySearch(int arr[], int val, int left, int right){

    if(left <= right){
        int mid = left + (right - left) / 2;

        if(arr[mid] == val) return mid;

        else if(arr[mid] < val) return binarySearch(arr, val, mid+1, right);

        return binarySearch(arr, val, left, mid-1);
    }
}

int main()
{
    int arr[]{ 1, 2, 3, 4, 5, 6, 7};

    cout << binarySearch(arr, 7, 0, sizeof(arr) / sizeof(arr[0])-1) << endl;

    return 0;
}
