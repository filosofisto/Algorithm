import java.io.*;
import java.util.*;
// Add any extra import statements you may need here


class MatchingPairs {

    // Add any helper functions you may need here
    int numberMatch(char[] sa, char[] ta) {
        int matches = 0;

        for (int i = 0; i < sa.length; i++) {
            if (sa[i] == ta[i]) {
                matches++;
            }
        }

        return matches;
    }

    void swap(char[] arr, int a, int b) {
        char tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;
    }

    int matchingPairs(String s, String t) {
        // Write your code here
        int max = 0;
        char[] sa = s.toCharArray();
        char[] ta = t.toCharArray();

        for (int i = 0; i < s.length(); i++) {
            for (int j = i+1; j < s.length(); j++) {
                swap(sa, i, j);
                int matches = numberMatch(sa, ta);
                if (max < matches) {
                    max = matches;
                }
                swap(sa, j, i);
            }
        }

        return max;
    }

//    int matchingPairs(String s, String t) {
//        // Write your code here
//        int max = 0;
//        char[] sa = s.toCharArray();
//        char[] ta = t.toCharArray();
//
//        for (int i = 0; i < s.length(); i++) {
//            for (int j = i+1; j < s.length(); j++) {
//                char[] clone = sa.clone();
//
//                swap(clone, i, j);
//                int matches = numberMatch(clone, ta);
//                if (max < matches) {
//                    max = matches;
//                }
//            }
//        }
//
//        return max;
//    }











    // These are the tests we use to determine if the solution is correct.
    // You can add your own at the bottom, but they are otherwise not editable!
    int test_case_number = 1;
    void check(int expected, int output) {
        boolean result = (expected == output);
        char rightTick = '\u2713';
        char wrongTick = '\u2717';
        if (result) {
            System.out.println(rightTick + " Test #" + test_case_number);
        }
        else {
            System.out.print(wrongTick + " Test #" + test_case_number + ": Expected ");
            printInteger(expected);
            System.out.print(" Your output: ");
            printInteger(output);
            System.out.println();
        }
        test_case_number++;
    }
    void printInteger(int n) {
        System.out.print("[" + n + "]");
    }
    public void run() {
        String s_1 = "abcde";
        String t_1 = "adcbe";
        int expected_1 = 5;
        int output_1 = matchingPairs(s_1, t_1);
        check(expected_1, output_1);

        String s_2 = "abcd";
        String t_2 = "abcd";
        int expected_2 = 2;
        int output_2 = matchingPairs(s_2, t_2);
        check(expected_2, output_2);

        // Add your own test cases here

    }
    public static void main(String[] args) {
        new MatchingPairs().run();
    }
}