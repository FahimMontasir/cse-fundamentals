package com.example.javalib;

public class HelloWorld {
    public static void main(String[] args){
        System.out.print("hello world \n");

        int[] luckyNumbers = {10, 20, 50};

        for (int i : luckyNumbers) {
            System.out.println(i);
        }

        System.out.println(luckyNumbers[0]);
    }
}