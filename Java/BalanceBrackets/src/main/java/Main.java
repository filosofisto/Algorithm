import java.util.*;
// Add any extra import statements you may need here


class Main {
    // Add any helper functions you may need here
    enum Symbol {
        BRACKET_OPEN,
        BRACKET_CLOSE,

        PARENTHESIS_OPEN,
        PARENTHESIS_CLOSE,

        KEY_OPEN,
        KEY_CLOSE;

        static Symbol charToSymbol(char ch) {
            switch (ch) {
                case '{': return KEY_OPEN;
                case '}': return KEY_CLOSE;
                case '[': return BRACKET_OPEN;
                case ']': return BRACKET_CLOSE;
                case '(': return PARENTHESIS_OPEN;
                case ')': return PARENTHESIS_CLOSE;
                default: return null;
            }
        }

        boolean isOpen() {
            return this == KEY_OPEN || this == BRACKET_OPEN || this == PARENTHESIS_OPEN;
        }

        static boolean isCompatible(Symbol close, Symbol open) {
            return open == KEY_OPEN && close == KEY_CLOSE
                    || open == BRACKET_OPEN && close == BRACKET_CLOSE
                    || open == PARENTHESIS_OPEN && close == PARENTHESIS_CLOSE;
        }
    }

    class Parser {
        String expression;
        LinkedList<Symbol> stack;

        public Parser(String expression) {
            this.expression = expression;
            stack = new LinkedList<>();
        }

        public boolean parse() {
            for (char ch: expression.toCharArray()) {
                Symbol symbol = Symbol.charToSymbol(ch);

                if (symbol.isOpen()) {
                    stack.push(symbol);
                } else {
                    Symbol popSymbol = stack.poll(); //avoid exception

                    if (!Symbol.isCompatible(symbol, popSymbol)) {
                        return false;
                    }
                }
            }

            return true;
        }
    }

    boolean isBalanced(String s) {
        // Write your code here
        Parser parser = new Parser(s);
        return parser.parse();
    }












    // These are the tests we use to determine if the solution is correct.
    // You can add your own at the bottom, but they are otherwise not editable!
    int test_case_number = 1;
    void check(boolean expected, boolean output) {
        boolean result = (expected == output);
        char rightTick = '\u2713';
        char wrongTick = '\u2717';
        if (result) {
            System.out.println(rightTick + " Test #" + test_case_number);
        }
        else {
            System.out.print(wrongTick + " Test #" + test_case_number + ": Expected ");
            System.out.print(expected);
            System.out.print(" Your output: ");
            System.out.print(output);
            System.out.println();
        }
        test_case_number++;
    }
    void printString(String str) {
        System.out.print("[" + str + "]");
    }

    public void run() {
        String s_1 = "{[(])}";
        boolean expected_1 = false;
        boolean output_1 = isBalanced(s_1);
        check(expected_1, output_1);

        String s_2 = "{{[[(())]]}}";
        boolean expected_2 = true;
        boolean output_2 = isBalanced(s_2);
        check(expected_2, output_2);

        // Add your own test cases here
        String s_3 = ")";
        boolean expected_3 = false;
        boolean output_3 = isBalanced(s_3);
        check(expected_3, output_3);

        String s_4 = "{(})";
        boolean expected_4 = false;
        boolean output_4 = isBalanced(s_4);
        check(expected_4, output_4);
    }

    public static void main(String[] args) {
        new Main().run();
    }
}