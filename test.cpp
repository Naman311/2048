#include<iostream>

using namespace std;

int te(int n)
{
    if(n==10)
    {
        return 1;
    }
    else
        return 0;

}
int main()
{
    if(te(11))
    {
        cout<<"yo"<<endl;
    }
    if(te(10))
    {
        cout<<"10"<<endl;
    }
    return 0;
}
