class Phone:
  manufactured = "China"

  def __init__(self, brand, model, price, color):
    self.brand = brand
    self.model = model
    self.price = price
    self.color = color
  
  def call(self, number):
    print("Calling...", number)

  @property
  def full_name(self):
    return f"{self.brand} {self.model}"

  @full_name.setter
  def full_name(self, name):
    self.brand, self.model = name.split(" ")

my_phone = Phone("Samsung", "Galaxy S10", 1000, "Black")
# my_phone.call(1010101)
# print(my_phone.manufactured)
# print(my_phone.brand)

class Person: 
  def __init__(self, name, age, money, password):
    self.name = name
    self.age = age
    self.money = money
    self.__password = password
  # dunder method
  def __add__(self, other):
    return self.money + other.money
  @staticmethod
  def add(a, b):
    return a + b
  def __show_password(self):
    print(self.__password)
  
# print(Person.add(10, 20))
alim = Person("Alim", 25, 1000, "1234")
dalim = Person("Dalim", 30, 2000, "5678")

# print(alim + dalim)
# print(type(alim))
# decorator
def timer(func):
  def inner(*args, **kwargs):
    print('time start')
    func(*args, **kwargs)
    print('time end')
  return inner

@timer
def get_factorial(n):
  print(f'factorial {n}')

# get_factorial(8)
  
from functools import cache
import time

@cache
def fib(n):
  if n <= 1:
    return n
  return fib(n-1) + fib(n-2)

start = time.time()
for i in range(10):
  print(fib(i))
end = time.time()

print(end - start)
