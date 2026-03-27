//
// Created by GoHyeonSeok on 26. 3. 18..
//

#include <stdio.h>
#include <stdlib.h>

void decimal_to_complement(int decimal,char *r) { //최대저장값은 127로 저장
    if (decimal < 0) {
        printf("%s의 10진수: %d\n",r,decimal);
        printf("9의 보수: %d\n",(decimal*-1)-1);
        printf("10의 보수: %d\n",(decimal*-1));
        printf("%d는 음수이기에 보수를 구하면 다시 양수가됩니다\n",decimal);
        return;
    }
    int size = 0;
    int temp = decimal;
    int temp2 = decimal;

    printf("\n");
    printf("%s의 10진수: %d\n",r,decimal);

    while (temp > 0) { //입력받은 decimal 정수가 몇의자리 수 까지 있는지 계산
        temp /= 10;
        size++;
    }
    int bit[size];
    for (int i=size-1; i>=0; i--) { //9의보수 생성로직
        bit[i] = 9-(temp2 % 10);
        temp2 /= 10;
    }
    printf("9의 보수: ");
    for (int i=0; i<size; i++) {printf("%d",bit[i]);} //9의보수 출력
    printf("\n");

    int carry = 1;
    for (int i = size - 1; i >= 0; i--) {
        int sum = bit[i] + carry;
        bit[i] = sum % 10;
        carry = sum / 10;
    }

    printf("10의 보수: ");
    for (int i=0; i<size; i++) {printf("%d",bit[i]);} //10의보수 출력
    printf("\n");

}