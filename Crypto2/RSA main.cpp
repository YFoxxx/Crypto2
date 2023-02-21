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
    generateFirstKey("key1.txt");   
    asciiinput = getVector("ASCII.txt");
    convertToASCII(readFile("input.txt"), "ASCII.txt");
    a = getA(asciiinput);
    bool bMenu = true;
    while (bMenu)
    {              
        cout << "***�������� ��������***\n";
        cout << "1 - ����������� ������ RSA\n";
        cout << "2 - ������������ ���� RSA\n";
        cout << "3 - � ���������\n";
        cout << (chr = _getch()) << endl;
        switch (chr)
        {
        case '1':    
            encrypt(a , "key1.txt", "encrypted.txt");
            break;
        case '2':
       
            c = getC("encrypted.txt");
            decrypt(c, "key1.txt", "decrypted.txt");
            ASCIIfromA(getAfromDec("decrypted.txt") , "reASCII2.txt", asciiinput);
            break;                                                                                                       
        case '3':
            cout << "�������� ������� ������� ��-31\n������������ ������ 2. ������������� ����������. ���� RSA\n\n\n";
            break;
        default:
            cout << "Unsupported key is pressed\n";
            break;
        }
        cout << "������� 0 ��� ����������� ������\n";
        cout << "��� ������ ������� ����� ������ ������\n";
        cout << (chr = _getch()) << endl;
        if (chr != '0')
            bMenu = false;
        system("cls");
    }
}





