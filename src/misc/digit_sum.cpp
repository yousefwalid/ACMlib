int DigitSum(ll x)
{
	int ret = 0;
	while(x) ret+=(x%10),x/=10;
	return ret;
}

// DigitSum(a+b) = DigitSum(DigitSum(a)+DigitSum(b))
// DigitSum(a-b) = DigitSum(DigitSum(a)-DigitSum(b))
// DigitSum(a*b) = DigitSum(DigitSum(a)*DigitSum(b))
