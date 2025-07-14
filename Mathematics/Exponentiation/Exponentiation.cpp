#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=1e9+7;
int calc(int a,int b)
{
    if(b==0)
    {
        return 1;
    }
    int temp=calc(a,b/2);
    int result=(temp%M)*(temp%M);
    if(b%2==1)
    {
        result=(result%M)*(a%M);
    }
    return result;
}
main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        cout<<calc(a,b)%M<<endl;;
    }
}