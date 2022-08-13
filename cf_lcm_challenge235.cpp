#include <iostream>
using namespace std;
 
int main() {
    long long int n;
    long long ans;
    cin >> n;
    if(n == 2) { cout << 2 << endl; return 0; }
    else if (n == 1) { cout << 1 << endl; return 0; } 
    long long t =  n * (n-1) * (n-2);
    long long s = (n-1) * (n-2) * (n-3);
    if( n % 2 == 1) {
        ans = t;
        cout << ans << endl;
        return 0;
    }
    else {
         if(n > 5 && n %3 == 0) {
              ans = s;
              cout << ans << endl;
              return 0;
        }
        else if ( n > 5) {
             ans = n * (n-1) * (n-3);
             cout << ans << endl;
             return 0;
        }
        else {
             ans = t/2;
              cout << ans << endl;
              return 0;
        }
    }         
}