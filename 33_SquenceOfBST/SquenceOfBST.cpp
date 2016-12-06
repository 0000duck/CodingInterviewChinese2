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

// ������33�������������ĺ����������
// ��Ŀ������һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ����
// ������򷵻�true�����򷵻�false���������������������������ֶ�������ͬ��

#include <cstdio>

// BST��Binary Search Tree������������
bool VerifySquenceOfBST(int sequence[], int length)
{
    if(sequence == nullptr || length <= 0)
        return false;

    int root = sequence[length - 1];

    // �ڶ������������������Ľ��С�ڸ����
    int i = 0;
    for(; i < length - 1; ++ i)
    {
        if(sequence[i] > root)
            break;
    }

    // �ڶ������������������Ľ����ڸ����
    int j = i;
    for(; j < length - 1; ++ j)
    {
        if(sequence[j] < root)
            return false;
    }

    // �ж��������ǲ��Ƕ���������
    bool left = true;
    if(i > 0)
        left = VerifySquenceOfBST(sequence, i);

    // �ж��������ǲ��Ƕ���������
    bool right = true;
    if(i < length - 1)
        right = VerifySquenceOfBST(sequence + i, length - i - 1);

    return (left && right);
}

// ====================���Դ���====================
void Test(const char* testName, int sequence[], int length, bool expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(VerifySquenceOfBST(sequence, length) == expected)
        printf("passed.\n");
    else
        printf("failed.\n");
}

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
void Test1()
{
    int data[] = {4, 8, 6, 12, 16, 14, 10};
    Test("Test1", data, sizeof(data)/sizeof(int), true);
}

//           5
//          / \
//         4   7
//            /
//           6
void Test2()
{
    int data[] = {4, 6, 7, 5};
    Test("Test2", data, sizeof(data)/sizeof(int), true);
}

//               5
//              /
//             4
//            /
//           3
//          /
//         2
//        /
//       1
void Test3()
{
    int data[] = {1, 2, 3, 4, 5};
    Test("Test3", data, sizeof(data)/sizeof(int), true);
}

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
void Test4()
{
    int data[] = {5, 4, 3, 2, 1};
    Test("Test4", data, sizeof(data)/sizeof(int), true);
}

// ����ֻ��1�����
void Test5()
{
    int data[] = {5};
    Test("Test5", data, sizeof(data)/sizeof(int), true);
}

void Test6()
{
    int data[] = {7, 4, 6, 5};
    Test("Test6", data, sizeof(data)/sizeof(int), false);
}

void Test7()
{
    int data[] = {4, 6, 12, 8, 16, 14, 10};
    Test("Test7", data, sizeof(data)/sizeof(int), false);
}

void Test8()
{
    Test("Test8", nullptr, 0, false);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();

    return 0;
}

