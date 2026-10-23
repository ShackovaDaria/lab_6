#include <stdio.h>
#include <locale.h>

// Прототипы функций
int z1_year(int years);
double z2_f(double x);
double z3_time(int h, int m);

int main(void) {
    setlocale(LC_ALL, "Russian");

    //Задание 1
    int y;
    printf("---Задание 1: Високосный год---\n");
    printf("Введите год: ");

    scanf("%d",&y);
        if (z1_year(y)==1) {
            printf("%d - високосный год\n", y);
        } else {
            printf("%d - не високосный год\n", y);
        }


    //Задание 2
    double x, fx;
    printf("\n---Задание 2: Вычисление функции F(x)---\n");
    printf("Введите x: ");
    scanf("%lf", &x);

    fx = z2_f(x);
    printf("F(%.2f) = %.6f\n", x, fx);


    //Задание 3
    int h, m;
    double t;
    printf("\n---Задание 3: Встреча стрелок часов---\n");
    printf("Введите часы (0-24): ");
    scanf("%d", &h);
    
    printf("Введите минуты (0-60): ");
    scanf("%d", &m);

    t = z3_time(h, m);
    if (t<60) printf("Время до встречи стрелок: %.2f мин (менее часа)\n", t);
    else printf("Время до встречи стрелок: %.2f мин (более часа)\n", t);
}


int z1_year(int years) {
    if ((years % 4 == 0 && years % 100 != 0) || (years % 400 == 0)) {
        return 1;
    }
    return 0;
}

double z2_f(double x) {
    if (x <= 7) {
        return 3 * x - 9;
    } else {
        return 1.0 / (x * x - 4);
    }
}

double z3_time(int h, int m) {
    double t, h12;
    h12 = h % 12;

    t = (60 * h12 - 11.0 * m + 720.0 * 0) / 11.0;
    if (t <= 0) {
        t = (60 * h12 - 11.0 * m + 720.0 * 1) / 11.0;
        if (t <= 0) {
            t = (60 * h12 - 11.0 * m + 720.0 * 2) / 11.0;
        }
    }
    return t;
}
