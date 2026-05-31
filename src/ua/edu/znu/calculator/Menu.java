package ua.edu.znu.calculator;
import java.util.Scanner;

/**
 * відображення головного меню програми та вибір режиму роботи.
 * @author Priadko
 * @version 1.0
 */
public class Menu {

//  обробку вибору пункту меню користувача.
    public static void showMenu(){
        Scanner scanner = new Scanner(System.in);

        int choice = 0;

        System.out.println("Меню\n1. Ввести вираз\n2. Перевод з [10] -> [2]\n3. Перевод з [2] -> [10]\n4. Перевод з [10] -> [16]\n5. Перевод з [16] -> [10]\n6. Вихiд ");

        while (choice != 6) {

            System.out.print("Оберiть пункт меню: ");
            choice = Integer.parseInt(scanner.nextLine());

            if (choice < 1 || choice > 6) {
                System.out.println("Введено неправильний діапазон");
                continue;
            }

            switch (choice) {
                case 1:
                    System.out.print("Введiть вираз: ");
                    String name = scanner.nextLine();

                    String postfix_row = ExpressionParser.infixToPostfix(name);
                    double result = PostfixEvaluator.evaluate(postfix_row);
                    System.out.println(result);
                    break;

                case 2:
                    System.out.print("Введiть число: ");
                    int num = Integer.parseInt(scanner.nextLine());

                    String res = Number.toBinaryString(num);
                    System.out.println(res);
                    break;

                case 3:
                    System.out.print("Введiть число: ");
                    String number = scanner.nextLine();

                    int res3 = Number.fromBinaryString(number);
                    System.out.println(res3);
                    break;

                case 4:
                    System.out.print("Введiть число: ");
                    int n = Integer.parseInt(scanner.nextLine());

                    String result4 = Number.convertDecimalToHex(n);
                    System.out.println(result4);
                    break;

                case 5:
                    System.out.print("Введiть число: ");
                    String number5 = scanner.nextLine();

                    long res5 = Number.convertHexToDecimal(number5);
                    System.out.println(res5);
                    break;

                case 6:
                    System.out.println("Ви вийшли з програми...");
                    break;
            }
        }

    }
}
