import sys

def inp():
    return sys.stdin.readline().strip()
def inplist():
    return list(map(int, inp().split()))

def debug(*args):
    print("DEBUG:", *args, file=sys.stderr)

def solve():
    # Your code here
    pass

def main():
    t = 1
    t = int(inp())
    for _ in range(t):
        solve()

if __name__ == "__main__":
    main()
