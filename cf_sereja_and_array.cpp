#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin>>vec[i];
    }
    int a,b,c;
    int y =0;
    for (int i = 0; i < m; i++)
    {
        cin>>a>>b;
        if(a == 1){

            cin>>c;
            vec[b-1] = c-y ;

        }
        else if (a == 2){
            y+=b;
        }
        else{

            // cout<<"y is "<<y<<endl;
            cout<< vec[b-1]+y<<endl;

        }
    }

    // cout<<endl;
    return 0;
}