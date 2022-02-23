// Laba1_2 Kalyshev.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>
#include <string.h>

int stack[99];
int head = -1;

bool stack_is_empty() {
    return head == -1;
}

void push_stack(int el) {
    head++;
    if (head == sizeof(stack) / sizeof(int)) {
        printf("Overflow\n");
        head--;
        return;
    }
    stack[head] = el;
}
    
void print_stack() {
    printf("\n");
    for (int i = 0; i <= head; i++) {
        printf("%4d", stack[i]);
    }
}

int pop_stack() {
    if (stack_is_empty()) {
        printf("Underflow");
        return 0;
    }
    head--;
    int temp = stack[head + 1];
    stack[head + 1] = 0;
    return temp;
}
    
void empty_stack() {
    if (stack_is_empty()) {
        return;
    }
    while (head != -1) {
        pop_stack();
    }
}

int main()
{
    push_stack(1);
    push_stack(3);
    push_stack(382);
    print_stack();
    int a = pop_stack();
    printf("\n%d\n", a);
    pop_stack();
    print_stack(); 
}
 