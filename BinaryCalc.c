//
// Created by GoHyeonSeok on 26. 3. 17
//
#include <stdio.h>
#include "Calc.h"


void decimal_to_binary(int D,char *r) {
    printf("\n%s의 2진수: ",r); //부호화 절댓값(2진법)변환로직
    int temp = D;
    int bit[8]={0,};
    int mag[7]={0,};
    if (D < 0) { //만약 음수가 입력됐으면, 0번째 인덱스를 1로 변경
        temp = -D;
        bit[0] = 1;
    }
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

    for (int i = 6; i >= 0; i--) { //받은 수 2진수로 변환하는 로직
        mag[i] = temp % 2;
        temp /= 2;
    }

    for (int i = 0; i < 7; i++) {
        bit[i + 1] = mag[i]; //부호비트가 저장된 0번째 인덱스를 건드리지않기위해 bit +1, 변환된 2진값을 bit에 저장
    }

    for (int i=0; i<=7; i++) {
        printf("%d",bit[i]);
    }

    int one[8]={0,};
    for (int i = 0; i < 8; i++) {
        one[i] = bit[i];
    }

    for (int i=0; i<=7; i++) { //1의보수 변환 및 출력 로직
        if (one[i] == 1) {one[i] = 0;}
        else {one[i] = 1;}
    }
    printf("\n1의 보수: ");
    for (int i=0; i<=7; i++) {
        printf("%d",one[i]);
    }

    int j =6; //2의 보수 변환 및 출력 로직
    int two[8]={0,};
    for (int i = 0; i < 8; i++) {
        two[i] = one[i];
    }

    int carry = 1;
    for (int i = 7; i >= 1; i--) {
        int sum = two[i] + carry;
        two[i] = sum % 2;
        carry = sum / 2;
    }

    printf("\n2의 보수: ");
    for (int i=0; i<=7; i++) {
        printf("%d",two[i]);
    }printf("\n\n");
}