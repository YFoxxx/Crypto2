#include "my_func.h"

using namespace std;
using namespace boost::multiprecision;
int main()
{
    setlocale(LC_ALL, "Russian");
    char chr;
    vector<boost::multiprecision::cpp_int> asciiinput;
    vector<boost::multiprecision::cpp_int> asciiout;
    boost::multiprecision::cpp_int a, c;  
    if (checkK1() == false)
        generateFirstKey("key1.txt");
    bool bMenu = true;
    while (bMenu)
    {              
        cout << "***Выберите действие***\n";
        cout << "1 - зашифровать шифром RSA\n";
        cout << "2 - расшифровать шифр RSA\n";
        cout << "3 - о программе\n";
        cout << "4 - выбрать другое значение k1 (текущий k1="<< getK1()<<")\n";
        cout << (chr = _getch()) << endl;
        switch (chr)
        {
        case '1':
            convertToASCII(readFile("input.txt"), "ASCII.txt");
            asciiinput = getVector("ASCII.txt");
            a = getA(asciiinput);
            encrypt(a , "key1.txt", "encrypted.txt");
            break;
        case '2':
            c = getC("encrypted.txt");
            decrypt(c, "key1.txt", "decrypted.txt");
            ASCIIfromA(getAfromDec("decrypted.txt") , "reASCII2.txt", asciiinput);
            break;                                                                                                       
        case '3':
            cout << "Выполнил Семенов Алексей БИ-31\nЛабораторная работа 2. Асимметричное шифрование. Шифр RSA\n\n\n";
            break;
        case '4':
            generateFirstKey("key1.txt");
            break;
        default:
            cout << "Unsupported key is pressed\n";
            break;
        }
        cout << "Нажмите 0 для продолжения работы\n";
        cout << "Для выхода нажмите любую другую кнопку\n";
        cout << (chr = _getch()) << endl;
        if (chr != '0')
            bMenu = false;
        system("cls");
    }
}





