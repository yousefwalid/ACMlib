const int MAX = 1e6+10;
int spf[MAX];
 
void Sieve() // O(nlogn)
{
	spf[1] = 1;
	for (int i = 2; i < MAX; i++) spf[i] = i;
	for (int i = 4; i < MAX; i += 2) spf[i] = 2;
	for (int i = 3; i < MAX; i++)
		if (spf[i] == i)
			for (int j = i; j < MAX; j += i)
				if (spf[j] == j) 
					spf[j] = i;
}