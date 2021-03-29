import java.io.*;
import java.util.*;
// Add any extra import statements you may need here


class Main {

    // Add any helper functions you may need here


    int[] findSignatureCounts(int[] arr) {
        // Write your code here
        int[] output = new int[arr.length];
        Arrays.fill(output, 0);

        for (int i = arr.length-1; i > -1; i--) {
            // Pass 1:

            // Student 1 signs their own yearbook
            output[i]++;

            // Then they pass the book to the student at arr[i-1], which is Student 2

            // Student 2 signs their own yearbook
            output[i-1]++;

            // Then they pass the book to the student at arr[i], which is Student 1




            output[i-1]++;
            output[i]++;
        }













        // My assumption here is process each student in numeric order: 1, 2, ..., n
        // I am not sure if this assumption is correct!?
        for (int i = 0; i < arr.length; i++) {
            int posFirstStudent = -1;
            int studentIndex = i+1;

            // find position into arr of the current student
            for (int j = 0; j < arr.length; j++) {
                if (arr[j] == studentIndex) {
                    posFirstStudent = j;
                    break;
                }
            }

            // Step 1:
            // Student 1 signs their own yearbook
            output[posFirstStudent]++;

            // Then they pass the book to the student at arr[0] (at left I suppose), which is Student 2
            // find student 2
            int posSecondStudent = arr[posFirstStudent-1];

            // Student 2 signs their own yearbook
            output[posSecondStudent]++;

            // Then they pass the book to the student at arr[1], which is Student 1

            // if it is not me
            if (posSecondStudent != posFirstStudent) {
                // other student sign my yearbook
                output[posFirstStudent]++;
            }
        }

        return output;
    }












    // These are the tests we use to determine if the solution is correct.
    // You can add your own at the bottom, but they are otherwise not editable!
    int test_case_number = 1;
    void check(int[] expected, int[] output) {
        int expected_size = expected.length;
        int output_size = output.length;
        boolean result = true;
        if (expected_size != output_size) {
            result = false;
        }
        for (int i = 0; i < Math.min(expected_size, output_size); i++) {
            result &= (output[i] == expected[i]);
        }
        char rightTick = '\u2713';
        char wrongTick = '\u2717';
        if (result) {
            System.out.println(rightTick + " Test #" + test_case_number);
        }
        else {
            System.out.print(wrongTick + " Test #" + test_case_number + ": Expected ");
            printIntegerArray(expected);
            System.out.print(" Your output: ");
            printIntegerArray(output);
            System.out.println();
        }
        test_case_number++;
    }
    void printIntegerArray(int[] arr) {
        int len = arr.length;
        System.out.print("[");
        for(int i = 0; i < len; i++) {
            if (i != 0) {
                System.out.print(", ");
            }
            System.out.print(arr[i]);
        }
        System.out.print("]");
    }

    public void run() {
        int[] arr_1 = {2, 1};
        int[] expected_1 = {2, 2};
        int[] output_1 = findSignatureCounts(arr_1);
        check(expected_1, output_1);

        int[] arr_2 = {1, 2};
        int[] expected_2 = {1, 1};
        int[] output_2 = findSignatureCounts(arr_2);
        check(expected_2, output_2);

        // Add your own test cases here

    }

    public static void main(String[] args) throws IOException {
        new Main().run();
    }
}