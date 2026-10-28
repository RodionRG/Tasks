package example;

import java.io.File;
import java.io.FileNotFoundException;
import java.time.LocalDate;
import java.time.format.DateTimeParseException;
import java.util.Scanner;
import java.io.PrintWriter;
import java.io.FileNotFoundException;

public class Main {
    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        try {
            Person p1 = new Person("Анатолий", "Маратович","Аухадеев", LocalDate.of(2009, 3,15));
            p1.setbirthDate(LocalDate.of(1999,5,12));
            System.out.println( "Возраст: " + p1.getAge() );
            System.out.println( "p1: " + p1 );

        } catch (IllegalArgumentException e) {
            System.out.println( "Неверный аргумент" );
        }


        Person[] band = new Person[15];

        System.out.println( "Ведите путь считываемого файла" );
        String fileIn = in.next();

        try (Scanner sc = new Scanner(new File(fileIn))) {
            int i = 0;
            while (sc.hasNextLine()) {
                if (i>=15);
                band[i] = new Person(sc.next(), sc.next(), sc.next(), LocalDate.parse(sc.next(), band[i].Format));
                i++;
            }
        }
        catch (FileNotFoundException e){
            System.out.println("Файл не найден");
            return;
        }
        catch (DateTimeParseException e){
            System.out.println("Неправильный формат даты");
        }

        System.out.println( "Band: " );

        for (int i = 0; i < 15; i++) {
            System.out.println(band[i]);
        }

        System.out.println( "" );
        System.out.println( "Введите путь файла для записи" );

        System.out.println( "Ведите путь считываемого файла" );
        String fileOut = in.next();

        try (PrintWriter w = new PrintWriter(fileOut)){
            for (int i = 0; i < 15; i++) {
                w.printf("%s%n",band[i]);
            }
        }catch (FileNotFoundException e){
            System.out.println("Файл не найден");
            return;
        }

    }
}
















