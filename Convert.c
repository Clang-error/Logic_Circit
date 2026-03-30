

#include "Calc.h"
#include <stdio.h>
#include <stdlib.h>

void convert() { // convert 함수기능 main.c로 기능 이전됨.
    int num;
    int r;
    char radix[10] ={0,};
    while (r != 5) {
        r=0;//비트수 제한없어지고
        int sign =0;
        int decimal = 0; //10진수 0으로 초기화
        printf("(참고) 입력한 진수데이터는 10진수로 변환 후 연산됩니다.\n");
        printf("2,8,10,16 진수 중 하나 입력 (5 입력시 종료): ");
        scanf("%d",&r);
        printf("양수(0)와 음수(1) 중 선택:");
        scanf("%d",&sign);
        if (sign != 0 && sign != 1) {
            printf("0 과 1 중 하나를 선택해주세요.");
            continue;
        }
        if (r == 2 || r == 8 || r == 10 || r == 16) {
            if (r == 2) { //2진수 입력 정수->문자열로 변환작업하기
                printf("|절대값|2진수 입력: ");
                scanf("%d", &num);

                int temp = num;
                int base = 1;
                while (temp > 0) {
                    if (temp % 10 != 0 && temp % 10 != 1) { //2진수를 입력받았을때 0또는 1이 아니라면 return값을 뱉는 로직
                        printf("올바른 2진값을 입력하세요");
                        continue;
                    }
                    decimal += (temp % 10) * base; //2진수를 10진으로 변환하는 로직
                    temp /= 10;
                    base *= 2;
                }
                if (sign == 1) {decimal = -decimal;}
                sprintf(radix, "%d", num);
            } else if (r == 8) {
                printf("8진수 입력: ");
                scanf("%o", &num); //o형으로 입력받았으면 10진수로 자동변환되어있음
                decimal = num;
                if (sign == 1) {decimal = -decimal;}
                sprintf(radix, "%o", decimal);
            } else if (r == 10) {
                printf("|절대값|10진수 입력: ");
                scanf("%d", &num);
                decimal = num;
                if (sign == 1) {decimal = -decimal;}
                sprintf(radix, "%d", decimal);
            } else if (r == 16) {
                printf("16진수 입력: ");
                scanf("%x", &num);
                decimal = num;
                if (sign == 1) {decimal = -decimal;}
                sprintf(radix, "%X", decimal);
            } else {
                printf("표현하는 진수중 하나를 입력해주세요.");

            }
            decimal_to_binary(decimal,radix);
            decimal_to_octal(decimal,radix);
            decimal_to_complement(decimal,radix);
            decimal_to_hexadecimal(decimal,radix);
            // if (decimal <= 127 && decimal >= -128) {
            //     decimal_to_binary(decimal,radix);
            //     decimal_to_octal(decimal,radix);
            //     decimal_to_complement(decimal,radix);
            //     decimal_to_hexadecimal(decimal,radix);
            //     printf("\n");
            // } else {
            //     printf("-127~127수 사이를 입력하시오\n");
            //     printf("입력된 수 (10진변환): %d\n",decimal);
            //
            // }
        }
    }
}