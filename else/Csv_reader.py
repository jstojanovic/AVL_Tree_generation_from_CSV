import csv
dictionari = {}
data = []
with open('FIFA.csv', 'r') as file:
    file = file.readlines()
    reader = csv.reader(file)
    for i, x in enumerate(reader):
        print( x )
        if(i==20):
            break;
        
        #break;
    
    
    # reader = csv.reader(data)
    # for item in reader:
    #     datum = datetime.datetime.strptime(item[3], '%Y-%m-%d')
    #     if datum >= start_date:
    #         dictionari[item[0]+" "+item[1]] = item[3]
    # return dictionari