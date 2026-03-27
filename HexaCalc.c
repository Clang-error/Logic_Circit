//
// Created by GoHyeonSeok on 26. 3. 18..
//

#include <ctype.h>

#include "Calc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decimal_to_hexadecimal(int Decimal,char *r) {
    if (Decimal < 0){ Decimal = -Decimal; }
    int val=0;
    char hex_str[10]={0,};
    sprintf(hex_str, "%02X", Decimal); //sprintf를 활용하여 문자열에 저장
    printf("\n");
    printf("%s의 16진수: ",r);
    printf("%s\n", hex_str);

    //15의보수 구하는 법 찾기.
    printf("15의보수: ");
   for (int i=0; i<strlen(hex_str); i++) {
       if (hex_str[i] >= '0' && hex_str[i] <= '9') {
           val = hex_str[i] - '0';
       } else {
           val = hex_str[i] - 'A' + 10;
       }
       int res = 15 - val;

       if (res <= 9) {
           hex_str[i] = res + '0';
       } else {
           hex_str[i] = res - 10 + 'A';
       }
   }
    for (int i=0; i<strlen(hex_str); i++) {
        printf("%c",hex_str[i]);
    }

    //16의보수
    printf("\n16의보수: ");
    for (int i=strlen(hex_str)-1; i>=0; i--) {
        if ( hex_str[i] == 'F') {
            hex_str[i] = '0';
        }
        else {
            if (hex_str[i] == '9') {hex_str[i] = 'A';}
            else {hex_str[i] = hex_str[i] + 1;}
            break;
        }
    }
    for (int i=0; i<strlen(hex_str); i++) {
        printf("%c",hex_str[i]);
    }
}
//8진수랑 16진수 음으로 표현하는 거 확인하기
