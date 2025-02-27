#include "bits/stdc++.h"

using namespace std;

template <typename T> std::ostream &operator<<(std::ostream &stream, const vector<T> &vec) {for (size_t i = 0; i < vec.size(); i++) { stream << vec[i]; if (i != vec.size() - 1) stream << ' '; }; return stream; } template <typename T> std::istream &operator>>(std::istream &stream, vector<T> &vec) {for (T &x : vec) stream >> x; return stream; } template <typename T, typename U> std::ostream &operator<<(std::ostream &stream, const pair<T, U> &pr) {stream << pr.first << ' ' << pr.second; return stream; } template <typename T, typename U> std::istream &operator>>(std::istream &stream, pair<T, U> &pr) {stream >> pr.first >> pr.second; return stream; } template <typename A, typename B> string to_string(pair<A, B> p); template <typename A, typename B, typename C> string to_string(tuple<A, B, C> p); template <typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> p); string to_string(const string &s) { return '"' + s + '"'; } string to_string(char c) {string s; s += c; return s; } string to_string(const char *s) { return to_string((string)s); } string to_string(bool b) { return (b ? "1" : "0"); } string to_string(vector<bool> v) {bool first = true; string res = "{"; for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) {res += ", "; } first = false; res += to_string(v[i]); } res += "}"; return res; } template <size_t N> string to_string(bitset<N> v) {string res = ""; for (size_t i = 0; i < N; i++) {res += static_cast<char>('0' + v[i]); } return res; } template <typename A> string to_string(A v) {bool first = true; string res = "{"; for (const auto &x : v) {if (!first) {res += ", "; } first = false; res += to_string(x); } res += "}"; return res; } template <typename A, typename B> string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; } template <typename A, typename B, typename C> string to_string(tuple<A, B, C> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")"; } template <typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")"; } void debug_out() { cout << endl; } template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {cout << " " << to_string(H); debug_out(T...); }

#define thepratholic ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define int            long long
#define double         long double
#define endl           "\n"
#define all(x)         x.begin(), x.end()
#define v              vector
#define vi             vector<int>
#define vvi            vector<vector<int>>
#define pii            pair<int, int>
#define mpci           map<char, int>
#define mpii           map<int, int>
#define pb             emplace_back
#define mp             make_pair
#define F              first
#define S              second
#define si             set<int>
#define msi            multiset<int>
#define maxn           1000005
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)


int gcd(int a, int b) { if (b == 0) return a; return gcd(b, a % b);}
int power(int a, int b, int m) { int ans = 1; while (b) { if (b & 1) ans = (ans * a) % m; b /= 2; a = (a * a) % m; } return ans; }
int lcm(int a, int b) { return (a * b) / gcd(a, b); }
int modInverse(int a, int m) { return power(a, m - 2, m); }
int modAdd(int a, int b, int m) { return ((a % m) + (b % m)) % m; }
int modMul(int a, int b, int m) { return ((a % m) * (b % m)) % m; }
int modSub(int a, int b, int m) { return ((a % m) - (b % m) + m) % m; }
int modDiv(int a, int b, int m) { return (modMul(a, modInverse(b, m), m) + m) % m; }
bool isPrime(int n) { if (n <= 1) return false; if (n <= 3) return true; if (n % 2 == 0 || n % 3 == 0) return false; for (int i = 5; i * i <= n; i = i + 6) if (n % i == 0 || n % (i + 2) == 0) return false; return true; }
int nCr(int n, int r) { if (r > n - r) r = n - r; int ans = 1; for (int i = 0; i < r; i++) { ans *= (n - i); ans /= (i + 1); } return ans; }
int nCrModP(int n, int r, int p) { if (r > n - r) r = n - r; int C[r + 1]; memset(C, 0, sizeof(C)); C[0] = 1; for (int i = 1; i <= n; i++) { for (int j = min(i, r); j > 0; j--) C[j] = (C[j] + C[j - 1]) % p; } return C[r]; }
int nPr(int n, int r) { int ans = 1; for (int i = 0; i < r; i++) ans *= (n - i); return ans; }
int nPrModP(int n, int r, int p) { int ans = 1; for (int i = 0; i < r; i++) ans = (ans * (n - i)) % p; return ans; }
int log(int num , int base){int ans = 0; while(num){num /= base;ans++;} return ans;}
int countSetBits(int x){int ans = 0;while(x){ans += (x&1);x >>= 1;}return ans;}



int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

bool testcases = 0;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct TreapNode {
    int val;            
    int priority;       
    int size;           
    bool rev;           
    TreapNode* left;   
    TreapNode* right;  

    TreapNode(int _val) 
        : val(_val), 
          priority(rng()), 
          size(1), 
          rev(false), 
          left(nullptr), 
          right(nullptr) {}
};

struct Treap {
    TreapNode* root;

    Treap() : root(nullptr) {}

    int getSize(TreapNode* node) {
        return node ? node->size : 0;
    }

    void update(TreapNode* node) {
        if (node) {
            node->size = 1 + getSize(node->left) + getSize(node->right);
        }
    }
    void push(TreapNode* node) {
        if (node && node->rev) {
            swap(node->left, node->right);
            if (node->left) node->left->rev ^= true;
            if (node->right) node->right->rev ^= true;
            node->rev = false;
        }
    }

    void split(TreapNode* node, int key, TreapNode*& left, TreapNode*& right) {
        if (!node) {
            left = right = nullptr;
            return;
        }
        push(node);
        int currentKey = getSize(node->left) + 1;
        if (key < currentKey) {
            split(node->left, key, left, node->left);
            right = node;
        } else {
            split(node->right, key - currentKey, node->right, right);
            left = node;
        }
        update(node);
    }

    TreapNode* merge(TreapNode* left, TreapNode* right) {
        if (!left || !right)
            return left ? left : right;
        if (left->priority > right->priority) {
            push(left);
            left->right = merge(left->right, right);
            update(left);
            return left;
        } else {
            push(right);
            right->left = merge(left, right->left);
            update(right);
            return right;
        }
    }

    TreapNode* build(const vector<int>& arr, int l, int r) {
        if (l > r) return nullptr;
        int mid = l + (r - l) / 2;
        TreapNode* node = new TreapNode(arr[mid]);
        node->left = build(arr, l, mid - 1);
        node->right = build(arr, mid + 1, r);
        update(node);
        return node;
    }

    void initialize(const vector<int>& arr) {
        root = build(arr, 0, arr.size() - 1);
    }

    int getIndex(int index) {
        return getIndex(root, index);
    }

    int getIndex(TreapNode* node, int index) {
        push(node);
        int currentIndex = getSize(node->left) + 1;
        if (index == currentIndex)
            return node->val;
        else if (index < currentIndex)
            return getIndex(node->left, index);
        else
            return getIndex(node->right, index - currentIndex);
    }

    void reverseRange(int l, int r) {
        TreapNode *left, *middle, *right;
        split(root, l - 1, left, middle);
        split(middle, r - l + 1, middle, right);
        if (middle) {
            middle->rev ^= true;
        }
        root = merge(merge(left, middle), right);
    }
};

void solve() {
    // Your code goes here

}


int32_t main()
{
    thepratholic 
    int t = 1;
    testcases and cin >> t;
    while(t--) solve();
}