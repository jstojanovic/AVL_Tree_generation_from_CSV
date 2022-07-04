B = [[2, 'Dog'], [0, 'Bird'], [7, 'Cat']]
print("Sorted List A based on index 1: % s" % (sorted(B, key=lambda x:x[-1])))



from datetime import datetime
my_dates = ['5-Nov-18', '25-Mar-17', '1-Nov-18', '7-Mar-17']
my_dates.sort(key=lambda date: datetime.strptime(date, "%d-%b-%y"))
print(my_dates)