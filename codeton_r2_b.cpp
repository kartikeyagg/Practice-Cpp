#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){

    int n,x;
    cin>>n>>x;
    // vector<int> vec(n,0);
    // for (int j = 0; j < n; j++)
    // {
    //     cin>>vec[j];
    // }
    int maxt =-1;
    int mint =1e9+1;

    int i =0,inp;
    int count=0;
    int previ = -1;
    while(i<n){

        if(previ !=i)
        {cin>>inp;
        previ = i;
        }
        if(maxt == -1){

            maxt = inp;
            mint= inp;
            count++;

        }

        maxt = max(maxt,inp);
        mint = min(mint , inp);

        if(abs(maxt-mint) > (2*x)){

            maxt = -1;
            mint = 1e9+1;

        }
        else{
            i++;
        }

    }
    // cout<<"\n#";
    cout<<count-1<<endl;

    return ;
}

int main()
{
    int t;
    cin>>t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
    

    cout<<endl;
    return 0;
}