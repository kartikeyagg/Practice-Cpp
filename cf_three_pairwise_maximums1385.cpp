#include<bits/stdc++.h>
using namespace std;
#define mod int(1e9+7)
#define ll long long

int main()
{   

    ios_base::sync_with_stdio(false); 
    int t;
    cin>>t;
    for (int i = 0; i < t; i++)
    {
        
    
        vector<int> vec(3,0);
        vector<int> arr;
        for (int i = 0; i < 3; i++)
        {
            cin>>vec[i];
        }
        arr = vec;
        sort(vec.begin(),vec.end());

        if(vec[2]!=vec[1]){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
            if(arr[0] == arr[1]){

                // cout<<vec[0]<<" "<<arr[1]<<" "<<arr[2];
                cout<<vec[2]<<" "<<vec[0]<<" "<<vec[0];
                cout<<endl;

            }
            else if(arr[0] == arr[2]){

                cout<<vec[0]<<" "<<vec[2]<<" "<<vec[0];
                cout<<endl;


            }
            else{
                cout<<vec[0]<<" "<<vec[0]<<" "<<vec[2];
                cout<<endl;


            }

        }
    }

    cout<<endl;
    return 0;
}