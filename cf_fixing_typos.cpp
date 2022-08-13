#include<bits/stdc++.h>
using namespace std;
#define mod int(1e9+7)
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false); 
    
    string s;
    cin>>s;
    int n = s.size();

    int t=0;
    char prev;
    int count=0;
    int wcount=1,prevcountw=0;
    for (int i = 1; i < s.size(); i++)
    {
        if(s[i] == s[i-1]){
            wcount++;
        }
        else {
            prevcountw = wcount;
            wcount =1;
        }
        // cout<<" wcount and prevcount is "<<wcount<<" "<<prevcountw<<endl;
        if(wcount>2){
            s.erase(s.begin()+i);
            wcount--;
            i--;
        }
        else if(prevcountw >= 2 && wcount == 2){

            s.erase(s.begin()+i);
            wcount--;
            i--;

        }

    }
    // cout<<"the answer is ";
    cout<<s;

    cout<<endl;
    return 0;
}