#include <bits/stdc++.h>
using namespace std;

bool isSafe(int board[][10], int i, int j, int n)
{
        //check the column
        for(int row=0;row<i;row++)
        {
            if(board[row][j]==1)
                return false;
        }

        //check the left diagonal
        int x=i;
        int y=j;
        while(x>=0 && y>=0)
        {
            if(board[x][y]==1)
                return false;
            
            x--;
            y--;
        }

    //check the right diagonal

        x=i;
        y=j;

        while(x>=0 && y<n)
        {
            if(board[x][y]==1)
                return false;
                x--;
                y++;
        }


    return true;// this place reached if all the 

}
 
bool solveNQueen(int board[][10], int i, int n)
{       //Base Case
        if(i==n)
            {
                //print the array 
                    for(int r=0;r<n;r++)
                    {   for(int c=0;c<n;c++)
                    {
                        // cout<<board[r][c]<<" ";
                            if(board[r][c]==1)
                                cout<<"Q"<<" ";
                            else    
                                cout<<"_"<<" ";
                        
                    }
                        cout<<endl;
                    }
                    //the below 2 lines are for all solutions of N Queem
                cout<<" ans  above separator ---------------"<<endl;
                return false;

                //the below line is for the 1st solution. Comment out the previous 2 lines in that case
                // return true;
            }


    //else recursion
        for(int j=0;j<n;j++)// iterate through all the columns 
        {
            if(isSafe(board,i,j,n))
            {
                board[i][j]=1;

                bool nextQueenRakhPaye= solveNQueen(board,i+1,n);

                if(nextQueenRakhPaye) return true;

                board[i][j]=0;//backtrack done is the previous condition is false

            }
        }


    return false;// this place reached if all else fails

}




int main() {
    // cout<<"Hello World!";
int n;//n>3
cin>>n;

int board[10][10]={0};//Empty 10*10 board initialised with 0s.The size 10 is arbitrary.Change it to the max constraint.
int i=0;//0th row is passed and recursion procees row by row
solveNQueen(board,i,n);

return 0;
 
}
