
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