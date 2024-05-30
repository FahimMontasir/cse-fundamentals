from django.urls import path
from book.views import home

urlpatterns = [
    path('', home)
]
