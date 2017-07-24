#include<bits/stdc++.h>
#include<conio.h>
#include <windows.h>
//#include <iostream>
using namespace std;

int X=4;
int Y=4;
int mat[10][10];

int random_2or4()
{
    int x=(rand()%4);
    if(x<=2)
    {
        return 2;
    }
    else
    {
        return 4;
    }

}
int random_pos()                                                        //Generate random values for program
{
    return(rand()%X);
}

void show_mat()
{
    for(int i=0;i<X;i++)
    {
        for(int j=0;j<Y;j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool no_collion(int x,int y)
{
    if(mat[x][y]!=0)
    {
        return false;
    }
    else
        return true;
}
bool swamp()
{
    int x,y,count=0;
    do
    {
        x=random_pos();
        y=random_pos();
        count++;
    }while(!(no_collion(x,y)) && count<=100);
    if(count>100)
    {
        return false;
    }
    else
    {
        cout<<"value of x and y is "<<x<<"  "<<y<<endl;
        mat[x][y]=random_2or4();
        return true;
    }
}
void move_up()
{
    for(int i=1;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            int I=i,J=j;
            if(mat[i][j]!=0)
            {
                while(mat[I-1][J]==0 && I!=0)
                {
                    mat[I-1][J]=mat[I][J];
                    mat[I][J]=0;
                    I--;
                }
                if(mat[I-1][J]==mat[I][J])
                {
                    mat[I-1][J]=mat[I][J]+mat[I][J];
                    mat[I][J]=0;
                }
            }
        }
    }
}
void move_down()
{
    for(int i=3;i>=0;i--)
    {
        for(int j=0;j<4;j++)
        {
            int I=i,J=j;
            if(mat[i][j]!=0)
            {
                while(mat[I+1][J]==0 && I!=3)
                {
                    mat[I+1][J]=mat[I][J];
                    mat[I][J]=0;
                    I++;
                }
                if(mat[I+1][J]==mat[I][J])
                {
                    mat[I+1][J]=mat[I][J]+mat[I][J];
                    mat[I][J]=0;
                }
            }
        }
    }
}
void move_left()
{
    for(int i=0;i<4;i++)
    {
        for(int j=1;j<4;j++)
        {
            int I=i,J=j;
            if(mat[i][j]!=0)
            {
                while(mat[I][J-1]==0 && J!=0)
                {
                    mat[I][J-1]=mat[I][J];
                    mat[I][J]=0;
                    J--;
                }
                if(mat[I][J-1]==mat[I][J])
                {
                    mat[I][J-1]=mat[I][J]+mat[I][J];
                    mat[I][J]=0;
                }
            }
        }
    }
}
void move_right()
{
    for(int i=0;i<4;i++)
    {
        for(int j=3;j>=0;j--)
        {
            int I=i,J=j;
            if(mat[i][j]!=0)
            {
                while(mat[I][J+1]==0 && J!=3)
                {
                    mat[I][J+1]=mat[I][J];
                    mat[I][J]=0;
                    J++;
                }
                if(mat[I][J+1]==mat[I][J])
                {
                    mat[I][J+1]=mat[I][J]+mat[I][J];
                    mat[I][J]=0;
                }
            }
        }
    }
}
void movement(char n)
{
    switch(n)
    {
    case 'w':move_up();
        break;
    case 's':move_down();
        break;
    case 'a':move_left();
        break;
    case 'd':move_right();
        break;
    }

}
int main()
{
    char n;
    for(;;)
    {
        if(!swamp())
        {
            cout<<"\nGame over";
            return 0;
        }
        show_mat();
        cout<<endl;
        while(!kbhit())
        {
            n=getch();
            break;
        }
        movement(n);
    }
}
/*  to add:-
1. no swamp for no movement

*/
