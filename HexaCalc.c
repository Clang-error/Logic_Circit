//
// Created by GoHyeonSeok on 26. 3. 18..
//

#include <ctype.h>

#include "Calc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decimal_to_hexadecimal(int decimal,char *r) {
    printf("\n|%d의 16진수 변환과정|\n",decimal);
    if (decimal < 0){ decimal = -decimal; }
    int val=0;
    char hex_str[10]={0,};
    sprintf(hex_str, "%02X", decimal); //sprintf를 활용하여 문자열에 저장
    // printf("%s의 16진수: ",r);
    printf("16진수: ");
    printf("%s\n", hex_str);

    //15의보수 구하는 법 찾기.
    printf("15의보수: ");
   for (int i=0; i<strlen(hex_str); i++) {
       if (hex_str[i] >= '0' && hex_str[i] <= '9') { //'0'의 아스키값은 48, '9'의 아스키값은 57
           val = hex_str[i] - '0';
       } else {
           val = hex_str[i] - 'A' + 10; //'A'는 아스키값이 65이기에 +10을 넣어 실제 숫자값으로 변환.
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
    printf("\n\n");
}

