import numpy as np
import matplotlib.pyplot as plt


nsteps = 10**6
x_list = np.zeros(nsteps)
y_list = np.zeros(nsteps)

data = np.zeros(nsteps) # Empty array for the estimator data
data_err = np.zeros(nsteps) # Empty array for the error-bar data.

x = np.random.uniform(-1,1)
y = np.random.uniform(-1,1)
c = 0.0

for i in range(nsteps):
    dx = np.random.normal(0,0.04) # Generating steps from N[0,0.05].
    dy = np.random.normal(0,0.04)
    xnew = x + dx
    ynew = y + dy
        
    if abs(xnew) <= 1 and abs(ynew) <= 1: # Checking if the new point falls inside the square.
        ft = 0.25
        
    else: ft = 0
        
    r = np.random.uniform() # Acceptance probability.
    
    if r < ft/0.25: # The current point will always be inside the square as it only makes sense if the walker starts within the square.
        x_list[i] = xnew
        y_list[i] = ynew
        x = xnew
        y = ynew
        
# Solution taken from CW1.

    if (xnew)**2 + (ynew)**2 <= 1:
        c += 1
        
    est = (c)/(i+1) # The mean estimator.
    second_mom = c/(i+1) # The second moment estimator.
    
    err = np.sqrt(second_mom-est**2)/np.sqrt(i+1) # The corresponding error-bars
    
    data[i] = 4*est # Storing estimations in an array and estimating for Pi.
    data_err[i] = 4*err # Storing errors in an array.


print('Pi estimation = ' + str(est*4))
print('Floating point value for Pi = ' + str(np.pi))

# Visual solution

plt.errorbar(range(nsteps),data,data_err,errorevery=10000)
plt.plot(range(nsteps), np.zeros(nsteps)+np.pi, 'k--')
plt.show()  