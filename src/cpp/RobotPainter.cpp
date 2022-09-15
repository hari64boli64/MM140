#include <bits/stdc++.h>  // clang-format off
using namespace std;constexpr int INF=1001001001;constexpr long long INFll=1001001001001001001;namespace viewer{using s=string;template<class T>s f(T i){s S=i==INF||i==INFll?"inf":to_string(i);return s(max(0,3-int(S.size())),' ')+S;}
template<class T>auto v(T&x,s&&e)->decltype(cerr<<x){return cerr<<x<<e;}void v(int x,s&&e){cerr<<f(x)<<e;}void v(long long x,s&&e){cerr<<f(x)<<e;}void v(float x,s&&e){cerr<<fixed<<setprecision(5)<<x<<e;}void v(double x,s&&e){cerr<<fixed<<setprecision(5)<<x<<e;}void v(long double x,s&&e){cerr<<fixed<<setprecision(5)<<x<<e;}
template<class T,class U>void v(const pair<T,U>&p,s&&e="\n"){cerr<<"(";v(p.first,", ");v(p.second,")"+e);}template<class T,class U>void v(const tuple<T,U>&t,s&&e="\n"){cerr<<"(";v(get<0>(t),", ");v(get<1>(t),")"+e);}template<class T,class U,class V>void v(const tuple<T,U,V>&t,s&&e="\n"){cerr<<"(";v(get<0>(t),", ");v(get<1>(t),", ");v(get<2>(t),")"+e);}template<class T,class U,class V,class W>void v(const tuple<T,U,V,W>&t,s&&e="\n"){cerr<<"(";v(get<0>(t),", ");v(get<1>(t),", ");v(get<2>(t),", ");v(get<3>(t),")"+e);}
template<class T>void v(const vector<T>&vx,s);template<class T>auto ve(int,const vector<T>&vx)->decltype(cerr<<vx[0]){cerr<<"{";for(const T&x:vx)v(x,",");return cerr<<"}\n";}template<class T>auto ve(bool,const vector<T>&vx){cerr<<"{\n";for(const T&x:vx)cerr<<"  ",v(x,",");cerr<<"}\n";}template<class T>void v(const vector<T>&vx,s){ve(0,vx);}
template<class T>void v(const deque<T>&q,s&&e){v(vector<T>(q.begin(),q.end()),e);}template<class T,class C>void v(const set<T,C>&S,s&&e){v(vector<T>(S.begin(),S.end()),e);}template<class T,class C>void v(const multiset<T,C>&S,s&&e){v(vector<T>(S.begin(),S.end()),e);}template<class T>void v(const unordered_set<T>&S,s&&e){v(vector<T>(S.begin(),S.end()),e);}
template<class T,class U,class V>void v(const priority_queue<T,U,V>&p,s&&e){priority_queue<T,U,V>q=p;vector<T>z;while(!q.empty()){z.push_back(q.top());q.pop();}v(z,e);}template<class T,class U>void v(const map<T,U>&m,s&&e){cerr<<"{"<<(m.empty()?"":"\n");for(const auto&kv:m){cerr<<"  [";v(kv.first,"");cerr<<"] : ";v(kv.second,"");cerr<<"\n";}cerr<<"}"+e;}
template<class T>void _view(int n,s&S,T&var){cerr<<"\033[1;32m"<<n<<"\033[0m: \033[1;36m"<<S<<"\033[0m = ";v(var,"\n");}template<class T>void grid([[maybe_unused]]T _){}void grid(const vector<vector<bool>>&vvb){cerr<<"\n";for(const vector<bool>&vb:vvb){for(const bool&b:vb)cerr<<(b?".":"#");cerr<<"\n";}}
void _debug(int,s){}template<typename H,typename... T>void _debug(int n,s S,const H&h,const T&... t){int i=0,cnt=0;for(;i<int(S.size());i++){if(S[i]=='(')cnt++;if(S[i]==')')cnt--;if(cnt==0&&S[i]==',')break;}if(i==int(S.size()))_view(n,S,h);else{s S1=S.substr(0,i),S2=S.substr(i+2);if(S2=="\"grid\""){cerr<<"\033[1;32m"<<n<<"\033[0m: \033[1;36m"<<S1<<"\033[0m = ";grid(h);}else _view(n,S1,h),_debug(n,S2,t...);}}}
template<class T>bool chmax(T&a,const T&b){return a<b?a=b,1:0;}template<class T>bool chmin(T&a,const T&b){return a>b?a=b,1:0;} // https://rsk0315.hatenablog.com/entry/2021/01/18/065720
namespace internal{template<class T>using is_signed_int128=typename conditional<is_same<T,__int128_t>::value||is_same<T,__int128>::value,true_type,false_type>::type;template<class T>using is_unsigned_int128=typename conditional<is_same<T,__uint128_t>::value||is_same<T,unsigned __int128>::value,true_type,false_type>::type;template<class T>using is_integral=typename conditional<std::is_integral<T>::value||is_signed_int128<T>::value||is_unsigned_int128<T>::value,true_type,false_type>::type;
template<class T>using is_signed_int=typename conditional<(is_integral<T>::value&&is_signed<T>::value)||is_signed_int128<T>::value,true_type,false_type>::type;template<class T>using is_unsigned_int=typename conditional<(is_integral<T>::value&&is_unsigned<T>::value)||is_unsigned_int128<T>::value,true_type,false_type>::type;template<class T>using is_signed_int_t=enable_if_t<is_signed_int<T>::value>;template<class T>using is_unsigned_int_t=enable_if_t<is_unsigned_int<T>::value>;
constexpr long long safe_mod(long long x,long long m){x%=m;if(x<0)x+=m;return x;}struct barrett{unsigned int _m;unsigned long long im;explicit barrett(unsigned int m):_m(m),im((unsigned long long)(-1)/m+1){}unsigned int umod()const{return _m;}unsigned int mul(unsigned int a,unsigned int b)const{unsigned long long z=a;z*=b;unsigned long long x=(unsigned long long)(((unsigned __int128)(z)*im)>>64);unsigned int v=(unsigned int)(z-x*_m);if(_m<=v)v+=_m;return v;}};
constexpr long long pow_mod_constexpr(long long x,long long n,int m){if(m==1)return 0;unsigned int _m=(unsigned int)(m);unsigned long long r=1;unsigned long long y=safe_mod(x,m);while(n){if(n&1)r=(r*y)%_m;y=(y*y)%_m;n>>=1;}return r;}constexpr pair<long long,long long>inv_gcd(long long a,long long b){a=safe_mod(a,b);if(a==0)return{b,0};long long s=b,t=a;long long m0=0,m1=1;while(t){long long u=s/t;s-=t*u;m0-=m1*u;auto tmp=s;s=t;t=tmp;tmp=m0;m0=m1;m1=tmp;}if(m0<0)m0+=b/s;return{s,m0};}
constexpr bool is_prime_constexpr(int n){if(n<=1)return false;if(n==2||n==7||n==61)return true;if(n%2==0)return false;long long d=n-1;while(d%2==0)d/=2;constexpr long long bases[3]={2,7,61};for(long long a:bases){long long t=d;long long y=pow_mod_constexpr(a,t,n);while(t!=n-1&&y!=1&&y!=n-1){y=y*y%n;t<<=1;}if(y!=n-1&&t%2==0)return false;}return true;}template<int n>constexpr bool is_prime=is_prime_constexpr(n);} // namespace internal
template<int m>struct static_modint{using mint=static_modint;static constexpr int mod(){return m;}static mint raw(int v){mint x;x._v=v;return x;}static_modint():_v(0){}template<class T,internal::is_signed_int_t<T>* =nullptr>static_modint(T v){long long x=(long long)(v%(long long)(umod()));if(x<0)x+=umod();_v=(unsigned int)(x);}template<class T,internal::is_unsigned_int_t<T>* =nullptr>static_modint(T v){_v=(unsigned int)(v%umod());}unsigned int val()const{return _v;}
mint&operator++(){_v++;if(_v==umod())_v=0;return*this;}mint&operator--(){if(_v==0)_v=umod();_v--;return*this;}mint operator++(int){mint result=*this;++*this;return result;}mint operator--(int){mint result=*this;--*this;return result;}mint&operator+=(const mint&rhs){_v+=rhs._v;if(_v>=umod())_v-=umod();return*this;}mint&operator-=(const mint&rhs){_v-=rhs._v;if(_v>=umod())_v+=umod();return*this;}
mint&operator*=(const mint&rhs){unsigned long long z=_v;z*=rhs._v;_v=(unsigned int)(z%umod());return*this;}mint&operator/=(const mint&rhs){return*this=*this*rhs.inv();}mint operator+()const{return*this;}mint operator-()const{return mint()-*this;}mint pow(long long n)const{assert(0<=n);mint x=*this,r=1;while(n){if(n&1)r*=x;x*=x;n>>=1;}return r;}mint inv()const{if(prime){assert(_v);return pow(umod()-2);}else{auto eg=internal::inv_gcd(_v,m);assert(eg.first==1);return eg.second;}}
friend mint operator+(const mint&lhs,const mint&rhs){return mint(lhs)+=rhs;}friend mint operator-(const mint&lhs,const mint&rhs){return mint(lhs)-=rhs;}friend mint operator*(const mint&lhs,const mint&rhs){return mint(lhs)*=rhs;}friend mint operator/(const mint&lhs,const mint&rhs){return mint(lhs)/=rhs;}friend bool operator==(const mint&lhs,const mint&rhs){return lhs._v==rhs._v;}friend bool operator!=(const mint&lhs,const mint&rhs){return lhs._v!=rhs._v;}
friend ostream&operator<<(ostream&os,const mint&rhs){return os<<rhs._v;}friend istream&operator>>(istream&is,mint&rhs){long long v;is>>v;v%=(long long)(umod());if(v<0)v+=umod();;rhs._v=(unsigned int)v;return is;}static constexpr bool prime=internal::is_prime<m>;private:unsigned int _v;static constexpr unsigned int umod(){return m;}};
constexpr int MOD = 1000000007;using mint=static_modint<MOD>;vector<mint>mint_factorial={mint(1)};/*n>1e8 ⇒ fast_modfact(deprecated)*/mint modfact(int n){assert(n<=100000000);if(int(mint_factorial.size())<=n){for(int i=mint_factorial.size();i<=n;i++){mint next=mint_factorial.back()*i;mint_factorial.push_back(next);}}return mint_factorial[n];}
/*x s.t. x^2 ≡ a (mod Prime) or -1*/mint modsqrt(mint a){long long p=mint::mod();if(a.val()==1)return a;if(a.pow((p-1)>>1).val()!=1)return -1;mint b=1,one=1;while(b.pow((p-1)>>1).val()==1)b+=one;long long m=p-1,e=0;while(m%2==0)m>>=1,e++;mint x=a.pow((m-1)>>1);mint y=a*x*x;x*=a;mint z=b.pow(m);while(y!=1){long long j=0;mint t=y;while(t!=one)j++,t*=t;z=z.pow(1ll<<(e-j-1));x*=z;z*=z;y*=z;e=j;}return x;}mint nCk(int n,int k){if(k<0||n<k)return mint(0);return modfact(n)*(modfact(k)).inv()*modfact(n-k).inv();}
/*min x s.t. a^x ≡ b (mod M) or -1*/int modlog(mint a,mint b){if(gcd(a.mod(),a.val())!=1){cout<<"\033[1;31mCAUTION: m must be coprime to a.\033[0m"<<endl;assert(false);}long long m=mint::mod();long long sq=round(sqrt(m))+1;unordered_map<long long,long long>ap;mint re=a;for(long long r=1;r<sq;r++){if(ap.find(re.val())==ap.end())ap[re.val()]=r;re*=a;}mint A=a.inv().pow(sq);re=b;for(mint q=0;q.val()<sq;q++){if(re==1&&q!=0)return(q*sq).val();if(ap.find(re.val())!=ap.end())return(q*sq+ap[re.val()]).val();re*=A;}return-1;};
#ifndef hari64
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#define debug(...)
#else
#define debug(...) viewer::_debug(__LINE__, #__VA_ARGS__, __VA_ARGS__)
#endif

struct Timer{
    void start(){_start=chrono::system_clock::now();}
    void stop(){_end=chrono::system_clock::now();sum+=chrono::duration_cast<chrono::nanoseconds>(_end-_start).count();}
    inline int ms()const{const chrono::system_clock::time_point now=chrono::system_clock::now();return static_cast<int>(chrono::duration_cast<chrono::microseconds>(now-_start).count()/1000);}
    inline int ns()const{const chrono::system_clock::time_point now=chrono::system_clock::now();return static_cast<int>(chrono::duration_cast<chrono::microseconds>(now-_start).count());}
    string report(){return to_string(sum/1000000)+"[ms]";}
    void reset(){_start=chrono::system_clock::now();sum=0;}
    private: chrono::system_clock::time_point _start,_end;long long sum=0;
}timer;
struct Xor128{// period 2^128 - 1
    uint32_t x,y,z,w;
    static constexpr uint32_t min(){return 0;}
    static constexpr uint32_t max(){return UINT32_MAX;}
    Xor128(uint32_t seed=0):x(123456789),y(362436069),z(521288629),w(88675123+seed){}
    uint32_t operator()(){uint32_t t=x^(x<<11);x=y;y=z;z=w;return w=(w^(w>>19))^(t^(t>>8));}
    uint32_t operator()(uint32_t l,uint32_t r){return((*this)()%(r-l))+l;}
    uint32_t operator()(uint32_t r){return(*this)()%r;}};
struct Rand{// https://docs.python.org/ja/3/library/random.html
    Rand(){};
    Rand(int seed):gen(seed){};
    // シードを変更します
    inline void set_seed(int seed){Xor128 _gen(seed);gen=_gen;}
    // ランダムな浮動小数点数（範囲は[0.0, 1.0)) を返します
    inline double random(){return(double)gen()/(double)gen.max();}
    // a <= b であれば a <= N <= b 、b < a であれば b <= N <= a であるようなランダムな浮動小数点数 N を返します
    inline double uniform(double a,double b){if(b<a)swap(a,b);return a+(b-a)*double(gen())/double(gen.max());}
    // range(0, stop) の要素からランダムに選ばれた要素を返します
    inline uint32_t randrange(uint32_t r){return gen(r);}
    // range(start, stop) の要素からランダムに選ばれた要素を返します
    inline uint32_t randrange(uint32_t l,uint32_t r){return gen(l,r);}
    // a <= N <= b であるようなランダムな整数 N を返します randrange(a, b + 1) のエイリアスです
    inline uint32_t randint(uint32_t l,uint32_t r){return gen(l,r+1);}
    // シーケンス x をインプレースにシャッフルします
    template<class T>void shuffle(vector<T>&x){for(int i=x.size(),j;i>1;){j=gen(i);swap(x[j],x[--i]);}}
    // 空でないシーケンス seq からランダムに要素を返します
    template<class T>T choice(const vector<T>&seq){assert(!seq.empty());return seq[gen(seq.size())];}
    // 相対的な重みに基づいて要素が選ばれます (※複数回呼ぶ場合は処理を変えた方が良い)
    template<class T,class U>T choice(const vector<T>&seq,const vector<U>&weights){assert(seq.size()==weights.size());vector<U>acc(weights.size());acc[0]=weights[0];for(int i=1;i<int(weights.size());i++)acc[i]=acc[i-1]+weights[i];return seq[lower_bound(acc.begin(),acc.end(),random()*acc.back())-acc.begin()];}
    // 母集団のシーケンスまたは集合から選ばれた長さ k の一意な要素からなるリストを返します 重複無しのランダムサンプリングに用いられます
    template<class T>vector<T>sample(const vector<T>&p,int k){int j,i=0,n=p.size();assert(0<=k&&k<=n);vector<T>ret(k);unordered_set<int>s;for(;i<k;i++){do{j=gen(n);}while(s.find(j)!=s.end());s.insert(j);ret[i]=p[j];}return ret;}
    // 正規分布です mu は平均で sigma は標準偏差です
    double normalvariate(double mu=0.0,double sigma=1.0){double u2,z,NV=4*exp(-0.5)/sqrt(2.0);while(true){u2=1.0-random();z=NV*(random()-0.5)/u2;if(z*z/4.0<=-log(u2))break;}return mu+z*sigma;}
    private: Xor128 gen;
}myrand;

namespace esc{const vector<int>colors{196,208,226,46,77,14,12,13,5,136,195,245};constexpr int RED=0,ORANGE=1,YELLOW=2,LIGHTGREEN=3,GREEN=4,AQUA=5,BLUE=6,PINK=7,PURPLE=8,BROWN=9,WHITE=10,GRAY=11;
void back(int n){cerr<<"\e["<<n<<"A";}void locate(int r,int c){cerr<<"\e["<<r+1<<+";"<<c+1<<"H";}void reset(){cerr<<"\e[0m";}
void color(int c){cerr<<"\e[38;5;"<<colors[c]<<"m";}void color(int c,string s){color(c);cerr<<s;reset();}void color(int c,int s){color(c,to_string(s));}
void bcolor(int c){cerr<<"\e[4;"<<colors[c]<<"m";}void bcolor(int c,string s){bcolor(c);cerr<<s;reset();}void bcolor(int c,int s){color(c,to_string(s));}
string with_sep(int n,char sep=','){string ret="",s=to_string(n);reverse(s.begin(),s.end());for(int i=0,len=s.length();i<=len;){ret+=s.substr(i,3);if((i+=3)>=len)break;ret+=sep;}reverse(ret.begin(),ret.end());return ret;}
string with_fill(int n,int num=3,char space=' '){string s=to_string(n);return string(max(0,num-int(s.size())),space)+s;}
// **VISUALIZER-TEMPLATE**
// int N=20,M=30,vis_length=10;
// for(int vis_cnt=1;vis_cnt<=vis_length;vis_cnt++){cerr<<esc::with_fill(vis_cnt)<<"/"<<vis_length<<endl;cerr<<"";
// for(int x=0;x<M;x++)esc::color(esc::GRAY,x%10);cerr<<""<<endl;
// for(int y=0;y<N;y++){esc::color(esc::GRAY,y%10);esc::reset();
// for(int x=0;x<M;x++){/*wirte here*/esc::bcolor(y%10,myrand.randint(0,9));}esc::color(esc::GRAY,y%10);cerr<<endl;}cerr<<"";
// for(int x=0;x<M;x++)esc::color(esc::GRAY,x%10);cerr<<""<<endl;if(vis_cnt<vis_length)esc::back(N+2+1);usleep(1.0*1000000);}
}// namespace esc

// clang-format on

int N;                      // grid size
int JC;                     // JUMP COST
int FC;                     // FOR COST
vector<vector<bool>> GRID;  // N*N
int TARGET_NUM;

constexpr int dirLen = 8;
constexpr int dr[dirLen] = {0, 1, 1, 1, 0, -1, -1, -1};
constexpr int dc[dirLen] = {1, 1, 0, -1, -1, -1, 0, 1};
///////////////////////////→  ↘  ↓  ↙  ←  ↖  ↑  ↗

void read_input() {
    cin >> N >> JC >> FC;
    GRID.resize(N, vector<bool>(N));
    TARGET_NUM = 0;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            char a;
            cin >> a;
            GRID[r][c] = (a == '#');
            TARGET_NUM += int(GRID[r][c]);
        }
    }
}

int to_idx(int r, int c) { return r * N + c; };
pair<int, int> to_hw(int idx) { return {idx / N, idx % N}; };

using Bitset = bitset<900>;

ostream& operator<<(ostream& os, const Bitset& b) {
    os << "----" << endl;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            os << (b[to_idx(r, c)] ? '#' : '.');
        }
        os << endl;
    }
    return os;
}

enum CommandType {
    D,    //       PEN DOWN
    U,    //       PEN UP
    F,    // n     MOVE FORWARD
    B,    // n     MOVE BACKWARD
    R,    //       ROTATE RIGHT
    L,    //       ROTATE LEFT
    J,    // dr dc JUMP
    FOR,  // x (2<=x<=10)
    END,  //
};
const string COMMAND_STR[9] = {"D", "U", "F", "B", "R", "L", "J", "FOR", "END"};

/**
 * @brief 問題に定義されている操作群をコマンドとして定義している
 */
struct Command {
    CommandType type;
    int info1;
    int info2;

    Command(CommandType type, vector<int>& forStartIds,
            vector<Command>& commands, int _info1 = -INF, int _info2 = -INF)
        : type(type), info1(_info1), info2(_info2) {
        if (type == D || type == U || type == R || type == L || type == END) {
            assert(info1 == -INF && info2 == -INF);
            if (type == END) {
                assert(!forStartIds.empty());
                info1 = forStartIds.back();
                forStartIds.pop_back();
                assert(commands[info1].info2 == -INF);
                commands[info1].info2 = commands.size();
            }
        } else if (type == F || type == B || type == FOR) {
            assert(info1 != -INF && info2 == -INF);
            if (type == FOR) {
                assert(2 <= info1 && info1 <= 10);
                forStartIds.push_back(commands.size());
            } else {
                assert(0 <= info1 && info1 < N);
            }
        } else {
            assert(info1 != -INF && info2 != -INF);
        }
    }

    int getCost() {
        if (type == J) {
            return JC;
        } else if (type == FOR) {
            return FC;
        } else if (type == END) {
            return 0;
        } else {
            return 1;
        }
    }

    friend ostream& operator<<(ostream& os, const Command& command) {
        os << COMMAND_STR[command.type];
        if (command.info1 != -INF && command.type != END) {
            os << " " << command.info1;
        }
        if (command.info2 != -INF && command.type != FOR) {
            os << " " << command.info2;
        }
        return os;
    }
};

/**
 * @brief commandの配列
 * @note L,Rはまとめて渡すこと 第一引数に個数を記す
 */
struct Commands {
    vector<Command> commands;
    vector<int> forStartIds;
    int cost;

    Commands() : cost(0) {}

    void addCommand(CommandType type, int info1 = -INF, int info2 = -INF) {
        if (type == R || type == L) {
            assert(info1 != -INF);
            if (info1 == 0) {
                return;
            }
            for (int _ = 0; _ < info1; _++) {
                commands.emplace_back(type, forStartIds, commands, -INF, info2);
            }
            cost += commands.back().getCost() * info1;
        } else {
            if ((type == F || type == B) && info1 == 0) {
                return;
            }
            commands.emplace_back(type, forStartIds, commands, info1, info2);
            cost += commands.back().getCost();
        }
    }
    void addCommandRF(int rnum, int fnum) {
        if (fnum == 0) return;
        if (rnum == 0) {
            commands.emplace_back(F, forStartIds, commands, fnum, -INF);
            cost += 1;
        } else if (rnum == 1) {
            commands.emplace_back(R, forStartIds, commands, -INF, -INF);
            commands.emplace_back(F, forStartIds, commands, fnum, -INF);
            cost += 2;
        } else if (rnum == 2) {
            commands.emplace_back(R, forStartIds, commands, -INF, -INF);
            commands.emplace_back(R, forStartIds, commands, -INF, -INF);
            commands.emplace_back(F, forStartIds, commands, fnum, -INF);
            cost += 3;
        } else if (rnum == 3) {
            commands.emplace_back(L, forStartIds, commands, -INF, -INF);
            commands.emplace_back(B, forStartIds, commands, fnum, -INF);
            cost += 2;
        } else if (rnum == 4) {
            commands.emplace_back(B, forStartIds, commands, fnum, -INF);
            cost += 1;
        } else if (rnum == 5) {
            commands.emplace_back(R, forStartIds, commands, -INF, -INF);
            commands.emplace_back(B, forStartIds, commands, fnum, -INF);
            cost += 2;
        } else if (rnum == 6) {
            commands.emplace_back(L, forStartIds, commands, -INF, -INF);
            commands.emplace_back(L, forStartIds, commands, -INF, -INF);
            commands.emplace_back(F, forStartIds, commands, fnum, -INF);
            cost += 3;
        } else if (rnum == 7) {
            commands.emplace_back(L, forStartIds, commands, -INF, -INF);
            commands.emplace_back(F, forStartIds, commands, fnum, -INF);
            cost += 2;
        } else {
            assert(false);
        }
    }

    friend ostream& operator<<(ostream& os, const Commands& commands) {
        os << commands.commands.size() << endl;
        for (auto& c : commands.commands) {
            os << c << endl;
        }
        return os;
    }
};

/**
 * @brief コマンド群から得点や塗られる箇所を計算する
 *        部分的に配布物のRobotPainterTester.javaから移植した
 */
struct Simulator {
    vector<vector<bool>> g;
    int grid_cost, commands_cost, total_cost;

    int initr, initc, initd;
    bool initpen;
    int initnest;

    int lastr, lastc, lastd;
    int success, fail;

    Simulator(const Commands& commands, const vector<vector<bool>>& painted,
              int initr, int initc, int initd, bool initpen, int initnest)
        : g(painted),
          commands_cost(commands.cost),
          total_cost(-1),
          initr(initr),
          initc(initc),
          initd(initd),
          initpen(initpen),
          initnest(initnest),
          success(0),
          fail(0) {
        assert(int(painted.size()) == N);
        assert(0 <= initr && initr < N && 0 <= initc && initc < N &&
               0 <= initd && initd < dirLen);
        reflectCommands(commands.commands);
    }

    void report() {
        esc::color(esc::ORANGE, "    Grid Cost: " + to_string(grid_cost));
        cerr << endl;
        esc::color(esc::ORANGE, "Commands Cost: " + to_string(commands_cost));
        cerr << endl;
        esc::color(esc::RED, "   Total Cost: " + to_string(total_cost));
        cerr << endl;
    }

   private:
    void reflectCommands(const vector<Command>& commands) {
        int r = initr;
        int c = initc;
        int dir = initd;
        bool isPenUp = initpen;
        int nest = initnest;

        unordered_map<int, int> loop_counter;
        for (int commandId = 0; commandId < int(commands.size()); commandId++) {
            if (commands[commandId].type == FOR) {
                loop_counter[commandId] = -1;
            }
        }

        for (int commandId = 0; commandId < int(commands.size());) {
            const Command& m = commands[commandId];
            if (m.type == L) {
                dir = (dir - 1 + dirLen) % dirLen;
            } else if (m.type == R) {
                dir = (dir + 1) % dirLen;
            } else if (m.type == U) {
                assert(!isPenUp);
                isPenUp = true;
            } else if (m.type == D) {
                assert(isPenUp);
                isPenUp = false;
                if (!g[r][c]) {
                    if (!GRID[r][c]) {
                        fail++;
                    } else {
                        success++;
                    }
                    g[r][c] = true;
                }
            } else if (m.type == F) {
                for (int i = 0; i < m.info1; i++) {
                    r = (r + dr[dir] + N) % N;
                    c = (c + dc[dir] + N) % N;
                    if (!isPenUp && !g[r][c]) {
                        if (!GRID[r][c]) {
                            fail++;
                        } else {
                            success++;
                        }
                        g[r][c] = true;
                    }
                }
            } else if (m.type == B) {
                for (int i = 0; i < m.info1; i++) {
                    r = (r - dr[dir] + N) % N;
                    c = (c - dc[dir] + N) % N;
                    if (!isPenUp && !g[r][c]) {
                        if (!GRID[r][c]) {
                            fail++;
                        } else {
                            success++;
                        }
                        g[r][c] = true;
                    }
                }
            } else if (m.type == J) {
                r = (r + m.info1 + N) % N;
                c = (c + m.info2 + N) % N;
                if (!isPenUp && !g[r][c]) {
                    if (!GRID[r][c]) {
                        fail++;
                    } else {
                        success++;
                    }
                    g[r][c] = true;
                }
            } else if (m.type == FOR) {
                if (loop_counter.at(commandId) == -1) {
                    loop_counter.at(commandId) = m.info1 - 1;
                    assert(2 <= m.info1 && m.info1 <= 10);
                    nest++;
                    assert(nest <= 3);
                } else if (loop_counter.at(commandId) == 0) {
                    nest--;
                    loop_counter.at(commandId) = -1;
                    commandId = m.info2;
                } else {
                    assert(loop_counter.at(commandId) > 0);
                    loop_counter.at(commandId)--;
                }
            } else if (m.type == END) {
                commandId = m.info1 - 1;
            }
            commandId++;
        }
        assert(nest == 0);
        for (const auto& [_key, value] : loop_counter) {
            assert(value == -1);
        }
        grid_cost = (TARGET_NUM - success + fail) * 10;
        total_cost = grid_cost + commands_cost;
        lastr = r;
        lastc = c;
        lastd = dir;
    }
};

// Bitset genBitsetFromGrid(int d, int r, int c,
//                          const vector<vector<bool>>& _grid) {
//     vector<vector<bool>> grid = _grid;
//     for (auto& row : grid) {
//         rotate(row.begin(), row.begin() + c, row.end());
//     }
//     rotate(grid.begin(), grid.begin() + r, grid.end());

//     Bitset ret(0);
//     int nowr = 0;
//     int nowc = 0;
//     for (int r = 0; r < N; r++, nowr += dr[((d + 1) * 2) % dirLen],
//              nowc += dc[((d + 1) * 2) % dirLen]) {
//         for (int c = 0; c < N; c++, nowr += dr[d * 2], nowc += dc[d * 2]) {
//             nowr = (nowr + N) % N;
//             nowc = (nowc + N) % N;
//             ret[to_idx(r, c)] = grid[nowr][nowc];
//         }
//     }

//     return ret;
// }

// /**
//  * @brief d*90度回転してr行c列ずらした盤面を前計算しておく
//  * @note 参照のみなら、データの取得は必ず以下の形で行うこと
//  *       const Bitset& g = bitsetbank.getBitset(d, r, c);
//  */
// struct BitsetBank {
//     vector<vector<vector<Bitset>>> _bitsets;

//     BitsetBank() {}

//     void init() {
//         assert(_bitsets.empty());
//         _bitsets.resize(4, vector<vector<Bitset>>(N, vector<Bitset>(N)));
//         for (int d = 0; d < 4; d++) {
//             for (int r = 0; r < N; r++) {
//                 for (int c = 0; c < N; c++) {
//                     _bitsets[d][r][c] = genBitsetFromGrid(d, r, c, GRID);
//                 }
//             }
//         }
//     }

//     /**
//      * @param d only [0,4)  This is different from the problem's rotation
//      system
//      * @param r accept N or more
//      * @param c accept N or more
//      */
//     const Bitset& getBitset(int d, int r, int c) const {
//         assert(0 <= r && 0 <= c);
//         r %= N;
//         c %= N;
//         assert(0 <= d && d < 4);  // RDLU
//         return _bitsets[d][r][c];
//     }
// };
// BitsetBank bb;

struct ForLoopInfo {
    int sr = -1;
    int sc = -1;
    int sd = -1;
    int dr = -1;
    int dc = -1;
    int dd = -1;
    int g_and = -1;
    int g_or = -1;

    ForLoopInfo(int sr, int sc, int sd, int dr, int dc, int dd, int g_and,
                int g_or)
        : sr(sr),
          sc(sc),
          sd(sd),
          dr(dr),
          dc(dc),
          dd(dd),
          g_and(g_and),
          g_or(g_or) {
        assert(g_and <= g_or);
    };

    double value() const {
        return (1 - double(g_and) / double(TARGET_NUM)) *
               (double(g_or) / double(g_and));
    }

    bool operator<(const ForLoopInfo& rhs) { return value() < rhs.value(); }

    friend ostream& operator<<(ostream& os, const ForLoopInfo& x) {
        return os << "["
                  << "sr:" << x.sr << ", "
                  << "sc:" << x.sc << ", "
                  << "sd:" << x.sd << ", "
                  << "dr:" << x.dr << ", "
                  << "dc:" << x.dc << ", "
                  << "dd:" << x.dd << "]";
    }
};

// auto findBestRect() {
//     debug(GRID, "grid");
//     vector<ForLoopInfo> cands;
//     int loopx = 4;  //?
//     int loop_cnt = 0;
//     for (int sr = 0; sr < N; sr++) {
//         for (int sc = 0; sc < N; sc++) {
//             if (!GRID[sr][sc]) continue;
//             for (int sd = 0; sd < 4; sd++) {
//                 for (int dr = 0; dr < N; dr++) {
//                     for (int dc = (dr ? 0 : 1); dc < N; dc++) {
//                         for (int dd = 0; dd < 4; dd++) {
//                             loop_cnt++;
//                             Bitset g_and = bb.getBitset(sd, sr, sc);
//                             for (int inner_loop = 1; inner_loop < loopx;
//                                  inner_loop++) {
//                                 const Bitset& g2 = bb.getBitset(
//                                     (sd + dd * inner_loop) % 4,
//                                     sr + dr * inner_loop, sc + dc *
//                                     inner_loop);
//                                 g_and &= g2;
//                             }
//                             if (sr == 0 && sc == 6 && sd == 3 && dr == 7 &&
//                                 dc == 0 && dd == 3) {
//                                 debug(g_and);
//                             }
//                             int g_and_count = g_and.count();
//                             if (g_and[0] && g_and_count > TARGET_NUM / loopx)
//                             {
//                                 vector<vector<bool>> g_and_vvb(N,
//                                                                vector<bool>(N));
//                                 for (int r = 0; r < N; r++) {
//                                     for (int c = 0; c < N; c++) {
//                                         g_and_vvb[r][c] = g_and[to_idx(r,
//                                         c)];
//                                     }
//                                 }
//                                 Bitset g_or = g_and;
//                                 for (int inner_loop = 1; inner_loop < loopx;
//                                      inner_loop++) {
//                                     const Bitset& g2 = genBitsetFromGrid(
//                                         (sd + dd * inner_loop) % 4,
//                                         (sr + dr * inner_loop + N) % N,
//                                         (sc + dc * inner_loop + N) % N,
//                                         g_and_vvb);
//                                     g_or |= g2;
//                                 }
//                                 if (sr == 0 && sc == 6 && sd == 3 && dr == 7
//                                 &&
//                                     dc == 0 && dd == 3) {
//                                     debug(g_or);
//                                 }
//                                 int g_or_count = g_or.count();
//                                 cands.emplace_back(sr, sc, sd, dr, dc, dd,
//                                                    g_and_count, g_or_count);
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//     }
//     debug(loop_cnt);
//     debug(cands.size());
//     sort(cands.begin(), cands.end());
//     debug(cands.front());
//     debug(cands.back());
//     assert(false);
// }

bool simple_check(int sr, int sc, int f1, int r1) {
    assert(GRID[sr][sc]);
    for (int step = 1; step <= f1; step++) {
        if (!GRID[(sr + step * dr[r1] + N) % N][(sc + step * dc[r1] + N) % N]) {
            return false;
        }
    }
    return true;
}

void solve() {
    Commands best_commands;

    bool isPenUp = true;
    int lastr = 0, lastc = 0, lastd = 0;
    vector<vector<bool>> painted(N, vector<bool>(N, false));
    int num_painted = 0;

    int loop_cnt = 0;

    const int TL = (N >= 20 ? 4500 : 7000);
    const int TL2 = 9500;

    while (num_painted < TARGET_NUM && ++loop_cnt < 100) {
        bool timeup = (timer.ms() > TL);
        int inner_best_score = INF;
        Commands inner_best_commands;
        vector<vector<bool>> best_painted;
        // int best_sr = -1;
        // int best_sc = -1;
        // int best_sd = -1;
        // int best_r1 = -1;
        // int best_f1 = -1;
        int best_loopx1 = -1;
        int best_lastr = -1;
        int best_lastc = -1;
        int best_lastd = -1;
        for (int sr = 0; sr < N; sr++) {
            for (int sc = 0; sc < N; sc++) {
                if (!GRID[(lastr + sr) % N][(lastc + sc) % N]) continue;
                for (int sd = 0; sd < dirLen; sd++) {
                    for (int r1 = 0; r1 < dirLen; r1++) {
                        for (int f1 = 0; f1 < N; f1 += (N > 20 ? 2 : 1)) {
                            if ((sd != 0 || f1 != 0 || r1 != 0) && timeup) {
                                break;
                            }
                            if (f1 == 0 && r1 > 0) continue;
                            if (loop_cnt == 1 && !simple_check(sr, sc, f1, r1))
                                break;
                            for (int loopx1 = 2 - 1; loopx1 <= 10; loopx1++) {
                                Commands commands;
                                if (sr != 0 || sc != 0) {
                                    commands.addCommand(J, sr, sc);
                                }
                                if (isPenUp) {
                                    commands.addCommand(D);
                                }

                                if (loopx1 >= 2) {
                                    commands.addCommand(FOR, loopx1);
                                }
                                { commands.addCommandRF(r1, f1); }
                                if (loopx1 >= 2) {
                                    commands.addCommand(END);
                                }

                                Simulator sim(commands, painted, lastr, lastc,
                                              lastd, isPenUp, 0);

                                if (sim.success &&
                                    chmin(inner_best_score,
                                          sim.total_cost + sim.fail * 1000)) {
                                    swap(inner_best_commands, commands);
                                    swap(best_painted, sim.g);
                                    best_lastr = sim.lastr;
                                    best_lastc = sim.lastc;
                                    best_lastd = sim.lastd;
                                    // best_sr = sr;
                                    // best_sc = sc;
                                    // best_sd = sd;
                                    // best_r1 = r1;
                                    // best_f1 = f1;
                                    best_loopx1 = loopx1;
                                } else if (sim.fail) {
                                    break;  // loopx
                                }
                            }
                        }
                    }
                }
            }
        }

        if (inner_best_score == INF) {
            break;
        }
        if (best_loopx1 == 1) {
            break;
        }

        for (auto& m : inner_best_commands.commands) {
            if (m.type == D) isPenUp = false;
            if (m.type == U) isPenUp = true;
            best_commands.addCommand(m.type,
                                     (m.type == L || m.type == R)
                                         ? 1
                                         : (m.type == END ? -INF : m.info1),
                                     m.type == FOR ? -INF : m.info2);
        }
        swap(painted, best_painted);
        num_painted = 0;
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                num_painted += int(painted[r][c]);
            }
        }
        lastr = best_lastr;
        lastc = best_lastc;
        lastd = best_lastd;
        debug("#");
    }

    //
    assert(loop_cnt > 0);
    //

    while (num_painted < TARGET_NUM && ++loop_cnt < 100) {
        bool timeup = (timer.ms() > TL2);
        int inner_best_score = INF;
        Commands inner_best_commands;
        vector<vector<bool>> best_painted;
        // int best_sr = -1;
        // int best_sc = -1;
        // int best_sd = -1;
        // int best_r1 = -1;
        // int best_f1 = -1;
        int best_loopx1 = -1;
        int best_lastr = -1;
        int best_lastc = -1;
        int best_lastd = -1;
        for (int sr = 0; sr < N; sr++) {
            for (int sc = 0; sc < N; sc++) {
                if (!GRID[(lastr + sr) % N][(lastc + sc) % N]) continue;

                for (int r1 = 0; r1 < dirLen; r1++) {
                    for (int f1 = 0; f1 < N; f1 += (N > 20 ? 2 : 1)) {
                        if ((f1 != 0 || r1 != 0) && timeup) {
                            break;
                        }
                        if (f1 == 0 && r1 > 0) continue;

                        Commands commands;
                        if (sr != 0 || sc != 0) {
                            commands.addCommand(J, sr, sc);
                        }
                        if (isPenUp) {
                            commands.addCommand(D);
                        }
                        commands.addCommandRF(r1, f1);

                        Simulator sim(commands, painted, lastr, lastc, lastd,
                                      isPenUp, 0);

                        if (sim.success &&
                            chmin(inner_best_score,
                                  sim.total_cost + sim.fail * 1000)) {
                            swap(inner_best_commands, commands);
                            swap(best_painted, sim.g);
                            best_lastr = sim.lastr;
                            best_lastc = sim.lastc;
                            best_lastd = sim.lastd;
                            // best_sr = sr;
                            // best_sc = sc;
                            // best_sd = sd;
                            // best_r1 = r1;
                            // best_f1 = f1;
                            // best_loopx1 = loopx1;
                        } else if (sim.fail) {
                            break;  // loopx
                        }
                    }
                }
            }
        }

        if (inner_best_score == INF) {
            break;
        }
        if (best_loopx1 == 1) {
            break;
        }

        for (auto& m : inner_best_commands.commands) {
            if (m.type == D) isPenUp = false;
            if (m.type == U) isPenUp = true;
            best_commands.addCommand(m.type,
                                     (m.type == L || m.type == R)
                                         ? 1
                                         : (m.type == END ? -INF : m.info1),
                                     m.type == FOR ? -INF : m.info2);
        }
        swap(painted, best_painted);
        num_painted = 0;
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                num_painted += int(painted[r][c]);
            }
        }
        lastr = best_lastr;
        lastc = best_lastc;
        lastd = best_lastd;
        debug("#");
    }

    debug(best_commands);
    vector<vector<bool>> none_painted(N, vector<bool>(N, false));
    Simulator sim(best_commands, none_painted, 0, 0, 0, true, 0);
    sim.report();
    cout << best_commands << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    timer.start();
    read_input();
    solve();
    timer.stop();

    cerr << timer.report() << endl;

    return 0;
}
