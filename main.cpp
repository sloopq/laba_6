#include <iostream>
#include <math.h>
using namespace std;


int Sum(int a, int b)
{
    return a+b;
}

double Sum(double a,double b)
{
    return a+b;
}

int Sum(int a, int b, int c)
{
    return a+b+c;
}
double Sum(double a, double b, double c)
{
    return a+b+c;
}


int mat(int x, int y, int arr[100][100])
{
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            cin >> arr[i][j];
            //sum += a[i][j];
        }


    }

}


bool sameColumns(int x, int y, int arr[100][100])
{
    int count;
    count = 0;
    for (int j = 0; j < y - 1; j++)
    {
        for (int k = 1; k < y; k++)
        {
            count = 0;
            for (int i = 0; i < x; i++)
            {
                if (arr[i][j] != arr[i][j + k])
                {
                    continue;
                }
                else
                {
                    count++;
                }
            }
            if (count == x)
            {
                return true;
            }
        }
    }
    return false;
}

bool isPrime(int x)
{
    x = abs(x);
    if (x < 2)
        return false;
    for (int d = 2; d <= sqrt(x); d++)
    {
        if (x%d==0)
            return false;

    }
    return true;
}
bool isPrimeInMat(int x, int y, int arr[100][100])
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (isPrime(arr[i][j]) == true)
            {
                return true;
            }
        }
    }
    return false;
}
void swapSort(int* mas, int n)  // Указатель
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (mas[i] > mas[j])
                swap(mas[i], mas[j]);
}

void sort_lines(int x, int y, int arr[100][100])
{
    int mas_sum_lines[100];
    int sum_line;
    sum_line = 0;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            sum_line += abs(arr[i][j]);
        }
        mas_sum_lines[i] = sum_line;
        sum_line = 0;
    }

    for (int i = 0; i < x-1; i++) // line number
    {
        for (int j = 1; j < x; j++) // +to line number
        {
            if (mas_sum_lines[i] > mas_sum_lines[i+j] && i+j < x)
            {
                for (int k = 0; k < y; k++)
                {
                    swap(arr[i][k], arr[i + j][k]);
                }
                swap(mas_sum_lines[i], mas_sum_lines[i+j]);
            }
        }
    }
}


    int main()
    {
        int n, m;
        int a[100][100];
        int num;
        //int sum;
        //int minsum = INT_MAX;
        //int bl0;
        cin >> m;
        cin >> n;

        mat(m, n, a);
        if (sameColumns(m,n,a) && isPrimeInMat(m,n,a))
        {
            sort_lines(m,n,a);
        }
        else{
            cout << "матрица не удовлетворяет необходимым условиям" << endl;
            return 0;
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
        }