# import utility functions
import json

def import_json(file):
    with open(file, "r") as f:
        return json.load(f) 

# list of dictionaries
people = [{"name": "John", "age": 30}, {"name": "Jane", "age": 25}, {"name": "Jake", "age": 35}]

# tuple
person = ("John", 30)

# set
unique_people = {"John", "Jane", "Jake"}

# lambda function
add = lambda x, y: x + y

# error handling
try:
    print(people[3])  
except IndexError:
    print("Index out of range")

# generator
def gen(n):
    for i in range(n):
        yield i

# decorator
def decorator(func):
    def wrapper(*args, **kwargs):
        print("Before function")
        func(*args, **kwargs)
        print("After function")
    return wrapper

@decorator
def say_hello():
    print("Hello")

