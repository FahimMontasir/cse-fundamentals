
# School and grade management
class School:
  # constructor
  def __init__(self, name, location, principal) -> None:
    self.name = name
    self.location = location
    self.principal = principal
    self.students = []
    self.teachers = []
    self.grades = []
  def add_grade(self, name, level, teacher):
    new_grade = Grade(name, level, teacher)
    self.grades.append(new_grade)
  def remove_grade(self, name, level):
    idx = 0
    for i, grade in enumerate(self.grades):
      if grade.name == name:
        idx = i
    del self.grades[idx]

class Grade:
  # constructor
  def __init__(self, name, level, teacher) -> None:
    self.name = name
    self.level = level
    self.teacher = teacher
  def __repr__(self) -> str:
    return f'{self.name} {self.level}'
  def __del__(self):
    print(f'{self.name} {self.level} has been deleted')
  
oxford = School('Oxford', 'London', 'Mr. Smith')
oxford.add_grade('Grade 1', 1, 'Mr. John')
oxford.add_grade('Grade 2', 2, 'Mr. Peter')
oxford.remove_grade('Grade 1', 1)
print(oxford.grades)

# inheritance and super
class Animal:
  def __init__(self, name, species) -> None:
    self.name = name
    self.species = species
  def make_sound(self):
    pass

class Dog(Animal):
  def __init__(self, name, species, breed) -> None:
    super().__init__(name, species)
    self.breed = breed
  def make_sound(self):
    print('Woof')

# multi level inheritance
class Pet(Animal):
  def __init__(self, name, species, breed, owner) -> None:
    super().__init__(name, species)
    self.breed = breed
    self.owner = owner
  def make_sound(self):
    print('Woof')

class Cat(Pet):
  def __init__(self, name, species, breed, owner, color) -> None:
    super().__init__(name, species, breed, owner)
    self.color = color
  def make_sound(self):
    print('Meow')

# multiple inheritance
class Bird:
  def __init__(self, name, species) -> None:
    self.name = name
    self.species = species
  def make_sound(self):
    print('Chirp')

class Parrot(Pet, Bird):
  def __init__(self, name, species, breed, owner, color) -> None:
    Pet.__init__(self, name, species, breed, owner)
    Bird.__init__(self, name, species)
    self.color = color
  def make_sound(self):
    print('Squawk')

# dry -> do not repeat yourself
    

# abstract base class
from abc import ABC, abstractmethod

class Shape(ABC):
  @abstractmethod
  def area(self):
    pass

class Square(Shape):
  def __init__(self, side):
    self.side = side
  def area(self):
    return self.side * self.side
  
# abstract property and abstraction vs interface

# This is an example of an abstract class (abstraction)
class AbstractClassExample(ABC):
  @abstractmethod
  def do_something(self):
    pass

  @property
  @abstractmethod
  def some_property(self):
    pass

# This is an example of a class implementing the abstract class (interface)
class AnotherClass(AbstractClassExample):
  _some_property = "Hello, World!"

  @property
  def some_property(self):
    return self._some_property

  def do_something(self):
    super().do_something()
    print("The subclass is doing something")

# Trying to instantiate an object of abstract class would raise an error
# So the following line should be commented
# an_abstract_class = AbstractClassExample()

# An object of the AnotherClass can be created
another_class = AnotherClass()
print(another_class.some_property)
another_class.do_something()

# encapsulation
class Car:
  def __init__(self, name, model, price) -> None:
    self.__name = name
    self.__model = model
    self.__price = price
  def get_price(self):
    return self.__price
  def set_price(self, price):
    self.__price = price

# access modifiers -> public, private, protected
    
# polymorphism -> overloading, overriding
class Animal:
  def __init__(self, name) -> None:
    self.name = name
  def make_sound(self):
    pass

class Dog(Animal):
  def make_sound(self):
    print('Woof')


# read only property, property deleter
class Person:
  def __init__(self, name, age) -> None:
    self.__name = name
    self.__age = age
  @property
  def name(self):
    return self.__name
  @property
  def age(self):
    return self.__age
  @age.deleter
  def age(self):
    del self.__age