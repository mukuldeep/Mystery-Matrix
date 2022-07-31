/*
 * Created by mukul on 02-03-2022.
 */

#include <bits/stdc++.h>

#define O cout<<
#define I cin>>
#define El endl;
//ds
#define ll long long
#define V(x) vector<x>

//constants
#define t9p7 1000000007
using namespace std;

/*
 * matrix binary exponentiation
 * you know me huh!
    V(V(ll)) arr={{0,1},{1,1}};
    matrix<ll> mat(2,2,arr);
    V(V(ll)) res = mat.matrix_binary_exponentiation(n_pow);
    V(V(ll)) res2=mat.matrix_multiplication({{0,1}},res);

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

    //matrix multiplication
    V(V(T)) matrix_multiplication(V(V(T)) mat1,V(V(T)) mat2){
        V(V(T)) ans(mat1.size(),V(T)(mat2[0].size()));
        if(mat1[0].size()!=mat2.size()){
            O "error: mismatches in dimensions of the matrices"<<El
        }else{
            for (ll i = 0; i < mat1.size(); i++)
            {
                for (ll j = 0; j < mat1[0].size(); j++)
                {
                    ans[i][j] = 0;
                    for (ll x = 0; x < mat1[0].size() ; x++)
                    {
                        ans[i][j]+= (mat1[i][x] * mat2[x][j])%t9p7;
                        ans[i][j]%=t9p7;
                    }
                }
            }
        }
        return ans;
    }

    // matrix binary exponentiation
    V(V(T)) matrix_binary_exponentiation(ll n){
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


int main(){
    ll n;
    I n;
    V(V(ll)) arr={ //base matrix
      //curr 1 2 3
            {0,0,1},//prev 1st
            {1,0,1},//prev 2nd
            {0,1,1},//prev 3rd
    };
    V(V(ll)) ini_mat={ //starting vector
            {2,5,8}
    };
    if(n<=3){//if n less than size of
        O ini_mat[0][n-1]<<El
        return;
    }

    //effective exponent
    ll n_pow=n-3;

    //creating instance of matrix class with base matrix
    matrix<ll> mat(3,3,arr);

    //binary exponentiation of base matrix
    V(V(ll)) res = mat.matrix_binary_exponentiation(n_pow);

    //multiplying the above result with start vector
    V(V(ll)) res2 = mat.matrix_multiplication(ini_mat, res);

    //answer is the last element of the previous result
    O res2[0][2]<<El
	
	return 0;
}


