package ua.edu.znu.calculator;

import java.util.Stack;

/**
 * Виконує аналіз введеного рядка та перетворення інфіксного виразу в постфіксну нотацію
 * @author Novak
 * @version 1.0
 */
public class ExpressionParser {

    public static String infixToPostfix(String vhidnyjRjadok) {
        StringBuilder rezultat = new StringBuilder();
        Stack<Character> stekOperatoriv = new Stack<>();

        if (vhidnyjRjadok.endsWith("=")) {
            vhidnyjRjadok = vhidnyjRjadok.substring(0, vhidnyjRjadok.length() - 1);
        }
        for (int i = 0; i < vhidnyjRjadok.length(); i++) {
            char symvol = vhidnyjRjadok.charAt(i);

            if (Character.isWhitespace(symvol)) {
                continue;
            }
            // на початку числа якщо символ є цифрою або крапкою
            if (Character.isDigit(symvol) || symvol == '.') {
                while (i < vhidnyjRjadok.length() && (Character.isDigit(vhidnyjRjadok.charAt(i)) || vhidnyjRjadok.charAt(i) == '.')) {
                    rezultat.append(vhidnyjRjadok.charAt(i));
                    i++;
                }
                rezultat.append(" ");
                i--;
            }
            // зустріли відкриваючу дужку
            else if (symvol == '(') {
                stekOperatoriv.push(symvol);
            }
            //зустріли закриваючу дужку
            else if (symvol == ')') {
                while (!stekOperatoriv.isEmpty() && stekOperatoriv.peek() != '(') {
                    rezultat.append(stekOperatoriv.pop()).append(" ");
                }
                if (!stekOperatoriv.isEmpty() && stekOperatoriv.peek() == '(') {
                    stekOperatoriv.pop();
                }
            }
            //зустріли математичний оператор (+ - * / % ^)
            else if (isOperator(symvol)) {
                while (!stekOperatoriv.isEmpty() && isOperator(stekOperatoriv.peek())) {
                    char staryjZnak = stekOperatoriv.peek();
                    int priorytetStarogo = getPrecedence(staryjZnak);
                    int priorytetNovogo = getPrecedence(symvol);
                    boolean staryjSylnishyj = priorytetStarogo > priorytetNovogo;
                    boolean odnakoviTaNeStepen = (priorytetStarogo == priorytetNovogo) && symvol != '^';

                    if (staryjSylnishyj || odnakoviTaNeStepen) {
                        rezultat.append(stekOperatoriv.pop()).append(" ");
                    } else {
                        break;
                    }
                }
                stekOperatoriv.push(symvol);
            }
        }
        //Вивантаження залишків знаків зі стеку в результат
        while (!stekOperatoriv.isEmpty()) {
            rezultat.append(stekOperatoriv.pop()).append(" ");
        }
        return rezultat.toString().trim();
    }
    private static int getPrecedence(char operator) {
        if (operator == '^') {
            return 4;
        }
        if (operator == '*' || operator == '/') {
            return 3;
        }
        if (operator == '+' || operator == '-') {
            return 2;
        }
        return -1;
    }
    private static boolean isOperator(char symvol) {
        return symvol == '+' || symvol == '-' || symvol == '*' || symvol == '/' || symvol == '^';
    }
}