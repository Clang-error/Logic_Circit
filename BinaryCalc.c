//
// Created by GoHyeonSeok on 26. 3. 17
//
#include <stdio.h>
#include <stdlib.h>
#include "Calc.h"


void decimal_to_binary(int decimal) {

    int temp = 0;
    int sign = 0; //부호지정 변수
    int count=0;
    if (decimal < 0) {
        temp = -decimal;
        sign = 1;
    } else temp = decimal;

    while (temp > 0) { //복사한 decimal값을 0보다 클때까지 나누어 count값을 얻어 배열사이즈 지정에 활용
        temp /= 2;
        count++;
    }

    if (decimal < 0) { //  나누어 사용했던 temp값을 다시 채움
        temp = -decimal;
    } else temp = decimal;

    int *bit = (int *)malloc(sizeof(int) * (count+1));
    //입력되는 값이 유동적이기 때문에 배열사이즈를 동적으로 할당
    int *one = (int *)malloc(sizeof(int) * (count+1));
    //1의 보수용 배열
    int *two = (int *)malloc(sizeof(int) * (count+1));
    //2의 보수용 배열



    for (int i = count; i >= 1; i--) { //10진수에서 2진수 변환하는 로직
        bit[i] = temp % 2;
        //수학적으로 어떤수를 계속 n의 값으로 나누면 나머지는 항상 0에서 n-1사이의 정수가 나오기때문에. 나머지 연산자사용.
        temp /= 2;
    }

    for (int i = 0; i <= count; i++) { //bit데이터값을 one배열로 복사
        one[i] = bit[i];
    }

    //1의보수 변환 및 출력 로직
    for (int i=0; i<=count; i++) { 
        if (one[i] == 1) {one[i] = 0;}
        else {one[i] = 1;}
        //모든 배열을 순회하여 1은 0으로 0은 1으로 인덱스값을 변경
    }
    
   
    for (int i = 0; i <= count; i++) { //one데이터값을 two배열로 복사
        two[i] = one[i];
    }


    //2의 보수 변환 및 출력 로직
    int carry = 1; //올림수 1로 먼저 선언
    for (int i = count; i >= 1; i--) {
        int sum = two[i] + carry; //배열 인덱스i값과 올림수를 더하오 배열인덱스값에 2를 나눈 나머지를 저장. 이때 배열인덱스의 값은 0또는 1이기에 1%2는 는 1, 2%2는 0임
        two[i] = sum % 2;
        carry = sum / 2;//다시보기
    }

    if (sign == 1) { //출력부분, 부호가 1일때.
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

    }else { //부호가 2일때
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
