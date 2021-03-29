import java.io.*;
import java.util.*;

import static java.util.Arrays.copyOf;
// Add any extra import statements you may need here


class Main {

    // Add any helper functions you may need here
    int lastDivisiblePos(int targetMoney, int[] denominations) {
        int pos = -1;

        for (int i = denominations.length-1; i > -1; i--) {
            if (targetMoney >= denominations[i]) {
                pos = i;
                break;
            }
        }

        return pos;
    }

    int divisibleBy(int targetMoney, int[] denominations) {
        int pos = lastDivisiblePos(targetMoney, denominations);

        if (pos == -1) return -1;

        int mod = targetMoney % denominations[pos];

        if (mod == 0) {
            return 0;
        }

        if (pos == 0) return -1;

        return divisibleBy(mod, copyOf(denominations, pos));
    }

    boolean canGetExactChange(int targetMoney, int[] denominations) {
        // Write your code here
        Arrays.sort(denominations);
        return divisibleBy(targetMoney, denominations) == 0;
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
        System.out.print("[\"" + str + "\"]");
    }

    public void run() {
        int target_1 = 94;
        int arr_1[] = {5, 10, 25, 100, 200};
        boolean expected_1 = false;
        boolean output_1 = canGetExactChange(target_1, arr_1);
        check(expected_1, output_1);

        int target_2 = 75;
        int arr_2[] = {4, 17, 29};
        boolean expected_2 = true;
        boolean output_2 = canGetExactChange(target_2, arr_2);
        check(expected_2, output_2);

        // Add your own test cases here

    }

    public static void main(String[] args) {
        new Main().run();
    }
}