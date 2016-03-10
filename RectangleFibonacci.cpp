#include "stdafx.h"

// ====================方法1：递归====================
long long RFibonacci_Solution1(unsigned int n)
{
    int result[3] = {0, 1, 2};
    if(n < 3)
        return result[n];

    return RFibonacci_Solution1(n - 1) + RFibonacci_Solution1(n - 2);
}

// ====================方法2：循环====================
long long RFibonacci_Solution2(unsigned n)
{
    int result[3] = {0, 1, 2};
    if(n < 3)
        return result[n];

    long long  fibNMinusOne = 1;
    long long  fibNMinusTwo = 0;
    long long  fibN = 0;
	for(unsigned int i = 3; i <= n; ++ i)
	{
        fibN = fibNMinusOne + fibNMinusTwo;

        fibNMinusTwo = fibNMinusOne;
        fibNMinusOne = fibN;
    }
	
	return fibN;
}