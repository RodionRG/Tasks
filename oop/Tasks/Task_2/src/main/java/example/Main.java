package example;
import java.lang.classfile.instruction.SwitchCase;
import java.util.InputMismatchException;
import java.util.Scanner;
import static java.lang.Math.*;

/* Автор: Галкин Р.Р.
 * Задача 136м из учебника https://bgu-chita.ru/zadachnik/files/spisoc.htm
 * Дано число n и числа a[1] a[2] ... a[n]
 * Нужно найти Sin|a[1]+a[2]+...+a[n]|
 */

public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n,choice;
        double[] arr;
        double sum, answer;

        if (args.length==0){                                        //Если аргументов нет то объявляется сканер
            System.out.println("Введите кол-во чисел");             //и значения вводятся пользоваелем вручную

            try {             //Проверка на правильный тип данных
                n = sc.nextInt();
            }
            catch (InputMismatchException e) {
                System.out.println("Это не целое число!");
                sc.close();
                return;
            }
            arr = new double[n];

            modul.Choice(arr, sc);
        }
        else if (args.length==2){                   //Если 2 аргумента соответствующих значений
            try {                                   //Проверка на правильный тип данных
                n = Integer.parseInt(args[0]);
                choice = Integer.parseInt(args[1]);

            } catch (NumberFormatException e) {
                System.out.println("Неверный тип данных");
                sc.close();
                return;
            }

            if (n<=0){
                System.out.println("Неверное кол-во элементов");
                return;
            }
            if (choice < 1 || choice > 2){                  //Проверка правильности варианта
                System.out.println("Нет такого варианта ввода");
                return;
            }

            arr = new double[n];
            switch (choice) {               //Проверка на выбор ввода
                case 1 -> {
                    System.out.printf("Выбран ручной ввод%n");
                    try {
                        modul.ManualIn(arr, sc);
                    } catch (InputMismatchException e) {
                        System.out.println("Неверный тип данных");
                        sc.close();
                        return;
                    }

                }
                case 2 -> {
                    System.out.printf("Выбран автоматический ввод:%n");
                    modul.AutoIn(arr);
                }
            }
        } else {                    //Если аргументом является -h или --help то выводится способ вызова программы
            if (args[0].equals("-h")||args[0].equals("--help")){printHelp(); return;}
            System.out.println("Неверное число переменных");    //Если число аргументов не 3 то выводится
            return;                                             //ошибка о неверном количестве аргументов
        }

        sc.close();

        System.out.println();
        System.out.println("Ваш массив:");      //Вывод массива
        modul.printArr(arr);

        sum = modul.Summ(arr);      //Нахождение суммы

        answer = sin(abs(sum));     //Нахождение итогового ответа

        System.out.printf("Ответ: %.15f",answer);
    }

    static void printHelp() {
        System.out.println("Использование:");
        System.out.println();
        System.out.println("java org.example.Main <n> <choice>");
        System.out.println();
        System.out.println("n - кол-во элементов, choice - выбор способа ввода: 1 ручной; 2 автоматический");
        System.out.println();
        System.out.println("Или ввод после запуска");
    }
}