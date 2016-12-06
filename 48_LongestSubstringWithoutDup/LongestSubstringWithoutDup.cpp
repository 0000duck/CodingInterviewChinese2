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

// ������48��������ظ��ַ������ַ���
// ��Ŀ������ַ������ҳ�һ����Ĳ������ظ��ַ������ַ�������������
// �ַ����ĳ��ȡ������ַ�����ֻ������'a'��'z'���ַ���

#include <string>
#include <iostream>

// ����һ��������
bool hasDuplication(const std::string& str, int position[]);

int longestSubstringWithoutDuplication_1(const std::string& str)
{
    int longest = 0;
    int* position = new int[26];
    for(int start = 0; start < str.length(); ++start)
    {
        for(int end = start; end < str.length(); ++end)
        {
            int count = end - start + 1;
            const std::string& substring = str.substr(start, count);
            if(!hasDuplication(substring, position))
            {
                if(count > longest)
                    longest = count;
            }
            else
                break;

        }
    }

    delete[] position;
    return longest;
}

bool hasDuplication(const std::string& str, int position[])
{
    for(int i = 0; i < 26; ++i)
        position[i] = -1;

    for(int i = 0; i < str.length(); ++i)
    {
        int indexInPosition = str[i] - 'a';
        if(position[indexInPosition] >= 0)
            return true;

        position[indexInPosition] = indexInPosition;
    }

    return false;
}

// ����һ����̬�滮
int longestSubstringWithoutDuplication_2(const std::string& str)
{
    int curLength = 0;
    int maxLength = 0;

    int* position = new int[26];
    for(int i = 0; i < 26; ++i)
        position[i] = -1;

    for(int i = 0; i < str.length(); ++i)
    {
        int prevIndex = position[str[i] - 'a'];
        if(prevIndex < 0 || i - prevIndex > curLength)
            ++curLength;
        else
        {
            if(curLength > maxLength)
                maxLength = curLength;

            curLength = i - prevIndex;
        }
        position[str[i] - 'a'] = i;
    }

    if(curLength > maxLength)
        maxLength = curLength;

    delete[] position;
    return maxLength;
}

// ====================���Դ���====================
void testSolution1(const std::string& input, int expected)
{
    int output = longestSubstringWithoutDuplication_1(input);
    if(output == expected)
        std::cout << "Solution 1 passed, with input: " << input << std::endl;
    else
        std::cout << "Solution 1 FAILED, with input: " << input << std::endl;
}

void testSolution2(const std::string& input, int expected)
{
    int output = longestSubstringWithoutDuplication_2(input);
    if(output == expected)
        std::cout << "Solution 2 passed, with input: " << input << std::endl;
    else
        std::cout << "Solution 2 FAILED, with input: " << input << std::endl;
}

void test(const std::string& input, int expected)
{
    testSolution1(input, expected);
    testSolution2(input, expected);
}

void test1()
{
    const std::string input = "abcacfrar";
    int expected = 4;
    test(input, expected);
}

void test2()
{
    const std::string input = "acfrarabc";
    int expected = 4;
    test(input, expected);
}

void test3()
{
    const std::string input = "arabcacfr";
    int expected = 4;
    test(input, expected);
}

void test4()
{
    const std::string input = "aaaa";
    int expected = 1;
    test(input, expected);
}

void test5()
{
    const std::string input = "abcdefg";
    int expected = 7;
    test(input, expected);
}

void test6()
{
    const std::string input = "aaabbbccc";
    int expected = 2;
    test(input, expected);
}

void test7()
{
    const std::string input = "abcdcba";
    int expected = 4;
    test(input, expected);
}

void test8()
{
    const std::string input = "abcdaef";
    int expected = 6;
    test(input, expected);
}

void test9()
{
    const std::string input = "a";
    int expected = 1;
    test(input, expected);
}

void test10()
{
    const std::string input = "";
    int expected = 0;
    test(input, expected);
}

int main(int argc, char* argv[])
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();

    return 0;
}
