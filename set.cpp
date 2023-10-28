#include <cstring>
#include "set.h"

set::set():len(1)
{
	nset = new setType[1];
    
	nset[0] = 0;

	//len = 1;

	//cout << "Called default constructor" << endl;
}

set::set(uint32_t n)
{
	//exception(n);
    

	len = num(n) + 1;
	nset = new setType[len];

	//for(size_t i = 0; i < len - 1; i++)
		//nset[i] = 0;
    memset(nset, 0, (len - 1) * sizeof(uint32_t));

	nset[len - 1] = 1 << (31 - bit(n)); 

	//cout << "Called constructor with parameters." << endl;
	//cout << bit(n) << endl;
}

set::set(const set& original)
{
	len = original.len;

	nset = new setType[len];

	//for(size_t i = 0; i < len; i++)
		//nset[i] = original.nset[i];
    memcpy(nset, original.nset, len * sizeof(uint32_t));
}

set::set(set&& original)
{
	len = original.len;
	nset = original.nset;

	original.len = 1;
	delete [] original.nset;
	original.nset = new setType[1];
	original.nset[0] = 0;
}

set::~set()
{
	if (nset) delete [] nset;

	//cout << "Called destructor." << endl;
}

void set::swap(set& other)
{
    setType *help = nset;
    size_t lenh = len;
    
    nset = other.nset;
    len = other.len;
    
    other.nset = help;
    other.len = lenh;
}

const set & set::operator=(const set& a)
{
	set tmp(a);
    swap(tmp);

	return *this;
}

const set & set::operator=(uint32_t n)
{
	//exception(n);

	delete [] nset;

	len = num(n) + 1;
	nset = new setType[len];
    
    if(!nset)
        throw -1;

	//for(size_t i = 0; i < len - 1; i++)
		//nset[i] = 0;
    memset(nset, 0, (len - 1) * sizeof(uint32_t));

	nset[len - 1] = 1 << (31 - bit(n));

	return *this;
}

const set & set::operator+=(const set& x)
{
	if(len >= x.len)
	{
		for(size_t i = 0; i < x.len; i++)
			nset[i] = nset[i] | x.nset[i];
	}
	else
	{
		setType* y;
		y = new setType[x.len];
        
        if(!y)
            throw -1;

		for(size_t i = 0; i < len; i++)
			y[i] = nset[i] | x.nset[i];
		for(size_t i = len; i < x.len; i++)
			y[i] = x.nset[i];
		
		delete [] nset;

		len = x.len;
		nset = new setType[x.len];
        
        if(!nset)
            throw -1;
        
		//for(size_t i = 0; i < len; i++)
			//nset[i] = y[i];
        memcpy(nset, y, len * sizeof(uint32_t));

		delete [] y;
	}

	return *this;
}

const set & set::operator-=(const set& x)
{
	if(len > x.len)
	{
		setType* help = new setType[x.len];
        
        if(!help)
            throw -1;

		for(size_t i = 0; i < x.len; i++)
		{
			help[i] = x.nset[i] & nset[i];
			help[i] = ~help[i];
			nset[i] = nset[i] & help[i];
		}

		delete [] help;
		return *this;
	}
	else
	{
		setType* help = new setType[len];
        
        if(!help)
            throw -1;

		for(size_t i = 0; i < len; i++)
		{
			help[i] = x.nset[i] & nset[i];
			help[i] = ~help[i];
			help[i] = nset[i] & help[i];
		}

		for(size_t i = len - 1; i > 0; i--)
		{
			if (help[i] == 0)
				len--;
			else
				break;
		}

		delete [] nset;
		
		nset = new setType[len];
        
        if(!nset)
            throw -1;

		//for(size_t i = 0; i < len; i++)
		//nset[i] = help[i];
        memcpy(nset, help, len * sizeof(uint32_t));

		delete [] help;
		return *this;
	}
}

const set & set::operator*=(const set& x)
{
	size_t len0;

	if(len >= x.len)
		len0 = x.len;
	else
		len0 = len;

	setType* help = new setType[len0];

	for (size_t i = 0; i < len0; i++)
	{
		help[i] = nset[i] & x.nset[i];
	}

	for(size_t i = len0 - 1; i > 0; i--)
	{
		if (help[i] == 0)
			len0--;
		else
			break;
	}

	len = len0;
	delete [] nset;

	nset = new setType[len];

	//for(size_t i = 0; i < len; i++)
		//nset[i] = help[i];
    memcpy(nset, help, len * sizeof(uint32_t));

	delete [] help;
	return *this;
}

const set & set::operator+=(uint32_t n)
{
	//exception(n);

	set help(n);

	*this += help;

	return *this;
}

const set & set::operator-=(uint32_t n)
{
	//exception(n);

	set help(n);

	*this -= help;

	return *this;
}

const set & set::operator*=(uint32_t n)
{
	//exception(n);

	set help(n);

	*this *= help;

	return *this;
}

set operator+(const set& a, const set& b)
{
	set c = a;
	return c += b;
}

set operator-(const set& a, const set& b)
{
	set c = a;
	return c -= b;
}

set operator*(const set& a, const set& b)
{
	set c = a;
	return c *= b;
}

void print(const set& a)
{
	for(size_t i = 0; i < a.len; i++)
	{
		for (int j = 31; j >= 0; j--)
			printf("%c", (a.nset[i] & 1 << j) ? '1' : '0');
		//cout << " ";
	}
	cout << endl;
}

bool set::operator==(const set& a) const
{
	if(len == a.len)
	{
		for(size_t i = 0; i < len; i++)
			if (nset[i] != a.nset[i])
				return false;
	}
	else
		return false;

	return true;
}

bool set::operator!=(const set& a) const
{
	if (*this == a)
		return false;
	else
		return true;
}

bool set::operator<(const set& a) const
{
	if (*this <= a && *this != a)
		return true;
	else
		return false;
}

bool set::operator<=(const set& a) const
{
	return (*this - a).isEmpty();
}

bool set::operator>(const set& a) const
{
	if (*this >= a && *this != a)
		return true;
	else
		return false;
}

bool set::operator>=(const set& a) const
{
	return (a - *this).isEmpty();
}

bool set::operator()(uint32_t n)
{
	//exception(n);

	uint32_t nn = 1 << (31 - bit(n));

	if ((nset[num(n)] & nn) == nn)
		return true;
	else
		return false;
}

bool set::isEmpty()
{
	if (len == 1 && nset[0] == 0)
		return true;
	else
		return false;
}

int set::lenght()
{
	int lenght = 0;
	for(size_t i = 0; i < len; i++)
	{
		for (int j = 31; j >= 0; j--)
		{
			if (nset[i] & 1 << j)
				lenght++;
		}
	}

	return lenght;
}

/*void set::exception(uint32_t n)
{
    uint32_t k = 1 << 31;
	if (n & k)
		throw -1;
}*/

