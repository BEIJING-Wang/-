#include <stdio.h>
#include "seqList.h"

int main()
{
    SeqList *table = createSeqList(10);
    if(table == NULL)
    {
        return -1;
    }

    //进行数据插入、删除、查看
    for(int i = 0;i < 5;i++)
    {
        pushBackSeq(table,100+i);
    }
    showSeqList(table);
    releaseSeqList(table);

    return 0;
}
