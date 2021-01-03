from sys import argv, exit
import csv
import re

#Test for the right command line arguments
if len(argv) != 3:
    print("Usage: python dna.py data.csv sequence.txt")
    exit(1)

#Opening up the sequence file
temp = 1
found = 1
fileName = argv[1]
seqName = argv[2]
with open(fileName, "r") as csvfile:
    reader = csv.DictReader(csvfile)
    field = (reader.fieldnames)
with open(seqName, "r") as fileTXT:
    DNA = fileTXT.read()
L = len(DNA)

#Populating the dictionary
DNATest = {}
for i in range(1, len(field)):
    DNATest[field[i]] = 0
    STRlen = len(field[i])
    
#Searching through the sequence
    for k in range(L):
        while bool(True):
            if re.search(f"^{field[i]}", DNA[k:]):
                if re.search(f"^{field[i]}", DNA[k+(STRlen):]):
                    temp += 1
                    k += (2*STRlen)
            
                else:
                    if temp > DNATest[field[i]]:
                        DNATest[field[i]] = temp
                    temp = 1
            break
    
#Populating the dictionary with the sample DNAs in DB file
with open(fileName, "r") as csvfile:
    reader = csv.DictReader(csvfile)
    for row in reader:
        for key, value in row.items():
            if value.isnumeric() == True:
                x = str(DNATest[key])
                if value == x:
                    found = 1
                else:
                    found = 0
                    break
#Printing the Name
        if found == 1:
            print(row['name'])
            exit(0)
print("No match")