import sys
import csv

# Read in the DWBA calculation file. A csv file with a single row.
# It is executed by python3 dwbaorder.py "filename" . Where file name is the single row of csv values to be retabulated.

with open(sys.argv[1], 'r') as file:
  csvreader = csv.reader(file)
  for row in csvreader:
    filerow = row

# Empty vector for storing angles and cross sections from DWBA calculations.
anglevec = []
csvec = []

# Loop for selecting elements 0,2,4,6,9 etc...
for i in range(0,len(filerow)-1,2):
    angle = filerow[i]
    anglevec.append(angle)

# Loop for selecting elements 1,3,5,7,9 etc...
for i in range(1, len(filerow),2):
    cs = filerow[i]
    csvec.append(cs)

# Write resulting data in a csv file line-by-line.
with open(sys.argv[1],"w") as f:
    for i in range(0,len(anglevec)):
        f.write("{0}, {1},\n".format(anglevec[i],csvec[i]))