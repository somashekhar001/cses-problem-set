// somashekhar
 
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
 
using namespace std;
 
typedef long long int ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
#define pb push_back
#define F first
#define S second
 
const ll mod = 1e9 + 7;
 
// sqrt function  O(log n)
ll mysqrt(ll x)
{
 
     ll low = 1;
     ll high = 1e9;
     ll best = 1;
     while (low <= high)
     {
 
          ll mid = (low + high) >> 1LL;
          if (mid * mid <= x)
          {
 
               low = mid + 1;
               best = mid;
               continue;
          }
          high = mid - 1;
     }
 
     return best;
}
 
 
// fast exponentiation
ll power(ll a, ll n,ll mod)
{
 
     a = a % mod;
     ll ans = 1;
     while (n > 0)
     {
 
          if (n & 1)
               ans = ans * a % mod;
          a = a * a % mod;
          n = n >> 1;
     }
 
     return ans;
}
 
// subset generation
vector<vector<ll>> subsets(vi arr)
{
 
     ll n = arr.size();
     vector<vector<ll>> Allsubsets((1LL << n), vector<ll>());
 
     for (int i = 0; i < (1LL << n); i++)
     {
 
          ll index = 0;
          vector<ll> subset;
          for (int j = i; j > 0; j >>= 1)
          {
 
               if (j & 1)
               {
 
                    subset.push_back(arr[index]);
               }
               index++;
          }
          Allsubsets[i] = (subset);
     }
 
     return Allsubsets;
}
 
// gcd function
 
// fenwick tree
class fenwicktree
{
 
public:
     vector<ll> bit;
     ll size;
 
     void init(ll n)
     {
 
          size = n;
          bit.assign(n, 0);
     }
 
     void build(vi arr)
     {
 
          for (int i = 0; i < arr.size(); i++)
          {
 
               add(arr[i], i);
          }
     }
 
     void add(ll val, ll index)
     {
 
          for (; index < size; index = index | (index + 1))
          {
 
               bit[index] += val;
          }
     }
 
     ll sum(ll index)
     {
 
          ll result = 0;
          for (; index >= 0; index = (index & (index + 1)) - 1)
          {
 
               result += bit[index];
          }
 
          return result;
     }
 
     ll sum(ll l, ll r)
     {
          if (l >= 1)
               return sum(r) - sum(l - 1);
          else
               return sum(r);
     }
 
     void set(ll i, ll val, ll check)
     {
          add(-check, i);
          add(val, i);
     }
};
// segment tree
struct node
{
     ll sum = 0LL;
};
class segmenttree
{
 
public:
     vector<node> tree;
 
     ll size;
 
     void init(ll n)
     {
 
          size = 1;
          while (size < n)
               size = size * 2;
          node temp;
          tree.assign(size * 2, temp);
     }
 
     node merge(node t1, node t2)
     {
 
          node result;
          result.sum = t1.sum + t2.sum;
 
          return result;
     }
 
     void build(vector<ll> &arr)
     {
 
          build(arr, 0, 0, size);
     }
 
     void build(vector<ll> &arr, ll cur, ll beg, ll end)
     {
 
          if (end - beg == 1)
          {
               if (beg < arr.size())
                    tree[cur].sum = arr[beg];
               return;
          }
          else
          {
 
               ll mid = (beg + end) / 2;
               build(arr, 2 * cur + 1, beg, mid);
               build(arr, 2 * cur + 2, mid, end);
 
               tree[cur] = merge(tree[2 * cur + 1], tree[2 * cur + 2]);
          }
     }
 
     void set(ll i, ll val)
     {
 
          set(i, val, 0, 0, size);
     }
 
     void set(ll i, ll val, ll cur, ll beg, ll end)
     {
 
          if (end - beg == 1)
          {
 
               tree[cur].sum = val;
               return;
          }
          else
          {
 
               ll mid = (beg + end) / 2;
               if (i < mid)
               {
 
                    set(i, val, 2 * cur + 1, beg, mid);
               }
               else
               {
                    set(i, val, 2 * cur + 2, mid, end);
               }
 
               tree[cur] = merge(tree[2 * cur + 1], tree[2 * cur + 2]);
          }
     }
 
     ll sum(ll l, ll r)
     {
 
          node result = sum(l, r, 0, 0, size);
          return result.sum;
     }
 
     node sum(ll l, ll r, ll cur, ll beg, ll end)
     {
 
          node result;
          result.sum = 0;
 
          if (beg >= r || end <= l)
          {
 
               return result;
          }
          if (beg >= l && end <= r)
          {
 
               return tree[cur];
          }
          else
          {
 
               ll mid = (beg + end) / 2;
 
               node left = sum(l, r, 2 * cur + 1, beg, mid);
               node right = sum(l, r, 2 * cur + 2, mid, end);
 
               result.sum += left.sum + right.sum;
               return result;
          }
     }
 
     void show()
     {
 
          for (auto c : tree)
          {
               cout << c.sum << " ";
          }
 
          cout << "\n";
     }
};
 
 
// suffix array
vi suffixarray(string s)
{
 
     s += '$';
     ll n = s.length();
     vi p(n), c(n);
     vector<pair<char, int>> a(n);
 
     for (int i = 0; i < n; i++)
     {
 
          a[i] = {s[i], i};
     }
 
     sort(a.begin(), a.end());
 
     for (int i = 0; i < n; i++)
     {
 
          p[i] = a[i].second;
     }
 
     c[p[0]] = 0;
 
     for (int i = 1; i < n; i++)
     {
 
          if (a[i].first == a[i - 1].first)
          {
 
               c[p[i]] = c[p[i - 1]];
          }
          else
          {
 
               c[p[i]] = c[p[i - 1]] + 1;
          }
     }
     auto radix_sort = [&](vector<pair<pi, int>> &a)
     {
          {
               vi count(n, 0);
 
               for (int i = 0; i < n; i++)
               {
 
                    count[a[i].first.second]++;
               }
 
               vector<pair<pi, int>> a_new(n);
               vi pos(n);
               pos[0] = 0;
 
               for (int i = 1; i < n; i++)
               {
 
                    pos[i] = pos[i - 1] + count[i - 1];
               }
 
               for (int i = 0; i < n; i++)
               {
 
                    a_new[pos[a[i].first.second]] = a[i];
                    pos[a[i].first.second]++;
               }
               a = a_new;
          }
     {
               vi count(n, 0);
 
               for (int i = 0; i < n; i++)
               {
 
                    count[a[i].first.first]++;
               }
 
               vector<pair<pi, int>> a_new(n);
               vi pos(n);
               pos[0] = 0;
 
               for (int i = 1; i < n; i++)
               {
 
                    pos[i] = pos[i - 1] + count[i - 1];
               }
 
               for (int i = 0; i < n; i++)
               {
 
                    a_new[pos[a[i].first.first]] = a[i];
                    pos[a[i].first.first]++;
               }
               a = a_new;
          }
     };
     ll k = 0;
 
     while ((1 << k) < n)
     {
 
          vector<pair<pi, int>> a(n);
 
          for (int i = 0; i < n; i++)
          {
 
               a[i] = {{c[i], c[(i + (1 << k)) % n]}, i};
          }
 
          radix_sort(a);
 
          for (int i = 0; i < n; i++)
          {
 
               p[i] = a[i].second;
          }
 
          c[p[0]] = 0;
 
          for (int i = 1; i < n; i++)
          {
 
               if (a[i].first == a[i - 1].first)
               {
 
                    c[p[i]] = c[p[i - 1]];
               }
               else
               {
 
                    c[p[i]] = c[p[i - 1]] + 1;
               }
          }
          k++;
     }
    
     return p;
}
 
ll hash1(string s){
     ll sum=0,pow=1;
     ll n=s.length();
     ll p=31;
     for(int i=0;i<n;i++){
          sum+=((s[i]-'a'+1)*pow)%mod;
          pow*=(p);
          pow%=mod;
     }
     return sum;
}
//kmp 
vi  KMP(string s){
     
     ll n=s.length();
     vi p(n+1);
     p[0]=-1;
     
     for(int i=1;i<=n;i++){
        
        ll k=p[i-1];
        
        while(k>=0 && s[i-1]!=s[k]){
         
              k=p[k];
        }
        p[i]=k+1;
     }
     return p;
}
vi Zfunc(string s){
     
     ll n=s.length();
     vi z(n+1,0);
     ll l=0;
     z[1]=0;
     for(int i=1;i<n;i++){
       
        z[i]=min(z[i-l],l+z[l]-i);
        z[i]=max(z[i],0LL);
     
        while(s[z[i]]==s[i+z[i]]){
              
              z[i]++;
        }
        if(z[i]+i>l+z[l]){
          l=i;
        }
 
     }
 
     return z;
}
// solve
void solve()
{
  
  string s;
  cin>>s;
  ll n=s.length();
  vi a=Zfunc(s);
  vi b=KMP(s);
  for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
  }
  cout<<endl;
  for(int i=1;i<=n;i++){
    cout<<b[i]<<" ";
  }
}
int main()
{
 
     ios::sync_with_stdio(0);
     cin.tie(0);
 
     // freopen("input.txt", "r", stdin);
     // freopen("output.txt", "w", stdout);
 
     solve();
 
     return 0;
}