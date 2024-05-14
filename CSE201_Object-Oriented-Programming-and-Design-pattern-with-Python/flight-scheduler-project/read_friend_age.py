import csv
with open('flight-scheduler-project/data/my_friends.csv', 'r') as file:
    lines = csv.reader(file)
    header = next(lines)
    for line in lines:
        print(line)
    print(header)