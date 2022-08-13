
#include <bits/stdc++.h>
using namespace std;
#define FAST()               \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
typedef long long ll;
const int N = 1e5 + 9;
const int mod = 1e9 + 7;
int MAX = 1e6 + 1;
 
int main()
{
    FAST();
    queue<pair<ll, ll>> q;
    q.push({0, 0});
    ll n;
    cin >> n;
    while (!q.empty())
    {
        ll val, c;
        val = q.front().first;
        c = q.front().second;
        q.pop();
        if (val >= n && c == 0)
        {
            cout << val;
            return 0;
        }
        q.push({val * 10 + 4, c + 1});
        q.push({val * 10 + 7, c - 1});
    }
}

// #include<bits/stdc++.h>
// using namespace std;
// #define mod 1e9+7
// #define ll long long

// int main()
// {
//     ios_base::sync_with_stdio(false); 
    
//     ll n;
//     cin>>n;
//     ll n1=n;
//     int l=0;
//     while(n>0){
//         n = n/10;
//         // n = n%10;
//         l++;
//     }
//     n = n1;
//     // cout<<"l is "<<l<<endl;

//     l = (l+1)/2;
//     // cout<<"l is "<<l<<endl;
//     string s;

//     for (int i = 0; i < l; i++)
//     {
//         s+='7';
//     }
//     for (int i = 0; i < l; i++)
//     {
//         s+='4';
//     }
//     n1 = stoll(s);
//     cout<<" n1 and n are "<<n1<<" "<<n<<endl;
//     if(n1<n){
//         s = s.substr(0,l)+'7'+s.substr(l,l)+'4';
//         l++;
//     }
//     cout<<"s is "<<s<<endl;
//     sort(s.begin(),s.end());
//     string s1 = to_string(n);
//     cout<<"s1 is "<<s1<<endl;
//     if(s1.size()<s.size()){
//         cout<<s<<endl;
//         return 0;
//     }
//     int ns = s.size();
//     int l1 = l; // count of 7;
//     // l is count of 4;
//     s = "";
//     int j =0;
//     int i4 = 0;
//     while(j<ns){
//         if(s1[j]<'4'){
//             break;
//         }
//         else if(s1[j] == '4' && l>0){
//             l--;
//             s+='4';
//             i4 = j;
//         }
//         else if(s1[j]<'7'){
//             l1--;
//             s+='7';
//             break;
//         }
//         else if(s1[j] == '7' && l1>0){
//             s+='7';
//             l1--;
//         }
//         else{
//             cout<<"fadsf"<<endl;
//             if(l1>0)
//                 {s+='7';
//                 swap(s[j],s[i4]);
//                 l1--;
//                 break;}
//             else{
//                 s[j-1] = '4';
//                 l--;
//                 s+= '7';
//                 swap(s[j],s[i4]);
//                 break;
//             }

//         }
//         j++;
//     }
//     for (int i = 0; i < l; i++)
//     {
//         s+='4';
//     }
//     for (int i = 0; i < l1; i++)
//     {
//         s+='7';
//     }
    
//     cout<<s<<endl;

//     cout<<endl;
//     return 0;
// }