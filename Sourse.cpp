#include <iostream>
#include <string>
#include <exception>

#include "Empty_.h"
#include "Error_.h"
#include "E_.h"

using namespace std;


double linearRoot1(double a, double b) {
	if (a == 0) {
		throw std::invalid_argument("Parameter 'a' cannot be zero");
	}
	return -b / a;
}

double linearRoot2(double a, double b) throw() {
	if (a == 0) {
		throw "Parameter 'a' cannot be zero";
	}
	return -b / a;
}

double linearRoot3(double a, double b) throw(invalid_argument) {
	if (a == 0) {
		throw invalid_argument("Parameter 'a' cannot be zero");
	}
	return -b / a;
}

double linearRoot4(double a, double b) throw(Empty) {
	if (a == 0) {
		throw Empty();
	}
	return -b / a;
}

double linearRoot5(double a, double b) throw(Error) {
	if (a == 0) {
		throw Error("Parameter 'a' cannot be zero");
	}
	if (a < -5000)
		throw Error("too small a");
	return -b / a;
}

double linearRoot6(int a, int b) throw(int)
{
	if (a == 0)
		throw E("Parameter 'a' cannot be zero");
	if (a < -5000)
		throw E("too small a");
	return -b / a;
}
void FU()
{
	cout << "unexpected error! - bad_exception" << endl;
	throw;
}
void FT()
{
	cout << "unknown error! - terminate" << endl;
	abort();
}
int main()
{
	set_unexpected(FU);
	set_terminate(FT);

	int a, b;
	cout << " a = ? "; cin >> a;
	cout << " b = ? "; cin >> b;

	try
	{
		cout << linearRoot1(a, b) << endl;
		cout << linearRoot2(a, b) << endl;
		cout << linearRoot3(a, b) << endl;
		cout << linearRoot4(a, b) << endl;
		cout << linearRoot5(a, b) << endl;
		cout << linearRoot6(a, b) << endl;

	}
	catch (int)
	{
		cout << " catch (int) <= linearRoot1()" << endl;
	}
	catch (double)
	{
		cout << " catch (double) <= linearRoot2()" << endl;
	}
	catch (char)
	{
		cout << " catch (char) <= linearRoot3()" << endl;
	}
	catch (Empty)
	{
		cout << " catch (Empty) <= linearRoot4()" << endl;
	}
	catch (Error e)
	{
		cout << " catch (Error) <= linearRoot5() :" << endl;
		cout << e.What() << endl;
	}
	catch (bad_exception)
	{
		cout << " catch (bad_exception)" << endl;
	}
	catch (exception)
	{
		cout << " catch (exception) <= linearRoot6() :" << endl;
	}
	catch (E e)
	{
		cout << " catch (E) <= linearRoot6() :" << endl;
		cout << e.What() << endl;
	}
	system("pause");
	return 0;
}