import seaborn as sb
import matplotlib.pyplot as plt
import numpy as np
x = np.arange(100)
y = np.random.randint(0,20,100)
sb.scatterplot(x=x,y=y,s  = 100).set(title = "hoke pip")
#plt.xlabel("XXXXXXX")
#plt.ylabel("YYYYYYY")
#plt.show()

t = sb.load_dataset('tips')
g = sb.FacetGrid(t,col = "smoker")
g.map(plt.hist, "tip")
plt.show()

sb.lmplot(x="tip",hue="smoker",data=t)
plt.show()