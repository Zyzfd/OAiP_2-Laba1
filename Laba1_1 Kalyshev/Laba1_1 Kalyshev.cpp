// Laba1_1 Kalyshev.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctime>
#include <malloc.h>
#include <stdlib.h>

void swap(int mass[], int ind1, int ind2) {
    int temp = mass[ind1];
    mass[ind1] = mass[ind2];
    mass[ind2] = temp;
}

int main() {
    for (int kolvo = 0; kolvo < 100000; kolvo += 10000) {
        int* mass = (int*)malloc(kolvo * sizeof(int));

        for (int i = 0; i < kolvo; i++) {
            mass[i] = rand();
        }

        unsigned int start_time = clock();
        bool need = true;
        while (need) {
            need = false;
            for (int i = 0; i < (sizeof(mass[i]) * kolvo / sizeof(int)); i++) {
                if (mass[i] < mass[i - 1]) {
                    swap(mass, i, i - 1);
                    need = true;
                }
            }
        }
        unsigned int end_time = clock();
        unsigned int search_time = end_time - start_time;
        printf("%d\n", search_time);
    }
}



