package example;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.*;

import static java.lang.Math.*;

public class modul {


        //Автоматическое заволнение массива
        //arrl - Объект ArrayList из элементов double
        //Max - верхняя граница, Min - нижняя граница
        //n - кол-во элементов
        public static void AutoIn(ArrayList<Double> arrl, double Max, double Min, int n){
            Random rnd = new Random(10);
            for (int i = 0; i<n; i++) {
                arrl.add(rnd.nextDouble(Min, Max));
            }
        }


        //Ручной ввод в массив
        //arrl - Объект ArrayList из элементов double, Scanner sc - Инициализированных в омновной программе сканер
        public static void ManualIn(ArrayList<Double> arrl, Scanner sc) throws InputMismatchException {
            System.out.printf("Вводите числа по очереди:%n");
            for (int i = 0; i<arrl.size(); i++){
                arrl.add(sc.nextDouble());
            }
        }

        //Заполнение из файла
        //arrl - Объект ArrayList из элементов double
        //url - Ссылка на файл
        public static void FileIn(ArrayList<Double> arrl, String url) throws FileNotFoundException {
            Scanner scf = new Scanner(new File(url));
            scf.useLocale(Locale.GERMANY);
            while (scf.hasNextDouble()){
                arrl.add(scf.nextDouble());
            }
            scf.close();
        }


        //Заполнение в файл
        //arrl - Объект ArrayList из элементов double
        //url - Ссылка на файл
        public static void FileOut(ArrayList<Double> arrl, String url) throws FileNotFoundException {
            PrintWriter w = new PrintWriter(url);

            for (int i = 0; i<arrl.size(); i++){
                w.printf(Locale.GERMANY,"   %.4f",arrl.get(i));
                if (i%10==9){
                    w.printf("%n");
                }
            }
            w.close();
        }

        //Для выбора способа ввода чисел в массив
        //arrl - Объект ArrayList из элементов double, Scanner sc - Инициализированных в омновной программе сканер
        //n - кол-во переменных
        public static void Choice(ArrayList<Double> arrl, Scanner sc, int n){
            int choice;

            System.out.printf("Выберите ручной ввод, атоматическое заполнение или заполнение из файла%n[1] Ручной%n[2] Автоматический%n[3] Из файла%n");
            try{  //Проверка на правильный тип данных
                choice = sc.nextInt();
            }
            catch (InputMismatchException e){
                System.out.println("Это не целое число!");
                sc.close();
                return;
            }

            if (choice < 1 || choice > 3){              //Проверка правильности варианта
                System.out.println("Нет такого варианта ввода");
                return;
            }

            switch (choice){
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
                    try{  //Проверка на правильный тип данных
                        modul.AutoIn(arrl, sc.nextDouble(),sc.nextDouble(),n);
                    }
                    catch (InputMismatchException e){
                        System.out.println("Это не целое число!");
                        sc.close();
                        return;
                    }

                }
                case 3 -> {
                    String url;
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
        }

        //Находит сумму всех элементов массива double
        //arr - Массив элементов double
        public static double Summ(ArrayList<Double> arrl){
                double sum = 0;
                for (int i = 0; i < arrl.size(); i++)
                    sum += arrl.get(i);
                return sum;
        }


        //Вывод массива в консоль (по 10 чисел в строке)
        //arr - Массив элементов double
        public static void printArr(ArrayList<Double> arrl){
            for (int i = 0;i<arrl.size();i++){
                System.out.printf("   %.4f",arrl.get(i));
                if (i%10==9){
                    System.out.println();
                }
            }
            System.out.println();
        }


        //Функция для проверки формул на правильность вычислений
        public static void ass(){
            ArrayList<Double> arr1 = new ArrayList<>(); arr1.add(1.0);arr1.add(1.0);
            ArrayList<Double> arr2 = new ArrayList<>(); arr2.add(3.48);arr2.add(6.52);
            ArrayList<Double> arr3 = new ArrayList<>(); arr3.add(-18.3);arr3.add(18.3);


            assert abs(Summ(arr1)) == 2.0 : "Ошибка вычислений суммы";
            assert abs(Summ(arr2)) == 10.0 : "Ошибка вычислений суммы";
            assert abs(Summ(arr3)) == 0 : "Ошибка вычислений суммы";
        }
    }