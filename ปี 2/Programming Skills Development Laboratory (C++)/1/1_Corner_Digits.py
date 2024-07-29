a = int(input(""))
count=0
for i in range(1,(a//2)+1):
    if a%i == 0:
        count += 1
    if count >= 2:
        print("NO")
        break
if count == 1:
    print("YES")

if count == 0:
    print("NO")