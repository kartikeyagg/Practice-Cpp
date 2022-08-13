// #include<bits/stdc++.h>
// using namespace std;
// #define mod int(1e9+7)
// #define ll long long

// int main()
// {
//     ios_base::sync_with_stdio(false); 
//     int n,x;
//     cin>>n>>x;
//     vector<int> vec(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin>>vec[i];
//     }
//     int ind;
//     sort(vec.begin(),vec.end());
//     // cout<<"vec is "<<endl;
//     // for(auto x: vec){
//     //     cout<<x<<" ";
//     // }cout<<endl;
//     auto t = lower_bound(vec.begin(),vec.end(),x);
//     auto ut = upper_bound(vec.begin(),vec.end(),x);
//     if(t !=vec.end()){
//        ut--;
//     }
//     if(ut == (--vec.begin())){
//         ind= -1;
//     }
//     else{
//         ind = distance(vec.begin(),ut);
//     }
//     int flag = 0;
//     if(ind>=0 && ind<n && vec[ind]!=x ){
//         // flag = 1;
//         n++;
//         ind++;
//     }
//     int low_ind = -1e5;
//     if(t!=vec.end())
//     low_ind = distance(vec.begin(),t);

//     // cout<<"the index is "<<ind<<endl;
//     int desired_ind = ((n+1)/2)-1;
//     int mn =0 ;
//     // if(ind == desired_ind || low_ind == desired_ind){
//     // if(ind >= desired_ind && low_ind <= desired_ind){
//     if(vec[desired_ind] == x ){
//         cout<<"0"<<endl;
//         return 0;
//     }
//     if(ind > desired_ind){
//         mn = (2*(ind+1))-1;
//         cout<<mn-n+flag<<endl;
//     }
//     else{
//         int left = ind+1;
//         int right = n - (ind +1);
//         cout<<right-left+flag<<endl;
//     }
//     cout<<endl;
//     return 0;
// }
#include <cstdio>
 
int main(){
 
    long n(0), x(0); scanf("%ld %ld", &n, &x);
 
    long temp(0), left(0), equal(0), right(0);
    for(int k = 0; k < n; k++){
        scanf("%ld", &temp);
        if(temp < x){++left;}
        else if(temp == x){++equal;}
        else if(temp > x){++right;}
    }
 
    long output(0);
    if(equal == 0){output = 1; equal = 1;}
 
    if(left + equal < right){
        output += right - left - equal; 
        if((n + output)%2 == 1){--output;}
    }
    else if(left + 1 > right + equal - 1){
        output += left + 2 - right - equal; 
        if((n + output)%2 == 0){--output;}
    }
 
    printf("%ld\n", output);
 
    return 0;
}