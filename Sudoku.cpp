#include<iostream>
#include"Sudoku.h"

using namespace std;

Sudoku::Sudoku()
	{

		for (int i = 0 ;i<sudokuSize ;i++)
		{
			map[i]=0;
			/*cout << map[i] << " ";
			if( i % 9 == 8)
				cout <<endl;*/
		}
	}
	
void Sudoku::readIn()
	{

		for (int j = 0 ;j<sudokuSize ;j++)
		{
			int temp;
			cin >> temp;
			map[j]=temp;
			/*cout << map[j] << " ";
			if(j % 9 == 8)
				cout<<endl;
			*/	
		}
	}

void Sudoku::setmap(const int setmap[])
	{
		int i;
		for(i=0;i<sudokuSize;i++)
		{
			map[i]=setmap[i];
		}
	}

void Sudoku::printOut()
	{
		int i;
		for(int i = 0; i<sudokuSize ; i++)
		{	
			cout<<map[i];
			cout<<(((i+1)%9 == 0)?'\n':' ');
		}
	}
	
void Sudoku::giveQuestion()
	{
		int giveMap[sudokuSize]={8,0,0,0,0,0,0,0,0,
							0,0,3,6,0,0,0,0,0,
		        			0,7,0,0,9,0,2,0,0,	
		 					0,0,0,0,0,7,0,0,0,
				            0,0,0,0,4,5,7,0,0,
				            0,0,0,1,0,0,0,3,0,
				            0,0,1,0,0,0,0,6,8,
				            0,0,8,5,0,0,0,1,0,
				            0,9,0,0,0,0,4,0,0
		};
		setmap(giveMap);
		printOut();	
	
	}
	

/*void Sudoku::slove()

	{
		


 
 	}	


void Sudoku::changeNum(int a, int b)
	{
		if(a == b) return;
		int i, j;
		for(i=0; i<9; i++)
			for(j=0; j<9; j++)
			{
				if (map[i][j]==a)
					map[i][j]=b;
				else if(map[i][j]==b)
					map[i][j]=a;
			}
	
	}
*/
void Sudoku::swap(int &a, int &b)
	{
		int temp;
		temp = a;
		a = b;
		b = temp;
	}

/*
void Sudoku::changeRow(int a, int b)
	{
		if(a==b) return;
		int i,j;
		a*=3; b*=3;
		for (i=0; i<3; i++, a++, b++)
			for(j=0; j<9; j++)
				swap(map[a][j], map[b][j]);
	}

void Sudoku::chageCol(int a, int b)
	{
		if(a == b) return;
		int i, j;
		a*=width; b*=width;
		for(i=0 ; i<3; i++, a++, b++)
			for(j=0;j=9;j++)
				swap(map[j][a], map[j][b]);
	}
*/
void Sudoku::rotate(int n)
	{
		int i,j;
		for(n%=4; n>0; n--)
			for(i= 0; i<4; i++)
				for(j=0; j<5; j++)
				{
					swap(map1[i][j], map1[8-j][i]);
					swap(map1[8-j][i], map1[8-i][8-j]);
					swap(map1[8-i][8-j], map1[j][8-i]);
				}
	}
	
/*
void Sudoku::filp(int n)
	{


	}

void Sudoku::transform()
	{
		readIn();
		change();
		printOut(false);

	}

void Sudoku::change()
	{
		srand(time(NULL));
		changeNum(rand()%SudokuNum+1, rand()%SudokuNum+1);
		changeRow(rand()%3, rand()%3);
		changeCol(rand()%3, rand()%3);
		rotate(rand()%101);
		flip(rand()%2);
	}

/*void Sudoku::printOut(bool ans)
	{
		int i;
		if(!ans)
			for(i=0; i<sudokuSize; i++)
				cout << map[i] <<(i+1)%9==0?'\n':' '
		else
			for(i=0; i<sudokuSize; i++)
				cout << ans[i] <<(i+1)%9==0?'\n':' '

	}


*/
