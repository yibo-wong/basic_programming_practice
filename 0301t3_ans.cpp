/*
@File     :   poly_calculation.cpp
@Time     :   2020/03/19 15:56:01
@Contact  :   levarz@163.com 
@Desc     :   多项式的加法和乘法计算
*/
#include <iostream>
#include <stdlib.h>

using namespace std;
//多项式结构体
typedef struct Node
{
    int exp;              //指数
    int coef;             //系数
    struct Node *next;
}*Poly;
/**
 * @brief 初始化一个结点
 * 
 * @param node 需要初始化的结点指针
 */
void initNode(Node *&node);
/**
 * @brief 单项式加多项式，看做一个结点插入链表
 * 
 * @param node 单项式指针
 * @param poly 多项式指针
 */
void insert(Node *node,const Poly &poly);
/**
 * @brief 复制一个多项式链表
 * 
 * @param A 多项式A
 * @return Poly 复制结果
 */
Poly copy(const Poly A);
/**
 * @brief 初始化一个多项式链表，输入系数，指数，以空格隔开，0 0 代表输入结束
 * 
 * @param head 多项式头指针
 */
void initPolynomial(Poly &head);
/**
 * @brief 计算多项式A加B
 * 
 * @param A 多项式A
 * @param B 多项式B
 * @return Poly 计算结果
 */
Poly add(const Poly A, const Poly B);
/**
 * @brief 计算多项式A乘B
 * 
 * @param A 多项式A
 * @param B 多项式B
 * @return Poly 计算结果
 */
Poly mul(const Poly A, const Poly B);
/**
 * @brief 计算单项式A乘多项式B，用作多项式乘法基础
 * 
 * @param A 单项式A
 * @param B 多项式B
 * @return Poly 计算结果
 */
Poly mul_base(const Poly A, const Poly B);
/**
 * @brief 打印多项式
 * 
 * @param A 多项式A
 */
void printPolynomial(const Poly &A);

int main(int argc, char const *argv[])
{
    Poly A, B;
    initPolynomial(A);
    initPolynomial(B);
    printPolynomial(add(A,B));
    printPolynomial(mul(A,B));
    //system("pause");
    return 0;
}
void initNode(Node *&node)
{
    node = (Node*)malloc(sizeof(Node));
    node ->next = NULL;
}
void initPolynomial(Poly &head)
{
    Poly node,head_;
    initNode(head);
    head_ = head;
    while (1) {
       initNode(node);
       cin >>node->coef >>node->exp;
       if (node->coef==0&&node->exp==0) return;
        head_->next = node;
        head_ = node;
    } 
}
void printPolynomial(const Poly &A)
{
    int f =1;
    for (Poly poly = A->next; poly; poly = poly->next, f++) {
        if (poly->coef>0) {                                     //正数显示规则
            if (f==1) {                                         //多项式首部不显"+"
                if(poly->coef!=1) cout <<poly->coef;            //系数不为1时头部显示                                   
            }else{
                if(poly->coef!=1||(poly->coef==1&&poly->exp==0)) cout <<"+" <<poly->coef;
            }
        } else {
            if (poly->coef!=-1||(poly->coef==-1&&poly->exp==0)) cout <<poly->coef;
            else cout <<"-";
        }
        if (poly->exp!=0) {
            if (poly->exp!=1) cout <<"x^" <<poly->exp;
            else cout <<"x";
        }
    }
    cout <<endl;
}
Poly add(const Poly A, const Poly B)
{
    Poly result = copy(A);
    for (Poly b=copy(B)->next;b;b=b->next) {
        insert(b,result);
    }  
    return result;
}
void insert(Poly node, const Poly &poly)
{
    Poly n, p;
    for (p = poly;p->next;p=p->next) {
        if (p->next->exp==node->exp) {
            p->next->coef+=node->coef;
            if (p->next->coef==0) p->next = p->next->next;
            return;  
        } 
        if ((p->next->exp)<(node->exp)) {
            initNode(n);
            n->coef = node->coef;
            n->exp = node->exp;
            n->next = p->next;
            p->next = n;
            return;
        } 
    }
    initNode(n);
    n->coef = node->coef;
    n->exp = node->exp;
    n->next = p->next;
    p->next = n;
    return;
}
Poly copy(const Poly A)
{
    Poly copy_A, node, head;
    initNode(copy_A);
    head = copy_A;
    for (Poly p = A->next;p;p=p->next) {
        initNode(node);
        node->coef = p->coef;
        node->exp = p->exp;
        head->next = node;
        head = node;
    }
    return copy_A;
}
Poly mul_base(const Poly A, const Poly B)
{
    Poly result = copy(B);
    for (Poly b =result ->next;b; b = b->next) {
        b->coef*=A->next->coef;
        b->exp+=A->next->exp;
    }
   return result; 
}
Poly mul(const Poly A, const Poly B)
{
    Poly tem;
    initNode(tem);
    for (Poly a = A;a->next;a=a->next) {
        tem=add(mul_base(a,B),tem);
    }
    return tem;
}
