#include "long_num.hpp"

using namespace std;

int main(int argc, const char * argv[])
{
	long_integer 	A;
	long_integer 	B;
	long_integer 	C;
	long_integer 	D;
	long_integer 	F;
	long_integer 	G;
	std::string		s;

	A = long_integer("2017");
	B = long_integer("7783935468");
	D = long_integer("9898454430");
	cout << "\t\t --KARATSUBA--\n\n";
	A.write();
	cout << " * ";
	B.write();
	cout << " = ";
	C = A.KARATSUBA(B);
	D = D - C;
	C.write();
	cout << endl;
	cout << "Wolfram Alpha - My KARATSUBA = ";
	D.write();
	cout << endl;
	F = long_integer("187754683");
	G = long_integer("345678");
	cout << "\n\t\t --Toom-Cook--\n\n";
	F.write();
	cout << " * ";
	G.write();
	cout << " = ";
	C = F.Toom_Cook(G);
	D = long_integer("630937");
	D = D - C;
	C.write();
	cout << endl;
	cout << "Wolfram Alpha - My Toom-Cook = ";
	D.write();
	cout << endl;
	B = long_integer("3456786434");
	G = long_integer("777465544");
	D = long_integer("26875271444");
	cout << "\n\t\t --Schtrassen--\n\n";
	B.write();
	cout << " * ";
	G.write();
	cout << " = ";
	C = B.Schtrassen(G);
	D = D - C;
	C.write();
	cout << endl;
	cout << "Wolfram Alpha - My Schtrassen = ";
	D.write();
	cout << endl;
	B = long_integer("34567864343");
	G = long_integer("7774645454");
	D = long_integer("13717146");
	cout << "\n\t\t --Shoenhage--\n\n";
	B.write();
	cout << " * ";
	G.write();
	cout << " = ";
	D = B.Shoenhage(G);
	D.write();
	D = D - C;
	cout << endl;
	cout << "Schtrassen - My Shoenhage = ";
	D.write();
	cout << endl;
	cout << "\n\t\t --Rabin-Miller-- \n";
	if (A.Rabin_Miller_prime())
		s = " is prime.";
	else
		s = " isn/'t prime.";
	cout << "Number ";
	A.write();
	cout << s << endl;
	cout << "\n\t\t --Lemmar-- \n";
	if (F.Lemmar_prime())
		s = " is prime.";
	else
		s = " isn/'t prime.";
	cout << "Number ";
	F.write();
	cout << s << endl;
	return (0);
}
