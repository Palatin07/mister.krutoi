#include <iostream>
#include <cmath>
#include "Complex.h"
int main()
{
	setlocale(LC_ALL, "RU");
	TComplex com1;
	com1.SetRe(-10);
	com1.SetIm(-7);
	std::cout << "com 1 = ";
	std::cout << com1 << std::endl;
	TComplex com2(4, 5);
	std::cout << "com 2 = ";
	std::cout << com2 << std::endl;
	TComplex com3 = com2;
	std::cout << "com 3 = ";
	std::cout << com3 << std::endl;
	com2 = com1 + com3;
	std::cout << "com 1 + com 3 = ";
	std::cout << com2 << std::endl;
	com2 = com1 - com3;
	std::cout << "com 1 - com 3 = ";
	std::cout << com2 << std::endl;
	com2 = com1 * com3;
	std::cout << "com 1 * com 3 = ";
	std::cout << com2 << std::endl;
	std::cout<<"Введите комплексное число: "<<std::endl;
	std::cin >> com3;
	com2 = com1 / com3;
	std::cout << "com 1 / com 3 = ";
	std::cout << com2 << std::endl << std::endl;
	if (com1 == com2) std::cout << "com1 == com2";
	std::cout << "Доп.задания:" << std::endl;
	TComplex com4;
	com4.SetRe(3);
	com4.SetIm(-5);
	std::cout << "Модуль: " << std::endl;
	std::cout << com4.Abs() << std::endl << std::endl << std::endl;
	std::cout << "Возведение в целую положительную степень: " << std::endl;
	com4.VozvedenieVStepen(3);
	std::cout << "\n\n";
	std::cout << "Возведение в целую отрицательную степень: " << std::endl;
	com4.VozvedenieVStepen(-3);
	std::cout << "\n\n";
	std::cout << "Тригонометрическая форма комплексного числа:  " << std::endl;
	com4.TrigForm();
	std::cout << "\n\n";
	return 0;
}
