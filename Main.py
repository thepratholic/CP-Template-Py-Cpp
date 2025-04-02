from collections import Counter,deque
from collections import defaultdict
import math
import  bisect
import heapq
import itertools 
import sys
import string
from fractions import Fraction
    
def pollard_rho(n):
    
    if n & 1 == 0:
        return 2
    if n % 3 == 0:
        return 3
 
    s = ((n - 1) & (1 - n)).bit_length() - 1
    d = n >> s
    for a in [2, 325, 9375, 28178, 450775, 9780504, 1795265022]:
        p = pow(a, d, n)
        if p == 1 or p == n - 1 or a % n == 0:
            continue
        for _ in range(s):
            prev = p
            p = (p * p) % n
            if p == 1:
                return math.gcd(prev - 1, n)
            if p == n - 1:
                break
        else:
            for i in range(2, n):
                x, y = i, (i * i + 1) % n
                f = math.gcd(abs(x - y), n)
                while f == 1:
                    x, y = (x * x + 1) % n, (y * y + 1) % n
                    y = (y * y + 1) % n
                    f = math.gcd(abs(x - y), n)
                if f != n:
                    return f
    return n
 
 
 
def prime_factors(n):
    
    if n <= 1:
        return Counter()
    f = pollard_rho(n)
    return Counter([n]) if f == n else prime_factors(f) + prime_factors(n // f)
                
def modexp(a, b, m):
    a %= m
    res = 1
    while b > 0:
        if b & 1:
            res = res * a % m
        a = a * a % m
        b >>= 1
    return res 
 
def gp(k, n):
    
    res = (1/k) * (1 - (1/k)**n) / (1 - 1/k)
    return res
 
def binpow(a,b):
    res = 1
    while b > 0:
        if b & 1:
            res *= a
        a *= a
        b >>= 1
    return res
 
def phi(n):
    res=n
    i=2
    while i*i<=n:
        if n%i==0:
            while n%i==0:
                n/=i
            res-=res/i
        i+=1
    if n>1:
        res-=res/n
        
    return int(res)
            
def ttt(x):
    d=[]
    for i in range(1,int(math.sqrt(x))+1):
        if x%i==0:
            d.append(i)
            if x//i!=i:
                d.append(x//i)
    return d

def lcm(a,b):
   return a*b//math.gcd(a,b)
 
def psum(a):
    psum = [0]
    for i in a:
        psum.append(psum[-1] + i)
    return psum
 
def sos(x):
    s=str(x)
    res=[int(s[i]) for i in range(len(s))]
    return sum(res)

def ar(a,n):
    d=a[1]-a[0]
    for i in range(1,n-1):
        if d!=a[i+1]-a[i]:
            return False
    return True

def pref_suff_gcd(a,n):
    a=[0]+a
    pref=[0]*(n+2)
    suff=[0]*(n+2)
    for i in range(1,n+1):
        pref[i]=math.gcd(pref[i-1],a[i])
    for i in range(n,0,-1):
        suff[i]=math.gcd(suff[i+1],a[i])
    return pref,suff
def binomial(n,k):
    dp = [[0] * (k + 1) for _ in range(n + 1)]
    for i in range(n + 1):
        dp[i][0] = 1
        if i <= k:
            dp[i][i] = 1
    for i in range(n + 1):
        for j in range(1, min(i, k) + 1):
            if i != j:
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j])

    return dp[n][k] 

def bisectll(v, x):
    l, r = -1, len(v)
    while r > l + 1:
        m = (l + r) // 2
        if v[m] > x:
            r = m
        else:
            l = m
    return l

def bisectrr(v, x):
    l, r = -1, len(v)
    while r > l + 1:
        m = (l + r) // 2
        if v[m] < x:
            l = m
        else:
            r = m
    return r

def connected(v,n):
    reach = [False] * n
    que = deque()
    reach[0] = True
    que.append(0)
    while que:
        u = que.popleft()
        for e in v[u]:
            if not reach[e]:
                reach[e] = True
                que.append(e)

    for i in range(n):
        if not reach[i]:
            return False
    return True

def cycle(node,vis,rec,v):
    vis[node]=True
    rec[node]=True
    for e in v[node]:
        if not vis[e]:
            if cycle(e,vis,rec,v):
                return True
        elif rec[e]:
            return True
    rec[node]=False
    return False
def bipartite(v):
    graph = defaultdict(list)

    for i in range(len(v)):
        x1, y1 = v[i]
        for j in range(i + 1, len(v)):
            x2, y2 = v[j]
            if x1 == x2 or y1 == y2:
                graph[i].append(j)
                graph[j].append(i)
    return graph

def cyclic(v,n):
    rec=[False]*n
    vis=[False]*n
    for i in range(n):
        if not vis[i]:
            if cycle(i,vis,rec,v):
                return True
    return False
    

def dfds(s):
    stack=[s]
    ver=1
    e=0
    while stack:
        x=stack.pop()
        vis[x]=True
        for i in v[x]:
            e+=1
            if not vis[i]:
                ver+=1
                vis[i]=True
                stack.append(i)
    return e==ver



def mss(arr):
    max_sum = float('-inf')
    curr_sum = 0

    for num in arr:
        curr_sum = max(num, curr_sum + num)
        max_sum = max(max_sum, curr_sum)

    return max_sum

def lss(arr):
    min_sum = float('inf')
    curr_sum = 0

    for num in arr:
        curr_sum = min(num, curr_sum + num)
        min_sum = min(min_sum, curr_sum)

    return min_sum



def sieve(n):
    p=[]
    prime=[True]*(n+1)
    i=2
    while i*i<=n:
        if prime[i]:
            for j in range(i*i,n+1,i):
                prime[j]=False
        i+=1
    j=1
    for e in range(2,n+1):
        if prime[e]:
            p.append(e)
    return p


def dsu_find(a):
    if parent[a] == a:
        return a
    leader=dsu_find(parent[a])
    parent[a]=leader
    return leader

def dsu_union(a, b):
    leader_a = dsu_find(a)
    leader_b = dsu_find(b)
    if leader_a != leader_b:
        if size[leader_a] < size[leader_b]:
            leader_a, leader_b = leader_b, leader_a
        parent[leader_b] = leader_a
        size[leader_a] += size[leader_b]





                
                
       




