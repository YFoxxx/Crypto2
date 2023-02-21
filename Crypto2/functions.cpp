#include "my_func.h"
using namespace std;
using namespace boost::multiprecision;


void convertToASCII(string s, string fileOutput)
{
    ofstream outFile(fileOutput.c_str());
    if (!outFile.is_open())
        return;
    for (int i = 0; i < s.length(); i++)
    {
        outFile << setw(3);
        outFile << setfill('0');
        outFile << (int)s[i] << " ";
    }
    outFile.close();
}

std::string readFile(string fileInput) 
{
    ifstream file(fileInput.c_str());
    file.seekg(0, ios::end);
    size_t size = file.tellg();
    string s(size, ' ');
    file.seekg(0);
    file.read(&s[0], size);
    return s;
    file.close();
}

std::vector<boost::multiprecision::cpp_int> getVector(std::string inputFile)
{
    vector<boost::multiprecision::cpp_int>vec;
    ifstream file(inputFile.c_str());
    if (file)
    {
        int n;
        while (file >> n)
            vec.push_back(n);
    }
    else
        cout << "Error opening file!" << endl;
    return vec;
}

boost::multiprecision::cpp_int getA(std::vector<boost::multiprecision::cpp_int>vec)
{
    boost::multiprecision::cpp_int a=0;
    boost::multiprecision::cpp_int b = 256;
    boost::multiprecision::cpp_int c = 0;
    vector<boost::multiprecision::cpp_int>res;
    int j = vec.size() - 1;
    for (int k = 0; k < vec.size(); k++)
    {
        c = pow(b, j);
        res.push_back(vec[k]*c);
        j--;

    }
    for (auto& n : res)
        a += n;
    return a;
}

void ASCIIfromA(boost::multiprecision::cpp_int a, std::string fileOut, std::vector<boost::multiprecision::cpp_int>vec)
{
    ofstream outFile(fileOut.c_str());
    int vectorLenght = vec.size();
    boost::multiprecision::cpp_int _pow = 0;
    boost::multiprecision::cpp_int c = 0;
    boost::multiprecision::cpp_int d = 0;
    vector<boost::multiprecision::cpp_int>res;
    int j = vec.size() - 1;
    for (int k = 0; k < vec.size(); k++)
    {
        _pow = boost::multiprecision::pow(boost::multiprecision::cpp_int(256), j);
        c = (a / _pow)%256;
        res.push_back(c);
        j--;

    }
    for (int k = 0; k < res.size(); k++)
    {
        outFile << (char)res[k];
    }
    outFile.close();
}

void generateFirstKey(std::string fileKey)
{
    boost::multiprecision::cpp_int p1{"13508144197848661939"};
    boost::multiprecision::cpp_int p2{ "10255132451835681187"};
    boost::multiprecision::cpp_int N, N1;
    int k1 = 53;
    N = p1 * p2;
    //N1 = (p1 - 1) * (p2 - 1);
    boost::filesystem::path p(fileKey.c_str());
    boost::filesystem::ofstream file(p) ;
    file << N << " " << k1;
    file.close();
}

void generateSecondKey(std::string fileKey)
{
    boost::multiprecision::cpp_int p1{ "13508144197848661939" };
    boost::multiprecision::cpp_int p2{ "10255132451835681187" };
    boost::multiprecision::cpp_int N, N1;
    int k2;
    int k1 = 53;
    N = p1 * p2;
    //N1 = (p1 - 1) * (p2 - 1);
    boost::filesystem::path p(fileKey.c_str());
    boost::filesystem::ofstream file(p);
    file << N << " " << k1;
    file.close();
}

void encrypt(boost::multiprecision::cpp_int a, std::string fileKey, std::string fileOut)
{
    boost::multiprecision::cpp_int N, c;
    boost::multiprecision::cpp_int k1;
    boost::filesystem::path p(fileKey.c_str());
    boost::filesystem::ifstream file(p);
    boost::filesystem::path g(fileOut.c_str());
    boost::filesystem::ofstream out(g);
    file >> N;
    file >> k1;
    c = modexp(a, k1, N);
    out << c;
    file.close();
    out.close();
}

boost::multiprecision::cpp_int modexp(boost::multiprecision::cpp_int x, boost::multiprecision::cpp_int y, boost::multiprecision::cpp_int N)
{
    if (y == 0) return 1;
    boost::multiprecision::cpp_int z = modexp(x, y / 2, N);
    if (y % 2 == 0)
        return (z * z) % N;
    else
        return (x * z * z) % N;
}

void decrypt(boost::multiprecision::cpp_int c, std::string fileKey, std::string fileOut)
{
    boost::multiprecision::cpp_int p1{ "13508144197848661939" };
    boost::multiprecision::cpp_int p2{ "10255132451835681187" };
    boost::multiprecision::cpp_int a, k2, N1, N, k1;
    boost::filesystem::path p(fileKey.c_str());
    boost::filesystem::ifstream file(p);
    boost::filesystem::path g(fileOut.c_str());
    boost::filesystem::ofstream out(g);
    file >> N;
    file >> k1;
    N1 = (p1 - 1) * (p2 - 1);
    k2 = reverse(k1, N1);
    a = modexp(c, k2, N);
    out << a;
    file.close();
    out.close();
}

boost::multiprecision::cpp_int getC(std::string fileC)
{
    boost::multiprecision::cpp_int c;
    boost::filesystem::path p(fileC.c_str());
    boost::filesystem::ifstream file(p);
    file >> c;
    return c;
}

boost::multiprecision::cpp_int reverse(boost::multiprecision::cpp_int a, boost::multiprecision::cpp_int b)
{
    boost::multiprecision::cpp_int p1{ "13508144197848661939" };
    boost::multiprecision::cpp_int p2{ "10255132451835681187" };
    boost::multiprecision::cpp_int a1, b1, A, c, t3, v, N1;
    N1 = (p1 - 1) * (p2 - 1);
    if (a > b)
    {
        a1 = a;
        b1 = b;
    }
    else 
    {
        a1 = b;
        b1 = a;
    }
    A = a1;
    boost::multiprecision::cpp_int r = 1;
    boost::multiprecision::cpp_int t1 = 0;
    boost::multiprecision::cpp_int t2 = 1;
    while (r != 0)
    {
        r = a1 % b1;
        c = a1 / b1;
        t3 = t1 - c * t2;
        a1 = b1;
        b1 = r;
        t1 = t2;
        t2 = t3;
    }
    v = (t1 + A) % A;
    return v;    
}

boost::multiprecision::cpp_int getAfromDec(std::string fileA)
{
    boost::multiprecision::cpp_int a;
    boost::filesystem::path p(fileA.c_str());
    boost::filesystem::ifstream file(p);
    file >> a;
    return a;
}

boost::multiprecision::cpp_int gcd(boost::multiprecision::cpp_int n1, boost::multiprecision::cpp_int n2) 
{
    return (n2 == 0) ? n1 : gcd(n2, n1 % n2);
}

std::vector<boost::multiprecision::cpp_int> EilerVector(boost::multiprecision::cpp_int a)
{
    vector<boost::multiprecision::cpp_int> eVec;
    boost::multiprecision::cpp_int n = 7654;
    int i = 0;
    while (true)
    {
        if (gcd(n, a) == 1)
        {
            eVec.push_back(n);
            i++;
        }
        n++;
        if (eVec.size() > 10)
            break;
    }
    return eVec;
}