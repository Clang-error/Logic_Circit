

#include "Calc.h"
#include <stdio.h>
#include <stdlib.h>

void convert() {
    int r1 = 0;
    int r2 = 0;
    int sign =0;
    long decimal = 0; //10진수 0으로 초기화
    char rawString[100]; //여기에 데이터를 먼저 받음 문자열형식으로

    while (r1 != 5) {
        printf("(참고) 입력한 진수데이터는 10진수로 변환 후 연산됩니다.\n");
        printf("2,8,10,16 진수 중 하나 입력 (5 입력시 종료): ");
        scanf("%d",&r1);
        if (r1 != 2 && r1 != 8 && r1 != 10 && r1 != 16 && r1 != 5) {
            //입력값 검증 로직
            printf("올바른 진법을 입력하시오\n\n");
            continue;
        }
        if (r1 == 5) {break;}

        printf("양수(0)와 음수(1) 중 선택:"); //
        scanf("%d",&sign);
        if (sign != 0 && sign != 1) {
            printf("0 또는 1만 입력하시오.\n\n");
            continue;
        }

        printf("|절대값|%d진수 입력: ",r1);
        scanf("%s",rawString);
        
        printf("어떤 진법으로 변환하시겠습니까? :");
        scanf("%d",&r2);
        if (r2 != 2 && r2 != 8 && r2 != 10 && r2 != 16) {
            printf("올바른 진법을 입력하시오\n\n");
            continue;
        }

        decimal = strtol(rawString, NULL, r1);
        if (sign == 1) decimal = -decimal;

        switch (r2) {
            case 2:  decimal_to_binary(decimal); break;
            case 8:  decimal_to_octal(decimal); break;
            case 10: decimal_to_complement(decimal); break;
            case 16: decimal_to_hexadecimal(decimal); break;
        }
    }
}