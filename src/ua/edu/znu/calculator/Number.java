package ua.edu.znu.calculator;

/**
 * Виконує операції конвертації чисел між системами числення.
 *
 * @author Федоряка - convertDecimalToBinary() / Миронюк - convertDecimalToHex(), convertHexToDecimal()
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

    public static String convertDecimalToHex(int number){//10->16
        StringBuilder hex = new StringBuilder();
        while (number > 0) {
            int remainder =(number % 16);
            if(remainder <10) {
                hex.insert(0,remainder);
            } else {
                hex.insert(0, (char)('a' + (remainder - 10)));
            }
            number /=16;
        }
        return hex.toString();
    }
    public static long convertHexToDecimal(String number){//16->10
        long decimal = 0;
        for(int i = 0; i <number.length();i++){
            char c = number.charAt(i);
            int digit = 0;
            if(c >='0'&& c<= '9'){
                digit = c-'0';
            } else if (c >= 'A' && c <= 'F'){
                digit = 10 + (c -'A');
            }
            decimal = decimal * 16 + digit;}
        return decimal;
    }
}
