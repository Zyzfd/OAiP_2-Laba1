// Laba1_3 Kalyshev.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>
#include <malloc.h>

void swap(int mass[], int ind1, int ind2) {
    int temp = mass[ind1];
    mass[ind1] = mass[ind2];
    mass[ind2] = temp;
}

void merge(int* mass, int start, int end) {
    int left_iterator, right_iterator, middle;
    int* mas = (int*)malloc((end - start) * sizeof(int));

    middle = (start + end) / 2;
    left_iterator = start;
    right_iterator = middle + 1;

    for (int i = start; i <= end; i++) {
        if ((left_iterator <= middle) && ((right_iterator > end) || (mass[left_iterator] < mass[right_iterator]))) {
            *(mas + i - start) = mass[left_iterator];
            left_iterator++;
        }
        else {
            *(mas + i - start) = mass[right_iterator];
            right_iterator++;
        }
    }

    for (int i = start; i <= end; i++) {
        mass[i] = *(mas + i - start);
    }

    printf("\n");
    for (int i = 0; i < 10; i++) {
        printf("%5d", mass[i]);
    }
}

void merge_sort(int* mass, int start, int end) {

    
    if (start < end) {
        int middle = (start + end) / 2;

        merge_sort(mass, start, middle);
        merge_sort(mass, middle + 1, end);

        merge(mass, start, end);
    
    }
}





int main()
{
    int mass[] = {10, 0, 52, 4254, 4, 86, 2, 4, 96, 3};
    
    merge_sort(mass, 0, 9);

    printf("\n");
    for (int i = 0; i < sizeof(mass) / sizeof(int); i++) {
        printf("%5d", mass[i]);
    }

}
