#include <bits/stdc++.h>
using namespace std;
class Matrix3D
{
private:
    double matrix[3][3];

public:
    Matrix3D()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                matrix[i][j] = 0.0;
            }
        }
    }

    ~Matrix3D() {}

    double getElement(int row, int col) const
    {
        return matrix[row][col];
    }
    void setElement(int row, int col, double value)
    {
        matrix[row][col] = value;
    }

    double det() const
    {
        return matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) -
               matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) +
               matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
    }

    Matrix3D inverse() const
    {
        Matrix3D result;
        double determinant = det();

        if (determinant == 0.0)
        {
            cout << "Matrix is singular.Inverse does not exist." << endl;
        }
        double invDet = 1.0 / determinant;

        result.setElement(0, 0, (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) * invDet);
        result.setElement(0, 1, (matrix[0][2] * matrix[2][1] - matrix[0][1] * matrix[2][2]) * invDet);
        result.setElement(0, 2, (matrix[0][1] * matrix[1][2] - matrix[0][2] * matrix[1][1]) * invDet);
        result.setElement(1, 0, (matrix[1][2] * matrix[2][0] - matrix[1][0] * matrix[2][2]) * invDet);
        result.setElement(1, 1, (matrix[0][0] * matrix[2][2] - matrix[0][2] * matrix[2][0]) * invDet);
        result.setElement(1, 2, (matrix[0][2] * matrix[1][0] - matrix[0][0] * matrix[1][2]) * invDet);
        result.setElement(2, 0, (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]) * invDet);
        result.setElement(2, 1, (matrix[0][1] * matrix[2][0] - matrix[0][0] * matrix[2][1]) * invDet);
        result.setElement(2, 2, (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]) * invDet);

        return result;
    }
    Matrix3D operator+(const Matrix3D &other) const
    {
        Matrix3D result;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                result.setElement(i, j, matrix[i][j] + other.getElement(i, j));
            }
        }
        return result;
    }

    Matrix3D operator-(const Matrix3D &other) const
    {
        Matrix3D result;

        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                result.setElement(i, j, matrix[i][j] - other.getElement(i, j));
            }
        }

        return result;
    }

    Matrix3D operator*(const Matrix3D &other) const
    {
        Matrix3D result;

        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                result.setElement(i, j,
                                  matrix[i][0] * other.getElement(0, j) +
                                      matrix[i][1] * other.getElement(1, j) +
                                      matrix[i][2] * other.getElement(2, j));
            }
        }

        return result;
    }

    void display() const
    {
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                cout << matrix[i][j] << " ";
            }
            cout << std::endl;
        }
    }
};
int main()
{
    Matrix3D mat1, mat2, mat3;

    Matrix3D result_add = mat2 + mat3;
    cout << "Matrix Addition Result:" << std::endl;
    result_add.display();

    Matrix3D result_sub = mat2 - mat3;
    cout << "Matrix Subtraction Result:" << std::endl;
    result_sub.display();

    Matrix3D result_mul = mat2 * mat3;
    cout << "Matrix Multiplication Result:" << std::endl;
    result_mul.display();

    return 0;
}