package example;

import java.util.InputMismatchException;
import static java.lang.Math.*;
import java.util.Random;
import java.util.Scanner;

    public class modul {


        //Автоматическое заволнение массива
        //arr - Массив элементов double
        public static void AutoIn(double[] arr){//if NULL
            Random rnd = new Random(10);
            for (int i = 0; i<arr.length; i++) {
                arr[i] = rnd.nextDouble(-100.0, 100.0);//A B
            }
        }


        //Ручной ввод в массив
        //arr - Массив элементов double, Scanner sc - Инициализированных в омновной программе сканер
        public static void ManualIn(double[] arr, Scanner sc) throws InputMismatchException {
            System.out.printf("Вводите числа по очереди:%n");
            for (int i = 0; i<arr.length; i++){
                arr[i] = sc.nextDouble();
            }
        }


        //Для выбора способа ввода чисел в массив
        //arr - Массив элементов double, Scanner sc - Инициализированных в омновной программе сканер
        public static void Choice(double[] arr, Scanner sc){
            int choice;

            System.out.printf("Выберите ручной или автоматический ввод чисел%n[1] Ручной%n[2] Автоматический%n");
            try{  //Проверка на правильный тип данных
                choice = sc.nextInt();
            }
            catch (InputMismatchException e){
                System.out.println("Это не целое число!");
                sc.close();
                return;
            }

            if (choice < 1 || choice > 2){              //Проверка правильности варианта
                System.out.println("Нет такого варианта ввода");
                return;
            }

            switch (choice){
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
        }

        //Находит сумму всех элементов массива double
        //arr - Массив элементов double
        public static double Summ(double[] arr){
                double sum = 0;
                for (double a : arr)
                    sum += a;
                return sum;
        }


        //Вывод массива в консоль (по 10 чисел в строке)
        //arr - Массив элементов double
        public static void printArr(double[] arr){
            for (int i = 0;i<arr.length;i++){
                System.out.printf("   %.4f",arr[i]);
                if (i%10==9){
                    System.out.println();
                }
            }
            System.out.println();
        }


        //Функция для проверки формул на правильность вычислений
        public static void ass(){
            double[] arr1={1.0,1.0};
            double[] arr2={3.48,6.52};
            double[] arr3={-18.3,18.3};

            assert abs(Summ(arr1)) == 2.0 : "Ошибка вычислений суммы";
            assert abs(Summ(arr2)) == 10.0 : "Ошибка вычислений суммы";
            assert abs(Summ(arr3)) == 0 : "Ошибка вычислений суммы";
        }
    }