#include <stdlib.h>
#include <stdio.h>
#include "seqList.h"

//申请表头和数据区域
SeqList *createSeqList(int n)
{
    SeqList *seqList;
    //申请表头
    seqList = (SeqList *)malloc(sizeof(SeqList));

    if(seqList == NULL)
    {
        printf("申请失败!\n");
        return NULL;
    }

    //初始化表头的每个成员

    seqList->data = (Element *)malloc(sizeof(Element)*n);
    seqList->len = 0;//待插入的位置
    seqList->capacity = n; //0到n-1

    return seqList;
}

//释放表
void releaseSeqList(SeqList *seq)
{
    if(seq)//指针非空
    {
        if(seq->data)
        {
            free(seq->data);
        }
        free(seq);
    }
}

//扩容方法，设置为静态方法
static int enLarger(SeqList *seq)
{
    //1.先申请更大的空间,建议为原空间的两倍
    Element *tmp = (Element *)malloc(sizeof(Element) * seq->capacity * 2);
    if(tmp == NULL)
    {
        return -1;
    }
    //2.原空间拷贝到新空间
    for(int i = 0;i < seq->len;i++)//此时len和capacity是一样的
    {
        tmp[i] = seq->data[i];
    }
    //3.释放原空间，更新表头的指针指向新空间
    free(seq->data);
    seq->data = tmp;
    seq->capacity *= 2;
    return 0;
}

//尾插法
int pushBackSeq(SeqList *seq,Element val)
{
    //判断是否溢出，溢出则要扩容
    if(seq->len >= seq->capacity && enLarger(seq))
    {
        return -1;
    }

    //放入新元素
    seq->data[seq->len] = val;
    ++seq->len;

    return 0;
}

//显示数据
void showSeqList(SeqList *seq)
{
    for(int i = 0;i < seq->len;i++)
    {
        printf("%d\t",seq->data[i]);
    }
    printf("\n");

}

/*下标的索引值的取值范围有从1开始，也有从0开始，这里从0开始*/
int insertSeq(SeqList *seq, int pos ,Element val)
{
    //1.范围校验
    if(pos < 0 || pos > seq->len)
    {
        printf("pos invalid!\n");
        return -1;
    }
    //2.是否扩容
    if(seq->len >= seq->capacity && enLarger(seq))
    {
        return -1;
    }

    //3.从后往前，依次向右移动
    for(int i = seq->len-1; i >= pos;i--)
    {
        seq->data[i+1] = seq->data[i];
    }

    //4.放新元素,更新表头
    seq->data[pos] = val;
    ++seq->len;

    return 0;
}

int deleteSeq(SeqList *seq,Element val)
{
    //1.找到val所在的下标索引值
    int pos = findSeq(seq,val);
    if(pos == -1){
        return -1;
    }
    //2.删除（覆盖）这个下标的值
    for(int i = pos + 1;i < seq->len;i++)
    {
        seq->data[i - 1] = seq->data[i];
    }
    --seq->len;
    return 0;
}

//找到第一个查找值所在位置。就返回;没有就返回-1
int findSeq(SeqList *seq,Element val)
{
    for(int i = 0;i < seq->len ;i++)
    {
        if(seq->data[i] == val) {
            return i;
        }
    }
    return -1;
}