mem={}
def fibo(n):
    if n in mem:
        return mem[n]
    if n==0:
        val=0
    elif n==1:
        val=1
    elif n>=2:
        val=fibo(n-1)+fibo(n-2)
    mem[n]=val
    return val

for x in range(1000):
    print(fibo(x))

