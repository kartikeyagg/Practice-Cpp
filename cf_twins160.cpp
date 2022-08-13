#include<bits/stdc++.h>
using namespace std;
#define mod int(1e9+7)
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false); 
    
    int n;
    cin>>n;
    vector<int> vec(n);
    ll sum1=0;
    for (int i = 0; i < n; i++)
    {
        cin>>vec[i];
        sum1+=vec[i];
    }
    sort(vec.begin(),vec.end());

    int h = n-1;
    ll pl = 0;
    int count =0;
    while(pl<=sum1/2 && h>=0){

        pl+=vec[h];
        count++;
        h--;

    }
    cout<<count;
    cout<<endl;
    return 0;
}