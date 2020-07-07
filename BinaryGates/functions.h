#pragma once
#include <iostream>
#include <bitset>

using std::cout;
using std::cin;
using std::endl;
using std::bitset;
using std::size_t;


template<size_t size>
bitset<size> And(bitset<size> a, bitset<size> b)
{
	bitset<size> c;
	for (size_t i = 0; i < size; ++i)
	{
		if (a[i] == b[i] && a[i] == 1)
		{
			c[i] = 1;
		}
		else
		{
			c[i] = 0;
		}
	}
	return c;

}

template<size_t size>
bitset<size> Or(bitset<size> a, bitset<size> b)
{
	bitset<size> c;
	for (size_t i = 0; i < size; ++i)
	{
		if (a[i] == 1 || b[i] == 1)
		{
			c[i] = 1;
		}
		else
		{
			c[i] = 0;
		}
	}
	return c;

}

template<size_t size>
bitset<size> Xor(bitset<size> a, bitset<size> b)
{
	bitset<size> c;
	for (size_t i = 0; i < size; ++i)
	{
		if (a[i] == b[i])
		{
			c[i] = 0;
		}
		else
		{
			c[i] = 1;
		}
	}
	return c;

}

template<size_t size>
bitset<size> Nor(bitset<size> a, bitset<size> b)
{
	bitset<size> c;
	for (size_t i = 0; i < size; ++i)
	{
		if (a[i] == b[i] && a[i] == 0)
		{
			c[i] = 1;
		}
		else
		{
			c[i] = 0;
		}
	}
	return c;

}

template<size_t size>
bitset<size> BitShiftLeft(bitset<size> a, size_t amount)
{
	/*for (size_t i = 0; i < amount; ++i)
	{
		bitset<1> temp;
		temp[0] = a[0];
		for (size_t k = 0; k < size - 1; ++k)
		{
			a[k] = a[k + 1];
		}
		a[size - 1] = temp[0];
	}*/
	return a << amount;
}

template<size_t size>
bitset<size> Add(bitset<size> a, bitset<size> b)
{
	bitset<size> c;
	bitset<1> carry("0");
	for (size_t i = 0; i < size; ++i)
	{
		c[i] = Xor<1>(Xor<1>(bitset<1>(a[i]), bitset<1>(b[i])), carry)[0];
		carry[0] = Or<1>(And<1>(carry, Xor<1>(bitset<1>(a[i]), bitset<1>(b[i]))), And<1>(bitset<1>(a[i]), bitset<1>(b[i])))[0];
	}

	return	c;

}
