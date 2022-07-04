#!/usr/bin/env python3

import csv
import datetime
import requests
import itertools

FILE_URL = "https://storage.googleapis.com/gwg-content/gic215/employees-with-date.csv"
def get_start_date():
    """Interactively get the start date to query for."""

    print()
    print('Getting the first start date to query for.')
    print()
    print('The date must be greater than Jan 1st, 2018')
    year = int(input('Enter a value for the year: '))
    month = int(input('Enter a value for the month: '))
    day = int(input('Enter a value for the day: '))
    print()

    return datetime.datetime(year, month, day)

def get_file_lines(url):
    """Returns the lines contained in the file at the given URL"""

    # Download the file over the internet
    response = requests.get(url, stream=True)
    lines = []

    for line in response.iter_lines():
        lines.append(line.decode("UTF-8"))
    return lines

def get_csv_line(reader, line_number):
    return next(itertools.islice(reader, line_number, None))

def get_same_or_newer(start_date):
    """Returns the employees that started on the given date, or the closest one.
"""
    try: 
        with open("data.dat", "r") as file:
            data = file.readlines()
            print("why?>?")
            file.close()
    except:
        data = get_file_lines(FILE_URL)
        for x in range(len(data)):
            data[x] = data[x].split(',')

        sorted_data = sorted(data[1:], key=lambda x: datetime.datetime.strptime(x[-1],'%Y-%m-%d'))
        sorted_data.insert(0, data[0])
        
        for x in range(len(sorted_data)):
            sorted_data[x] = sorted_data[x][0] +","+ sorted_data[x][1] +","+ sorted_data[x][2] +","+ sorted_data[x][3] +  '\n'

        with open('data.dat', 'w') as file:
            for value in sorted_data:
                file.write(value)
            file.close()
        data = sorted_data
        
    reader = csv.reader(data[1:])
    # We want all employees that started at the same date or the closest newer
    # date. To calculate that, we go through all the data and find the
    # employees that started on the smallest date that's equal or bigger than
    # the given start date.
    min_date = datetime.datetime.today()
    min_date_employees = []
    #usporedujem srednji
    print("SPEC>LINE", get_csv_line(reader, 3))

def list_newer(start_date):
    while start_date < datetime.datetime.today():
        start_date, employees = get_same_or_newer(start_date)
        print("Started on {}: {}".format(start_date.strftime("%b %d, %Y"), employees))

        # Now move the date to the next one
        start_date = start_date + datetime.timedelta(days=1)

def main():
    start_date = get_start_date()
    list_newer(start_date)

if __name__ == "__main__":
    main()
