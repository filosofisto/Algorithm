// Given a binary tree structure, compute the minimum value on each level.
//
//
//
//          5                 [5, 1]
//        /   \
//       2     1

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class TreeUtil {

    // [5, 1]
    //private int level = 0;
    private int min = Integer.MAX_VALUE;
    private Map<Integer, Integer> map = new HashMap<>();

    void min(Node node, int level) {
        if (node == null) return;

        Integer minValue = map.get(level);

        if (minValue == null || node.val < minValue) {
            map.put(level, node.val);
        }

        min(node.left, level+1);
        min(node.right, level+1);
    }

    public List<Integer> minimumByLevel(Node root) {
        List<Integer> ret = new ArrayList<>();

        min(root, 1);

        map.keySet().stream().sorted().forEach(item -> ret.add(map.get(item)));

        return ret;
    }

}
