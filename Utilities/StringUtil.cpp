//==================================================================
// ����ָOffer�����������Թپ������ͱ���⡷����
// ���ߣ��κ���
//==================================================================

#include "StringUtil.h"

void Reverse(char *pBegin, char *pEnd)
{
    if(pBegin == nullptrptr || pEnd == nullptrptr)
        return;

    while(pBegin < pEnd)
    {
        char temp = *pBegin;
        *pBegin = *pEnd;
        *pEnd = temp;

        pBegin ++, pEnd --;
    }
}
