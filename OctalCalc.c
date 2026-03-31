//
// Created by GoHyeonSeok on 26. 3. 18..
//

#include "Calc.h"
#include <stdio.h>

void decimal_to_octal(int decimal) {
    printf("|%d의 8진수 변환과정|\n",decimal);
    if (decimal < 0){ decimal = -decimal; } //배열 생성
    int bit[100]={0,};
    int one[100]={0,};
    int i;
    int size=0, temp=decimal;
    while (temp > 0) { //입력받은 decimal 정수가 몇의자리 수 까지 있는지 계산
        temp /= 10;
        size++;
    }
    for (i=size-1; i>=0; i--) { //10진수 8진수 변환로직
        bit[i] = decimal % 8;
        decimal = decimal / 8;
    }
    printf("8진수: ");
    for (i=0; i<size; i++) {
        printf("%d",bit[i]);
    }

    //7의 보수 생성로직
    printf("\n7의보수: ");
    for (i=0; i<size; i++) {
        one[i] = 7 - bit[i];
        printf("%d",one[i]);
    }

    printf("\n8의보수: ");
    for (i = size-1; i >= 0; i--) {
        if (one[i] < 7) {
            one[i] += 1;
            break;
        }else {
            one[i] = 0;
        }
    }

    for (i=0; i<size; i++) {
        printf("%d",one[i]);
    }
    printf("\n\n");
}