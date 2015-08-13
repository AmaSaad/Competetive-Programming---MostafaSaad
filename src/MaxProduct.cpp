#include<set>
#include<map>
#include<list>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<complex>
#include<sstream>
#include<iostream>
#include<fstream>
#include<algorithm>
#include<numeric>
#include<utility>
#include<functional>
#include<stdio.h>
#include<assert.h>
#include<memory.h>
#include<bitset>
using namespace std;

#define all(v)              ((v).begin()), ((v).end())
#define sz(v)               ((int)((v).size()))
#define clr(v, d)           memset(v, d, sizeof(v))
#define rep(i, v)       for(int i=0;i<sz(v);++i)
#define lp(i, n)        for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)    for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)    for(int i=(j);i>=(int)(n);--i)
#define ull unsigned long long
#define ui unsigned int
#define us unsigned short

typedef long long ll;
//////  //  / / / other macros / / / / / //////////
// Input macros
#define s(n)                        scanf("%d",&n)
#define sc(n)                       scanf("%c",&n)
#define sl(n)                       scanf("%lld",&n)
#define sf(n)                       scanf("%lf",&n)
#define ss(n)                       scanf("%s",n)

// Useful constants
#define INF                         (int)1e9
#define EPS                         1e-9
#define PI 3.1415926535897932384626
// Useful container manipulation / traversal macros
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define foreach(v, c)               for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define in(a,b)                     ( (b).find(a) != (b).end())
#define pb                          push_back

// Some common useful functions
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))
#define char2Int(c) (c-'0')
#define lastEle(vec) vec[vec.size()-1]
#define SZ(x) ((int)((x).size()))
#define REMAX(a,b) (a)=max((a),(b)) // set a to the maximum of a and b
#define REMIN(a,b) (a)=min((a),(b));
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++) // traverse an STL data structure

class MaxProduct {
public:
	int k;
	int s;
	int tracker[100][100];

	void userInput() {
		printf("Enter S");
		s(s);
		printf("Enter K");
		s(k);

	}
	void solve() {
		printf("Product is: %lld\n", this->solve(s, 0));
		int remainder = s;
		lp(i,k)
		{
			int value = tracker[i][remainder];
			cout << value << "\n";
			remainder-=value;
		}
	}

	//assign optimal value at index i
	ll solve(int remainder, int i) {
		if (i == k-1) {
			tracker[i][remainder] = remainder;

			return remainder;

		}
		int max = remainder - (k-i-1);
		ll product = 1;
		ll maxProduct = 0;
		int maxJ = 0;
		for (int j = 1; j <= max; j++) {
			product = j * solve(remainder - j, i+1);
			if (product > maxProduct) {
				maxProduct = product;
				maxJ = j;
			}
		}
		tracker[i][remainder] = maxJ;
		return maxProduct;

	}

};
int main() {
	MaxProduct x;
	x.userInput();
	x.solve();
	return 0;
}

