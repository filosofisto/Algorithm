import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class TreeTest {

    @Test
    public void tree() {
        Node root = new Node(5);
        Node left = new Node(2);
        Node right = new Node(1);
        root.left = left;
        root.right = right;

        int[] expected = new int[] { 5, 1 };
        Integer[] result = new TreeUtil().minimumByLevel(root).toArray(new Integer[0]);
        assertEquals(expected.length, result.length);

        for (int i = 0; i < expected.length; i++) {
            assertEquals(expected[i], result[i]);
        }
    }
}
