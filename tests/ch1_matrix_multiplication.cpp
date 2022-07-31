/*
 * Created by me on 16-02-2022.
 */
#include <bits/stdc++.h>
#define ll long long
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
//template <typename T>
//class matrix{
//public:
//    ll row,col;
//    vector<vector<T>> mat;
//
//    matrix(ll row,ll col, vector<vector<T>> mat){
//        this->row=row;
//        this->col=col;
//        this->mat=mat;
//    }
//
//
//    vector<vector<T>> matrix_multiplication(vector<vector<T>> mat1,vector<vector<T>> mat2){
//        vector<vector<T>> ans(mat1.size(),vector<T>(mat2[0].size()));
//        if(mat1[0].size()!=mat2.size()){
//            cout<<"error: mismatches in dimensions of the matrices"<<endl;
//        }else{
//            for (ll i = 0; i < mat1.size(); i++)
//            {
//                for (ll j = 0; j < mat2[0].size(); j++)
//                {
//                    ans[i][j] = 0;
//                    for (ll x = 0; x < mat1[0].size() ; x++)
//                    {
//                        ans[i][j]+= (mat1[i][x] * mat2[x][j])%t9p7;
//                        ans[i][j]%=t9p7;
//                    }
//                }
//            }
//        }
//        return ans;
//    }
//
//    vector<vector<T>> matrix_binary_exponentiation(ll n){
//        vector<vector<T>> res = mat,a=mat;
//        n--;
//
//        while (n > 0) {
//            if (n & 1)
//                res =matrix_multiplication(res,a);
//            a=matrix_multiplication(a,a);
//            n >>= 1;
//        }
//        return res;
//    }
//
//
//};

/*
 * Multiply two matrices
 * parameters: 2 matrices as 2D vectors
 * returns: Resultant matrix
 */
template <typename T>
vector<vector<T>> matrix_multiplication(vector<vector<T>> mat1,vector<vector<T>> mat2){
    //dimensions: mat1  (m1_row x m1_col)
    //            mat2  (m2_row x m2_col)
    ll m1_row=mat1.size();      // no of rows in first matrix i.e. mat1
    ll m1_col=mat1[0].size();   // no of columns in first matrix i.e. mat1
    ll m2_row=mat2.size();      // no of rows in second matrix i.e. mat2
    ll m2_col=mat2[0].size();   // no of columns in second matrix i.e. mat2

    //initializing resulting matrix of dimension: (m1_row x m2_col)
    vector<vector<T>> ans(m1_row,vector<T>(m2_col,0));
    if(m1_col!=m2_row){//checking if multiplication is possible
        cout<<"Can not perform multiplication: mismatches in dimensions"<<endl;
    }else{
        for (ll i = 0; i < m1_row; i++)//iterating over rows of resulting matrx
        {
            for (ll j = 0; j < m2_col; j++)//iterating over rows of resulting matrix
            {
                //generating single elemets of the resulting matrix ans[i][j]
                for (ll x = 0; x < mat1[0].size() ; x++)
                {
                    ans[i][j]+= (mat1[i][x] * mat2[x][j])%t9p7;
                    ans[i][j]%=t9p7;
                }
            }
        }
    }
    return ans;//returning resulting matrix
}



int main(){

    vector<vector<ll>> mat1={
            {1,2},
            {3,4},
            {5,6}
    };
    vector<vector<ll>> mat2={
            {7,8},
            {9,10},
    };

    vector<vector<ll>> result=matrix_multiplication(mat1,mat2);

    cout<<"resultant matrix is"<<endl;
    for(auto row:result){
        for(auto col:row){
            cout<<col<<" ";
        }cout<<endl;
    }

    return 0;
}
