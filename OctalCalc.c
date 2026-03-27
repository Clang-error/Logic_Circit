//
// Created by GoHyeonSeok on 26. 3. 18..
//

#include "Calc.h"
#include <stdio.h>

void decimal_to_octal(int D,char *r) { //나머지는 다 8비트사이즈로 구현했는데 8진수는 어떤식으로 구해야하는지 명확히 몰라서 그냥 정석 풀이로 설계
    if (D < 0){ D = -D; } //배열 생성
    int bit[3]={0,};
    int one[3]={0,};
    // int comp8[8]={0,};
    int i;
    int size=0, temp=D;
    while (temp > 0) { //입력받은 decimal 정수가 몇의자리 수 까지 있는지 계산
        temp /= 10;
        size++;
    }
    for (i=2; i>=0; i--) { //10진수 8진수 변환로직
        bit[i] = D % 8;
        D = D / 8;
    }
    printf("%s의 8진수: ",r); //부호화 절댓값 변환로직
    for (i=0; i<3; i++) {
        printf("%d",bit[i]);
    }

    //7의 보수 생성로직
    printf("\n7의보수: ");
    for (i=0; i<3; i++) {
        if (i == 0) {
            one[i] = 1 - bit[i]; // 최대값이 377
        } else {
            one[i] = 7 - bit[i];
        }
        printf("%d",one[i]);
    }
    // for (i=0; i<3;) { //가장 가까운 0이 아닌 수 찾는 로직 더미로직
    //     if (bit[i] == 0) {
    //         i++;
    //     }
    //     else if (bit[i] >= 1) {
    //         break;
    //     }
    // }
    // for (i; i<3; i++) {
    //     one[i] = 7-bit[i];
    // }


    printf("\n8의보수: ");
    for (i = 2; i >= 0; i--) {
        if (one[i] < 7) {
            one[i] += 1;
            break;
        }else {
            one[i] = 0;
        }
    }

    for (i=0; i<3; i++) {
        printf("%d",one[i]);
    }
    printf("\n");
}