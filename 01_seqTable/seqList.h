#ifndef SEQ_LIST_H
#define SEQ_LIST_H

typedef int Element;//作用一：方便以后想再用的时候修改
                    //作用二：和int区分开，用Element定义的是数据，用int定义的是标识

//定义结构头，在这里是表头
typedef struct {
    Element *data;  //指向顺序表的数据区域
    int capacity;   //该区域的最大容量，超过该容量需要扩容
    int len;        //该区域能访问的边界条件,目前的容器内存储数据的数量,像一个坐标
}SeqList;

/*维护表头结构接口*/
//申请表头和表的数据区域
SeqList *createSeqList(int n);//返回空间的首地址
//释放表
void releaseSeqList(SeqList *seq);

/*维护表数据操作接口*/
//1.尾插法
int pushBackSeq(SeqList *seq,Element val);
//2.显示表内数据
void showSeqList(SeqList *seq);
//3.任意位置插入(不推荐使用的接口)
int insertSeq(SeqList *seqList, int pos ,Element val);
//4.删除指定值
int deleteSeq(SeqList *seqList,Element val);
//5.查找
int findSeq(SeqList *seqList,Element val);

#endif