/*
                       _oo0oo_
                      o8888888o
                      88" . "88
                      (| -_- |)
                      0\  =  /0
                    ___/`---'\___
                  .' \\|     |// '.
                 / \\|||  :  |||// \
                / _||||| -:- |||||- \
               |   | \\\  -  /// |   |
               | \_|  ''\---/''  |_/ |
               \  .-\__  '-'  ___/-. /
             ___'. .'  /--.--\  `. .'___
          ."" '<  `.___\_<|>_/___.' >' "".
         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
         \  \ `_.   \_ __\ /__ _/   .-` /  /
     =====`-.____`.___ \_____/___.-`___.-'=====
                       `=---='

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
The code is written by Aykhan Imanov
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

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

const int RANGE = 255;
const int INF = 1<<29;

using namespace std;

void countSort(char arr[])
{
    char output[strlen(arr)];
  
    int count[RANGE + 1];
    memset(count, 0, sizeof(count));
  
    for (int i = 0; arr[i]; ++i)
        ++count[arr[i]];
  
    for (int i = 1; i <= RANGE; ++i)
        count[i] += count[i - 1];
  
    for (int i = 0; arr[i]; ++i) {
        output[count[arr[i]] - 1] = arr[i];
        --count[arr[i]];
    }
  
    for (int i = 0; arr[i]; ++i)
        arr[i] = output[i];
}
  
int main()
{
    char arr[] = "geeksforgeeks";
  
    countSort(arr);
  
    cout << "Sorted character array is " << arr;
    return 0;
}