#include<bits/stdc++.h>
using namespace std;
#define mod 1e9+7
#define ll long long

void solve(){
    int m;

    vector<int> ar1;
    vector<int> ar2;

    int inp;

    for (int i = 0; i < m; i++)
    {
        cin>>inp;
        ar1.push_back(inp);
    }
    for (int i = 0; i < m; i++)
    {
        cin>>inp;
        ar2.push_back(inp);
    }
    int max1 = -1;
    int max1i,max2i;
    int max2 = -1;

    for (int i = 0; i < m; i++)
    {
        if(ar1[i]>max1){
            max1 = ar1[i];
            max1i = i;
        }
        if(ar2[i]>max2){
            max2 = ar2[i];
            max2i = i;
        }

    }
    int a =0;
    if(max2 == max1){

        if(max1i>max2i){

            if(max2i >1){
                a+=2;
            }
            a+=max1i;
            
            cout<<m*2-a+max1<<endl;
            return;

        }
        else{
            if(max1i >1){
                a+=2;
            }
            a+=max1i;
            
            cout<<m*2-a+max1<<endl;
            return;

        }

    }
    

    

}

int main()
{
    ios_base::sync_with_stdio(false); 
    int t;
    cin>>t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
    

    cout<<endl;
    return 0;
}