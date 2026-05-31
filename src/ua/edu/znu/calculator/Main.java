package ua.edu.znu.calculator;

/**
 * Забезпечує запуск програми, зчитування виразу від користувача, виклик модулів для обробки
 * та виведення результату.
 *
 * @author Приядко Вадим
 * @version 1.0
 */
public class Main {

    static void main(String[] args) {
        int number = 25;
        System.out.println("Десяткове число: " + number);
        String numberBin = Number.toBinaryString(number);
        System.out.println("Двійкове представлення: " + numberBin);

    }
}
