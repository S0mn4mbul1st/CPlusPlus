/*
Design the basic function of Excel and implement the function of the sum formula.

Implement the Excel class:

Excel(int height, char width) Initializes the object with the height and the width of the sheet. The sheet is an integer matrix mat of size height x width with the row index in the range [1, height] and the column index in the range ['A', width]. All the values should be zero initially.
void set(int row, char column, int val) Changes the value at mat[row][column] to be val.
int get(int row, char column) Returns the value at mat[row][column].
int sum(int row, char column, List<String> numbers) Sets the value at mat[row][column] to be the sum of cells represented by numbers and returns the value at mat[row][column]. This sum formula should exist until this cell is overlapped by another value or another sum formula. numbers[i] could be on the format:
"ColRow" that represents a single cell.
For example, "F7" represents the cell mat[7]['F'].
"ColRow1:ColRow2" that represents a range of cells. The range will always be a rectangle where "ColRow1" represent the position of the top-left cell, and "ColRow2" represents the position of the bottom-right cell.
For example, "B3:F7" represents the cells mat[i][j] for 3 <= i <= 7 and 'B' <= j <= 'F'.
Note: You could assume that there will not be any circular sum reference.

For example, mat[1]['A'] == sum(1, "B") and mat[1]['B'] == sum(1, "A").
 

Example 1:

Input
["Excel", "set", "sum", "set", "get"]
[[3, "C"], [1, "A", 2], [3, "C", ["A1", "A1:B2"]], [2, "B", 2], [3, "C"]]
Output
[null, null, 4, null, 6]

Explanation
Excel excel = new Excel(3, "C");
 // construct a 3*3 2D array with all zero.
 //   A B C
 // 1 0 0 0
 // 2 0 0 0
 // 3 0 0 0
excel.set(1, "A", 2);
 // set mat[1]["A"] to be 2.
 //   A B C
 // 1 2 0 0
 // 2 0 0 0
 // 3 0 0 0
excel.sum(3, "C", ["A1", "A1:B2"]); // return 4
 // set mat[3]["C"] to be the sum of value at mat[1]["A"] and the values sum of the rectangle range whose top-left cell is mat[1]["A"] and bottom-right cell is mat[2]["B"].
 //   A B C
 // 1 2 0 0
 // 2 0 0 0
 // 3 0 0 4
excel.set(2, "B", 2);
 // set mat[2]["B"] to be 2. Note mat[3]["C"] should also be changed.
 //   A B C
 // 1 2 0 0
 // 2 0 2 0
 // 3 0 0 6
excel.get(3, "C"); // return 6
*/
/*I have put detailed explanation in the comments. A vector<vector> is used for the Excel. Here I just want to highlight two things.

When a cell changes, all the sum related have to update. So a forward link from a cell to all the cells with it in the sum is required. Because a cell may be used for multiple times in the sum due to overlapping ranges, unordered_map<cell, unordered_map<cell, weight>> is used. The weight could improve the efficiency in the worst case.
When reset a cell's value, or reassign a new sum range to it, the cells contribute to its sum will change. So a backward link from this cell to all those cells is necessary. unordered_map<cell, unordered_set> is sufficient.
The excel is small, at most 26 by 26. So we can use row*26+col as the key of a cell, which is int.*/

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

class Excel {
public:
    Excel(int H, char W) {
        // initialization. Because r starts from 1, I used H+1 instead of H.
        Exl = vector<vector<int>> (H+1, vector<int>(W-'A'+1, 0));
        fward.clear();
        bward.clear();
    }
    
    void set(int r, char c, int v) {
        int col = c-'A', key = r*26+col;
        // update its value and all the sum related
        update(r, col, v);
        // This is a reset, so break all the forward links if existing
        if (bward.count(key)) {
            for (int k:bward[key]) {
                fward[k].erase(key);
            }
            bward[key].clear();
        }
    }
    // update a cell and all the sum related, using BFS
    // weights are used to improve efficiency for overlapping ranges
    void update(int r, int col, int v) {
        int prev = Exl[r][col];
        Exl[r][col] = v;
        // myq is keys for cells in next level, and update is the increment for each cell
        queue<int> myq, update;
        myq.push(r*26+col);
        update.push(v-prev);
        while (!myq.empty()) {
            int key = myq.front(), dif = update.front();
            myq.pop();
            update.pop();
            if (fward.count(key)) {
                for (auto it = fward[key].begin(); it != fward[key].end(); it++) {
                    int k = it->first;
                    myq.push(k);
                    update.push(dif*(it->second));
                    Exl[k/26][k%26] += dif*(it->second);
                }
            }
        }
    }
    
    int get(int r, char c) {
        return Exl[r][c-'A'];
    }
    
    int sum(int r, char c, vector<string> strs) {
        // this is another reset, so break all the forward links
        int col = c-'A', key = r*26+col, ans = 0;
        if (bward.count(key)) {
            for (int k:bward[key]) {
                fward[k].erase(key);
            }
            bward[key].clear();
        }
        // get the sum over multiple ranges
        for (string str:strs) {
            int p = str.find(':'), left, right, top, bot;
            left = str[0]-'A';
            right = str[p+1]-'A';
            if (p == -1) 
                top = stoi(str.substr(1));
            else
                top = stoi(str.substr(1, p-1));
            bot = stoi(str.substr(p+2));
            for (int i = top; i <= bot; ++i) {
                for (int j = left; j <= right; ++j) {
                    ans += Exl[i][j];
                    fward[i*26+j][key]++;
                    bward[key].insert(i*26+j);
                }
            }
        }
        // update this cell and all the sum related
        update(r, col, ans);
        return ans;
    }
private:
    // The key of a cell is defined as 26*row+col, which is int;
    // fward links a cell to all the cells which use it for sum, and it may be used for 
    // multiple times due to overlap ranges, so another map is used for its weight
    // bward links a cell to all the cells that contribute to its sum. When reset its value,
    // or reassign a new sum range to it, we need disconnect the forward link of those cells to it. 
    unordered_map<int, unordered_map<int, int>> fward;
    unordered_map<int, unordered_set<int>> bward;
    vector<vector<int>> Exl;
};


int main(){


    return 0;
}