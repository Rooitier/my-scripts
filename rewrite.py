import numpy as np
from scipy.interpolate import interp1d

#Defining empty arrays
energy = []
psf = []
energynew = []

# Importing the File and reading it to arrays
file = open("90Zr2015.dat",'r')

for line in file:
    line = line.strip()
    if not line.startswith("#"):
        column = line.split()
        energy.append(float(column[0]))
        psf.append(float(column[2]))

# Conversions and handling precision of digits and rounding bins

for i in range(len(psf)):
    psf[i] = float(np.format_float_scientific(psf[i]/8.6737E-08, precision = 3, exp_digits=2))
    energy[i] = round(energy[i],1)

energy = np.array(energy)
psf = np.array(psf)

a = len(energy)

# Making an array of energy bins such as in TALYS and corresponding NaNs

energynew = np.arange(min(energy),max(energy)+0.1,0.1)
energynew = [round(energynew[i],1) for i in range(len(energynew))]

nanarr = np.empty((len(energynew),))
nanarr[:] = np.NaN

#Concatenating the experimental data and NaNs

epsf = np.vstack((energy,psf)).T
energynewnan = np.vstack((energynew,nanarr)).T

mergearr = np.concatenate((epsf,energynewnan),axis=0)
mergearr  = mergearr.tolist()

#Sorting the data after concatenating

sorted_li = sorted(mergearr, key=lambda x:x[0])

# Procedure for removing nan-duplicates. In general TALYS is alright with duplicates of data-points but its safer to do this way. You only want duplicates from you experimental data not from interpolation. Find here https://stackoverflow.com/questions/41791521/compare-1-column-of-2d-array-and-remove-duplicates-python

counts = {}

for elem in sorted_li:
    # add 1 to counts for this string, creating new element at this key
    # with initial value of 0 if needed
    counts[elem[0]] = counts.get(elem[0], 0) + 1

# 
neg_array = []
for elem in sorted_li:
    # check that there's only 1 instance of this element.
    if counts[elem[0]] == 1:
        neg_array.append(elem)

# Combining the negative array with the original data set and sorting etc again.

finalarr = np.concatenate((epsf,neg_array),axis=0)
finalarr = finalarr.tolist()
finalarr = sorted(finalarr,key=lambda x:x[0])
finalarr = np.array(finalarr)


# Function for finding NaNs and then perform linear interpolation to fill in NaNs. Find here https://stackoverflow.com/questions/6518811/interpolate-nan-values-in-a-numpy-array
def nan_helper(y):
    """Helper to handle indices and logical indices of NaNs.

    Input:
        - y, 1d numpy array with possible NaNs
    Output:
        - nans, logical indices of NaNs
        - index, a function, with signature indices= index(logical_indices),
          to convert logical indices of NaNs to 'equivalent' indices
    Example:
        >>> # linear interpolation of NaNs
        >>> nans, x= nan_helper(y)
        >>> y[nans]= np.interp(x(nans), x(~nans), y[~nans])
    """

    return np.isnan(y), lambda z: z.nonzero()[0]

xsplit,ysplit = np.split(finalarr,2,axis=1)

nans, x= nan_helper(ysplit)
ysplit[nans]= np.interp(x(nans), x(~nans), ysplit[~nans]).round(4) # Interpolate and Rounding

# Flattening and writing to a file in your directory with the same spacing as TALYS files in structure/hfb
x = xsplit.flatten()
y = ysplit.flatten()

with open("E1file90Zr2015.dat","w") as f:
    # f.write(' Z=  22 A=  46\n')
    # f.write('  U[MeV]  fE1[mb/MeV]\n')
    for i in range(0, len(x)):
        f.write("   {0}   {1}\n".format(x[i],y[i]))