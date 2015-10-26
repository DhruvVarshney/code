#include<vector>
#include<iostream>
#include<stdio.h>
using namespace std;
class Sudoku
{
	int SIZE;
	public:
	Sudoku(int n)
	{
		SIZE = n;
	}
	void printBoard(vector<vector<int> > &grid)
	{
		int n = grid.size();
		for (int row = 0; row < n; row++)
		{
			for (int col = 0; col < n; col++)
				printf("%2d", grid[row][col]);
			printf("\n");
		}
	}
	bool isFull(vector<vector<int> > &board)
	{
		int len = board.size();
		for(int i=0;i<len;i++)
			for(int j=0;j<len;j++)
				if(board[i][j]==0)
					return false;
		return true;
	}
	vector<int> getPossibilities(vector<vector<int> > &board,int i,int j)
	{
		vector<int> ans;
		vector<bool> found(15,false);
		for(int k=1;k<=SIZE;k++)
			found[k] = false;
		if(board[i][j]!=0)
			return ans;

		//horizontal check
		for(int k=0;k<SIZE;k++)
		{
			if(board[i][k]!=0)
				found[board[i][k]]=true;
		}

		//horizontal check
		for(int k=0;k<SIZE;k++)
		{
			if(board[k][j]!=0)
				found[board[k][j]]=true;
		}
		//block check
		int l=(i/3)*3,r=(j/3)*3;
		for(int x=l;x<l+3;x++)
			for(int y=r;y<r+3;y++)
				if(board[x][y]!=0)
					found[board[x][y]] = true;
		for(int k=1;k<=SIZE;k++)
			if(!found[k])
				ans.push_back(k);
		return ans;
	}
	bool solveSudoku(vector<vector<int> > &board)
	{
		if(isFull(board))
		{
			cout<<"solved successfully"<<endl;
			printBoard(board);
			return true;
		}
		int x=0,y=0;
		//find first empty value
		for(int i=0;i<SIZE;i++)
			for(int j=0;j<SIZE;j++)
				if(board[i][j]==0)
				{
					x=i,y=j;
					break;
				}

		vector<int> ans;
		//get All possible values at possition x,y
		ans = getPossibilities(board,x,y);
		for(int i=0;i<ans.size();i++)
		{
			board[x][y] = ans[i];
			if(solveSudoku(board))
				return true;
		}
		board[x][y]=0;
		return false;
	}
};
int main()
{
	#define N 9
	int grid[][9] = 
		{{0, 0, 0, 9, 0, 0, 0, 6, 8},
		{0, 0, 0, 7, 8, 0, 3, 1, 0},
		{0, 0, 0, 0, 0, 0, 4, 0, 0},
		{6, 0, 0, 0, 9, 0, 5, 0, 0},
		{1, 0, 0, 5, 0, 4, 0, 0, 2},
		{0, 0, 8, 0, 7, 0, 0, 0, 6},
		{0, 0, 1, 0, 0, 0, 0, 0, 0},
		{0, 9, 7, 0, 5, 6, 0, 0, 0},
		{3, 5, 0, 0, 0, 9, 0, 0, 0}};
	vector<vector<int> > board(N,vector<int>(N));
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
			board[i][j] = grid[i][j];
	}
	Sudoku S(N);
	S.solveSudoku(board);
	return 0;
}
