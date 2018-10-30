#include<bits/stdc++.h>

typedef long long ll;

ll pow(ll a, ll x, ll p)
{
	ll ret = 1;
	for (; x; x >>= 1)
	{
		if (x & 1)
			ret = ret * a % p;
		a = a * a % p;
	}
	return ret;
}
//p is prime && p != 2
ll solve(ll a, ll p)
{
	if (pow(a, (p - 1) / 2, p) == p - 1)
		return -1;
	ll s = p - 1;
	ll t = 0;
	for (; ~s & 1; s >>= 1)
		t++;
	ll b = 1;
	for (; pow(b, (p - 1) / 2, p) % p == 1; b++);
	ll inva = pow(a, p - 2, p);
	
	ll x = pow(a, (s + 1) / 2, p);  
	ll e = pow(a, s, p);
	for (int k = 1; k < t; k++)
	{
		if (pow(e, pow(2, t - (k + 1), p - 1), p) % p != 1)
			x = x * pow(b, (pow(2, k - 1, p - 1) * s) % (p - 1), p) % p;
		e = inva * x % p * x % p;
	}
	return x;
}
int T;
ll a, p, ans;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%lld%lld", &a, &p);
		a %= p;
		if (p == 2)
		{
			puts("1");
			continue;
		}
		ans = solve(a, p);
		if (ans == - 1)
			puts("No root");
		else if (ans < p - ans)
			printf("%lld %lld\n", ans, p - ans);
		else
			printf("%lld %lld\n", p - ans, ans);
	}
	return 0;
}
