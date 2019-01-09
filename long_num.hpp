#ifndef LONG_NUM_HPP
# define LONG_NUM_HPP

# include <assert.h>
# include <sstream>
# include <cmath>
# include <vector>
# include <cstdlib>
# include <algorithm>
# include <iterator>
# include <complex>
# include <stdio.h>
# include <string>
# include <iostream>

# define n_len 10
# define PI 3.14159265358979323846

using namespace std;

class long_integer {
public:
	long_integer();
	long_integer(const long long&);
	long_integer(vector<int>);
	long_integer(const long_integer&);
	long_integer(string s);
	vector<int> 	getlong_integer();
	int				get_size();
	void 			write()const;
	long_integer	operator-();
	long_integer	operator+(long_integer);
	long_integer	operator-(long_integer);
	long_integer	operator*(long_integer);
	long_integer	operator/(long_integer);
	long_integer	operator*(long long);
	long_integer	operator/(long long);
	long_integer	operator%(long_integer);
	long_integer&	operator = (const long_integer &other);
	bool 			operator==(long_integer);
	bool 			operator>=(long_integer);
	bool 			operator<=(long_integer);
	bool			operator!=(long_integer);
	bool			operator<(long_integer);
	bool			operator>(long_integer);
	void			Fast_Fourier_Transform(vector<complex<double>>&, bool);
	long_integer	KARATSUBA(long_integer);
	long_integer	Toom_Cook(long_integer);
	long_integer	Shoenhage(long_integer);
	long_integer	Schtrassen(long_integer);
	long_integer	inverse(long_integer);
	long_integer	chinese_remainder(vector<long_integer>, vector<long_integer>);
	long_integer	eval(long_integer, long_integer, int);
	long_integer	randomize();
	long_integer	power(long_integer, long_integer);
	long_integer	rise_power(long_integer);
	bool			Lemmar_prime();
	bool			Rabin_Miller_prime();

protected:
	vector<int> nums;
};

#endif