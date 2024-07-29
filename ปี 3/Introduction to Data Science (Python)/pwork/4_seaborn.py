import seaborn as sb
import matplotlib.pyplot as plt
import numpy as np
x = np.arange(100)
y = np.random.randint(0,20,100)

sb.scatterplot(x=x,y=y,s  = 20).set(title = "hoke pip")

t = sb.load_dataset('tips')
g = sb.FacetGrid(t,col = "smoker")
g.map(plt.hist, "tip")


sb.lmplot(x="total_bill", y="tip", col="smoker", data=t)
