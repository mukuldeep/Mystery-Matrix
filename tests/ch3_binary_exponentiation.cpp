/*
 * Created by mukul on 17-02-2022.
 */
#include <bits/stdc++.h>
#define ll long long
#define t9p7 1000000007
using namespace std;

/*
 * power by binary exponentiaion
 * parameters: base, exponent, mod(default value 10^9+7)
 * returns: power a^b mod p
 */
ll power_by_binary_exponentiation(ll a,ll b, ll p=t9p7){
    ll result=1;
    a%=p;//modulus the base
    if(b==0)return 1; //in case exponent is 0
    if(a==0)return 0; //in case base is 0
    while(b){
        //if current lowest significant bit is set
        if(b&1)
            //considering current power of 2 worth multiply
            result=(result*a)%p;
        b>>=1;//right shifting b, same as inter division by 2
        //squaring a to get a^(next power of 2)
        a=(a*a)%p;
    }
    return result;//returning result
}


int main(){
    cout<<power_by_binary_exponentiation(1233473443423,78687921793871283);
    return 0;
}
