#include<bits/stdc++.h>
using namespace std;
#define ll long long

 
void solve(){
	int n,k;
	cin >> n >> k;
	vector <int> v;
    int a;

	for(int i=0; i<n; i++){
		cin >> a;
		v.push_back(a);
	}
	int i=0;
	while(k>0 && v[i]<0){
		v[i] = v[i]*(-1);
		k--;
		i++;
	}
	if(k==0){
		long long int sum = accumulate(v.begin(), v.end(), 0);
		cout << sum;
		return;
	}
	else if(k%2==0){
		long long int sum = accumulate(v.begin(), v.end(), 0);
		cout << sum;
		return;
	}
	else{
		sort(v.begin(), v.end());
		long long int sum = accumulate(v.begin(), v.end(), 0);
		cout << sum-(2*v[0]);
		return;
	}
	
}
 

int main()
{   
    solve();
    

    cout<<endl;
    return 0;
}