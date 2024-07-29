import numpy as np
from scipy.io import savemat
a = np.arange(1,41)
savemat('onetoforty.mat',{'a':a})
