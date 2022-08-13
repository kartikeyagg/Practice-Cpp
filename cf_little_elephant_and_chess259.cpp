#include<bits/stdc++.h>
using namespace std;
#define mod int(1e9+7)
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false); 
    char c;
    char prev = 't';
    for (int i = 0; i < 8; i++)
    {   
        prev = 't';
        for (int j = 0; j < 8; j++)
        {
            cin>>c;
            if(c == prev){
                cout<<"NO"<<endl;
                return 0;
            }
            prev = c;
        }

    }
    cout<<"YES";
    cout<<endl;
    return 0;
}