package ua.edu.znu.calculator;

/**
 * Виконує операції конвертації чисел між системами числення.
 *
 * @author Федоряка - convertDecimalToBinary() / Миронюк - convertDecimalToHex()
 * @version 1.0
 */
public class Number {

    /**
     * Перетворює ціле число з десяткової системи числення у двійкову.
     *
     * @param number - ціле число, яке потрібно конвертувати
     * @return рядок, що представляє двійкове представлення числа. Якщо число від'ємне, рядок починається з '-'.
     */
    public static String toBinaryString(int number) {
        if (number == 0) return "0";

        boolean isNegative = number < 0;
        if (isNegative) number = -number;

        StringBuilder sb = new StringBuilder();

        while (number > 0) {
            sb.insert(0, number % 2);  // залишок від ділення на 2
            number /= 2;               // ціла частина від ділення на 2
        }

        if (isNegative) sb.insert(0, '-');
        return sb.toString();
    }

    // Перетворює число з десяткової системи числення у шістнадцяткову.
//    public static String convertDecimalToHex(int number){
//
//    }
}
