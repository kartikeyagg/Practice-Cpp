#include<bits/stdc++.h>
using namespace std;
#define ll long long

int gcd1(int a,int c){

    while(a>0 && c>0){

        if(a>c){
            a = a%c;
        }
        else{
            c = c%a;
        }
    }
    if(a>c) return a;
    else return c;

}

int main()
{   
    // cout<<gcd(2,4)<<endl;
    // return 0;
    int a,b,c,d;
    cin>>a>>b>>c>>d;

    float x;
    int y,z,vc;
    
    x = (float(a)*d)/(b*c);
    if(x<=1){
        // cout<<"#"<<endl;
        y = (b*c) - a*d;
        z = b*c;
        vc = gcd1(y,z);
        // cout<<"gcd is "<<vc<<endl;

        cout<<y/vc<<"/"<<z/vc<<endl;

    }
    else{
        y = (a*d) - (c*b);
        z = d*a;
        // cout<<"Y and Z are "<<y<<" "<<z<<endl;
        vc = gcd1(y,z);
        // cout<<"gcd is "<<vc<<endl;

        cout<<y/vc<<"/"<<z/vc<<endl; 
    }

    cout<<endl;
    return 0;
}