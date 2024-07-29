import matplotlib.pyplot as plt


y1 = [5,15,15,20,10]
y2 = [15,20,10,5,15]
#y3 = [10,5,15,15,20]
x = [1,2,3,4,5]


plt.title('My homework')
plt.xlabel('Day')
plt.ylabel('Homework')
g = plt.grid(True,color='green',alpha=0.1,lw=1,linestyle= '--')
plt.plot(x,y1,linestyle= '-.',marker='*',color='Magenta')
plt.plot(x,y2,linestyle= '--',marker='o',color='green')
#plt.plot(x,y3,linestyle= ':',marker='^',color='red')
plt.show()
