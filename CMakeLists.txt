cmake_minimum_required(VERSION 4.1)
project(Logic_Circit C)

set(CMAKE_C_STANDARD 11)

add_executable(Logic_Circit
        main.c
        BinaryCalc.c
        Calc.h
        Convert.c
        OctalCalc.c
        HexaCalc.c
        DecimalCalc.c)
