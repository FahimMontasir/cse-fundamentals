from django.http import HttpResponse

def home(request):
    return HttpResponse("Hello, World!")

def about(request):
    return HttpResponse("<h1>Hello, This is my about page!</h1>")