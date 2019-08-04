// O( log(max(a,b)) )
// Returns Bezout's coeffs of the smallest
// linear combination of s.a + t.b = gcd(a,b)
pair<int,int> ExtendedEuclid(int a,int b) 
{                                         
    if(b==0)
        return {1,0};
    pair<int, int> p = ExtendedEuclid(b,a%b);
    int s = p.first, t = p.second;
    return {t, s-t * (a/b)};
}