nk, nd = map(int, input().split())

keyword = input()
decrypt = input()

cipher = keyword[::-1]

fromend = 1
while len(cipher) < nd:
    cipher+=str(chr((ord(decrypt[len(decrypt)-fromend])-ord(cipher[fromend-1]))%26 + 97))
    fromend+=1

print(cipher[::-1])
'''
for i, c in enumerate(decrypt[len(decrypt)-len(keyword):]):
    cipher.append((ord(c)-ord(keyword[i]))%26)
print(cipher)
trueword =''
for i, c in enumerate(decrypt[:len(decrypt)-len(keyword)]):
    print(cipher[i%5])
    trueword+=str(chr((ord(c)-97-cipher[i%5])%26 + 97))
trueword+=keyword
print(trueword)
'''
