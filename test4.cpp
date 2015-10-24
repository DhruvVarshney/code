#include <lvp\gui_top.h> 
#include<iostream>
#include<stdio.h>
using namespace std;
class GuiClass
{
    public:
            GuiClass();
            void GuiMouseClick(int x, int y);
            void GuiPaint();
            void GetMousePos();
            void CheckWin();
            void NextPlayer();
            void PlayGame();
            bool checkEmpty(int a,int b);
            String Title();
            char board[3][3];
            int i,j,turn;
            char play;
   private:
            int LastX;
            int LastY;
};
 
GuiClass::GuiClass()
{
     //initializes matrix to empty then sets player turn to 'O'
      for (i = 0; i < 3; i++)
            for (j = 0; j < 3; j++)
                board[i][j] = '\0';
     turn = 1;
     play = 'O';
}
void GuiClass::NextPlayer()
{
    //Controls the player turn
    if (turn == 1)
        {
            turn = 2;
            play = 'X';
        }
    else
        {
            turn = 1;
            play = 'O';
        }
}
 
 
void GuiClass::PlayGame()
{
   GetMousePos();
   //CheckWin ();
   //NextPlayer ();
}
 
bool GuiClass::checkEmpty (int a, int b)
{
        if (board[a][b] == '\0')
            return true;
        else
            return false;
}
 
void GuiClass::GetMousePos()
{
    bool empty;
   empty = checkEmpty(i,j);
   if (empty == true)
    board[i][j] = play;
   else
    {
        gotoxy(310,100); DrawText("Already occupied!");
        // NextPlayer();
      }
}
 
void GuiClass::CheckWin()
{
    if((board[0][0] == play && board[1][0] == play && board[2][0] == play) ||
    (board[0][1] == play && board[1][1] == play && board[2][1] == play) ||
    (board[0][2] == play && board[1][2] == play && board[2][2] == play) ||
    (board[0][0] == play && board[0][1] == play && board[0][2] == play) ||
    (board[1][0] == play && board[1][1] == play && board[1][2] == play) ||
    (board[2][0] == play && board[2][1] == play && board[2][2] == play) ||
    (board[0][0] == play && board[1][1] == play && board[2][2] == play) ||
    (board[0][2] == play && board[1][1] == play && board[2][0] == play))
DrawText("Player"); //x; DrawText("Wins!");
}
 
 
String GuiClass::Title()
{
    return("Tic Tac Toe~~!!!");
}
 
void GuiClass::GuiMouseClick(int x, int y)
{
    LastX = x;
   LastY = y;
}
 
void GuiClass::GuiPaint()
{
    Line(350,150,350,350); Line(450,150,450,350);
   Line(255,290,550,290); Line(255,210,550,210);
   gotoxy(210,100); DrawText("Player 1:");
   gotoxy(510,100); DrawText("Player 2:");
}
 
int main()
{
   GuiClass Start;
   Start.PlayGame();
    return 0;
}
#include <lvp\gui_bot.h>
