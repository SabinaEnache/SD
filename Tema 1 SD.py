import random
import time
n=int(input("Elementul maxim"))
maxx=int(input("Nr de elemente"))
L=[]
L.append("Nr de elemente este")
L.append(maxx)
L.append("si elementul maxim este")
L.append(n)

vector=[random.randint(0,n) for _ in range(maxx)]
print("Vectorul nesortat:",vector)
start=time.time()
vector.sort()
stop=time.time()
print("Timpul de executare este pentru implicit: ",stop-start)
print("Vectorul sortat: ")
print(vector)
L.append("Timpul de executare este pentru implicit: ")
L.append(stop-start)
print("\n")

#mergesort
def mergesort(v):
    if len(v) >1:
        mid = len(v)//2
        l=v[:mid]
        r=v[mid:]
        mergesort(l)
        mergesort(r)
        i = j = k = 0
        while i < len(l) and j < len(r):
            if l[i] <= r[j]:
                v[k] = l[i]
                i += 1
                k += 1
            else:
                v[k] = r[j]
                j += 1
                k += 1
        while i < len(l):
            v[k] = l[i]
            i += 1
            k += 1

        while j < len(r):
            v[k] = r[j]
            j += 1
            k += 1
    return v
vector=[random.randint(0,n) for _ in range(maxx)]
print("Vectorul nesortat:",vector)
start=time.time()
A = mergesort(vector)
stop=time.time()
print("Timpul de executare este pentru mergesort: ",stop-start)
print("Vectorul sortat: ",A)
L.append("Timpul de executare este pentru mergesort: ")
L.append(stop-start)
print("\n")

#shellsort
def shellsort(v,n):
    gap = n // 2
    while gap > 0:
        i = gap
        while i < n:
            j = i-gap
            while j >= 0:
                if v[j] > v[j+gap]:
                    v[j],v[j+gap] = v[j+gap], v[j]
                else:
                    break;
                j = j - gap
            i += 1
        gap = gap // 2
    return v
vector=[random.randint(0,n) for _ in range(maxx)]
print("Vectorul nesortat:",vector)
start=time.time()
A = shellsort(vector, len(vector))
stop=time.time()
print("Timpul de executare este pentru shellsort: ",stop-start)
print("Vectorul sortat: ",A)
L.append("Timpul de executare este pentru shellsort: ")
L.append(stop-start)
print("\n")

#radixsort care se ajuta de countsort
def radixsort(v):
    max_nr = max(v)
    p = 1
    while max_nr // p > 0:
        countsort(v, p)
        p *= 10
    return v

def countsort(v, exp):
    n = len(v)
    rez = [0] * n
    frev = [0] * 10
    for i in range(n):
        cifra = (v[i] // exp) % 10
        frev[cifra] += 1
    for i in range(1, 10):
        frev[i] += frev[i - 1]
    i = n - 1
    while i >= 0:
        cifra = (v[i] // exp) % 10
        rez[frev[cifra] - 1] = v[i]
        frev[cifra] -= 1
        i -= 1
    for i in range(n):
        v[i] = rez[i]

vector = [random.randint(0,n) for _ in range(maxx)]
print("Vectorul nesortat:",vector)
start=time.time()
A=radixsort(vector)
stop=time.time()
print("Timpul de executare este pentru radixsort: ",stop-start)
print("Vectorul sortat: ",A)
L.append("Timpul de executare este pentru radixsort: ")
L.append(stop-start)
print("\n")

#countingsort - bazat pe numarare (primul algortim la alegere)
def countingsort(v):
    max_nr = max(v)
    frev = [0] * (max_nr + 1)
    for i in range(len(v)):
        frev[v[i]] += 1
    for i in range(1, len(frev)):
        frev[i] += frev[i - 1]
    rez = [0] * len(v)
    for i in range(len(v) - 1, -1, -1):
        rez[frev[v[i]] - 1] = v[i]
        frev[v[i]] -= 1
    return rez
vector=[random.randint(0,n) for _ in range(maxx)]
print("Vectorul nesortat:",vector)
start=time.time()
A=countingsort(vector)
stop=time.time()
print("Timpul de executare este pentru countingsort: ",stop-start)
print("Vectorul sortat: ",A)
L.append("Timpul de executare este pentru countingsort: ")
L.append(stop-start)
print("\n")

#insertionsort (al doilea algoritm la alegere)
def insertionsort(v):
    for i in range(1,len(v)):
        key = v[i]
        j = i - 1
        while j >= 0 and v[j] > key:
            v[j+1] = v[j]
            j -= 1
        v[j+1] = key

    return v
vector = [random.randint(0,n) for _ in range(maxx)]
print("Vectorul nesortat:",vector)
start=time.time()
A = insertionsort(vector)
stop=time.time()
print("Timpul de executare este pentru insertionsort: ",stop-start)
L.append("Timpul de executare este pentru insertionsort: ")
L.append(stop-start)
print("Vectorul sortat: ",A)
print(L)