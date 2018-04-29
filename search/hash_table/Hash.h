/*
function:Hash函数
by:Erland
date:2017.7.22
*/

#pragma once

int hash(int v, int M)	//整数关键字的散列函数
{
	if (v >= 0)
		return v % M;
	else
		return (-v) % (M);
}

int hash(char *v, int M)	//字符串关键字的普通散列函数
{
	int h, a = 127;
	for (h = 0; *v != '\0'; v++)
		h = (a*h + *v) % M;
	return h;
}

int hash_Rand(char *v, int M)	//字符串关键字的通用散列函数_伪随机数
{
	int h, a = 31415, b = 27183;
	for (h = 0; *v != '\0'; v++, a = a*b % (M - 1))
		h = (a*h + *v) % M;
	return h;
}

