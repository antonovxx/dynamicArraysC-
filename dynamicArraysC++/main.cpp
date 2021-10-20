//1. Печать массива на экран
//2. Сумма элементов массива
//3. Произведение элементов массива
//4. Поиск минимума в массиве
//5. Поиск максимума в массиве
//6. Среднее арифметическое элементов массива
//7. Поиск индекса элемента в массиве
//8. Наличие элемента в массиве
//9. Сортировка пузырьком, используя видео https://www.youtube.com/watch?v=lyZQPjUT5B4
//10. Сортировка простым выбором, используя видео https://www.youtube.com/watch?v=Ns4TPTC8whw
//11. Сортировка простыми вставками, используя видео https://www.youtube.com/watch?v=ROalU379l3U
//12. Вставка в массив
//13. Удаление из массива
//Все функции необходимо проверить внутри функции main, создавая и заполняя динамические массивы как с помощью new,
// так и с помощью malloc для вызова каждой функции. Так же необходимо корректно очищать память для всех созданных массивов.

#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;
void FulFillArray(int *array, int size)
{
    for (int i = 0; i < size; ++i)
    {
        array[i] = rand() % (100 - 1) + 1;
    }

}
void PrintArray(int *array, int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << array[i] << " ";
    }
}
int Sum(int *array, int size)
{
    int summ = 0;
    for (int i = 0; i < size; ++i)
    {
        summ += array[i];
    }
    return summ;
}
unsigned long long Multiplication(int *array, int size)
{
    unsigned long long mul = 1;
    for (int i = 0; i < size; ++i)
    {
        mul *= array[i];
    }
    return mul;
}
int MinElement(int *array, int size)
{
    int Min = array[0];
    for (int i = 0; i < size; ++i)
    {
        if (Min > array[i])
            Min = array[i];
    }
    return Min;
}
int MaxElement(int *array, int size)
{
    int Max = array[0];
    for (int i = 0; i < size; ++i)
    {
        if(Max < array[i])
            Max = array[i];
    }
    return Max;
}
int AverageValue(int *array, int size)
{
    int count = 0;
    int sum = 0;
    int result = 0;
    for (int i = 0; i < size; ++i)
    {
        sum += array[i];
        count ++;
    }
    return result = sum/count;
}
bool SearchElement(int *array, int size, int number)
{
    bool result;

    for (int i = 0; i < size; ++i)
        {
            if (number == *(array + i))
            {
                result = true;
                break;
            }
            else if (number != *(array + i))
            {
                result = false;
                break;
            }
        }
    return result;
}
int CountEntries(int *array, int size, int number){
    int count = 0;
    for (int i = 0; i < size; ++i) {
        {
            if(number == array[i])
                ++count;
        }
    }
    return count;
}
void BubbleSort(int *array, int size)
{
    bool flag;
    for (int i = 0; i < size; ++i)
    {
        flag = false;
        for (int j = 0; j < size - i - 1; ++j)
        {
            if(array[j] > array[j + 1])
            {
                swap(array[j], array[j + 1]);
                flag = true;
            }
        }
        if(!flag) break;
    }
}
void SelectSort(int *array, int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        int MinIndex = i;
        for (int j = i + 1; j < size; ++j)
        {
            if (array[j] < array[MinIndex])
                MinIndex = j;
        }
        swap(array[i], array[MinIndex]);
    }
}
void InsertSort(int *array, int size)
{
    for (int i = 1; i < size; ++i)
    {
        int tmp = array[i];
        int j = i - 1;
        while(j >= 0 && array[j] > tmp)
        {
            array[j + 1] = array[j];
            array[j] = tmp;
            j--;
        }
    }
}
void push_back(int *&array, int &size, int value)
{
    int *newArray = new int[size + 1];
    for (int i = 0; i < size; ++i)
    {
        newArray[i] = array[i];
    }
    newArray[size] = value;
    size++;
    delete[] array;
    array = newArray;
}
void pop_back(int *&array, int &size)
{
    size--;
    int *newArray = new int [size];
    for (int i = 0; i < size; ++i)
    {
        newArray[i] = array[i];
    }
    delete[] array;
    array = newArray;
}

int main()
{

//    srand(time(NULL)); // it allows us to generate the same numbers in the array for checking the value out.

    int size = 0;

    cout << "Enter the range of the dynamic array: " << endl;
    cin >> size;
    int *array = new int[size];

    FulFillArray(array, size);

    cout << endl;

    cout << "Dynamic array with generated numbers: " << endl;
    PrintArray(array, size);

    cout << endl;

    cout << "Sum of all elements of the array: " << Sum(array, size) << endl;
    cout << "Multiplication of all elements of the array: " << Multiplication(array, size) << endl;
    cout << "Minimal element of the array: " << MinElement(array, size) << endl;
    cout << "Maximal element of the array: " << MaxElement(array, size) << endl;
    cout << "Average value of the array: " << AverageValue(array, size) << endl;

    cout << endl;

    cout << "Enter the number that you want to find in the array.\n"
         << "(If there is the number here, Clion will output 1, if there is not one in the array, Clion will output 0.) \n" << endl;
    int number;
    cin >> number;

    cout << endl;

    cout << "Result of the searching inputted element: " << SearchElement(array, size, number) << endl;
    cout << "Count of entries of this number: " << CountEntries(array, size, number) << endl;

    cout << endl;
//    BubbleSort(array, size);
//    cout << "Bubble sort: " << endl;
//    PrintArray(array, size);

//    SelectSort(array, size);
//    cout << "Select sort: " << endl;
//    PrintArray(array, size);

//    InsertSort(array, size);
//    cout << "Insert sort: " << endl;
//    PrintArray(array, size);

    cout << "Insert element into the array: " << endl;
    push_back(array, size, 10);

    PrintArray(array, size);
    cout << endl;


    cout << "Delete element from the array: " << endl;
    pop_back(array, size);

    PrintArray(array, size);

    delete [] array;
    return 0;
}
