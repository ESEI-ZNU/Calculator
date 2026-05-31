package ua.edu.znu.calculator;

import java.util.Stack;

/**
 * Обчислення результату за постфіксним записом
 * @author Novak
 * @version 1.0
 */
public class PostfixEvaluator {
    public static double evaluate(String postfix) {
        Stack<Double> stek = new Stack<>(); // Стек, де будуть зберігатися тільки числа

        // Розбиваємо наш рядок на окремі елементи за допомогою пробілів
        String[] elementy = postfix.split(" ");
        for (String x : elementy) {
            // пропуск порожнього елемента
            if (x.isEmpty()) {
                continue;
            }
            if (x.equals("+") || x.equals("-") || x.equals("*") || x.equals("/") || x.equals("^")) {
                double b = stek.pop(); // зі стеку друге число
                double a = stek.pop(); // зі стеку перше число
                // Рахуємо результат залежно від знака і відразу кладемо його назад у стек
                if (x.equals("+")) stek.push(a + b);
                else if (x.equals("-")) stek.push(a - b);
                else if (x.equals("*")) stek.push(a * b);
                else if (x.equals("/")) stek.push(a / b);
                else if (x.equals("^")) stek.push(Math.pow(a, b));
            }
            else {
                // Перетворюємо текст на звичайне комп'ютерне число та кладемо в стек
                double chislo = Double.parseDouble(x);
                stek.push(chislo);
            }
        }
        return stek.pop();
    }
}