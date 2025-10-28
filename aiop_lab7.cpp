// ЛР 7. Задачи на break/continue, вложенные циклы
// Компилятор: C++17
#include <bits/stdc++.h>
using namespace std;

// 1) Простые числа до N
vector<int> primesUpTo(int N){
    vector<int> primes;
    if(N < 2) return primes;
    vector<bool> isPrime(N+1, true);
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i*i<=N;++i){
        if(isPrime[i]){
            for(int j=i*i;j<=N;j+=i) isPrime[j]=false;
        }
    }
    for(int i=2;i<=N;++i) if(isPrime[i]) primes.push_back(i);
    return primes;
}

// 2) Таблица умножения 1..10
void multTable(){
    for(int i=1;i<=10;++i){
        for(int j=1;j<=10;++j){
            cout<<setw(4)<<i*j;
        }
        cout<<"\n";
    }
}

// 3) НОК двух чисел
long long gcdll(long long a, long long b){
    while(b){ long long t=a%b; a=b; b=t; }
    return a;
}
long long lcmll(long long a, long long b){
    if(a==0||b==0) return 0;
    return llabs(a / gcdll(a,b) * b);
}

// 4) Палиндром (число)
bool isPal(long long x){
    string s = to_string(llabs(x));
    string t = s; reverse(t.begin(), t.end());
    return s==t;
}

// 5) Пропущенные из 1..N
vector<int> missingFrom1toN(int N, const vector<int>& seq){
    vector<bool> seen(N+1,false);
    for(int v: seq){
        if(1<=v && v<=N) seen[v]=true;
    }
    vector<int> miss;
    for(int i=1;i<=N;++i) if(!seen[i]) miss.push_back(i);
    return miss;
}

// 6) Фибоначчи
bool isPerfectSquare(long long x){
    if(x<0) return false;
    long long r = llround(sqrt((long double)x));
    return r*r==x || (r-1)*(r-1)==x || (r+1)*(r+1)==x;
}
bool inFibonacci(long long n){
    return isPerfectSquare(5*n*n+4) || isPerfectSquare(5*n*n-4);
}

// 7) Числа 1..100, кратные k
vector<int> divisibleByK(int k){
    vector<int> out;
    if(k==0) return out;
    for(int i=1;i<=100;++i) if(i%k==0) out.push_back(i);
    return out;
}

// 8) Среднее арифметическое
double average(const vector<double>& a){
    if(a.empty()) return 0.0;
    long double s=0; for(double v:a) s+=v;
    return (double)(s/a.size());
}

// 9) Первые N простых
vector<int> firstNPrimes(int N){
    vector<int> out;
    if(N<=0) return out;
    for(int x=2; (int)out.size()<N; ++x){
        bool ok=true;
        for(int p: out){
            if(1LL*p*p> x) break;
            if(x%p==0){ ok=false; break; }
        }
        if(ok) out.push_back(x);
    }
    return out;
}

// 10) Квадраты 1..M
vector<long long> squaresUpTo(int M){
    vector<long long> out;
    for(long long i=1;i<=M;++i) out.push_back(i*i);
    return out;
}

void printVec(const vector<int>& v){
    for(size_t i=0;i<v.size();++i){
        if(i) cout<<" ";
        cout<<v[i];
    }
    cout<<"\n";
}
template<class T>
void printVecT(const vector<T>& v){
    for(size_t i=0;i<v.size();++i){
        if(i) cout<<" ";
        cout<<v[i];
    }
    cout<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout<<"ЛР7: выберите задание (1..10), 0 — выход:\n";
    int m; 
    while ( (cout<<"> ", cin>>m) ){
        if(m==0) break;
        switch(m){
            case 1:{
                int N; cout<<"N= "; cin>>N;
                auto v=primesUpTo(N);
                printVec(v);
                break;
            }
            case 2:{
                multTable(); 
                break;
            }
            case 3:{
                long long a,b; cout<<"a b= "; cin>>a>>b;
                cout<<"LCM= "<<lcmll(a,b)<<"\n";
                break;
            }
            case 4:{
                long long x; cout<<"x= "; cin>>x;
                cout<<(isPal(x)?"PALINDROME\n":"NOT PALINDROME\n");
                break;
            }
            case 5:{
                int N, k; cout<<"N и кол-во элементов k= "; cin>>N>>k;
                vector<int> seq(k); for(int i=0;i<k;++i) cin>>seq[i];
                auto miss = missingFrom1toN(N, seq);
                printVec(miss);
                break;
            }
            case 6:{
                long long n; cout<<"n= "; cin>>n;
                cout<<(inFibonacci(n)?"YES\n":"NO\n");
                break;
            }
            case 7:{
                int k; cout<<"k= "; cin>>k;
                auto v=divisibleByK(k);
                printVec(v);
                break;
            }
            case 8:{
                int k; cout<<"кол-во элементов k= "; cin>>k;
                vector<double> a(k); for(int i=0;i<k;++i) cin>>a[i];
                cout.setf(std::ios::fixed); cout<<setprecision(6)<<average(a)<<"\n";
                break;
            }
            case 9:{
                int N; cout<<"N= "; cin>>N;
                auto v=firstNPrimes(N);
                printVec(v);
                break;
            }
            case 10:{
                int M; cout<<"M= "; cin>>M;
                auto v=squaresUpTo(M);
                printVecT(v);
                break;
            }
            default: cout<<"Нет такого задания.\n";
        }
    }
    return 0;
}
