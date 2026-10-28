package example;
import java.time.LocalDate;
import java.time.Period;
import java.time.format.DateTimeFormatter;

//Личность
public class Person {
    private String firstName, middleName,lastName ; //Имя Отчество Фамилия
    private LocalDate birthDate;    //Дата рождения

    //Формат для вывода даты
    public static final DateTimeFormatter Format = DateTimeFormatter.ofPattern("dd.MM.yyyy");

    // Конструктор -- метод инициализирующий объект
    public Person(String firstName1, String lastName1, String middleName1, LocalDate birthDate1){
        setfirstName(firstName1);
        setmiddleName(middleName1);
        setlastName(lastName1);
        setbirthDate(birthDate1);
    }

    // Конструктор -- метод инициализирующий объект
    public Person(){
        firstName = "Не указано";
        middleName = "Не указано";
        lastName = "Не указана";
        birthDate = null;
    }

    // Сеттер для имени - в нём не могут быть никакие символы кроме букв и дефиса
    // бросает исключение IllegalArgumentException если в имени
    // есть символы не являющиеся буквами (кроме дефиса)
    public void setfirstName(String firstName1){
        if (!firstName1.matches("[А-Яа-яЁёA-Za-z-]+"))
            throw new IllegalArgumentException("Имя указано неверно");
        if (firstName1 == null || firstName1.strip().isEmpty()){
            firstName = "Не указано";
            return;
        }
        firstName = firstName1;}


    // Сеттер для Отчества
    // бросает исключение IllegalArgumentException если в имени
    // есть символы не являющиеся буквами (кроме дефиса)
    public void setmiddleName(String middleName1){

        if (!middleName1.matches("[А-Яа-яЁёA-Za-z-]+"))  // проверка предусловия - требования к входным данным
            throw new IllegalArgumentException("Отчество указано неверно");

        if (middleName1 == null || middleName1.strip().isEmpty()){
            middleName = "Не указано";
            return;
        }
        middleName = middleName1;   }


    // Сеттер для фамилии
    // бросает исключение IllegalArgumentException если в имени
    // есть символы не являющиеся буквами (кроме дефиса)
    public void setlastName(String lastName1){
        if (!lastName1.matches("[А-Яа-яЁёA-Za-z-]+"))  // проверка предусловия - требования к входным данным
            throw new IllegalArgumentException("Фамилия указана неверно");
        if (lastName1 == null || lastName1.strip().isEmpty()){
            lastName = "Не указана";
            return;
        }
        lastName = lastName1;}

    // Сеттер для даты рождения
    // Если дата не указана то устанавливается текущая
    public void setbirthDate(LocalDate birthDate1){
        if (birthDate1 == null) {
            birthDate = LocalDate.now();
            return;
        }
        birthDate = birthDate1;
    }


    // геттер для имени
    public String getfirstName(){ return firstName; }

    // геттер для фамилии
    public String getlastName(){ return lastName; }

    // геттер для отчества
    public String getmiddleName(){ return middleName; }

    //геттер для даты рождения в формате дд.мм.гггг
    public String getbirthDateFormatted(){return birthDate.format(Format);}

    //геттер для даты рождения
    public LocalDate getbirthDate(){ return birthDate; }

    // геттер для возраста
    public int getAge(){return Period.between(birthDate, LocalDate.now()).getYears();}

    //toString для вывода
    public String toString(){
        String info = String.format("%s %s %s %s", firstName, middleName, lastName, getbirthDateFormatted());
        return info;
    }


    //Метод для очистки объекта
    public void clear(){
        firstName = "";
        middleName = "";
        lastName = "";
        birthDate = null;
    }
}
