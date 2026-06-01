package ua.edu.znu.calculator;

/**
 * Виконує операції конвертації чисел між системами числення.
 *
 * @author Федоряка - convertDecimalToBinary() / Миронюк - convertDecimalToHex(), convertHexToDecimal()
 * @version 1.0
 */
```
    public class MyNumber {
        /**
         * Перетворює ціле число з десяткової системи числення у двійкову та перетворення з двійкової системи в десяткову.
         * @Author Ivan
         * @since 1.0
         * @param choice
         */
        public  void Number(String[] choice){
            //System.out.println.(LocalDate.now ());
        }

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

    }
}


    public static String convertDecimalToHex(int number) {//10->16
        StringBuilder hex = new StringBuilder();
        while (number > 0) {
            int remainder = (number % 16);
            if (remainder < 10) {
                hex.insert(0, remainder);
            } else {
                hex.insert(0, (char) ('a' + (remainder - 10)));
            }
            number /= 16;
        }
        return hex.toString();
    }

    public static long convertHexToDecimal(String number) {//16->10
        number = number.toUpperCase();
        long decimal = 0;
        for (int i = 0; i < number.length(); i++) {
            char c = number.charAt(i);
            int digit = 0;
            if (c >= '0' && c <= '9') {
                digit = c - '0';
            } else if (c >= 'A' && c <= 'F') {
                digit = 10 + (c - 'A');
            }
            decimal = decimal * 16 + digit;
        }
        return decimal;
    }
}
