/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met :
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and / or other materials provided with the distribution.
    * Neither the name of Harry He nor the names of its contributors
      may be used to endorse or promote products derived from this software
      without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED.IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*******************************************************************/

//==================================================================
// ����ָOffer�����������Թپ������ͱ���⡷����
// ���ߣ��κ���
//==================================================================

// ������16����ֵ�������η�
// ��Ŀ��ʵ�ֺ���double Power(double base, int exponent)����base��exponent
// �η�������ʹ�ÿ⺯����ͬʱ����Ҫ���Ǵ������⡣

#include <iostream>
#include <cmath>

bool g_InvalidInput = false;
bool equal(double num1, double num2);
double PowerWithUnsignedExponent(double base, unsigned int exponent);

double Power(double base, int exponent)
{
    g_InvalidInput = false;

    if (equal(base, 0.0) && exponent < 0)
    {
        g_InvalidInput = true;
        return 0.0;
    }

    unsigned int absExponent = (unsigned int) (exponent);
    if (exponent < 0)
        absExponent = (unsigned int) (-exponent);

    double result = PowerWithUnsignedExponent(base, absExponent);
    if (exponent < 0)
        result = 1.0 / result;

    return result;
}

/*
double PowerWithUnsignedExponent(double base, unsigned int exponent)
{
    double result = 1.0;
    
    for (int i = 1; i <= exponent; ++i)
        result *= base;

    return result;
}
*/

double PowerWithUnsignedExponent(double base, unsigned int exponent)
{
    if (exponent == 0)
        return 1;
    if (exponent == 1)
        return base;

    double result = PowerWithUnsignedExponent(base, exponent >> 1);
    result *= result;
    if ((exponent & 0x1) == 1)
        result *= base;

    return result;
}

bool equal(double num1, double num2)
{
    if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
        return true;
    else
        return false;
}

// ====================���Դ���====================
void Test(const char* testName, double base, int exponent, double expectedResult, bool expectedFlag)
{
    double result = Power(base, exponent);
    if (equal(result, expectedResult) && g_InvalidInput == expectedFlag)
        std::cout << testName << " passed" << std::endl;
    else
        std::cout << testName << " FAILED" << std::endl;
}

int main(int argc, char* argv[])
{
    // ������ָ����Ϊ����
    Test("Test1", 2, 3, 8, false);

    // ����Ϊ������ָ��Ϊ����
    Test("Test2", -2, 3, -8, false);

    // ָ��Ϊ����
    Test("Test3", 2, -3, 0.125, false);

    // ָ��Ϊ0
    Test("Test4", 2, 0, 1, false);

    // ������ָ����Ϊ0
    Test("Test5", 0, 0, 1, false);

    // ����Ϊ0��ָ��Ϊ����
    Test("Test6", 0, 4, 0, false);

    // ����Ϊ0��ָ��Ϊ����
    Test("Test7", 0, -4, 0, true);

    return 0;
}

