package org.example;
import java.util.InputMismatchException;
import java.util.Scanner;

/* Автор: Галкин Р.Р.
 * Задача 11д из учебника https://bgu-chita.ru/zadachnik/files/spisoc.htm
 * Даны переменные x y z. Нужно найти a и b по заданным формулам
 */
public class Main {
    public static void main(String[] args) {
        modul.ass();

        double a,b,x,y,z;  //x y z переменные для ввода. a b искомые числа

        x = y = z = 0.0;

        //Для проверки наличия аргументов
        if (args.length==0){                                         //Если аргументов нет то объявляется сканер
            System.out.println("Вводите числа x y z по очереди");    //и значения вводятся пользоваелем вручную

            try (Scanner sc = new Scanner(System.in)){             //Проверка на правильный тип данных
                x = sc.nextDouble();
                y = sc.nextDouble();
                z = sc.nextDouble();
            }
            catch (InputMismatchException e) {
                System.out.println("Это не число!");
                return;
            }
        }

        else if (args.length==3){       //При наличии 3 аргументов, их значения вводятся в переменные вводятся

            try {                                   //Проверка на правильный тип данных
                x = Double.parseDouble(args[0]);
                y = Double.parseDouble(args[1]);
                z = Double.parseDouble(args[2]);
            } catch (NumberFormatException e) {
                System.out.println("Неверный тип данных");
                return;
            }

        } else {                    //Если аргументом является -h или --help то выводится способ вызова программы
            if (args[0].equals("-h")||args[0].equals("--help")){printHelp(); return;}
            System.out.println("Неверное число переменных");    //Если число аргументов не 3 то выводится
            return;                                             //ошибка о неверном количестве аргументов
        }



        a = modul.GetA(x,y);        //Искомые значения высчитываются по вормуле данной в задании
        b = modul.GetB(z);          //11д учебника https://bgu-chita.ru/zadachnik/files/spisoc.htm

        System.out.printf("Ответ: a = %.3f b =  %.3f%n", a, b);



    }

    static void printHelp() {   //Функция для вывода подсказки о исполььзовании аргументов
        System.out.println("Использование:");
        System.out.println("java org.example.Main <x> <y> <z>");
        System.out.println();
        System.out.println("Или ввод после запуска");
    }
}