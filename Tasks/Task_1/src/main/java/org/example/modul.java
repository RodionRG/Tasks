package org.example;

import static java.lang.Math.*;

public class modul {

    //Искомые значения высчитываются по вормуле данной в задании
    //11д учебника https://bgu-chita.ru/zadachnik/files/spisoc.ht
    public static double GetA(double x, double y){
        return (2 * cos(x-(PI / 6))) / ((1.0 / 2.0)+(pow(sin(y),2)));
    }
    public static double GetB(double z){
        return 1 + (pow(z,2) / (3+(pow(z,2)/5)));
    }

    public static void ass(){           //Функция для проверки формул на правильность вычислений
        assert abs(GetA(0, 0) - 3.46410)<0.00001 : "Ошибка вычислений A";
        assert abs(GetA(1, 0) - 3.55460)<0.00001 : "Ошибка вычислений A";
        assert abs(GetA(0, 1) - 1.434)<0.001 : "Ошибка вычислений A";

        assert abs(GetB(0)) == 1 : "Ошибка вычислений B";
        assert abs(GetB(1)) == 1.3125 : "Ошибка вычислений B";
        assert abs(GetB(5)) == 4.125 : "Ошибка вычислений B";
    }
}