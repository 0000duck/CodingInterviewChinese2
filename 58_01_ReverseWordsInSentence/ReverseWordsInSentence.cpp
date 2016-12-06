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

// ������58��һ������ת����˳��
// ��Ŀ������һ��Ӣ�ľ��ӣ���ת�����е��ʵ�˳�򣬵��������ַ���˳�򲻱䡣
// Ϊ������������ź���ͨ��ĸһ���������������ַ���"I am a student. "��
// �����"student. a am I"��

#include <cstdio>
#include "..\Utilities\StringUtil.h"
#include <string>

char* ReverseSentence(char *pData)
{
    if(pData == nullptr)
        return nullptr;

    char *pBegin = pData;

    char *pEnd = pData;
    while(*pEnd != '\0')
        pEnd ++;
    pEnd--;

    // ��ת��������
    Reverse(pBegin, pEnd);

    // ��ת�����е�ÿ������
    pBegin = pEnd = pData;
    while(*pBegin != '\0')
    {
        if(*pBegin == ' ')
        {
            pBegin ++;
            pEnd ++;
        }
        else if(*pEnd == ' ' || *pEnd == '\0')
        {
            Reverse(pBegin, --pEnd);
            pBegin = ++pEnd;
        }
        else
            pEnd ++;
    }

    return pData;
}

// ====================���Դ���====================
void Test(const char* testName, char* input, const char* expectedResult)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    ReverseSentence(input);

    if((input == nullptr && expectedResult == nullptr)
        || (input != nullptr && strcmp(input, expectedResult) == 0))
        printf("Passed.\n\n");
    else
        printf("Failed.\n\n");
}

// ���ܲ��ԣ��������ж������
void Test1()
{
    char input[] = "I am a student.";
    char expected[] = "student. a am I";

    Test("Test1", input, expected);
}

// ���ܲ��ԣ�������ֻ��һ������
void Test2()
{
    char input[] = "Wonderful";
    char expected[] = "Wonderful";

    Test("Test2", input, expected);
}

// ³���Բ���
void Test3()
{
    Test("Test3", nullptr, nullptr);
}

// �߽�ֵ���ԣ����Կ��ַ���
void Test4()
{
    Test("Test4", "", "");
}

// �߽�ֵ���ԣ��ַ�����ֻ�пո�
void Test5()
{
    char input[] = "   ";
    char expected[] = "   ";
    Test("Test5", input, expected);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}

