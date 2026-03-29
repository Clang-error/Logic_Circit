//
// Created by GoHyeonSeok on 26. 3. 17
//
#include <stdio.h>
#include <stdlib.h>
#include "Calc.h"


void decimal_to_binary(int decimal,char *r) {

    int temp = 0;
    int sign = 0;
    int count=0;
    if (decimal < 0) {
        temp = -decimal;
        sign = 1;
    } else temp = decimal;

    while (temp > 0) {
        temp /= 2;
        count++;
    }

    if (decimal < 0) { // 사용한 값 다시 채우기
        temp = -decimal;
    } else temp = decimal;

    int *bit = (int *)malloc(sizeof(int) * (count+1));
    int *one = (int *)malloc(sizeof(int) * (count+1));
    int *two = (int *)malloc(sizeof(int) * (count+1));


    //2 8 16 -> 10 -> 2 8 16
    // while (n >= 0) { //n의 값이 0보다 크거나 같으때까지 루프
    //     if (D >= (1 << n)) { // D가 2의 n승보다 크거나 같다면.
    //         bit[7 - n] = 1; // 너무 어렵게 접근했음 그냥 n%2 n/=2 방식이 훨씬 쉬움
    //         D = D - (1 << n);
    //     } else {
    //         bit[7 - n] = 0;
    //     }
    //     n--;
    // }


    for (int i = count; i >= 1; i--) { //받은 수 10진수로 변환하는 로직
        bit[i] = temp % 2;
        temp /= 2;
    }

    for (int i = 0; i <= count; i++) { //bit데이터값을 one배열로 복사
        one[i] = bit[i];
    }

    for (int i=0; i<=count; i++) { //1의보수 변환 및 출력 로직
        if (one[i] == 1) {one[i] = 0;}
        else {one[i] = 1;}
    }
    //2의 보수 변환 및 출력 로직
    for (int i = 0; i <= count; i++) { //one데이터값을 two배열로 복사
        two[i] = one[i];
    }

    int carry = 1;
    for (int i = count; i >= 1; i--) {
        int sum = two[i] + carry;
        two[i] = sum % 2;
        carry = sum / 2;
    }

    if (sign == 1) {
        printf("\n|%d의 2진수 변환과정|",decimal);
        printf("\n1. 양수 2진수|절대값|: ");
        for (int i=0; i<=count; i++) printf("%d",bit[i]);
        printf(" |%d비트: 부호 0 + 데이터 %d|",count+1,count);
        printf("\n2. 1의 보수: ");
        for (int i=0; i<=count; i++) printf("%d",one[i]);
        printf("\n3. 2의 보수: ");
        for (int i=0; i<=count; i++) printf("%d",two[i]);
        printf(" (최종 %d의 모습) ",decimal);
        printf("\n\n");

    }else {
        printf("\n|%d의 2진수 변환과정|",decimal);
        printf("\n2진수: ");
        for (int i=0; i<=count; i++) printf("%d",bit[i]);
        printf(" |%d비트: 부호 0 + 데이터 %d|",count+1,count);
        printf("\n1의 보수: ");
        for (int i=0; i<=count; i++) printf("%d",one[i]);
        printf("\n2의 보수: ");
        for (int i=0; i<=count; i++) printf("%d",two[i]);
        printf("\n\n");
    }
    free(bit);
    free(one);
    free(two);
}
