#include<bits/stdc++.h>
using namespace std;
#define mod int(1e9+7)
#define ll long long

bool check_pallindrome(int n ,string &s){

    for (int i = 0; i <=n/2; i++)
    {
        if(s[i]!=s[n-1-i]){
            return 0;
        }
    }
    
    return 1;

}

int main()
{
    ios_base::sync_with_stdio(false); 

    // cout<<'z'-'a'<<endl;
    int n,p;
    cin>>n>>p;
    p--;
    string s;
    cin>>s;
    if(n == 1){
        cout<<"0\n";
        return 0;
    }
    if(check_pallindrome(n,s)){
        cout<<"0\n";
        return 0;
    }
    p = min(p,n-1-p);

    vector<int> diff((n+1)/2,0);
    ll sum1 =0 ;
    for (int i = 0; i <(n+1)/2; i++)
    {
        diff[i]  = abs(s[i] - s[n-1-i]);
        diff[i] = min(diff[i],(abs(26-diff[i])));
        sum1+=diff[i];
    }

    // cout<<"the diff array is "<<endl;
    // for(auto x: diff){
        
    //     cout<<x<<" ";

    // }cout<<endl;
    
    int ln1 = -1+(n+1)/2 ,rn1 = 0;

    int h = p;
    int t = p;

    while(h>=0){

        if(diff[h] != 0)
        {
            t = h;
        }

        
    h--;
    }
    h = p;
    int y = p;
    while(h<diff.size())
    {

        if(diff[h] != 0 ){
            y = h;
        }

        h++;

    }

    if(y-p<p-t)
    {
        sum1+=y-p;
        if(t<p)
        sum1+=abs(y-t);
        cout<<sum1;
    }
    else{
        sum1+=(p-t);
        if(y>p);
        sum1+=abs(y-t);
        cout<<sum1;
    }
    cout<<endl;
    return 0;
}