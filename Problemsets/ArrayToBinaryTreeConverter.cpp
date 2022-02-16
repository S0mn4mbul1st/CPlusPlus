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

struct TreeNode {
	  int val;
	  TreeNode *left;
	  TreeNode *right;
	  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};
	

	void createTree(TreeNode* node, int i, vector<string>& arr) {
	  if (node != nullptr) {
	    if (2 * i + 1 < arr.size()) {
	      if (arr[2 * i + 1] == "null")
	        node->left = nullptr;
	      else
	        node->left = new TreeNode(stoi(arr[2 * i + 1]));
	      createTree(node->left, 2 * i + 1, arr);
	    }
	

	    if (2 * i + 2 < arr.size()) {
	      if (arr[2 * i + 2] == "null")
	        node->right = nullptr;
	      else
	        node->right = new TreeNode(stoi(arr[2 * i + 2]));
	      createTree(node->right, 2 * i + 2, arr);
	    }
	  }
	}
	

	TreeNode* levelOrderCreateTree(vector<string>& arr) {
	  if (arr.size() == 0)
	    return nullptr;
	  TreeNode *head = new TreeNode(stoi(arr[0]));
	  createTree(head, 0, arr);
	  return head;
	}
	

	int main() {
	
	  vector<string> arr = { "1", "2", "3", "4", "5" };
	  TreeNode* node = levelOrderCreateTree(arr);
	  return 0;
    }