/*
 * Created by me on 25-12-2021.
 */
#include <bits/stdc++.h>
#define Sync ios_base::sync_with_stdio(false); cin.tie(nullptr);pre();ll t=1; // I t;
#define Dr int main(){Sync W(t)soln(t);return 0;}
#define Drt int cc_main(){Sync W(t)soln(t);return 0;}
#define Fi(i,s,e) for(ll i=s;i<e;i++)
#define Fa(xx,xxs) for(auto xx:xxs)
#define W(n) while(n--)
#define O cout<<
#define I cin>>
#define El endl;
//ds
#define ll long long
#define V(x) vector<x>
//constants
#define t9p7 1000000007
#define INF 100000000000000000 //1e17
using namespace std;

void pre(){

}

/*
 * matrix binary exponentiation
 *
 * //code in driver
    V(V(ll)) arr={{0,1},{1,1}}; //conversion matrix (Mat)
    matrix<ll> mat(2,2,arr);
    V(V(ll)) res = mat.matrix_binary_exponentiation(n_pow);//binary expo (Mat)^n_pow mod P
    V(V(ll)) res2=mat.matrix_multiplication({{0,1}},res);//multiplication result (Ini_Mat * (Mat)^n_pow mod P) mod P
    
 */
template <typename T>
class matrix{
public:
    ll row,col;
    V(V(T)) mat;

    matrix(ll row,ll col,V(V(T)) mat){
        this->row=row;
        this->col=col;
        this->mat=mat;
    }

    /*
     * multiply two matrices provided in parameter O(n^3)
     * return resulted matrix
     */
    V(V(T)) matrix_multiplication(V(V(T)) &mat1,V(V(T)) &mat2, ll P=t9p7){
        V(V(T)) ans(mat1.size(),V(T)(mat2[0].size()));
        if(mat1[0].size()!=mat2.size()){
            O "error: mismatches in dimensions of the matrices"<<El
        }else{
            // multiplication in O(n^3) for nxn dimension-ed matrix
            for (ll i = 0; i < mat1.size(); i++)
            {
                for (ll j = 0; j < mat1[0].size(); j++)
                {
                    ans[i][j] = 0;
                    for (ll x = 0; x < mat1[0].size() ; x++)
                    {
                        ans[i][j]+= (mat1[i][x] * mat2[x][j])%P;
                        ans[i][j]%=P;
                    }
                }
            }
        }
        return ans;
    }

    /*
     * return (Matrix)^n mod P
     */
    V(V(T)) matrix_binary_exponentiation(ll n,ll P=t9p7){
        V(V(T)) res = mat,a=mat;
        n--;
        while (n > 0) {
            if (n & 1)
                res =matrix_multiplication(res,a);
            a=matrix_multiplication(a,a);
            n >>= 1;
        }
        return res;
    }


};


void soln(ll t){
    ll m,n,k,a,b,c,u,d,l,r,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
// 0 1 1 2 3 5 8
    V(V(ll)) arr={
            {0,1},
            {1,1}
    };
    V(V(ll)) ini_mat={
            {0,1}
    };
    ll n_pow=5;

    matrix<ll> mat(2,2,arr);

    V(V(ll)) res = mat.matrix_binary_exponentiation(n_pow);
    V(V(ll)) res2=mat.matrix_multiplication(ini_mat,res);
    O res2[0][0]<<El
    //Fi(i,1,10) {

        Fa(xd, res) {
            Fa(xxd, xd) {
                O xxd << " ";
            }
            O El
        }O El
    //}


    Fa(xd, res2) {
        Fa(xxd, xd) {
            O xxd << " ";
        }
        O El
    }O El
    //}

}

Drt
