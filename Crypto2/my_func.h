#ifndef MY_FUNC_H
#define MY_FUNC_H

#include <iostream>
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <iomanip>
#include <boost/multiprecision/cpp_int.hpp>
#include <string>
#include <conio.h>
#include <random>
#include <time.h>
#include <array>
#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
#include <vector>
#include <locale>
#include <fstream>
#include <streambuf>

std::string readFile(std::string fileInput);
std::vector<boost::multiprecision::cpp_int> getVector(std::string inputFile);
std::vector<boost::multiprecision::cpp_int> EilerVector(boost::multiprecision::cpp_int a);
bool checkK1();
void convertToASCII(std::string s, std::string fileOutput);
void ASCIIfromA(boost::multiprecision::cpp_int a, std::string fileOut, std::vector<boost::multiprecision::cpp_int>vec); 
void generateFirstKey(std::string fileKey);
void encrypt(boost::multiprecision::cpp_int a, std::string fileKey, std::string fileOut);
void decrypt(boost::multiprecision::cpp_int c, std::string fileKey, std::string fileOut);
boost::multiprecision::cpp_int getA(std::vector<boost::multiprecision::cpp_int>vec);
boost::multiprecision::cpp_int getC(std::string fileC);
boost::multiprecision::cpp_int generateK1();
boost::multiprecision::cpp_int getK1();
boost::multiprecision::cpp_int modexp(boost::multiprecision::cpp_int x, boost::multiprecision::cpp_int y, boost::multiprecision::cpp_int N);
boost::multiprecision::cpp_int reverse(boost::multiprecision::cpp_int a, boost::multiprecision::cpp_int b);
boost::multiprecision::cpp_int getAfromDec(std::string fileA);
boost::multiprecision::cpp_int gcd(boost::multiprecision::cpp_int n1, boost::multiprecision::cpp_int n2);


#endif