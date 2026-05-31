package ua.edu.znu.calculator;

/**
 * Виконує операції конвертації чисел між системами числення.
 *
 * @author Федоряка - convertDecimalToBinary() / Миронюк - convertDecimalToHex(), convertHexToDecimal()
 * @version 1.0
 */
public class Number {

         // Перетворює ціле число з десяткової системи числення у двійкову.
     //Приклад: 47 → "101111"
     //
     //@param number число для перетворення
     // @return двійковий рядок
   //
    public static String toBinaryString(int number) {
        if (number == 0) return "0";
        boolean isNegative = number < 0;
        if (isNegative) number = -number;
        StringBuilder sb = new StringBuilder();
        while (number > 0) {
            sb.insert(0, number % 2);
            number /= 2;
        }
        if (isNegative) sb.insert(0, '-');
        return sb.toString();
    }
   //Перетворення з двійкової системи в десяткову
     //Кожна цифра рядка множиться на 2 у відповідному степені,
      //після чого результати складаються.
     // Приклад: "101111" -> 1·2⁵ + 0·2⁴ + 1·2³ + 1·2² + 1·2¹ + 1·2⁰ = 47
     //
     // @param binary двійковий рядок, наприклад "101111"
     //@return ціле число, наприклад 47
     //@throws IllegalArgumentException якщо рядок порожній або містить недопустимі символи
    //
    public static int fromBinaryString(String binary) {
        if (binary == null || binary.isEmpty()) {
            throw new IllegalArgumentException("Рядок не може бути порожнім!");
        }
        boolean isNegative = binary.charAt(0) == '-';
        String digits = isNegative ? binary.substring(1) : binary;
        if (!digits.matches("[01]+")) {
            throw new IllegalArgumentException("Невірний формат: " + binary);
        }
        int result = 0;
        int power = 1;
        for (int i = digits.length() - 1; i >= 0; i--) {
            if (digits.charAt(i) == '1') {
                result += power;
            }
            power *= 2;
        }
        return isNegative ? -result : result;
    }

    public static void main(String[] args) {
        // toBinaryString
        System.out.println(toBinaryString(47));   // 101111
        System.out.println(toBinaryString(-47));  // -101111
        System.out.println(toBinaryString(1));    // 0

        // fromBinaryString
        System.out.println(fromBinaryString("101111"));   // 47
        System.out.println(fromBinaryString("-101111"));  // -47
        System.out.println(fromBinaryString("0"));        // 0
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
