package example;
import java.io.FileNotFoundException;
import java.lang.classfile.instruction.SwitchCase;
import java.util.ArrayList;
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
        ArrayList<Double> arrl = new ArrayList<>();
        double sum, answer;
        String url;

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

            modul.Choice(arrl, sc, n);
        }
        else if (args.length==3){                   //Если 3 аргумента соответствующих значений
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
            if (choice < 1 || choice > 3){                  //Проверка правильности варианта
                System.out.println("Нет такого варианта ввода");
                return;
            }

            switch (choice) {               //Проверка на выбор ввода
                case 1 -> {
                    System.out.printf("Выбран ручной ввод%n");
                    try {
                        modul.ManualIn(arrl, sc);
                    } catch (InputMismatchException e) {
                        System.out.println("Неверный тип данных");
                        sc.close();
                        return;
                    }

                }
                case 2 -> {
                    System.out.printf("Выбрано автоматическое заполнение:%n");
                    System.out.printf("Ведите диапазон (по очереди верх низ)%n");
                    modul.AutoIn(arrl, sc.nextDouble(),sc.nextDouble(),n);
                }
                case 3 -> {
                    System.out.printf("Выбрано заполнение из файла:%n");
                    System.out.printf("Введите путь читаемого файла:%n");
                    url = sc.next();
                    try{
                        modul.FileIn(arrl, url);
                    }
                    catch ( FileNotFoundException e){
                        System.out.println("Файл не найден");
                        return;
                    }
                    catch (InputMismatchException e){
                        System.out.println("Неверная запись числа");
                    }
                }
            }
        } else {                    //Если аргументом является -h или --help то выводится способ вызова программы
            if (args[0].equals("-h")||args[0].equals("--help")){printHelp(); return;}
            System.out.println("Неверное число переменных");    //Если число аргументов не 3 то выводится
            return;                                             //ошибка о неверном количестве аргументов
        }



        System.out.println();
        System.out.println("Ваш массив:");      //Вывод массива
        modul.printArr(arrl);

        sum = modul.Summ(arrl);      //Нахождение суммы

        answer = sin(abs(sum));     //Нахождение итогового ответа

        System.out.printf("Ответ: %.15f%n",answer);

        System.out.printf("Записать массив в файл?%n [1] Да%n [2] Нет%n");
        try {
            if (1 == sc.nextInt()){
                System.out.printf("Введите путь файла для записи:%n");
                url = sc.next();
                try{
                    modul.FileOut(arrl, url);
                }
                catch ( FileNotFoundException e){
                    System.out.println("Файл не найден");
                    return;
                }
            };
        }
        catch (InputMismatchException e){
            System.out.println("Это не целое число!");
        }
            sc.close();
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