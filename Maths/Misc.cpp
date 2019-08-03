ll gcd(ll a, ll b)  { return (b == 0 ? a : gcd(b, a % b)); } // O(log(max(a,b)))
ll lcm(ll a, ll b){ return ((a*b) / gcd(a, b)); } // O(log(max(a,b)))

ll modInverse(ll a, ll m) // O(logm)
{
    return power(a,m-2,m);
}

ll nCr(ll n, ll r) // O(r) - Call the function as nCr(n,min(r,n-r)) for better performance
{
    if(n<r) return 0;
    if(r==0) return 1;
    return n*nCr(n-1,r-1)/r;
}

// Factorization - O(sqrt(n))

vector<ll>factors;
void GetFactors(ll n){
	for (int i = 1; i*i <= n; i++) {
		if (n%i == 0) {
			if (i != n / i)
				factors.push_back(i), factors.push_back(n / i);
			else
				factors.push_back(i);
		}
	}
}

//Mod of very large numbers - O(n)
//rule: xy (mod a) ≡ ((x (mod a) * y) (mod a))
 
ll mod(string num)
{
    int res = 0;
    for (int i = 0; i < num.size(); i++)
         res = (res*10 + num[i] - '0') %mod;
    return res;
}

// Derangements - O(n)

ll fact(int n)
{
    ll ret = 1;
    for(int i=n;i>1;i--) ret = ret* 1LL * i;
    return ret;
}

ll pww(ll p){return p&1 ? -1 : 1;}

ll Derangement(ll n)
{
    ll tmp = fact(n), sum=0;
    for(int i=0;i<=n;i++) sum+= (pww(i) * tmp) / fact(i);
    return sum;
}

// isPowerOfTwo - O(1)

bool isPowerOfTwo(ll x) {return x && (!(x&(x-1)));}