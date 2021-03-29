import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
// Add any extra import statements you may need here


class Main {

    // Add any helper functions you may need here
    static class MapCharacterCount {

        Map<Character, Integer> _map = new HashMap<>();
        String s;

        MapCharacterCount(String s) {
            this.s = s;
        }

        int count(char ch) {
            if (!_map.containsKey(ch)) {
                int count = 0;

                for (int i = 0; i < s.length(); i++) {
                    if (s.charAt(i) == ch) count++;
                }

                _map.put(ch, count);

                return count;
            }

            return _map.get(ch);
        }
    }

    int minLengthSubstring(String s, String t) {
        // Write your code here
        char[] ta = t.toCharArray();

        int minPos = Integer.MAX_VALUE;
        int maxPos = Integer.MIN_VALUE;

        int currPos;

        MapCharacterCount counterS = new MapCharacterCount(s);
        MapCharacterCount counterT = new MapCharacterCount(t);

        for (int i = 0; i < ta.length; i++) {
            currPos = s.indexOf(ta[i]);

            if (currPos < 0) {
                return -1;
            }

            if (counterS.count(ta[i]) != counterT.count(ta[i])) {
                return -1;
            }

            if (currPos < minPos) {
                minPos = currPos;
            }
            if (currPos > maxPos) {
                maxPos = currPos;
            }
        }

        String substring = s.substring(minPos, maxPos+1);
        return substring.length();
    }











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
    public void run() throws IOException {
        String s_1 = "dcbefebce";
        String t_1 = "fd";
        int expected_1 = 5;
        int output_1 = minLengthSubstring(s_1, t_1);
        check(expected_1, output_1);

        String s_2 = "bfbeadbcbcbfeaaeefcddcccbbbfaaafdbebedddf";
        String t_2 = "cbccfafebccdccebdd";
        int expected_2 = -1;
        int output_2 = minLengthSubstring(s_2, t_2);
        check(expected_2, output_2);

        // Add your own test cases here

    }
    public static void main(String[] args) throws IOException {
        new Main().run();
    }
}