import csv
dictionari = {}
data = []
lis = []
instanca = []
string = ''
with open('FIFA.csv', newline='\n') as csvfile:
    reader = csv.DictReader(csvfile)
    for i, row in enumerate(reader):
        dictionari[row['Nationality']] = row
        if i == 100:
            break;
    for val in dictionari.values():
        for v in val.values():
            lis.append(v)
        string = string + ','.join(lis)+'\n'
        lis = [] 
print(string)

    

#f = open('Skup_podataka.csv', 'w')
#writer = csv.writer(f)
#for x in dictionari.values():
#    writer.writerow(x)
#f.close()
