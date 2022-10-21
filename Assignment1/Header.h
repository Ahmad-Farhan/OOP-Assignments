#pragma once
#include<iostream>
using namespace std;

void initializePoly(char Polybius[][5]);
void converter(char* Tapcode, char ch, int& index);
void check_position(char ch, int& row, int& col);
void generateTapCode(char* Tapcode, int& index, int row, int col);
void pos_correction(char* res, int size);
void rearrange(char* str, int i, int& size);

char* convertToTapCode(char* str)
{
    int index = 0;
    char* Tapcode = new char[100];

    for (int i = 0; *(str + i) != '\0'; i++)
        converter(Tapcode, *(str + i), index);

    *(Tapcode + index - 2) = '\0';

    return Tapcode;
}

void converter(char* Tapcode, char ch, int& index)
{
    int row, col;

    if (ch < 97)
        ch += 32;

    check_position(ch, row, col);
    generateTapCode(Tapcode, index, row, col);
}

void check_position(char ch, int& row, int& col)
{
    char Polybius[5][5];

    initializePoly(Polybius);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (Polybius[i][j] == ch)
            {
                row = i + 1;
                col = j + 1;
                return;
            }
        }
    }
}

void initializePoly(char Polybius[][5])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i > 1)
                Polybius[i][j] = 98 + i * 5 + j;

            else
                Polybius[i][j] = 97 + i * 5 + j;
        }
    }
}

void Taps(char* Tapcode, int times, int& index)
{
    times += index;
    while (index < times)
    {
        *(Tapcode + index) = '.';
        index++;
    }
    *(Tapcode + index) = ' ';
    index++;
}

void generateTapCode(char* Tapcode, int& index, int row, int col)
{
    Taps(Tapcode, row, index);
    Taps(Tapcode, col, index);
    *(Tapcode + index) = ' ';
    index++;
}

void check_indices(char* str, int& index, int& row, int& col)
{
    row = col = 0;
    while (*(str + index) != ' ' && *(str + index) != '\0')
    {
        row++;
        index++;
    }

    index++;

    while (*(str + index) != ' ' && *(str + index) != '\0')
    {
        col++;
        index++;
    }
    index += 2;
}

char GenerateString(char* str, int index, int row, int col)
{
    char Polybius[5][5];
    initializePoly(Polybius);
    return Polybius[row - 1][col - 1];
}

char* convertToString(char* str)
{
    int row, col, index = 0, res_index = 0;
    char* Stringcode = new char[100];

    while (*(str + index) != '\0')
    {
        check_indices(str, index, row, col);
        Stringcode[res_index] = GenerateString(str, index, row, col);
        res_index++;

        if (*(str + index - 2) == '\0')
            break;
    }
    *(Stringcode + res_index) = '\0';

    return Stringcode;
}

char Add_chars(char num1, char num2, int& carry)
{
    int result = (static_cast<int>(num1) - 48) + (static_cast<int>(num2) - 48) + carry;
    carry = 0;

    while (result > 10)
    {
        result %= 10;
        carry++;
    }

    return static_cast<char>(result + 48);
}

void digit_comp(char* res, char* num, int size, int carry, int s)
{
    *(res + s) = Add_chars(*(num + s), '0', carry);

    for (int i = s + 2; i < size; i++)
        *(res + i) = Add_chars(*(num + i), '0', carry);

    pos_correction(res, size);
}

void pos_correction(char* res, int size)
{
    for (int i = 0, j = size - 1; i < size / 2 && j >= 0; i++, j--)
    {
        char temp = *(res + i);
        *(res + i) = *(res + j);
        *(res + j) = temp;
    }

    *(res + size) = '\0';
}

char* additionOfBigInteger(char* Num1, char* Num2)
{
    char* result = new char[100];
    int s1, s2, carry = 0;

    for (s1 = 0; *(Num1 + s1) != '\0'; s1++);
    for (s2 = 0; *(Num2 + s2) != '\0'; s2++);

    for (int i = 0; i < s1 && i < s2; i++)
        *(result + i) = Add_chars(*(Num1 + s1 - i - 1), *(Num2 + s2 - i - 1), carry);

    if (s1 > s2)
        digit_comp(result, Num1, s1, carry, s2);

    else if (s2 > s1)
        digit_comp(result, Num2, s2, carry, s1);

    else if (s1 = s2)
    {
        *(result + s1 + 1) = carry;
        pos_correction(result, s1);
    }

    return result;
}

void check_borrow(char* num1, int s1, char* num2)
{
    for (int i = 1; i < s1; i++)
    {
        if (*(num1 + s1 - i) >= *(num2 + s1 - i))
            break;

        *(num1 + s1 - i) += 10;
        *(num1 + s1 - i - 1) -= 1;
    }
}

char* subtractionOfBigInteger(char* Num1, char* Num2)
{
    char* result = new char[100];
    int s1, s2;
    bool revNum = false;

    for (s1 = 0; *(Num1 + s1) != '\0'; s1++);
    for (s2 = 0; *(Num2 + s2) != '\0'; s2++);

    if (*Num1 < *Num2 && s1 == s2)
    {
        char* temp = Num1;
        Num1 = Num2;
        Num2 = temp;

        revNum = true;
        *(result + s1) = '-';
    }

    for (int i = 0; i < s1 && i < s2; i++)
    {

        check_borrow(Num1, s1 - i, Num2);
        *(result + i) = *(Num1 + s1 - i - 1) - *(Num2 + s2 - i - 1) + 48;
    }

    if (revNum)
        pos_correction(result, ++s1);
    else
        pos_correction(result, s1);
    return result;
}

char* multiplicationOfBigInteger(char* Num1, char* Num2)
{
    return Num1;
}

bool punctuation(char ch)
{
    if (ch != ' ' && ch < 65 || ch > 90 &&
        ch < 97 || ch > 122)
        return true;
    else
        return false;
}

void rearrange(char* str, int i, int& size)
{
    for (int j = i; j < size; j++)
        *(str + j) = *(str + j + 1);

    size--;
}

void removePunctuation(char* str)
{
    int size;
    for (size = 0; *(str + size) != '\0'; size++);

    for (int i = 0; i <= size; i++)
    {
        if (punctuation(*(str + i)))
        {
            rearrange(str, i, size);
            while (punctuation(*(str + i)) && *(str + i) != '\0')
                rearrange(str, i, size);
        }

        if (*(str + i) == ' ' && *(str + i + 1) == ' ')
            rearrange(str, i + 1, size);
    }
}

bool checkrepeat(char* str, int index, char ch)
{
    for (int i = index - 1; i >= 0; i--)
    {
        if (*(str + i) == ch)
            return false;
    }
    return true;
}

void countLetters(char* str, int*& array, int& size)
{
    int Arr[100];
    for (int i = 0; *(str + i) != '\0'; i++)
    {
        int count = 0;
        if ((checkrepeat(str, i, *(str + i))))
        {
            for (int j = i; *(str + j) != '\0'; j++)
            {
                if (*(str + i) == *(str + j))
                    count++;
            }
            *(Arr + size) = count;
            size++;
        }
    }
    array = Arr;
}

bool isprimeNumber(int n, int i)
{
    if (n == 2)
        return true;

    else if (n < 2)
        return false;

    else if (n % i == 0)
        return false;

    else if (i * i > n)
        return true;

    isprimeNumber(n, i + 1);
}

char findUppercase(char* str)
{
    cout << *str << endl;

    if (*str < 91 && *str > 64)
        return *str;

    else
        findUppercase(str + 1);
}

void sumval(int** array, int row, int column, int& evenSum, int& oddSum)
{
    if (column > 0)
    {
        sumval(array, row, column - 1, evenSum, oddSum);
    }

    if (array[row][column] % 2 == 0)
        evenSum += array[row][column];
    else
        oddSum += array[row][column];
}

int sum(int** array, int row, int column, int& evenSum, int& oddSum) {
    --row;
    if (row >= 0)
    {
        sum(array, row, column, evenSum, oddSum);
        sumval(array, row, column - 1, evenSum, oddSum);
    }
    return 0;
}

void printspace(int n)
{
    if (n > 0)
    {
        cout << "  ";
        printspace(n - 1);
    }
}

void printstar(int n)
{
    if (n > 0)
    {
        cout << "*";
        printstar(n - 1);
    }
}

void printspace1(int n)
{
    if (n > 0)
    {
        cout << " ";
        printspace1(n - 1);
    }
}

void printstar3(int n)
{
    if (n > 0)
    {
        cout << "* * ";
        printstar3(n - 1);
    }
}

void PrintPattern1(int start, int end)
{
    if (end / 2 > start)
    {
        printspace(start - 1);
        cout << " *" << endl;
        PrintPattern1(start + 1, end);
    }
    printspace(start - 1);
    cout << " *" << endl;
}

void PrintPattern2(int n1, int n2, int n3)
{
    if (n1 > 1)
    {
        printspace1(n1 - 1);
        printstar(n2);
        cout << endl;
        PrintPattern2(n1 - 1, n2 + 2, n3);
    }
    printspace1(n1 - 1);
    printstar(n2);
    cout << endl;
}

void PrintPattern3(int n1, int n2, int n3)
{

    if (n1 > 1)
    {
        printspace(n1);
        cout << "| ";
        printspace(n1 - 1);
        printstar3(n2 - 1);
        cout << "| ";
        printstar3(n2 - 1);
        printspace(n1 - 1);
        cout << "| " << endl;
        PrintPattern3(n1 - 1, n2 + 1, n3);
    }

    printspace(n1);
    cout << "| ";
    printspace(n1 - 1);
    printstar3(n2 - 1);
    cout << "| ";
    printstar3(n2 - 1);
    printspace(n1 - 1);
    cout << "| " << endl;
}