
#include "long_num.hpp"

using namespace std;
using std::string;

vector<int> long_integer::getlong_integer()
{
	return (nums);
}

int	long_integer::get_size()
{
	return (nums.size());
}

long_integer::long_integer()
{
	nums = vector<int>(1, 0);
}

long_integer::long_integer(string s)
{
	while (s.length() != 0)
	{
		nums.push_back(s[s.length() - 1] - '0');
		s.erase(s.length() - 1, s.length());
	}
}

long_integer::long_integer(const long long& n)
{
	long long	x;

	x = n;
	while (x != 0)
	{
		nums.push_back(x % 10);
		x /= 10;
	}
}

long_integer::long_integer(const long_integer& other)
{
	operator = (other);
}

long_integer::long_integer(vector<int> n)
{
	nums = n;
}

long_integer& long_integer::operator=(const long_integer &other)
{
	nums = other.nums;
	return (*this);
}

bool long_integer::operator==(long_integer other)
{
	if (nums.size() != other.nums.size()) 
		return (0);
	else
		for (int i = 0; i < (int)nums.size(); i++)
		{
			if (nums[i] == other.nums[i])
				continue;
			else
				return (0);
		}
	return (1);
}

bool long_integer::operator!=(long_integer other)
{
	return (!operator==(other));
}

bool long_integer::operator>=(long_integer other)
{
	return (operator>(other) || operator==(other));
}

bool long_integer::operator<(long_integer other)
{
	return (!operator>(other) && !operator==(other));
}

bool long_integer::operator<=(long_integer other)
{
	return (operator<(other) || operator==(other));
}

bool long_integer::operator>(long_integer other)
{
	int		i;
	bool	res;

	if ((*this).nums[(*this).nums.size() - 1] < 0 && (other.nums[other.nums.size() - 1] >= 0))
		return (0);
	if ((*this).nums[(*this).nums.size() - 1] >= 0 && (other.nums[other.nums.size() - 1] < 0))
		return (1);
	if ((*this).nums.size() > other.nums.size())
		return (1);
	if ((*this).nums.size() < other.nums.size())
		return (0);
	i = (*this).nums.size() - 1;
	res = 0;
	while (i >= 0 && !res)
	{
		if ((*this).nums[i] > other.nums[i])
			res = 1;
		if ((*this).nums[i] < other.nums[i])
			i = -1;
		i--;
	}
	return (res);
}

void long_integer::write() const
{
	for (auto I = nums.end(); I != nums.begin(); )
		cout << *(--I);
}

long_integer long_integer::operator+(long_integer other)
{
	long_integer	x;
	long_integer	y;
	int			n;
	int			k;
	int			i;
	int			j;
	int			t;
	string		s;

	x = (*this);
	y = other;
	if (nums[nums.size() - 1] < 0)
	{
		if (other.nums[other.nums.size() - 1] < 0)
		{
			x.nums[x.nums.size() - 1] *= -1;
			y.nums[y.nums.size() - 1] *= -1;
			x = x + y;
			x.nums[x.nums.size() - 1] *= -1;
			return (x);
		}
		x.nums[x.nums.size() - 1] *= -1;
		return (y - x);
	}
	if (y.nums[y.nums.size() - 1] < 0)
	{
		y.nums[y.nums.size() - 1] *= -1;
		return (x - y);
	}
	n = max((*this).nums.size(), other.nums.size());
	k = 0;
	for (i = 0; i <= n + 1; ++i)
		s += '0';
	long_integer	res(s);
	if (x.nums.size() < y.nums.size())
		while (x.nums.size() != y.nums.size())
			x.nums.push_back(0);
	if (x.nums.size() > y.nums.size())
		while (y.nums.size() != x.nums.size())
			y.nums.push_back(0);
	for (i = 0; i < n; i++)
	{
		t = x.nums[i] + y.nums[i] + k;
		res.nums[i] = t % 10;
		k = t / 10;
	}
	res.nums[n] += k;
	j = n + 1;
	while (res.nums[j] == 0 && j != 0)
	{
		res.nums.pop_back();
		j--;
	}
	return (res);
}

long_integer long_integer::operator-()
{
	long_integer	n_e_w;
	long_integer	o_l_d;

	o_l_d = *this;
	n_e_w = o_l_d;
	n_e_w.nums[n_e_w.nums.size() - 1] = -nums[n_e_w.nums.size() - 1];
	return (n_e_w);
}

long_integer long_integer::operator-(long_integer other)
{
	long_integer	x;
	long_integer	y;
	bool			pos;
	int				n;
	int				i;
	int				j;
	string			s;

	x = (*this);
	y = other;
	if (y.nums[y.nums.size() - 1] < 0)
	{
		if (x.nums[x.nums.size() - 1] > 0)
		{
			y.nums[y.nums.size() - 1] *= -1;
			return (x + y);
		}
		y.nums[y.nums.size() - 1] *= -1;
		x.nums[x.nums.size() - 1] *= -1;
		return (y - x);
	}
	if (x.nums[x.nums.size() - 1] < 0)
	{
		x.nums[x.nums.size() - 1] *= -1;
		x = y + x;
		x.nums[x.nums.size() - 1] *= -1;
		return (x);
	}
	pos = true;
	if (other > (*this))
	{
		y = (*this);
		x = other;
		pos = false;
	}
	n = max((*this).nums.size(), other.nums.size());
	for (i = 0; i <= n + 1; ++i)
		s += '0';
	long_integer	res(s);
	if (x.nums.size() < y.nums.size())
		while (x.nums.size() != y.nums.size())
			x.nums.push_back(0);
	if (x.nums.size() > y.nums.size())
		while (y.nums.size() != x.nums.size())
			y.nums.push_back(0);
	for (i = 0; i < (int)y.nums.size(); i++)
	{
		if (x.nums[i] < y.nums[i])
		{
			x.nums[i + 1]--;
			x.nums[i] += 10;
		}
		res.nums[i] = x.nums[i] - y.nums[i];
	}
	j = n + 1;
	while (res.nums[j] == 0 && j != 0)
	{
		res.nums.pop_back();
		j--;
	}
	if (pos == false)
		res.nums[res.nums.size() - 1] *= -1;
	return (res);
}

long_integer long_integer::operator*(long_integer other)
{
	long_integer	M2;
	long_integer	M1;
	int				m;
	int				i;
	int				j;
	int				tmp;
	vector<int>		x1;
	vector<int>		x2;

	m = max(nums.size(), other.nums.size());
	vector<int>	res(m * 2);
	M1 = other;
	M2 = (*this);
	if (nums[nums.size() - 1] < 0)
		M2 = -(*this);
	if (other.nums[other.nums.size() - 1] < 0)
		M1 = -other;
	x1 = M2.getlong_integer();
	x2 = M1.getlong_integer();
	if (x1.size() < x2.size())
		swap(x1, x2);
	for (i = 0; i < (int)x2.size(); ++i)
	{
		for (j = 0; j < (int)x1.size(); ++j)
		{
			tmp = 0;
			tmp += res[i + j] + x2[i] * x1[j];
			res[i + j] = tmp % 10;
			res[i + j + 1] += tmp / 10;
		}
	}
	while (res.size() > 1 && res.back() == 0)
		res.pop_back();
	long_integer	M(res);
	if ((nums[nums.size() - 1] < 0) || (other.nums[other.nums.size() - 1] < 0))
		return (-M);
	else
		return (M);
}

long_integer long_integer::operator*(long long x)
{
	int			m;
	int			r;
	int			i;
	vector<int> a;

	a = nums;
	m = nums.size();
	vector<int>	res(m);
	r = 0;
	for (i = 0; i < (int)a.size(); i++)
	{
		if (i == (int)a.size() - 1)
		{
			res[i] = a[i] * x + r;
			if (res[i] >= 10)
			{
				r = res[i] / 10;
				res[i] = res[i] % 10;
				res.push_back(r);
			}
		}
		else
		{
			res[i] = a[i] * x + r;
			r = res[i] / 10;
			res[i] = res[i] % 10;
		}
	}
	while (res.size() > 1 && res.back() == 0)
		res.pop_back();
	return (res);
}

long_integer  long_integer::operator/(long long x)
{
	int		len;
	int		r;
	int		i;
	int		cur;

	if (x == 0)
		throw ("Error: division by zero!");
	len = nums.size();
	vector<int>	res(len);
	r = 0;
	for (i = nums.size() - 1; i >= 0; i--)
	{
		cur = 10 * r + nums[i];
		res[i] = cur / x;
		r = cur % x;
	}
	while (res.size() > 1 && res.back() == 0) res.pop_back();
	long_integer	res1(res);
	return (res1);
}

long_integer long_integer::operator/(long_integer other)
{
	long_integer	x;
	long_integer	y;
	int				k;

	if (other == long_integer("0"))
		throw ("Error: division by zero!");
	x = (*this);
	y = other;
	if (x.nums[x.nums.size() - 1] < 0)
	{
		if (y.nums[y.nums.size() - 1] < 0)
		{
			x.nums[x.nums.size() - 1] *= -1;
			y.nums[y.nums.size() - 1] *= -1;
			return (x / y);
		}
		x.nums[x.nums.size() - 1] *= -1;
		x = x / y;
		x.nums[x.nums.size() - 1] *= -1;
		return (x);
	}
	if (y.nums[y.nums.size() - 1] < 0)
	{
		y.nums[y.nums.size() - 1] *= -1;
		x = x / y;
		x.nums[x.nums.size() - 1] *= -1;
		return (x);
	}
	long_integer	res("0");
	long_integer	z("1");
	k = 0;
	while (!(y > x))
	{
		y = y + y;
		z = z + z;
		++k;
	}
	while (k)
	{
		y = y / 2;
		z = z / 2;
		--k;
		while (!(y > x))
		{
			x = x - y;
			res = res + z;
		}
	}
	return (res);
}

long_integer long_integer::operator%(long_integer other)
{
	long_integer	a;
	long_integer	b;
	long_integer	res;

	a = (*this);
	b = other;
	res = a - (a / b)*b;
	return (res);
}

long_integer long_integer::eval(long_integer x1, long_integer x0, int m)
{
	long_integer res;

	res = x0 + x1*m + (*this)*(m*m);
	return (res);
}

long_integer long_integer::Toom_Cook(long_integer other)
{
	vector<int> 	x_2;
	vector<int> 	x_1;
	vector<int> 	x_0;
	vector<int> 	y_2;
	vector<int> 	y_1;
	vector<int> 	y_0;
	vector<int> 	x;
	vector<int> 	y;
	long_integer	R0;
	long_integer	R1;
	long_integer	R2;
	long_integer	R3;
	long_integer	R4;
	int				forY;
	int				forX;
	int				sizeXY;
	int				len;
	int				c;
	int				i;
	int				j;
	int				k;

	x = nums;
	y = other.nums;
	if (max(x.size(), y.size()) <= n_len)
	{
		return (*this)*other;
	}
	if (x.size() < y.size())
	{
		forY = y.size();
		i = 0;
		if ((y.size() % 3) != 0)
		{
			y.push_back(0);
			++i;
		}
		y.resize(forY + i);
		do {
			x.push_back(0);
		} while (x.size() != y.size());
		x.resize(y.size());
	}
	if (y.size() < x.size())
	{
		forX = x.size();
		j = 0;
		if ((x.size() % 3) != 0)
		{
			x.push_back(0);
			++j;
		}
		x.resize(forX + j);
		do {
			y.push_back(0);
		} while (y.size() != x.size());
		y.resize(x.size());
	}
	if (y.size() == x.size())
	{
		c = 0;
		sizeXY = x.size();
		while ((x.size() % 3) != 0)
		{
			x.push_back(0);
			y.push_back(0);
			++c;
		};
		x.resize(sizeXY + c);
		y.resize(sizeXY + c);
	}
	len = x.size();
	vector<int>	res(2 * len);
	k = len / 3;

	x_2 = { x.begin() + 2 * k, x.end() };
	x_1 = { x.begin() + k, x.begin() + 2 * k };
	x_0 = { x.begin(), x.begin() + k };
	y_2 = { y.begin() + 2 * k, y.end() };
	y_1 = { y.begin() + k, y.begin() + 2 * k };
	y_0 = { y.begin(), y.begin() + k };
	long_integer	x2(x_2);
	long_integer	x1(x_1);
	long_integer	x0(x_0);
	long_integer	y2(y_2);
	long_integer	y1(y_1);
	long_integer	y0(y_0);

	R0 = (x2.eval(x1, x0, 0))
			*(y2.eval(y1, y0, 0));
	R1 = (x2.eval(x1, x0, 1))
			*(y2.eval(y1, y0, 1));
	R2 = (x2.eval(x1, x0, 2))
			*(y2.eval(y1, y0, 2));
	R3 = (x2.eval(x1, x0, 3))
			*(y2.eval(y1, y0, 3));
	R4 = (x2.eval(x1, x0, 4))
			*(y2.eval(y1, y0, 4));

	R1 = R1 - R0;
	R2 = R2 - R0;
	R3 = R3 - R0;
	R4 = R4 - R0;

	R2 = R2 - R1 * 2;
	R3 = R3 - R1 * 3;
	R4 = R4 - R1 * 4;

	R3 = R3 - R2 * 3;
	R4 = R4 - R2 * 6;

	R4 = R4 - R3 * 4;

	R4 = R4 / 24;
	R3 = R3 / 6;
	R2 = R2 / 2;

	R3 = R3 - R4 * 6;
	R2 = R2 - R4 * 7;
	R1 = R1 - R4;

	R2 = R2 - R3 * 3;
	R1 = R1 - R3;

	R1 = R1 - R2;

	R4.nums.insert(R4.nums.begin(), 4 * k, 0);
	R3.nums.insert(R3.nums.begin(), 3 * k, 0);
	R2.nums.insert(R2.nums.begin(), 2 * k, 0);
	R1.nums.insert(R1.nums.begin(), k, 0);

	long_integer	res1(res);
	res1 = R4 + R3 + R2 + R1 + R0;
	return (res1);

}

long_integer long_integer::KARATSUBA(long_integer other)
{
	vector<int>		x;
	vector<int>		y;
	long_integer	z0;
	long_integer	z1;
	long_integer	z2;
	long_integer	z3;
	int				m;
	int				n;
	int				k;
	int				len;

	len = max(nums.size(), other.nums.size());
	if (len <= n_len)
	{
		return ((*this)*other);
	}
	vector<int>	res(2 * len);
	x = nums;
	y = other.nums;
	m = other.nums.size();
	n = nums.size();
	if (n < m)
	{
		while (x.size() != y.size())
			x.push_back(0);
		x.resize(other.nums.size());
	}
	if (m < n)
	{
		while (y.size() != x.size())
			y.push_back(0);
		y.resize(nums.size());
	}
	k = (len / 2) + (len % 2);
	vector<int>		a_;
	vector<int>		b_;
	vector<int>		c_;
	vector<int>		d_;
	long_integer	r(res);
	a_ = { x.begin() + k,x.end() };
	b_ = { x.begin(), x.begin() + k };
	c_ = { y.begin() + k, y.end() };
	d_ = { y.begin(), y.begin() + k };
	long_integer	a(a_);
	long_integer	b(b_);
	long_integer	c(c_);
	long_integer	d(d_);
	z0 = a.KARATSUBA(c);
	z1 = (a + b).KARATSUBA(c + d);
	z2 = b.KARATSUBA(d);
	z3 = z1 - z2 - z0;
	z0.nums.insert(z0.nums.begin(), 2 * k, 0);
	z3.nums.insert(z3.nums.begin(), k, 0);
	r = (z0)+(z3)+(z2);
	return (r);
}

long_integer long_integer::inverse(long_integer b)
{
	long_integer		a;
	long_integer		b0;
	long_integer		t;
	long_integer		q;
	long_integer		one("1");
	long_integer		null("0");
	long_integer		x0("0");
	long_integer		x1("1");

	b0 = b;
	a = (*this);
	if (b == one)
		return (one);
	while (one < a)
	{
		q = a / b;
		t = b;
		b = a % b;
		a = t;
		t = x0;
		x0 = x1 - q * x0;
		x1 = t;
	}
	if (x1 < null)
		x1 = b0 + x1;
	return (x1);
}

long_integer long_integer::chinese_remainder(vector <long_integer> n, vector <long_integer> a)
{
	long_integer	p;
	long_integer	prod("1");
	long_integer	sum("0");
	int				i;
	int				j;

	for (i = 0; i < 6; i++)
		prod = prod * n[i];
	for (j = 0; j < 6; j++)
	{
		p = prod / n[j];
		sum = sum + (p.inverse(long_integer(n[j])) * p) * a[j];
	}
	sum = sum % prod;
	return (sum);
}

long_integer long_integer::Shoenhage(long_integer other)
{
	long_integer 	a;
	long_integer	b;
	long_integer	v1;
	long_integer	v2;
	long_integer	v3;
	long_integer	v4;
	long_integer	v5;
	long_integer	v6;
	long_integer	u1;
	long_integer	u2;
	long_integer	u3;
	long_integer	u4;
	long_integer	u5;
	long_integer	u6;
	long_integer	x1;
	long_integer	x2;
	long_integer	x3;
	long_integer	x4;
	long_integer	x5;
	long_integer	x6;
	long_integer	res;
	
	long_integer	w1("1300727");
	long_integer	w2("1313423");
	long_integer	w3("1327877");
	long_integer	w4("15487001");
	long_integer	w5("179423411");
	long_integer	w6("179426341");

	a = *this;
	b = other;

	v1 = a % w1;
	v2 = a % w2;
	v3 = a % w3;
	v4 = a % w4;
	v5 = a % w5;
	v6 = a % w6;

	u1 = b % w1;
	u2 = b % w2;
	u3 = b % w3;
	u4 = b % w4;
	u5 = b % w5;
	u6 = b % w6;

	x1 = (v1 * u1) % w1;
	x2 = (v2 * u2) % w2;
	x3 = (v3 * u3) % w3;
	x4 = (v4 * u4) % w4;
	x5 = (v5 * u5) % w5;
	x6 = (v6 * u6) % w6;

	res = chinese_remainder(
		{ w1, w2, w3, w4, w5, w6 },
		{ x1, x2, x3, x4, x5, x6 });
	return (res);
}

void long_integer::Fast_Fourier_Transform(vector<complex<double>>& a, bool invert)
{
	int		n;
	int		i;
	int		j;
	int		k;
	double	ang;

	n = (int)a.size();
	if (n == 1)
		return ;
	vector<complex<double>>	a0(n / 2);
	vector<complex<double>>	a1(n / 2);
	for (i = 0, j = 0; i < n; i += 2, ++j)
	{
		a0[j] = a[i];
		a1[j] = a[i + 1];
	}
	Fast_Fourier_Transform(a0, invert);
	Fast_Fourier_Transform(a1, invert);
	ang = 2 * PI / n * (invert ? -1 : 1);
	complex<double>	vec(1);
	complex<double>	vec_n(cos(ang), sin(ang));
	for (k = 0; k < n / 2; ++k)
	{
		a[k] = a0[k] + vec * a1[k];
		a[k + n / 2] = a0[k] - vec * a1[k];
		if (invert)
			a[k] /= 2, a[k + n / 2] /= 2;
		vec *= vec_n;
	}
}

long_integer long_integer::Schtrassen(long_integer other)
{
	int						carry;
	size_t					n;
	size_t					i;
	size_t					j;
	size_t					k;
	long_integer			f;
	long_integer			s;
	vector<int>				res;

	n = 1;
	carry = 0;
	f = *this;
	s = other;
	vector<complex<double>>	ff(f.nums.begin(), f.nums.end());
	vector<complex<double>>	fs(s.nums.begin(), s.nums.end());
	while (n < max(f.nums.size(), s.nums.size()))
		n <<= 1;
	n <<= 1;
	fs.resize(n);
	ff.resize(n);
	Fast_Fourier_Transform(ff, false);
	Fast_Fourier_Transform(fs, false);
	for (i = 0; i < n; i++)
		ff[i] *= fs[i];
	Fast_Fourier_Transform(ff, true);
	res.resize(n);
	for (j = 0; j < n; j++)
		res[j] = int(ff[j].real() + 0.5);
	for (k = 0; k < n; k++)
	{
		res[k] += carry;
		carry = res[k] / 10;
		res[k] %= 10;
	}
	while (res.size() > 1 && res.back() == 0)
		res.pop_back();
	return (long_integer(res));
}

long_integer long_integer::randomize()
{
	bool		r;
	int			i;
	int			b;
	int			c;
	vector<int>	a;

	r = true;
	while (r)
	{
		a.clear();
		for (i = 0; i < (int)this->nums.size(); i++)
		{
			if (i == 0)
			{
				b = rand() % (this->nums[0] + 1);
				a.insert(a.begin(), b);
			}
			else
			{
				c = rand() % 10;
				while (c == 0)
					c = rand() % 10;
				a.insert(a.begin(), c);
			}
		}
		if (long_integer(a) < *this)
			r = false;
		else 
			r = true;
	}
	while (a.size() > 1 && a.back() == 0)
		a.pop_back();
	return (long_integer(a));
}

long_integer long_integer::power(long_integer y, long_integer p)
{
	long_integer	x1;
	long_integer	y1;
	long_integer	res;

	y1 = y;
	x1 = *this;
	res = long_integer("1");
	while (y1 != long_integer("0"))
	{
		if (y1.nums[0] % 2 == 1)
			res = (res * x1) % p;
		y1 = y1 / 2;
		x1 = (x1 * x1) % p;
	}
	return (res);
}

bool long_integer::Lemmar_prime()
{
	long_integer	one("1");
	long_integer	lem;
	long_integer	check;
	long_integer	a;
	bool			flag;
	bool			isOK;
	int				i;

	lem = *this;
	if (lem == long_integer("2"))
		return (1);
	if (lem == one || lem.nums[0] % 2 == 0)
		return (0);
	flag = 0;
	isOK = 1;
	for (i = 0; i < 10 && isOK; i++)
	{
		a = lem.randomize();
		check = a.power(((*this) - one) / 2, lem);
		if (check == one || check == (lem - one))
			flag = 1;
		else
			isOK = 0;
	}
	return (isOK && flag);
}

long_integer long_integer::rise_power(long_integer other)
{
	long_integer	n;
	long_integer	m;
	long_integer	i;
	long_integer	null("0");
	long_integer	one("1");

	m = *this;
	n = one;
	i = other;
	while (null < i)
	{
		n = n.Toom_Cook(m);
		i = i - one;
	}
	return (n);
}

bool long_integer::Rabin_Miller_prime()
{
	long_integer	n;
	long_integer	null("0");
	long_integer	one("1");
	long_integer	two("2");
	long_integer	s;
	long_integer	t;
	long_integer	a;
	long_integer	x;
	long_integer	w;
	long_integer	z;
	bool			isOK;
	bool			isOK_2;
	int				i;

	n = *this;
	if (n == long_integer("2"))
		return (true);
	if (n < two)
		return (false);
	if (n == one || n.nums[0] % 2 == 0)
		return (false);
	isOK = true;
	s = one;
	w = n - one;
	while (w.nums[0] % 2)
	{
		s = s + one;
		w = w / 2;
	}
	t = (n - one) / two.rise_power(s);
	i = 0;
	while (isOK && i < 10)
	{
		a = n.randomize();
		x = a.power(t, n);
		if (x == one || x == n - one)
			i++;
		else
		{
			long_integer	j("0");
			isOK_2 = true;
			while (j < s - one && isOK_2)
			{
				x = (x.Toom_Cook(x)) % n;
				if (x == one)
				{
					isOK = false;
					isOK_2 = false;
				}
				else if (x == n - one)
				{
					i++;
					isOK_2 = false;
					break;
				}
				j = j + one;
			}
			if (isOK_2)
				isOK = false;
		}
	}
	return (isOK);
}
