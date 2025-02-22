#include <array>

using std::array;

template <typename T, size_t N>
class Matrix
{
public: 

	Matrix() 
	{
  	for (size_t i = 0; i < N; ++i) {
    	for (size_t j = 0; j < N; ++j) {
      	data[i][j] = T{}; // Initialize with default value of T (e.g., 0 for int)
      }
    }
  }

	Matrix(const array<array<T, N>, N>& data) : data(data) 
	{ 

	}

	~Matrix() = default;

	T& operator()(size_t row, size_t col) 
	{
		return data[row][col];
	}

	const T& operator()(size_t row, size_t col) const 
	{
		return data[row][col];
	}

	Matrix<T, N> operator+(const Matrix<T, N>& other) const 
	{
		Matrix<T, N> result;

		for (size_t i = 0; i < N; ++i) {
			for (size_t j = 0; j < N; ++j) {
				result(i,j) = data[i][j] + other(i,j);
			}
		}

		return result;
	}

	Matrix<T, N> operator-(const Matrix<T, N>& other) const 
	{
		Matrix<T, N> result;

		for (size_t i = 0; i < N; ++i) {
			for (size_t j = 0; j < N; ++j) {
				result(i,j) = data[i][j] - other(i,j);
			}
		}

		return result;
	}

	Matrix<T, N> operator*(const Matrix<T, N>& other) const 
	{
		Matrix<T, N> result;

		for (size_t i = 0; i < N; ++i) {
			for (size_t j = 0; j < N; ++j) {
				result(i,j) = 0;
				for (size_t k = 0; k < N; ++k) {
					result(i,j) += data[i][k] * other(k,j);
				}
			}
		}

		return result;
	}

	bool operator==(const Matrix<T, N>& other) const
	{
		for (size_t i = 0; i < N; ++i) {
			for (size_t j = 0; j < N; ++j) {
				if (data[i][j] != other(i,j)) {
					return false;
				}
			}
		}

		return true;
	}
	
private:

	array<array<T, N>, N> data;	
};


