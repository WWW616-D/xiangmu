#include <stdio.h>
#include <math.h>

// 题目1：找出三个整数的最大值
void exe1() {
    int a, b, c, max;
    printf("请输入三个整数：");
    scanf("%d%d%d", &a, &b, &c);

    max = a;
    if (b > max) max = b;
    if (c > max) max = c;

    printf("最大值为：%d\n", max);
}

// 题目2：找出三个字符中ASCII码最大的字符
void exe2() {
    char ch1, ch2, ch3, max;
    printf("请输入三个字符：");
    scanf(" %c %c %c", &ch1, &ch2, &ch3);

    max = ch1;
    if (ch2 > max) max = ch2;
    if (ch3 > max) max = ch3;

    printf("ASCII码最大的字符为：%c\n", max);
}

// 题目3：一元二次方程求解
void exe3() {
    double a, b, c, delta, x1, x2;
    printf("请输入一元二次方程的系数a, b, c：");
    scanf("%lf%lf%lf", &a, &b, &c);

    if (a == 0) {
        printf("这不是一元二次方程！\n");
        return;
    }

    delta = b * b - 4 * a * c;

    if (delta > 0) {
        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);
        printf("方程有两个不相等的实根：x1=%.2lf, x2=%.2lf\n", x1, x2);
    }
    else if (delta == 0) {
        x1 = -b / (2 * a);
        printf("方程有两个相等的实根：x1=x2=%.2lf\n", x1);
    }
    else {
        double real = -b / (2 * a);
        double imag = sqrt(-delta) / (2 * a);
        printf("方程有两个共轭复根：x1=%.2lf+%.2lfi, x2=%.2lf-%.2lfi\n", real, imag, real, imag);
    }
}

// 题目4：百分制成绩转等级
void exe4() {
    int score;
    char grade;
    printf("请输入学生的百分制分数：");
    scanf("%d", &score);

    if (score >= 90) grade = 'A';
    else if (score >= 80) grade = 'B';
    else if (score >= 70) grade = 'C';
    else if (score >= 60) grade = 'D';
    else grade = 'E';

    printf("学生的成绩等级为：%c\n", grade);
}

// 题目5：三个整数从小到大排序
void exe5() {
    int a, b, c, temp;
    printf("请输入三个整数：");
    scanf("%d%d%d", &a, &b, &c);

    // 使用冒泡排序思想
    if (a > b) { temp = a; a = b; b = temp; }
    if (a > c) { temp = a; a = c; c = temp; }
    if (b > c) { temp = b; b = c; c = temp; }

    printf("从小到大排序结果为：%d %d %d\n", a, b, c);
}

// 题目6：判断是否能同时被2、3、5整除
void exe6() {
    int num;
    printf("请输入一个整数：");
    scanf("%d", &num);

    if (num % 2 == 0 && num % 3 == 0 && num % 5 == 0) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }
}

// 题目7：字符大小写转换
void exe7() {
    char ch;
    printf("请输入一个字符：");
    scanf(" %c", &ch);

    if (ch >= 'a' && ch <= 'z') {
        ch = ch - 'a' + 'A';
        printf("转换后的字符为：%c\n", ch);
    }
    else if (ch >= 'A' && ch <= 'Z') {
        ch = ch - 'A' + 'a';
        printf("转换后的字符为：%c\n", ch);
    }
    else {
        printf("The character needn't to be changed\n");
    }
}

// 题目8：判断奇偶数
void exe8() {
    int num;
    printf("请输入一个整数：");
    scanf("%d", &num);

    if (num % 2 == 0) {
        printf("%d是偶数\n", num);
    }
    else {
        printf("%d是奇数\n", num);
    }
}

// 题目9：计算税金
void exe9() {
    double price, tax;
    printf("请输入货物价格：");
    scanf("%lf", &price);

    if (price > 10000) {
        tax = price * 0.05;
    }
    else if (price > 5000) {
        tax = price * 0.03;
    }
    else if (price > 1000) {
        tax = price * 0.02;
    }
    else {
        tax = 0;
    }

    printf("应收取的税金为：%.2lf元\n", tax);
}

// 题目10：根据班级号查询学生人数
void exe10() {
    int classNo, students;
    printf("请输入班级号(91-95)：");
    scanf("%d", &classNo);

    switch (classNo) {
    case 91:
        students = 30;
        break;
    case 92:
        students = 32;
        break;
    case 93:
        students = 30;
        break;
    case 94:
        students = 30;
        break;
    case 95:
        students = 32;
        break;
    default:
        printf("无效的班级号！\n");
        return;
    }

    printf("%d班的学生人数为：%d人\n", classNo, students);
}

// 显示菜单
void showMenu() {
    printf("\n========== 题目列表 ==========\n");
    printf("1. 三个整数找最大值\n");
    printf("2. 三个字符找ASCII码最大值\n");
    printf("3. 一元二次方程求解\n");
    printf("4. 百分制成绩转等级\n");
    printf("5. 三个整数从小到大排序\n");
    printf("6. 判断能否被2、3、5整除\n");
    printf("7. 字符大小写转换\n");
    printf("8. 判断奇偶数\n");
    printf("9. 计算税金\n");
    printf("10. 班级号查询学生人数\n");
    printf("0. 退出程序\n");
    printf("==============================\n");
}

// 主函数
int main_555555() {
    int choice;

    while (1) {
        showMenu();
        printf("请选择要调试的题目编号(1-10)，输入0退出：");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("程序已退出，再见！\n");
            break;
        }

        printf("\n=== 执行题目%d ===\n", choice);

        switch (choice) {
        case 1:
            exe1();
            break;
        case 2:
            exe2();
            break;
        case 3:
            exe3();
            break;
        case 4:
            exe4();
            break;
        case 5:
            exe5();
            break;
        case 6:
            exe6();
            break;
        case 7:
            exe7();
            break;
        case 8:
            exe8();
            break;
        case 9:
            exe9();
            break;
        case 10:
            exe10();
            break;
        default:
            printf("无效的选择，请输入1-10之间的数字！\n");
            break;
        }

        printf("\n按回车键继续...");
        getchar(); // 清除之前的换行符
        getchar(); // 等待用户按回车
    }
    
    return 0;
}