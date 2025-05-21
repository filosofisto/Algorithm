# Topographic Map

Given a topographic map represented by an m x n integer matrix. Each entry represents the elevation at that point. 
A traveler plans to move from (0, 0) to (m - 1, n - 1). The traveler can move up/down and left/right. 
For a path, the elevation is defined to be the maximum elevation of all points on that path.
What is the minimum of path elevation among all the paths the traveler can take?
  
Return an integer. The path that achieves the minimum elevation does not matter and is not unique.
  
1 3 4 1
3 1 5 2
  
m = 1, n = 3

Answer is 4, because path 1-3-4-1-2 => 4
Others paths: 1-3-5-2 => 5
4 < 5, so 4 is the answer


