#include <bits/stdc++.h>
using namespace std;
 
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define RFOR(i,b,a) for (int i = (b) - 1; i >= (a); i--)
#define ITER(it,a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a,value) memset(a, value, sizeof(a))
 
#define SZ(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair
 
typedef long long Int;
typedef vector<int> VI;
typedef pair<int, int> PII;
 
const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000;
const Int LINF = INF * (Int) INF;
const int MAX = 200007;
const int MOD = 1000000007;

string s = "1111111111111111111111111100000000000011111111111111111111111111111111111111111111111100000000000000000000111111111111111111111111111111111111111111000000000000000000000000111111111111111111111111111111111111101100000000000000000000000000011111111111111111111111111111111100111000000000000000000000000000111111111111111111111111111111000001100000000000000000000000000000111111111111111111111111111000000111000000000000000000000000000001111111111111111111111110000000001100000000000000000000000000000001111111111111111111110000000000111000000000000000000000000000000011111111111111111110000000000001100000000000000000000100000000000111111111111111110000000000000111010000000000000000011110000000001111111111111110000000000000001101011101000000000000010000000000011111111111111000000000000000110111011100100000000011111000000001111111111111000000000000000001110101011011000000000001000000000011111111111000000000000000001101000100111000000000011110100000000111111111110000000000000000100001011010110000000001001110000000011111111101100000000000000111111100001001100000000110001110000000111111100011000000000000010101000101110010100000001101101100000001111110100000000000000011000111110100011110000000010100011000000111111011100000000000011001001000000101010000000011000101000000011111001011000000000001001110000111111101100000000111110000000000111101100000000000000111101011010101000010000000110101101000000011100010101000000000001000111000000110111000000010000010110000000111111011100000000001110110001011000010100000001101100010000000011000001010000000000101001010100111111000000000010100111110000001101111101000000000000110001111010001000000000001111001001000000100100010000000000000001101101000011110000110001100101110100000001110101110000000000000010100001011000000001000010111100010000000000010001000000000000001111010100110000011100111001010100000000011101110110000000000000010111111010011100100110110000011000000000010100010000000000000000000010000000100111110001011011000000000011110111000000000000000000011111101011110101110001000100000000000010010000000000000000000000001000111010010001101111011100000000101011010000000000000000000110001110101100000010000111011000000011100001000000000000000000110001100000100000011101110001000000000000101100000000000000000001110100110000000000010010011100000001110110100000000000000000011101111110000000000101111101000000000001010011100000000000000111000101000000000000011101000111000000010101111010000000000001110001110111010000000000100110110100000011011101000000000000110001110001000111000000000110110000010000001100000001000000000010010001110001001000000000001000010111000000110111101100000000001111110001101111111000000000111011001000000011110011100000000000010001010000100010100000000110101000000000011110011000100000000011010001011000100011000000110011111000000001111100001110000000000111010100111110100100000001101001000000001111111111100000000000110101111000001111110000000000110100000000111111001000000000000001000100101100010010000000001001000000000011111110001100000000000110111000100100011100000001111100000000011111111111100000000000001110110110111011010000000100100000000011111111110011000000000000010010010010001000000000110110000000001111111111100100000000000011100011101101110000000001000000000001111111111111000000000000000111101010011101000000001110000000001111111111111100000000000000011011100011010000000000100000000000111111111111111000000000000011100100111000000000000111000000000111111111111111110000000000001100111110110000000000001000000000111111111111111111100000000000110000000000000000000000000000000111111111111111111111000000000111000000000000000000000000000000111111111111111111111111000000011000000000000000000000000000001111111111111111111111111110000001100000000000000000000000000001111111111111111111111111111110001110000000000000000000000000011111111111111111111111111111111100110000000000000000000000000011111111111111111111111111111111111111000000000000000000000001111111111111111111111111111111111111111110000000000000000000011111111111111111111111111111111111111111111111100000000000011111111111111111111111111";

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false); cin.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // mt19937 rng(47);
    
    int x, y;
    cin >> x >> y;
    if (s[y * 64 + x] == '1') {
        cout << "OUT" << endl;
    } else {
        cout << "IN" << endl;
    }
    
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	return 0;
}