/*
Knuth–Morris–Pratt algorithm
The KMP matching algorithm uses degenerating property (pattern having same sub-patterns appearing more than once in the pattern) of the pattern and improves the worst case 
complexity to O(n). The basic idea behind KMP’s algorithm is: whenever we detect a mismatch (after some matches), we already know some of the characters in the text of the 
next window. We take advantage of this information to avoid matching the characters that we know will anyway match. Let us consider below example to understand this.
*/

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


const int INF = 1<<29;

using namespace std;


void computeLPSArray(char* pat, int M, int* lps);
  
void KMPSearch(char* pat, char* txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
  
    int lps[M];
  
    computeLPSArray(pat, M, lps);
  
    int i = 0; 
    int j = 0; 
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
  
        if (j == M) {
            printf("Found pattern at index %d ", i - j);
            j = lps[j - 1];
        }
  
        else if (i < N && pat[j] != txt[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}
  
void computeLPSArray(char* pat, int M, int* lps)
{
    int len = 0;
  
    lps[0] = 0;
  
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {

            if (len != 0) {
                len = lps[len - 1];

            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
  
int main()
{
    char txt[] = "ABABDABACDABABCABAB";
    char pat[] = "ABABCABAB";
    KMPSearch(pat, txt);
    return 0;
}