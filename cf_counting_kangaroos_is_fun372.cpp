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
    for (int i = 0; i < n; i++)
    {
        cin>>vec[i];
    }
    sort(vec.begin(),vec.end());
    int l = n/2;
    l--;
    int h = n-1;
    int count =0;
    int firstl = 0;
    while( l>=0 && h>firstl && h>l){

        if(vec[h] >= 2* vec[l]){
            count++;
            if(count == 1){
                firstl = l;
            }
            h--;
            l--;
        }
        else{
            l--;
        }

    }
    // cout<<"ans is ";
    cout<<n - count;
    cout<<endl;
    return 0;
}