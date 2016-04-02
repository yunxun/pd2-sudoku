#include<iostream>
#include<vector>
#include<ctime>

using namespace std;

class Sudoku{
	public:
		Sudoku();
		Sudoku(const int init_map[]);
		//void initial();
		void giveQuestion();
		void readIn();
		void slove();
		void changeNum(int a, int b);
		void changeRow(int a, int b);
		void changeCol(int a ,int b);
		void rotate(int n);
		void flip(int n);//(0<=n<=1)
		void transform();
		void change();
		//void printOut(bool ans);		
		bool checkCorrect();
		
		void setmap(const int setMap[]);
		void printOut();  
		void swap(int&a,int&b);

		static const int sudokuSize = 81;
		static const int width = 3;//column width
			
	private:
		int i,j,k;
		int map[81];
		int temp;
		bool judge();
		int map1[9][9];
};
