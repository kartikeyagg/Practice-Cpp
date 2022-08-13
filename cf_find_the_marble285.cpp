// #include<bits/stdc++.h>
using namespace std;
#include<iostream>
#include<bits/stdc++.h>

int main()
{
    int n,s,t;
    cin>>n>>s>>t;

    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin>>vec[i];
        --vec[i];
    }
    s--;t--;
    
    vector<int> visited(n,0);
    int ans=0;
    int j = s;
    while(j!=t){

        if(visited[j]==1) { cout<<"-1"<<endl;return 0;}
        visited[j] =1;

        j = vec[j];
        ans++;

    }
    cout<<ans<<endl;
    cout<<endl;
    return 0;
}