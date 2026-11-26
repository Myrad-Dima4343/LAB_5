#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <Windows.h>

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    // 66
    int n1, arr1[100], has_neg = 0;
    long long prod1 = 1;
    printf("--- Завдання 66 ---\nВведіть розмір масиву n: ");
    scanf("%d", &n1);
    printf("Введіть %d цілих чисел: ", n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
        if (arr1[i] < 0) {
            prod1 *= arr1[i];
            has_neg = 1;
        }
    }
    if (has_neg)
        printf("Добуток від'ємних елементів: %lld\n\n", prod1);
    else
        printf("Від'ємних елементів немає\n\n");

    // 71
    int n2, arr2[100], count2 = 0;
    long long sum2 = 0;
    printf("--- Завдання 71 ---\nВведіть розмір масиву n: ");
    scanf("%d", &n2);
    printf("Введіть %d цілих чисел: ", n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }
    long long sq = (long long)arr2[0] * arr2[0];
    for (int i = 0; i < n2; i++) {
        if (arr2[i] > sq) {
            sum2 += arr2[i];
            count2++;
        }
    }
    if (count2 > 0)
        printf("Сума елементів, більших за квадрат першого (%lld): %lld\n\n", sq, sum2);
    else
        printf("Пошук невдалий: таких елементів немає\n\n");

    // 73
    double a3[15], target3;
    printf("--- Завдання 73 ---\nВведіть 15 дійсних чисел (за зростанням): ");
    for (int i = 0; i < 15; i++) {
        scanf("%lf", &a3[i]);
    }
    printf("Введіть число n: ");
    scanf("%lf", &target3);
    int min_idx = 0;
    double min_diff = fabs(a3[0] - target3);
    for (int i = 1; i < 15; i++) {
        double diff = fabs(a3[i] - target3);
        if (diff < min_diff) {
            min_diff = diff;
            min_idx = i;
        }
    }
    printf("Найближчий елемент: номер %d, значення %.4lf\n\n", min_idx + 1, a3[min_idx]);

    // 92
    int A[50], k;
    printf("--- Завдання 92 ---\nВведіть 50 цілих чисел масиву A: ");
    for (int i = 0; i < 50; i++) {
        scanf("%d", &A[i]);
    }
    printf("Введіть номер елемента k для видалення (1..50): ");
    scanf("%d", &k);
    if (k >= 1 && k <= 50) {
        for (int i = k - 1; i < 49; i++) {
            A[i] = A[i + 1];
        }
        A[49] = 0;
        printf("Оновлений масив:\n");
        for (int i = 0; i < 50; i++) {
            printf("%d ", A[i]);
        }
        printf("\n\n");
    }
    else {
        printf("Некоректний номер k\n\n");
    }

    // 129
    int n5;
    double a5[100], b;
    printf("--- Завдання 129 ---\nВведіть кількість елементів n: ");
    scanf("%d", &n5);
    printf("Введіть %d дійсних чисел (у неспадній послідовності): ", n5);
    for (int i = 0; i < n5; i++) {
        scanf("%lf", &a5[i]);
    }
    printf("Введіть число b для вставки: ");
    scanf("%lf", &b);
    int pos = n5;
    for (int i = 0; i < n5; i++) {
        if (a5[i] > b) {
            pos = i;
            break;
        }
    }
    for (int i = n5; i > pos; i--) {
        a5[i] = a5[i - 1];
    }
    a5[pos] = b;
    printf("Послідовність після вставки:\n");
    for (int i = 0; i <= n5; i++) {
        printf("%.2lf ", a5[i]);
    }
    printf("\n\n");

    // 190
    int n6, arr6[100], found6 = 0;
    printf("--- Завдання 190 ---\nВведіть кількість чисел n: ");
    scanf("%d", &n6);
    printf("Введіть %d чотирицифрових натуральних чисел: ", n6);
    for (int i = 0; i < n6; i++) {
        scanf("%d", &arr6[i]);
    }
    printf("Підходящі числа: ");
    for (int i = 0; i < n6; i++) {
        int x = arr6[i];
        int d1 = x / 1000;
        int d2 = (x / 100) % 10;
        int d3 = (x / 10) % 10;
        int d4 = x % 10;
        if (d1 + d2 == d3 + d4) {
            printf("%d ", x);
            found6 = 1;
        }
    }
    if (!found6) printf("немає");
    printf("\n");

    return 0;
}
