/*
 * Created by me on 14-02-2022.
 */

#include <bits/stdc++.h>
#define Sync ios_base::sync_with_stdio(false); cin.tie(nullptr);pre();ll t=1; // I t;
#define Dr int main(){Sync W(t)soln(t);return 0;}
#define Drt int cc_main(){Sync W(t)soln(t);return 0;}
#define F(a,c) for (ll a=0;a<c; a++)
#define Fe(a,c) for(ll a=0;a<=c; a++)
#define Fi(i,s,e) for(ll i=s;i<e;i++)
#define Rfi(i,s,e) for(ll i=s;i>e;i--)
#define Fa(xx,xxs) for(auto xx:xxs)
#define Srt(x) sort(x.begin(),x.end());
#define Rsrt(x) sort(x.rbegin(),x.rend());
#define Rev(x) reverse(x.begin(),x.end());
#define W(n) while(n--)
#define Wh while
#define Il while(1)
#define Pb push_back
#define O cout<<
#define Prcn fixed<<setprecision(20)
#define I cin>>
#define El endl;
//ds
#define ll long long
#define ld long double
#define S string
#define Ch char
#define V(x) vector<x>
#define Vv(x) V(V(x))
#define Sk(x) stack<x>
#define St(x) set<x>
#define Q(x) queue<x>
#define Dq(x) deque<x>
#define P(x) pair<x,x>
#define P2(x,y) pair<x,y>
#define Mp(x,y) map<x,y>
#define Uom(x,y) unordered_map<x,y>

//functions
#define p_bin(x) if(x)O "YES"<<El else O "NO"<<El

//constants
#define t9p7 1000000007
#define INF 100000000000000000 //1e17
using namespace std;

void pre(){

}

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

vector<ll> nw;
ll n_ways_dp(ll sum){
    nw.assign(sum+5,0);
    nw[0]=1;
    for(ll x=1;x<=sum;x++){
        ll cnt=0;
        for(ll i=1;i<7;i++){
            if(x-i>=0){
                cnt+=nw[x-i];
                cnt%=t9p7;
            }
        }
        nw[x]=cnt;
        O "x("<<x<<")="<<cnt<<El
    }
    return nw[sum];
}


void soln(ll t){
    ll m,n,k,a,b,c,u,d,l,r,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    I n;
    //1 1 1 3 5 9 17 31 57 => sum of last three

    //mat multiplication 6^3=216
    //exponentiation of n = log(n)
    // total 216*log(n)
    //prev, 216*log(n)<=6*n
    //   =>  36*log(n)<=n
    //n>295

    V(V(ll)) arr={
            {0,0,0,0,0,1},
            {1,0,0,0,0,1},
            {0,1,0,0,0,1},
            {0,0,1,0,0,1},
            {0,0,0,1,0,1},
            {0,0,0,0,1,1}

    };
    V(V(ll)) ini_mat={
            {1,2,4,8,16,32}
    };
    if(n<=6){
        O ini_mat[0][n-1]<<El
        return;
    }
    //n_ways_dp(20);
    ll n_pow=n-6;


//    Fi(i,1,10) {
//        n_pow=i;
        matrix<ll> mat(6,6,arr);
        V(V(ll)) res = mat.matrix_binary_exponentiation(n_pow);
        V(V(ll)) res2 = mat.matrix_multiplication(ini_mat, res);
       // O res2[0][0] << El
//        O "res"<<El
//        Fa(xd, res) {
//            Fa(xxd, xd) {
//                O xxd << " ";
//            }
//            O El
//        }//O El
//        O "res2"<<El
//        Fa(xd, res2) {
//            Fa(xxd, xd) {
//                O xxd << " ";
//            }
//            O El
//        }O El
    //}
        O res2[0][5]<<El

}

Dr
