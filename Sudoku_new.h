#include <bits/stdc++.h>
using namespace std;
class Sudoku
{
    public:
       Sudoku();
       void giveQuestion();
       void readIn();// ok
       void solve();// ok
       void changeNum(int a,int b);// ok
	   void changeRow(int a,int b);// ok
	   void changeCol(int a,int b);// ok
	   void printOut(bool isAns);// ok
	   void rotate(int n);// ok
	   void flip(int n);// ok
	   void transform();// 不知道要幹嘛，照打
	   void change();// ok
	private:
	   const int sudokuSize, maxn;
	   bool yes;
	   int d[10][10],ans[10][10], num_ans;
	   vector<int> X,Y;
	   bool check();
	   void dfs(int index);
};

