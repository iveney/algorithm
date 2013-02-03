"""
Implements the quadratic time algorithm
"""
import random

def ThreeSum(S):
    S.sort()
    n = len(S)
    for i in range(0, n - 2):
        a = S[i]
        j = i + 1
        k = n - 1
        while (j < k):
            b, c = S[j],S[k]
            sum = a + b + c
            if (sum == 0):
                return (a, b, c)
            elif (sum > 0):
                k = k - 1
            else:
                j = j + 1
    return False

if __name__ == "__main__":
    n = 20
    S = random.sample(xrange(-200, 200), n)
    print S
    tuple = ThreeSum(S)
    print tuple
