
#include "Matrix/matrix.hpp"

Matrix::Matrix(int n, int m)
{
    if (n > 1 || m > 1)
    {
        x = n;
        y = m;
        mat = new double *[n];
        for (int i = 0; i < n; ++i)
            mat[i] = new double[m];
    }
    else
        cout << "blad\n";

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
            mat[i][j] = 0;
    }
}

Matrix::Matrix(int n)
{
    if (n > 1)
    {
        y = n;
        x = n;
        mat = new double *[n];
        for (int i = 0; i < n; ++i)
            mat[i] = new double[n];
    }
    else
        cout << "blad\n";
    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
            mat[i][j] = 0;
    }
}

Matrix::Matrix(string filename, string path)
{
    ifstream plik(path);
    plik.open(filename);

    plik >> x >> y;

    mat = new double *[x];
    for (int i = 0; i < x; ++i)
        mat[i] = new double[y];

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
            plik >> mat[i][j];
    }
    plik.close();
}

int Matrix::cols()
{
    return x;
}

int Matrix::rows()
{
    return y;
}

double Matrix::get(int n, int m)
{
    if (n < x && m < y)
        return mat[n][m];
    else
    {
        cout << "Podana komurka nie istnieje w podanej macierzy\n";
        return 0.0;
    }
}

void Matrix::set(int n, int m, double val)
{
    if (n < x && m < y)
        mat[n][m] = val;
    else
        cout << "Podana komurka nie istnieje w podanej macierzy\n";
}

void Matrix::print()
{
    for (int i = 0; i < x; ++i)
    {
        cout << endl;
        for (int j = 0; j < y; ++j)
        {
            cout.width(8);
            cout << mat[i][j] << "  ";
        }
    }
}

Matrix Matrix::substract(Matrix &m2)
{
    if (x != m2.x && y != m2.y)
    {
        cout << "Nie da sie odjac macierzy, poniewaz nie sa one tej samej wielkosci!" << endl;
        return NULL;
    }
    else
    {
        Matrix temp(m2.x, m2.y);

        for (int i = 0; i < m2.x; ++i)
        {
            for (int j = 0; j < m2.y; ++j)
            {
                temp.mat[i][j] = m2.mat[i][j] - mat[i][j];
            }
        }

        return temp;
    }
}

Matrix Matrix::add(Matrix &m2)
{
    if (x != m2.x && y != m2.y)
    {
        cout << "Nie da sie dodac macierzy, poniewaz nie sa one tej samej wielkosci!" << endl;
        return NULL;
    }
    else
    {
        Matrix temp(m2.x, m2.y);

        for (int i = 0; i < m2.x; ++i)
        {
            for (int j = 0; j < m2.y; ++j)
            {
                temp.mat[i][j] = m2.mat[i][j] + mat[i][j];
            }
        }

        return temp;
    }
}

Matrix Matrix::multiply(Matrix &m2)
{
    if (x != m2.y)
    {
        cout << "Nie mozna pomnozyc macierzy, poniewaz liczba kolumn pierwszej nie jest rowna liczbie wierszy drugiej!" << endl;
        return NULL;
    }
    else
    {
        Matrix temp(y, m2.x);

        for (int i = 0; i < y; ++i)
        {
            for (int j = 0; j < m2.x; ++j)
            {
                temp.mat[i][j] = 0.0;

                for (int k = 0; k < x; ++k)
                    temp.mat[i][j] += mat[i][k] * m2.mat[k][j];
            }
        }
        return temp;
    }
}

void Matrix::CreateMatrix()
{
    for (int i = 0; i < x; ++i)
    {
        cout << endl;
        double temp_i = i;
        for (int j = 0; j < y; ++j)
        {
            double temp_j = j;
            mat[i][j] = ((temp_i + 1) * (temp_j + 4)) / 3;
        }
    }
}

void Matrix::store(string filename, string path)
{
    ofstream plik(path);
    plik.open(filename);

    if (plik.good() == false)
        cout << "Dostep do pliku zostal zabroniony!" << endl;

    plik << x << " " << y << endl;

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            plik << get(i, j) << " ";
        }
        plik << endl;
    }
    plik.close();
}