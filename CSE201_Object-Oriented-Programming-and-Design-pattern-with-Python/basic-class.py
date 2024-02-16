class Phone:
  manufactured = "China"

  def __init__(self, brand, model, price, color):
    self.brand = brand
    self.model = model
    self.price = price
    self.color = color
  
  def call(self, number):
    print("Calling...", number)


my_phone = Phone("Samsung", "Galaxy S10", 1000, "Black")
# my_phone.call(1010101)
# print(my_phone.manufactured)
# print(my_phone.brand)

class Person: 
  def __init__(self, name, age, money):
    self.name = name
    self.age = age
    self.money = money
  # dunder method
  def __add__(self, other):
    return self.money + other.money

alim = Person("Alim", 25, 1000)
dalim = Person("Dalim", 30, 2000)

print(alim + dalim)
print(type(alim))