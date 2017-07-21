#include<bits/stdc++.h>
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
int main()
{
    for(;;)
    {
        show_mat();
        cout<<endl;
        if(!swamp())
        {
            cout<<"\nGame over";
            return 0;
        }

    }
}
