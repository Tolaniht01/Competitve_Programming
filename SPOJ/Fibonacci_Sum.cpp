#include <vector>
#define REP(i,n) for (int i = 1; i <= n; i++)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<vector<ll> > matrix;
const ll MOD = 1000000007;
const int K = 2;

// computes A * B
matrix mul(matrix A, matrix B)
{
    matrix C(K+2, vector<ll>(K+2));
    REP(i, K+1) REP(j, K+1) REP(k, K+1)
        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
    return C;
}

// computes A ^ p
matrix pow(matrix A, int p)
{
    if (p == 1)
        return A;
    if (p % 2)
        return mul(A, pow(A, p-1));
    matrix X = pow(A, p/2);
    return mul(X, X);
}

// returns the N-th term of Fibonacci sequence
int fib(int N)
{
    // create vector F1
    
    
    vector<ll> F1(K+2);
    F1[1] = 0;
    F1[2] = 1;
    F1[3]=1;

    // create matrix T
    matrix T(K+2, vector<ll>(K+2));
    T[1][1] = 1, T[1][2] = 1;T[1][3] = 0;
    T[2][1] = 0, T[2][2] = 0;T[2][3] = 1;
	T[3][1] = 0, T[3][2] = 1;T[3][3] = 1;
    // raise T to the (N-1)th power
  
    if (N == 1)
    {
        return 1;
    }
        
      
   
    T = pow(T, N);

	
    // the answer is the first row of T . F1
    ll res = 0;
    REP(i, K+1)
        res = (res + T[1][i] * F1[i]) % MOD;
    return res;
}

int main()
{
	int t,p=1;
	ll m,n;
	cin>>t;
	while(p<=t)
	{
		p++;
		cin>>m>>n;
		ll res1=0,res2=0;
		if(n>=1)
		res1=fib(n);
		if (m>1)
		res2=fib(m-1);
		//cout<<res1<<" "<<res2<<endl;
		if(res1-res2<0)
		{
		    cout<<res1-res2+MOD<<endl;
		}
		else
		{
		cout<<(res1-res2)%MOD<<endl;
		}
	
		
		
	}
	
	return 0;
}
