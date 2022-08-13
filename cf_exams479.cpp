#include<bits/stdc++.h>
using namespace std;
#define mod int(1e9+7)
#define ll long long

bool cmp(pair<int,int> &a, pair<int,int>&b){

    if(a.first == b.first){

        return a.second<b.second;
    }
    return a.first<b.first;

}

int main()
{
    ios_base::sync_with_stdio(false); 
    int a,b;
    vector<pair<int,int>> vec;
    int n;
    cin>>n;
    for (int i = 0; i <  n; i++)
    {
        cin>>a>>b;
        vec.push_back({a,b});
    }

    sort(vec.begin(),vec.end(),cmp);
    // cout<<"vec is "<<endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<vec[i].first<<" "<<vec[i].second<<endl;
    // }
    

    int mint = 1e9,maxt = -1;

    for (int i = 0; i < n; i++)
    {
        a = min(vec[i].first,vec[i].second);
        if(!(a>=maxt)){
            a = max(vec[i].first,vec[i].second);
        }
        maxt = max(maxt,a);
    }
    
    // cout<<"ans is ";
    cout<<maxt;

    cout<<endl;
    return 0;
}