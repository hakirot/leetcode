# Python program to print all permutations with
# duplicates NOT allowed

permutations = []

def toString(List):
    return ''.join(List)

# Function to print permutations of string
# This function takes three parameters:
# 1. String
# 2. Starting index of the string
# 3. Ending index of the string.
def permute(a, l, r):
    if l == r:
        #print (toString(a))
        if toString(a) not in permutations:
            permutations.append(toString(a))
    else:
        for i in range(l, r):
            a[l], a[i] = a[i], a[l]
            permute(a, l + 1, r)
            a[l], a[i] = a[i], a[l] # backtrack

# Driver program to test the above function
string = "DDDRRR"
n = len(string)
#print("len: " + str(n))
a = list(string)
permute(a, 0, n)
for i in range(len(permutations)):
    print(permutations[i])

# This code is contributed by Bhavya Jain
