// relatives.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <cstring>
#include <iostream>

using namespace std;

class Animal
{
public:
	Animal();
	Animal(const char*, int, int);
	~Animal();
	void print();
	static void print(Animal);

private:
	char* classification;
	int limb_num;

protected:
	int child_num;
};

class Pet : public Animal
{
public:
	Pet();
	Pet(const char*, int, int, const char*);
	~Pet();
	static void print(Pet);
	void rename(const char*);
	void reset_child(int);
private:
	char* name;
};

int main()
{
	Animal a;
	Pet b("dog", 4, 3, "Rex");
	Animal::print(a);
	cout << endl;
	b.rename("Fert");
	b.reset_child(6);
	Pet::print(b);
	system("pause");
	return 0;
}

Animal::Animal()
{
	classification = new char[6];
	strcpy_s(classification, 6, "mamal");
	limb_num = 4;
	child_num = 2;
}

Animal::Animal(const char *c, int ln, int cn)
{
	classification = new char[strlen(c) + 1];
	strcpy_s(classification, strlen(c) + 1, c);
	limb_num = ln;
	child_num = cn;
}

Animal::~Animal()
{
}

void Animal::print()
{
	cout << "classified as " << classification << endl;
	cout << "quantity of limbs: " << limb_num << endl;
	cout << "quantity of childs: " << child_num << endl;
}

void Animal::print(Animal a)
{
	a.print();
}

Pet::Pet() : Animal()
{
	name = new char[6];
	strcpy_s(name, 6, "Butch");
}

Pet::Pet(const char *c, int ln, int cn, const char *n) : Animal(c, ln, cn)
{
	name = new char[strlen(n) + 1];
	strcpy_s(name, strlen(n) + 1, n);
}

Pet::~Pet()
{
}

void Pet::print(Pet a)
{
	Animal::print(a);
	cout << "name: " << a.name << endl;
}

void Pet::rename(const char *n)
{
	delete []name;
	name = new char[strlen(n) + 1];
	strcpy_s(name, strlen(n) + 1, n);
}

void Pet::reset_child(int n)
{
	child_num = n;
}
