#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    string s;
    cin>>s;
    int n = s.size();
    int m;
    cin>>m;
    vector<int> vec(n,0);

    for (int i = 1; i < n; i++)
    {

        if(s[i] == s[i-1]){
            vec[i] = vec[i-1]+1;
        }
        else{
            vec[i] = vec[i-1];
        }

    }
    int a,b;
    for (int i = 0; i < m; i++)
    {
        cin>>a>>b;
        a--;
        b--;
        cout<<vec[b]-vec[a]<<endl;
    }
    
    

    cout<<endl;
    return 0;
}