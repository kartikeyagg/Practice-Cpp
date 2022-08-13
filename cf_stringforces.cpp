#include<bits/stdc++.h>
using namespace std;
#define ll long long

int rec1(int i, string &s, vector<int> &vec,int k,char c_prev,vector<int> &mvex){

    if(i>=s.size()){

        // cout<<"s is "<<s<<endl;
        // for(auto x:vec){
        //     cout<<x<<" ";
        // }cout<<endl;
        // int x =*min_element(vec.begin(),vec.end());
        int x =*min_element(mvex.begin(),mvex.end());
        return x;

    }
    int pvj,mxv;
    if(s[i]!='?'){
        mxv = mvex[s[i]-'a'];
        pvj = vec[s[i]-'a'];
        vec[s[i]-'a']++;
        if(c_prev !=s[i]){
            vec[s[i]-'a'] =1;
        }
        mvex[s[i]-'a'] = max(mvex[s[i]-'a'],vec[s[i]-'a']);
        int y =rec1(i+1,s,vec,k,s[i],mvex);
        vec[s[i]-'a'] = pvj;
        mvex[s[i]-'a'] = mxv;
        return y;
    }
    int res =0;
    char prev = s[i];
    for (int j = 0; j < k; j++)
    {   
        mxv = mvex[j];
        pvj = vec[j];
        vec[j]+=1;
        s[i] = j+'a';
        if(c_prev!=s[i]){
            vec[j]=1;
        }
        mvex[j] =max(mvex[j],vec[j]);
        res  = max(res,rec1(i+1,s,vec,k,s[i],mvex));
        // vec[j]-=1;
        vec[j] = pvj;
        mvex[j] = mxv;
        s[i] = prev;
    }
    

    return res;

}

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> vec(k,0);
    vector<int> mvex(k,0);
    string s;
    cin>>s;
    int res = rec1(0,s,vec,k,'#',mvex);
    cout<<res<<endl;
    cout<<endl;
    return 0;
}