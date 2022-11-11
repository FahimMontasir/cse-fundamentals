import requests

params = {
  'access_key': '3616be51146c1fa1ddded955d5543a03',
  'query': 'Dhaka'
}

def weather_data():
  response = requests.get(f'http://api.openweathermap.org/data/2.5/weather?appid={params["access_key"]}&q={params["query"]}')
  result = response.json()
  print(result)

weather_data()
