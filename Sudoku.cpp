#include "Sudoku.h"

Sudoku::Sudoku():sudokuSize(9), maxn(3){
	X.clear();
	Y.clear();
	yes = false;
	num_ans = 0;
}

void Sudoku::giveQuestion(){
	memset(d,0,sizeof(d));
	for(int i=1; i<=sudokuSize; i++)
		for(int j=1; j<=sudokuSize; j++){
			X.push_back(i);
			Y.push_back(j);
		}
	dfs(0);
	memcpy(d, ans, sizeof(ans));
	for(int i=1;i<=sudokuSize; i++){
		for(int j=1; j<=sudokuSize; j++){
			if(rand()%2==0) printf("%d ",d[i][j]);
			else printf("0 ");
		}
		printf("\n");
	}
}

void Sudoku::readIn(){
	for(int i=1; i<=sudokuSize; i++)
		for(int j=1; j<=sudokuSize; j++){
			scanf("%d",&d[i][j]);
			if(d[i][j] == 0){
				X.push_back(i);
				Y.push_back(j);
			}
		}
}

void Sudoku::changeNum(int a,int b){
	for(int i=1; i<=sudokuSize; i++)
		for(int j=1; j<=sudokuSize; j++){
			if(d[i][j] == a) d[i][j] = b;
			else if(d[i][j] == b) d[i][j] = a;
		}
}

void Sudoku::changeRow(int a,int b){
	int temp;
	for(int i=1; i<=maxn; i++)
		for(int j=1; j<=sudokuSize; j++){
			temp= d[a*3+i][j];
			d[a*3+i][j] = d[b*3+i][j];
			d[b*3+i][j] = temp;
		}
}

void Sudoku::changeCol(int a,int b){
	int temp;
	for(int i=1; i<=maxn; i++)
		for(int j=1; j<=sudokuSize; j++){
			temp= d[j][a*3+i];
			d[j][a*3+i] = d[j][b*3+i];
			d[j][b*3+i] = temp;
		}
}

void Sudoku::rotate(int n){
	if(!n) return;
	n %= 4;
	while(n--){
		int temp[10][10];
		for(int i=1; i<=sudokuSize; i++){
			for(int j=1; j<=sudokuSize; j++)
				temp[i][j] = d[sudokuSize-j+1][i];
		}
		memcpy(d, temp, sizeof(d));
	}
}

void Sudoku::flip(int n){
	int temp;
	if(n==0){// vertically A|B
		for(int i=1; i<=sudokuSize/2; i++)
			for(int j=1; j<=sudokuSize; j++){
				temp = d[j][i];
				d[j][i] = d[j][sudokuSize-i+1];
				d[j][sudokuSize-i+1] = temp;
			}
	}
	else{
		for(int i=1; i<=sudokuSize/2; i++)
			for(int j=1; j<=sudokuSize; j++){
				temp = d[i][j];
				d[i][j] = d[sudokuSize-i+1][j];
				d[sudokuSize-i+1][j] = temp;
			}
	}
}

void Sudoku::transform(){
	readIn();
	change();
	printOut(false);
}

void Sudoku::change(){
	srand(time(NULL));
	changeNum(rand()%sudokuSize+1, rand()%sudokuSize+1);
	changeRow(rand()%3, rand()%3);
	changeCol(rand()%3, rand()%3);
	rotate(rand()%101);
	flip(rand()%2);
}

void Sudoku::solve(){
	if(X.size()==0 && check()){
		memcpy(ans, d, sizeof(ans));
		printOut(true);
	}
	else if(X.size()==0) printf("0\n");
	else dfs(0);

	if(X.size()){
		if(yes==false)	printf("0");
		else if(num_ans == 1) printOut(true);
		else printf("2\n");
	}
}

void Sudoku::printOut(bool isAns){
	if(isAns){
		printf("1\n");
		for(int i=1; i<=sudokuSize; i++){
			for(int j=1; j<=sudokuSize; j++)
				printf("%d ",ans[i][j]);
			printf("\n");
		}
	}
	else{
		for(int i=1; i<=sudokuSize; i++){
			for(int j=1; j<=sudokuSize; j++)
				printf("%d ",d[i][j]);
			printf("\n");
		}
	}
}

bool Sudoku::check(){
	bool used[3][10][10];
	memset(used,0,sizeof(used));
	for(int i=1; i<=maxn*maxn; i++)
		for(int j=1; j<=maxn*maxn; j++)if(d[i][j]){
			int ix = i/maxn + (i%maxn!=0? 1:0) - 1;
			int iy = j/maxn + (j%maxn!=0? 1:0) - 1;
			if(used[0][i][d[i][j]]) return false;
			if(used[1][j][d[i][j]]) return false;
			if(used[2][ix*3+iy][d[i][j]]) return false;
			used[0][i][d[i][j]] = 1;
			used[1][j][d[i][j]] = 1;
			used[2][ix*3+iy][d[i][j]] = 1;
		}
	return true;
}

void Sudoku::dfs(int index){
	if(num_ans>=2) return;
	if(index==X.size()){
		memcpy(ans, d, sizeof(d));
		num_ans++;
		yes = 1;
		return;
	}
	int x,y;
	x = X[index];
	y = Y[index];
	for(int i=1; i<=sudokuSize; i++){
		d[x][y] = i;
		if(!check()){
			d[x][y] = 0;
			continue;
		}
		dfs(index+1);
		d[x][y] = 0;
	}
}

