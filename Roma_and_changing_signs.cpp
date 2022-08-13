#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll rec1(int i,vector<int> &vec,int k,vector<vector<vector<int>>> &memo1,ll sum1,ll asum1){

    if(i>=vec.size()){
        return sum1;
    }

    ll ct =0,nct;

    if(memo1[i][k][asum1] !=-11 ){
        cout<<"#"<<endl;
        cout<<i<<" "<<k<<" "<<asum1<<endl;
        cout<<memo1[i][k][asum1];
        cout<<endl;
        return memo1[i][k][asum1];
    }
    ll h =k;
    if(k>0){

        vec[i]*=-1;
        // ct = vec[i]+rec1(i+1,vec,k-1,memo,sum1);
        ct = rec1(i,vec,k-1,memo1,sum1+(2*vec[i]),asum1+abs(vec[i]));
        vec[i]*=-1;

    }

    nct = rec1(i+1,vec,k,memo1,sum1,asum1);

    return memo1[i][k][asum1]=max(nct,ct);
    // cout<<"###### /"<<max(nct,ct)<<endl;
    // return max(nct,ct);

}
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> vec(n);
    ll negcount =0 ;
    ll sum1=0;
    ll absum=0;

    for (int i = 0; i < n; i++)
    {
        cin>>vec[i];
        sum1+=vec[i];
        absum+=abs(vec[i]);
        if(vec[i]<=0) negcount++;
    } 
    vector<vector<int>> memo(n+1,vector<int>(k+1,-1));
    vector<vector<vector<int>>> memo1(n+1,vector<vector<int>> (k+1,vector<int> (absum+1,-11)));

    for(auto v:memo1){
        for(auto x: v){
            for(auto y:x){
                cout<<y<<" ";
            }cout<<endl;
        }
        cout<<"###########"<<endl;
    }

    ll res =0;
    res = rec1(0,vec,k,memo1,sum1,0);

    // sort(vec.begin(),vec.end());



    cout<<res<<endl;
    cout<<endl;
    return 0;
}

    // int j=0;
    // if(negcount>=k){

    //     while(j<k){
    //         res+= -1*vec[j];j++;
    //     }
    //     while(j<n){
    //         res+=vec[j];j++;
    //     }


    // }
    // else{

        

    // }