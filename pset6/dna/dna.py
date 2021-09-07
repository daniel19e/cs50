import csv
from sys import argv

def main():

    #check for correct number of arguments
    if len(argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")

    #open files
    databaseFile = open("./" + argv[1])
    dnaFile = open("./" + argv[2])

    reader = csv.DictReader(databaseFile)
    strs = reader.fieldnames[1:]


    dna = dnaFile.read()
    dnaFile.close()

    dna_fingerprint = {}
    for i in strs:
        dna_fingerprint[i] = repeats(i, dna)

    for i in reader:
        if match(strs, dna_fingerprint, i):
            print(f"{i['name']}")
            databaseFile.close()
            return
    
    print("No match")
    databaseFile.close()

def repeats(x, dna):
    i = 0
    while x * (i + 1) in dna:
        i += 1
    return i
    
def match(strs, dna_fingerprint, row):
    for i in strs:
        if dna_fingerprint[i] != int(row[i]):
            return False
    return True

main()