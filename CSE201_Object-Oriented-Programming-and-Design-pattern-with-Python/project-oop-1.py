import hashlib
import random

class User:
  def __init__(self, name, email, password) -> None:
    self.name = name
    self.email = email
    encrypted_password = hashlib.md5(password.encode()).hexdigest()
    with open('users.txt', 'w') as file:
      file.write(f'{email} {encrypted_password}')
    file.close()
    print(name, 'User created successfully')
  @staticmethod
  def log_in(email, password):
    stored_pwd = ''
    with open('users.txt', 'r') as file:
      lines = file.readlines()
      for line in lines:
        if email in line:
          stored_pwd = line.split(' ')[1]
    file.close()
    print("Stored password: ", stored_pwd)
    encrypted_password = hashlib.md5(password.encode()).hexdigest()
    if encrypted_password == stored_pwd:
      print('Logged in successfully')
      return True
    else:
      print('Invalid user')
      return False
    

class Rider(User):
  def __init__(self, name, email, password, location, balance) -> None:
    super().__init__(name, email, password)
    self.location = location
    self.balance = balance
  def set_location(self, location):
    self.location = location
  def get_location(self):
    return self.location
  def request_trip(self, destination):
    pass
  def start_a_trip(self, fare):
    self.balance -= fare


class Driver(User):
  def __init__(self, name, email, password, location, license) -> None:
    super().__init__(name, email, password)
    self.location = location
    self.license = license
    self.validate_driver = license_authority.validate_license(email, license)
    self.earning = 0
  def take_driving_test(self):
    result = license_authority.driving_test(self.email)
    if result:
      self.license = result
      self.validate_driver = True
    else:
      print('You have failed the driving test')
  def start_a_trip(self,destination, fare):
    self.earning += fare
    self.location = destination

class BRTA:
  def __init__(self) -> None:
    self.__license = {}
  def driving_test(self, email):
    score = random.randint(0, 100)
    if score>= 33:
      print('You have passed the driving test')
      license_number = random.randint(1000, 9999)
      self.__license[email] = license_number
      return license_number
    else:
      print('You have failed the driving test')
      return False
  def validate_license(self, email, license):
    for key, value in enumerate(self.__license):
      if key == email and value == license:
        return True
      return False
  

license_authority = BRTA()

users = User("fahim", "fahim@gmail.com", "atelmoshai")

User.log_in( "fahim@gmail.com", "atelmoshai")

driver_atela = Driver("atela", "atela@gmail.com", "atelmoshai", "Dhaka", 1234)
driver_atela.take_driving_test()
license_authority.validate_license(driver_atela.email, driver_atela.license)
