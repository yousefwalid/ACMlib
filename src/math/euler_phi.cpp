// Theorem: a^phi(b) % b = 1, if a,b are coprimes (gcd(a,b) == 1)
ll Phi(ll n) // O(sqrt(n)), returns Euler Phi of n
{
    ll result = n;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i == 0)
            result -= result/i;
        while(n%i==0)
            n/=i;
    }
    if(n>1)
        result -=result/n;
    return result;
}


ll phi[N];
void EulerTotient() // O(nlog(logn)), generates all Euler Phi's to N
{
    for(int i=0;i<N;i++) phi[i] = i;
    for(int i=2;i<N;i++)
        if(phi[i] == i)
            for(int j=i;j<N;j+=i) phi[j] -= phi[j]/i;
}