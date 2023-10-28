#pragma once
#include <iostream>

#define num(x) ((x) >> 5) //division by 2^5
#define bit(x) ((x) & 31) //remainder of the division by 2^5

using namespace std;

typedef uint32_t setType;

class set
{ 
private:
	setType* nset;
	size_t len;

public:
	set();
	set(uint32_t n);
	set(const set& original);
	set(set&& original);
	~set();
    
    void swap(set& other);

	const set & operator=(const set& a);
	const set & operator=(uint32_t n);

	const set & operator+=(const set& x);
	const set & operator-=(const set& x);
	const set & operator*=(const set& x);
	const set & operator+=(uint32_t n);
	const set & operator-=(uint32_t n);
	const set & operator*=(uint32_t n);
	
	friend set operator+(const set& a, const set& b);
	friend set operator-(const set& a, const set& b);
	friend set operator*(const set& a, const set& b); 

	friend void print(const set&);

	bool operator==(const set& a) const;
	bool operator!=(const set& a) const;
	bool operator<(const set& a) const;
	bool operator<=(const set& a) const;
	bool operator>(const set& a) const;
	bool operator>=(const set& a) const;

	bool operator()(uint32_t n);
	bool isEmpty();
	int lenght();

	void exception(uint32_t n);
};
