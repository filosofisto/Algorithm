#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

constexpr int dr[4] = {-1, 1, 0, 0}; // row change
constexpr int dc[4] = {0, 0, -1, 1}; // col change

void dfs(
	const vector<vector<int>>& matrix, 
	int r, 
	int c, 
	int targetR, 
	int targetC, 
	vector<pair<int, int>>& path, 
	vector<vector<bool>>& visited,
	vector<vector<pair<int, int>>>& listOfPaths) 
{
	if (r == targetR && c == targetC) {
		listOfPaths.push_back(path);

		// print current path
		for (auto [pr, pc] : path) {
			cout << "(" << pr << ", " << pc << ")[" << matrix[pr][pc] << "] ";
		}
		cout << "\b\n";
	}

	for (int d = 0; d < 4; ++d) {
		int nr = r + dr[d];
		int nc = c + dc[d];

		// Check bounds and if already visited
		if (nr >= 0 && nr < matrix.size() && nc >= 0 && nc < matrix[0].size() && !visited[nr][nc]) {
			visited[nr][nc] = true;
			path.emplace_back(nr, nc);
			dfs(matrix, nr, nc, targetR, targetC, path, visited, listOfPaths);
			path.pop_back();
			visited[nr][nc] = false;
		}
	}
}

int minElevation(
	const vector<vector<int>>& matrix, 
	const vector<vector<pair<int, int>>>& listOfPaths)
{
	vector<int> maxByPath{};

	for (const auto& path : listOfPaths) {
		int max = numeric_limits<int>::min();

		for (auto [pr, pc] : path) {
			if (matrix[pr][pc] > max) {
				max = matrix[pr][pc];
			}
		}

		maxByPath.push_back(max);
	}

	return *min_element(maxByPath.begin(), maxByPath.end());	
}

int main()
{
	vector<vector<int>> matrix = {
		{1, 3, 4, 1},
		{3, 1, 5, 2}
	};
	vector<pair<int, int>> path = {{0, 0}};
	vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size(), false));
	visited[0][0] = true;
	vector<vector<pair<int, int>>> listOfPaths{};

	dfs(matrix, 0, 0, 1, 3, path, visited, listOfPaths);

	cout << minElevation(matrix, listOfPaths) << endl;

	return EXIT_SUCCESS;
}
