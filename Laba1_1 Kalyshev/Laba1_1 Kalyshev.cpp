// Laba1_1 Kalyshev.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(int mass[], int ind1, int ind2) {
    int temp = mass[ind1];
    mass[ind1] = mass[ind2];
    mass[ind2] = temp;
}

int main()
{
    int mass[] = { 8, 42, 5, 2, 0, 234, 897, 1, 8 };
    bool need = true;
    while (need) {
        need = false;
        for (int i = 0; i < (sizeof(mass) / sizeof(int)); i++) {
            if (mass[i] < mass[i - 1]) {
                swap(mass, i, i - 1);
                printf("\n");
                for (int i = 0; i < (sizeof(mass) / sizeof(int)); i++) {
                    printf("%4d", mass[i]);
                }
                printf("\n");
                need = true;
            }
        }
    }

    /*for (int i = 0; i < (sizeof(mass) / sizeof(int)); i++) {
        printf("%3d", mass[i]);
    }*/

}



