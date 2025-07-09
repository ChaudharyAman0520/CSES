#include<bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int row,col;
        cin>>row>>col;
        if(row>col)
        {
            if(row%2==0)
            {
                int start=row*row;
                cout<<start-col+1<<endl;
            }
            else
            {
                int start=row*(row-2)+2;
                cout<<start+col-1<<endl;
            }
        }
        else
        {
            if(col%2==0)
            {
                int start=col*(col-2)+2;
                cout<<start+row-1<<endl;
            }
            else
            {
                int start=col*col;
                cout<<start-row+1<<endl;
            }
        }
    }
}