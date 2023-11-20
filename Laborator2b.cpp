#include <iostream>
#include <cstring>
using namespace std;
class Matrix
{
public:
    char* Tab[50][50];
    int line;
    int column;
public:
    Matrix();
    Matrix(int);
    Matrix(int, int);
    Matrix(const Matrix&);
    ~Matrix();
    void f_set_matr();
    void f_show();
    void f_addition(const Matrix &matrix);
    void f_subtract(const Matrix &matrix);
    void f_multipl_matrix(const Matrix &matrix);
    void f_multipl_num(char* value);
};
int g_size;

Matrix::Matrix() : line(0), column(0) {}
Matrix::Matrix(int line, int column) : line(line), column(column)
{
    int i, j;
    if ((line >= 0) && (column >= 0))
    {
        for (i = 0; i < line; i++)
            for (j = 0; j < column; j++)
                Tab[i][j] = new char[100]; // Alocare spațiu pentru fiecare element
    }
    else
        cout << "Error. Matrix are not positive !!" << endl;
}
Matrix::Matrix(const Matrix& Tab2) : line(Tab2.line), column(Tab2.column)
{
    int i, j;
    for (i = 0; i < line; i++)
        for (j = 0; j < column; j++)
        {
            Tab[i][j] = new char[100];
            strcpy(Tab[i][j], Tab2.Tab[i][j]); // Copierea conținutului
        }
}

Matrix::~Matrix()
{
    int i, j;

    for (i = 0; i < line; i++)
        for (j = 0; j < column; j++)
            delete[] Tab[i][j]; // Eliberarea fiecărui element
    line = 0;
    column = 0;
}

void Matrix::f_set_matr()
{
    int i, j;
    for (i = 0; i < line; i++)
        for (j = 0; j < column; j++)
        {
            cout << " Matrix[" << i << "][" << j << "] = ";
            char temp[100];
            cin >> temp;
            Tab[i][j] = new char[strlen(temp) + 1];
            strcpy(Tab[i][j], temp);
        }
}

void Matrix::f_show()
{
    int i, j;

    for (i = 0; i < line; i++)
    {
        for (j = 0; j < column; j++)
            cout << "\t" << Tab[i][j] << "\t";
        cout << endl;
    }
}

void Matrix::f_addition(const Matrix &matrix)
{
    int i, j;

    if ((line == matrix.line) && (column == matrix.column))
    {
        for (i = 0; i < line; i++)
            for (j = 0; j < column; j++)
            {
                strcat(Tab[i][j], matrix.Tab[i][j]); // Concatenare șiruri de caractere
            }
    }
    else
        cout << "The dimensions do not match !!" << endl;
}

void Matrix::f_subtract(const Matrix &matrix)
{
    // Nu are sens să faci scăderea pentru șiruri de caractere
    cout << "Subtraction operation is not defined for strings." << endl;
}

void Matrix::f_multipl_matrix(const Matrix &matrix)
{
    // Nu are sens să înmulțești matrici de șiruri de caractere
    cout << "Matrix multiplication operation is not defined for strings." << endl;
}

void Matrix::f_multipl_num(char* value)
{
    int i, j;

    for (i = 0; i < line; i++)
        for (j = 0; j < column; j++)
        {
            strcat(Tab[i][j], value); // Concatenare cu șirul dat
        }
}

void f_menu()
{
    Matrix m1, m2;
    char value[100];

    cout << "\tInput first matrix !!\n" << endl;
    cout << "**Lines =   ";
    cin >> m1.line;
    cout << "**Columns =  ";
    cin >> m1.column;
    Matrix matrix1(m1.line, m1.column);
    matrix1.f_set_matr();
    system("pause");
    system("cls");

    cout << "\tInput second matrix !!\n" << endl;
    cout << "**Lines =   ";
    cin >> m2.line;
    cout << "**Columns =  ";
    cin >> m2.column;
    Matrix matrix2(m2.line, m2.column);
    matrix2.f_set_matr();
    system("pause");
    system("cls");

    cout << "***First Matrix:" << endl;
    matrix1.f_show();
    cout << "\n***Second Matrix:" << endl;
    matrix2.f_show();

    Matrix matrix3 = matrix1;

    cout << "\n***Matrix addition:" << endl;
    matrix1.f_addition(matrix2);
    matrix1.f_show();

    cout << "\n***Multiply first matrix with string" << endl;
    cout << "**Input string >>>   ";
    cin >> value;
    cout << endl;
    matrix3.f_multipl_num(value);
    matrix3.f_show();

    system("pause");
    exit(0);
}

int main()
{
    f_menu();
    return (0);
}
