#include<iostream>
#include<math.h>
using namespace std;
void print(int board[][9],int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
bool isValid(int board[][9],int  i, int j, int num, int n){
    //row col check
    for (int r = 0; r < n; r++)
    {
        if (board[i][r]==num || board[r][j]==num)
        {
            return false;
        }
        
    }
    //submatrix check
    int rn=sqrt(n);
    int starti=i-i%rn;
    int startj=j-j%rn;
    for (int r = starti; r < starti+rn; r++)
    {
        for (int s = startj; s < startj+rn; s++)
        {
            if (board[r][s]==num)
            {
                return false;
            }

        }
    }
    
}
bool SudokuSolver(int board[][9],int i, int j,int n){
    //Base
    if (i==n)
    {
        print(board,n);
        return true;
    }
    if (j==n)
    {
        return SudokuSolver(board,i+1,0,n);
    }
    //cell already filled
    if (board[i][j]!=0)
    {
        return SudokuSolver(board,i,j+1,n);
    }
    
    //fill cell with app no
    for (int num = 1; num <= 9; num++)
    {
        //check validity
        if(isValid(board,i,j,num,n)){
            board[i][j]=num;
            bool subAns=SudokuSolver(board,i,j+1,n);
        if (subAns)
        {
            return true;
        }
        //Backtrack
        board[i][j]=0;
        }
        
    }
    return false;
}
int main(){
    
    return 0;
}