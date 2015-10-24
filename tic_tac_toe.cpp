#include<fstream>
#include<cassert>
#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
#define SIZE    3
enum state {EMPTY=0,P1,P2};

bool isFull(vector<vector<int> > &board)
{
    for(int i=0;i<SIZE;i++)
        for(int j=0;j<SIZE;j++)
            if(board[i][j]==EMPTY)
                return false;
   return true;
}
bool gameOver(vector<vector<int> > &board,state s)
{
    //check each row 
    for(int i=0;i<SIZE;i++)
    {
        int count=0;
       for(int j=0;j<SIZE;j++)
       {
           if(board[i][j] == (int)s) 
             count++;
       }
       if(count==SIZE)
        return true;
    }
    //check each column
    for(int i=0;i<SIZE;i++)
    {
        int count=0;
       for(int j=0;j<SIZE;j++)
       {
           if(board[j][i] == (int)s) 
             count++;
       }
       if(count==SIZE)
        return true;
    }
    //check diagonal
    int count1=0,count2=0;
    for(int i=0;i<SIZE;i++)
    {
        if(board[i][i] == (int)s)
            count1++;
        if(board[i][SIZE-i-1] == (int)s)
            count2++;
    }
    if(count1==SIZE || count2==SIZE)
        return true;
    return false;
}
bool canWin(vector<vector<int> > &board,state player,state set)
{
  for(int i=0;i<SIZE;i++)
    for(int j=0;j<SIZE;j++)
       if(board[i][j] == EMPTY)
       {
            board[i][j] = player;
            if(gameOver(board,player))
            {
                board[i][j] = set;
                return true;
            }
            board[i][j] = EMPTY;
       }
  return false;
}
bool fork(vector<vector<int> > &board,state player)
{
    
   for(int i=0;i<SIZE;i++)
    for(int j=0;j<SIZE;j++)
        if(board[i][j] == EMPTY)
        {
            board[i][j] = player;
            if(canWin(board,player,EMPTY))
                return true;;
            board[i][j] = EMPTY;
        }
  return false;
}
bool optMove(vector<vector<int> > &board,state player)
{
    
   /*check if we are winning */
   if(canWin(board,player,P2))
        return true;
   /* block  if oppenent is winning*/
   if(canWin(board,P1,P2))
        return true;
    return fork(board,player);
}
void makeMove(vector<vector<int> > &board,state player)
{
   if(player == EMPTY)
   {
       retry:
       cout<<"Enter x y:"<<endl; 
       int x,y;
       cin>>x>>y;
       assert(x<=2 && y<=2);
       if(board[x][y] !=EMPTY)
       {
            cout<<"Enter at empty slot"<<endl;
            goto retry;
       }
       board[x][y] = P1;
       return;
   }
   
   if(optMove(board,player))
    return;
   // if no optimal move found then make an arbitary move
   if(board[1][1]==EMPTY)
   {
        board[1][1] = player;
        return;
   }
   for(int i=0;i<SIZE;i++)
    for(int j=0;j<SIZE;j++)
      if(board[i][j] == EMPTY)
        {
            board[i][j] =  player;
            return;
        }
  return ;
}
void printBoard(vector<vector<int> > &board)
{
  ofstream io;
  io.open("tic_tac_toe.trc",std::fstream::in | std::fstream::out | std::fstream::app);
  for(int i=0;i<SIZE;i++)
  {
    for(int j=0;j<SIZE;j++)
    {
        if(board[i][j] == EMPTY)
        {
            io<<"E  ";
            printf("E  ");
        }
        if(board[i][j] == P1)
        {
            io<<"P1 ";
            printf("P1 ");
        }
        if(board[i][j]== P2)
        {
            io<<"P2 ";
            printf("P2 ");
        }
    }
    printf("\n");
    io<<endl;
  }
    printf("\n");
  io<<endl;
  io.close();
  return;
}
bool move(vector<vector<int> > &board,state player)
{
    bool remMove = true;
    makeMove(board,player);
    if(gameOver(board,player))
    {
        printf("Game Over player %d wins\n",player);
        remMove = false;
    }
    else if(isFull(board))
    {
        printf("Game Draw\n");
        remMove = false;
    }
    printBoard(board);
    return remMove;
}
void startGame()
{
   vector<vector<int> > board(SIZE,vector<int>(SIZE)); 
   for(int i=0;i<SIZE;i++)
    for(int j=0;j<SIZE;j++)
        board[i][j] = EMPTY;
   state turn = P1;
   while(move(board,turn))
   {
        if(turn == P1)
            turn = P2;
        else turn = P1;
   }
   return ;
}
int main()
{
    startGame();
}
