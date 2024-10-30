#include <bits/stdc++.h>
using namespace std;
#define LOCAL
#pragma region Macros
typedef long long ll;
#define ALL(x) (x).begin(),(x).end()
const long long MOD=1000000007;
// const long long MOD=998244353;
const int INF=1e9;
const long long IINF=1e18;
const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
const char dir[4]={'D','R','U','L'};

template<typename T>
istream &operator>>(istream &is,vector<T> &v){
    for (T &x:v) is >> x;
    return is;
}
template<typename T>
ostream &operator<<(ostream &os,const vector<T> &v){
    for (int i=0;i<v.size();++i){
        os << v[i] << (i+1==v.size()?"": " ");
    }
    return os;
}
template<typename T,typename U>
ostream &operator<<(ostream &os,const pair<T,U> &p){
    os << '(' << p.first << ',' << p.second << ')';
    return os;
}
template<typename T,typename U>
ostream &operator<<(ostream &os,const map<T,U> &m){
    os << '{';
    for (auto itr=m.begin();itr!=m.end();++itr){
        os << '(' << itr->first << ',' << itr->second << ')';
        if (++itr!=m.end()) os << ',';
        --itr;
    }
    os << '}';
    return os;
}
template<typename T>
ostream &operator<<(ostream &os,const set<T> &s){
    os << '{';
    for (auto itr=s.begin();itr!=s.end();++itr){
        os << *itr;
        if (++itr!=s.end()) os << ',';
        --itr;
    }
    os << '}';
    return os;
}

void debug_out(){cerr << '\n';}
template<class Head,class... Tail>
void debug_out(Head&& head,Tail&&... tail){
    cerr << head;
    if (sizeof...(Tail)>0) cerr << ", ";
    debug_out(move(tail)...);
}
#ifdef LOCAL
#define debug(...) cerr << " ";\
cerr << #__VA_ARGS__ << " :[" << __LINE__ << ":" << __FUNCTION__ << "]" << '\n';\
cerr << " ";\
debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

template<typename T> T gcd(T x,T y){return y!=0?gcd(y,x%y):x;}
template<typename T> T lcm(T x,T y){return x/gcd(x,y)*y;}

template<class T1,class T2> inline bool chmin(T1 &a,T2 b){
    if (a>b){a=b; return true;} return false;
}
template<class T1,class T2> inline bool chmax(T1 &a,T2 b){
    if (a<b){a=b; return true;} return false;
}
#pragma endregion

void solve(){
    int n,m; cin >> n >> m;
    vector<string> S(n); cin >> S;

    vector<vector<int>> ans(n*m,vector<int>(6));
    int ope=0;
    auto change=[&](int x,int y){
        S[x][y]=(S[x][y]=='0'?'1':'0');
    };
    auto flip=[&](int a,int b,int c,int d,int e,int f){
        ans[ope][0]=a; ans[ope][1]=b; change(a,b);
        ans[ope][2]=c; ans[ope][3]=d; change(c,d);
        ans[ope][4]=e; ans[ope][5]=f; change(e,f);
        ++ope;
    };
    auto flip1=[&](int x,int y){
        if (S[x][y]=='0'&&S[x][y+1]=='0') return;
        if (S[x][y]=='1'&&S[x][y+1]=='1'){
            flip(x,y,x,y+1,x+1,y);
        } else if (S[x][y]=='1'){
            flip(x,y,x+1,y,x+1,y+1);
        } else {
            flip(x,y+1,x+1,y,x+1,y+1);
        }
    };
    auto flip2=[&](int x,int y){
        if (S[x][y]=='0'&&S[x+1][y]=='0') return;
        if (S[x][y]=='1'&&S[x+1][y]=='1'){
            flip(x,y,x+1,y,x,y+1);
        } else if (S[x][y]=='1'){
            flip(x,y,x,y+1,x+1,y+1);
        } else {
            flip(x+1,y,x,y+1,x+1,y+1);
        }
    };
    auto flip3=[&](int x,int y){
        vector<vector<pair<int,int>>> pos(2);
        for (int i=0;i<2;++i){
            for (int j=0;j<2;++j){
                int nx=x+i,ny=y+j;
                pos[S[nx][ny]-'0'].emplace_back(nx,ny);
            }
        }
        int one=pos[1].size();
        if (one==0) return;
        if (one==1){
            for (int i=0;i<3;++i){
                flip(pos[1][0].first,pos[1][0].second,pos[0][i].first,pos[0][i].second,pos[0][(i+1)%3].first,pos[0][(i+1)%3].second);
            }
        } else if (one==2){
            for (int i=0;i<2;++i){
                flip(pos[0][0].first,pos[0][0].second,pos[0][1].first,pos[0][1].second,pos[1][i].first,pos[1][i].second);
            }
        } else if (one==3){
            flip(pos[1][0].first,pos[1][0].second,pos[1][1].first,pos[1][1].second,pos[1][2].first,pos[1][2].second);
        } else {
            flip(pos[1][1].first,pos[1][1].second,pos[1][2].first,pos[1][2].second,pos[1][3].first,pos[1][3].second);
            for (int i=0;i<3;++i){
                pos[0].emplace_back(pos[1].back());
                pos[1].pop_back();
            }
            for (int i=0;i<3;++i){
                flip(pos[1][0].first,pos[1][0].second,pos[0][i].first,pos[0][i].second,pos[0][(i+1)%3].first,pos[0][(i+1)%3].second);
            }
        }
    };

    for (int j=0;j<m-1;++j){
        for (int i=0;i<n-2;++i){
            flip1(i,j);
        }
    }
    for (int j=0;j<m-2;++j) flip2(n-2,j);
    flip3(n-2,m-2);

    cout << ope << '\n';
    for (int i=0;i<ope;++i){
        for (int j=0;j<6;++j){
            cout << ans[i][j]+1 << (j+1==6?'\n':' ');
        }
    }

    // for (int i=0;i<n;++i) cerr << S[i] << '\n';
    // for (int i=0;i<n;++i){
    //     for (int j=0;j<m;++j){
    //         assert(S[i][j]=='0');
    //     }
    // }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        solve();
    }
}