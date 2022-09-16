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
// #pragma GCC target("avx2")
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

int N;                                    // grid size
int JC;                                   // JUMP COST
int FC;                                   // FOR COST
vector<vector<bool>> GRID;                // N*N
unordered_map<int, int> TARGET_IDXS;      // TARGET_IDXS[to_idx(r,c)] = idx
unordered_map<int, int> REV_TARGET_IDXS;  // REV_TARGET_IDXS[idx] = rc
int TARGET_NUM;

constexpr int dirLen = 8;
constexpr int DR[dirLen] = {0, 1, 1, 1, 0, -1, -1, -1};
constexpr int DC[dirLen] = {1, 1, 0, -1, -1, -1, 0, 1};
///////////////////////////→  ↘  ↓  ↙  ←  ↖  ↑  ↗

inline int to_idx(int r, int c) { return r * N + c; };
inline pair<int, int> to_rc(int idx) { return {idx / N, idx % N}; };

void read_input() {
    cin >> N >> JC >> FC;
    GRID.resize(N, vector<bool>(N));
    TARGET_NUM = 0;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            char a;
            cin >> a;
            GRID[r][c] = (a == '#');
            if (GRID[r][c]) {
                TARGET_IDXS[to_idx(r, c)] = TARGET_NUM;
                REV_TARGET_IDXS[TARGET_NUM] = to_idx(r, c);
                TARGET_NUM++;
            }
        }
    }
}

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
 * @brief The group of operations defined in the problem
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
 * @brief vector of commands
 * @note L and R must be passed with the num of count as info1
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
    // note that the info Command has is different from
    // the args addCommand takes
    void addCommand(const Command& m) {
        addCommand(
            m.type,
            (m.type == L || m.type == R) ? 1 : (m.type == END ? -INF : m.info1),
            m.type == FOR ? -INF : m.info2);
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
 * @brief Calculate scores and areas to be painted from the commands
 *        see the provided program (RobotPainterTester.java)
 */
struct Simulator {
    vector<vector<bool>> g;
    int grid_cost, commands_cost, total_cost;

    int initr, initc, initd;
    bool initpen;
    int initnest;

    int lastr, lastc, lastd;
    int success, fail;

    Simulator() {}

    /**
     * @param painted
     *  if painted == {{false}} then g := vector(N, vector<bool>(N, false))
     */
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
        assert(0 <= initr && initr < N && 0 <= initc && initc < N &&
               0 <= initd && initd < dirLen);
        if (g.size() == 1 && g[0].size() == 1 && g[0][0] == false) {
            g.assign(N, vector<bool>(N, false));
        } else {
            assert(int(g.size()) == N && int(g[0].size()) == N);
        }
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
                    r = (r + DR[dir] + N) % N;
                    c = (c + DC[dir] + N) % N;
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
                    r = (r - DR[dir] + N) % N;
                    c = (c - DC[dir] + N) % N;
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

struct CandInfo {
    int sr, sc, sd;
    int gr, gc, gd;
    int commands_cost;
    vector<Command> raw_commands;
    Bitset painted_tiles;

    CandInfo() {}
    CandInfo(int sr, int sc, int sd, const Commands& _commands,
             const Simulator& sim)
        : sr(sr), sc(sc), sd(sd), gr(sim.lastr), gc(sim.lastc), gd(sim.lastd) {
        assert(!sim.fail);
        assert(sim.initr == 0 && sim.initc == 0);
        assert(_commands.commands[0].type == J);
        raw_commands.assign(_commands.commands.begin() + 1,
                            _commands.commands.end());
        commands_cost = sim.commands_cost;
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                if (sim.g[r][c]) {
                    painted_tiles[to_idx(r, c)] = true;
                }
            }
        }
        assert(sim.success == int(painted_tiles.count()));
    };
};

int get_direction(int dr, int dc) {
    // constexpr int DR[dirLen] = {0, 1, 1, 1, 0, -1, -1, -1};
    // constexpr int DC[dirLen] = {1, 1, 0, -1, -1, -1, 0, 1};
    // ///////////////////////////→  ↘  ↓  ↙  ←  ↖  ↑  ↗
    if (dr == 0 && dc == 0) return -1;
    if (dr == 0) return dc > 0 ? 0 : 4;
    if (dc == 0) return dr > 0 ? 2 : 6;
    if (abs(dr) == abs(dc)) {
        assert(abs(dr) > 0);
        if (dr > 0) {
            return dc > 0 ? 1 : 3;
        } else {
            return dc > 0 ? 7 : 5;
        }
    }
    return -1;
}

bool simple_check(int sr, int sc, int sd, int f1, int r1) {
    assert(GRID[sr][sc]);
    int d = (sd + r1) % dirLen;
    for (int step = 1; step <= f1; step++) {
        if (!GRID[(sr + step * DR[d] + N) % N][(sc + step * DC[d] + N) % N]) {
            return false;
        }
    }
    return true;
}

bool is_good_edge(int f, int sr, int sc, int sd) {
    if (f == 0) return true;
    int loop = 0;
    if (sd % 2 == 0) {
        loop = N;
    } else {
        while (++loop) {
            if (loop > 1000) assert(false);
            if ((DR[sd] * loop + 2 * N) % N == 0 &&
                (DC[sd] * loop + 2 * N) % N == 0) {
                break;
            }
        }
    }
    if (f >= loop - 1) {
        return simple_check(sr, sc, sd, f, 0);
    } else {
        return !GRID[(sr + DR[(sd + 4) % dirLen] + N) % N]
                    [(sc + DC[(sd + 4) % dirLen] + N) % N] &&
               !GRID[(sr + DR[sd] * (f + 1) + 2 * N) % N]
                    [(sc + DC[sd] * (f + 1) + 2 * N) % N];
    }
}

vector<CandInfo> enumerate_candidates() {
    constexpr int TL_ENUM = 5000;

    vector<CandInfo> candidates;

    if (N <= 12) {
        // FOR RFRF
        for (int sr = 0; sr < N; sr++) {
            for (int sc = 0; sc < N; sc++) {
                if (!GRID[sr][sc]) continue;
                for (int sd = 0; sd < dirLen; sd++) {
                    for (int r1 = 0; r1 < dirLen; r1++) {
                        for (int f1 = 0; f1 < N; f1++) {
                            if (f1 == 0 && r1 > 0) continue;
                            if (!simple_check(sr, sc, sd, f1, r1)) break;
                            for (int r2 = 0; r2 < dirLen; r2++) {
                                for (int f2 = 0; f2 < (f1 ? N : 1); f2++) {
                                    if (f2 == 0 && r2 > 0) continue;
                                    Commands best_commands;
                                    Simulator best_sim;
                                    for (int loopx1 = 2; loopx1 <= 10;
                                         loopx1++) {
                                        Commands commands;

                                        // Always add this Jump for the sake of
                                        // cost and implementation convenience
                                        commands.addCommand(J, sr, sc);

                                        commands.addCommand(FOR, loopx1);
                                        commands.addCommandRF(r1, f1);
                                        commands.addCommandRF(r2, f2);
                                        commands.addCommand(END);

                                        Simulator sim(commands, {{false}}, 0, 0,
                                                      sd, false, 0);

                                        if (sim.success && !sim.fail) {
                                            swap(best_commands, commands);
                                            swap(best_sim, sim);
                                        }
                                        if (sim.fail || loopx1 == 10) {
                                            if (!best_commands.commands
                                                     .empty()) {
                                                candidates.emplace_back(
                                                    sr, sc, sd, best_commands,
                                                    best_sim);
                                            }
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    } else {
        // FOR RF
        for (int sr = 0; sr < N; sr++) {
            for (int sc = 0; sc < N; sc++) {
                if (!GRID[sr][sc]) continue;
                for (int sd = 0; sd < dirLen; sd++) {
                    for (int r1 = 0; r1 < dirLen; r1++) {
                        for (int f1 = 0; f1 < N; f1++) {
                            if (f1 == 0 && r1 > 0) continue;
                            if (!simple_check(sr, sc, sd, f1, r1)) break;
                            Commands best_commands;
                            Simulator best_sim;
                            for (int loopx1 = 2; loopx1 <= 10; loopx1++) {
                                Commands commands;

                                // Always add this Jump for the sake of
                                // cost and implementation convenience
                                commands.addCommand(J, sr, sc);

                                commands.addCommand(FOR, loopx1);
                                commands.addCommandRF(r1, f1);
                                commands.addCommand(END);

                                Simulator sim(commands, {{false}}, 0, 0, sd,
                                              false, 0);

                                if (sim.success && !sim.fail) {
                                    swap(best_commands, commands);
                                    swap(best_sim, sim);
                                }
                                if (sim.fail || loopx1 == 10) {
                                    if (!best_commands.commands.empty()) {
                                        candidates.emplace_back(sr, sc, sd,
                                                                best_commands,
                                                                best_sim);
                                    }
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
        debug(candidates.size());
    }

    // RF
    for (int sr = 0; sr < N; sr++) {
        for (int sc = 0; sc < N; sc++) {
            if (!GRID[sr][sc]) continue;
            for (int sd = 0; sd < dirLen; sd++) {
                for (int f1 = 0; f1 < N; f1++) {
                    if (!is_good_edge(f1, sr, sc, sd)) {
                        continue;
                    }
                    for (int r1 = 0; r1 < 1 /*dirLen*/; r1++) {
                        if (f1 == 0 && r1 > 0) continue;
                        if (!simple_check(sr, sc, sd, f1, r1)) break;

                        Commands commands;

                        // Always add this Jump for the sake of cost and
                        // implementation convenience
                        commands.addCommand(J, sr, sc);

                        commands.addCommandRF(r1, f1);

                        Simulator sim(commands, {{false}}, 0, 0, sd, false, 0);

                        if (sim.success && !sim.fail) {
                            candidates.emplace_back(sr, sc, sd, commands, sim);
                        }
                    }
                }
            }
        }
    }
    debug(candidates.size());

    // FOR FJ
    vector<int> Ps1(N), Ps2(N);
    iota(Ps1.begin(), Ps1.end(), 0);
    iota(Ps2.begin(), Ps2.end(), 0);
    myrand.shuffle(Ps1);
    myrand.shuffle(Ps2);
    for (int _sr = 0; _sr < N; _sr++) {
        int sr = Ps1[_sr];
        for (int _sc = 0; _sc < N; _sc++) {
            int sc = Ps2[_sc];
            if (timer.ms() > TL_ENUM) {
                break;
            }
            if (!GRID[sr][sc]) continue;
            for (int sd = 0; sd < dirLen; sd++) {
                for (int dr = 0; dr < N; dr++) {
                    for (int dc = 0; dc < N; dc++) {
                        if (dr == 0 && dc == 0) {
                            continue;
                        }
                        for (int f1 = 0; f1 < N; f1++) {
                            int dir_of_dr_dc =
                                get_direction((f1 * DR[sd] + dr + N) % N,
                                              (f1 * DC[sd] + dc + N) % N);
                            if (dir_of_dr_dc == -1 ||
                                (sd % 4 == dir_of_dr_dc % 4)) {
                                continue;
                            }
                            if (!is_good_edge(f1, sr, sc, sd)) continue;

                            Commands best_commands;
                            Simulator best_sim;
                            for (int loopx1 = 2; loopx1 <= 10; loopx1++) {
                                Commands commands;

                                // Always add this Jump for the sake of cost and
                                // implementation convenience
                                commands.addCommand(J, sr, sc);

                                commands.addCommand(FOR, loopx1);
                                commands.addCommand(F, f1);
                                commands.addCommand(J, dr, dc);
                                commands.addCommand(END);

                                Simulator sim(commands, {{false}}, 0, 0, sd,
                                              false, 0);

                                if (sim.success && !sim.fail) {
                                    swap(best_commands, commands);
                                    swap(best_sim, sim);
                                }
                                if (sim.fail || loopx1 == 10) {
                                    if (!best_commands.commands.empty()) {
                                        candidates.emplace_back(sr, sc, sd,
                                                                best_commands,
                                                                best_sim);
                                    }
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    debug(candidates.size());

    return candidates;
}

int del_cand_failed_cnt = 0;
CandInfo find_best_cand(vector<CandInfo>& candidates, Bitset& painted,
                        int lastr, int lastc, int lastd, double cost_e1,
                        double effect_e1) {
    int best_idx = -1;
    double best_cost_effectiveness = 0.0;
    painted.flip();
    double cost_e2 = 1.5 + cost_e1 + 0.5 * myrand.random();
    double effect_e2 = 1.0 + effect_e1 + 0.5 * myrand.random();
    for (int i = 0; i < int(candidates.size()); i++) {
        const CandInfo& cand = candidates[i];
        double cost = cand.commands_cost + abs(cand.sd - lastd) +
                      (cand.sr == lastr && cand.sc == lastc ? 0 : JC);
        double effect = (cand.painted_tiles & painted).count();
        cost = powf(cost, cost_e2);
        effect = powf(effect, effect_e2);
        if (chmax(best_cost_effectiveness, effect / cost)) {
            best_idx = i;
        }
    }
    painted.flip();
    if (best_cost_effectiveness <= 1e-10) {
        assert(false);
    }
    const CandInfo ret = candidates[best_idx];
    if (del_cand_failed_cnt < 10) {
        size_t ret_count = ret.painted_tiles.count();
        size_t bef_candidates_size = candidates.size();
        candidates.erase(
            remove_if(
                candidates.begin(), candidates.end(),
                [&](const CandInfo& cand) {
                    return (cand.painted_tiles | ret.painted_tiles).count() ==
                               ret_count &&
                           ret.commands_cost < cand.commands_cost;
                }),
            candidates.end());
        debug(candidates.size());
        if (bef_candidates_size == candidates.size()) {
            del_cand_failed_cnt++;
        }
    }
    return ret;
}

auto solve() {
    del_cand_failed_cnt = 0;
    vector<CandInfo> candidates = enumerate_candidates();

    int TL = 9000;

    int outer_loop_cnt = 0;
    int outer_best_score = INF;
    Commands outer_best_commands;
    Simulator outer_best_sim;

    while (timer.ms() < TL) {
        outer_loop_cnt++;

        Commands best_commands;
        bool isPenUp = true;
        int lastr = 0, lastc = 0, lastd = 0;
        Bitset painted(0);
        int num_painted = 0;

        double cost_e1 = myrand.random();
        double efffect_e1 = myrand.random();

        while (num_painted < TARGET_NUM) {
            auto info = find_best_cand(candidates, painted, lastr, lastc, lastd,
                                       cost_e1, efffect_e1);

            if (info.sd != lastd) {
                best_commands.addCommand(info.sd > lastd ? R : L,
                                         abs(info.sd - lastd));
            }
            if (info.sr != lastr || info.sc != lastc) {
                best_commands.addCommand(J, info.sr - lastr, info.sc - lastc);
            }
            if (isPenUp) {
                isPenUp = false;
                best_commands.addCommand(D);
            }
            for (auto& m : info.raw_commands) {
                if (m.type == D) isPenUp = false;
                if (m.type == U) isPenUp = true;
                best_commands.addCommand(m);
            }

            Simulator sim(best_commands, {{false}}, 0, 0, 0, true, 0);

            lastr = sim.lastr;
            lastc = sim.lastc;
            lastd = sim.lastd;

            for (int r = 0; r < N; r++) {
                for (int c = 0; c < N; c++) {
                    if (sim.g[r][c] && !painted[to_idx(r, c)]) {
                        num_painted++;
                        painted[to_idx(r, c)] = true;
                    }
                }
            }
        }

        assert(num_painted == int(painted.count()));
        Simulator sim(best_commands, {{false}}, 0, 0, 0, true, 0);

        if (chmin(outer_best_score, sim.total_cost)) {
            swap(outer_best_commands, best_commands);
            swap(outer_best_sim, sim);
        }
    }

    debug(outer_loop_cnt);

    outer_best_sim.report();
    return outer_best_commands;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    timer.start();
    read_input();
    auto ans = solve();
    timer.stop();

    cerr << timer.report() << endl;
    assert(timer.ms() < 9800);

    cout << ans << endl;

    return 0;
}
