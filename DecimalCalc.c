//
// Created by GoHyeonSeok on 26. 3. 18..
//

#include <stdio.h>

void decimal_to_complement(int decimal,char *r) { //최대저장값은 127로 저장
    // printf("%s의 10진수: %d\n",r,decimal);
    printf("\n|%d의 10진수 변환과정|\n",decimal);
    printf("10진수: %d\n",decimal);

    if (decimal < 0){ decimal = -decimal; } //음수 입력받았을 시 sign을 1로 만들어 뒷 출력에서 -를 붙히는 식으로 작동
    int size = 0;
    int temp = decimal; //정수 자릿수 계산을 했을 때 데이터 원본을 유지하기 위해 temp 선언
    int temp2 = decimal;
    int bit[size]; //보수로 변환된 데이터 저장

    while (temp > 0) { //입력받은 decimal 정수가 몇의자리 수 까지 있는지 계산
        temp /= 10;
        size++;
    }

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