/*
@File     :   poly_calculation.cpp
@Time     :   2020/03/19 15:56:01
@Contact  :   levarz@163.com 
@Desc     :   ����ʽ�ļӷ��ͳ˷�����
*/
#include <iostream>
#include <stdlib.h>

using namespace std;
//����ʽ�ṹ��
typedef struct Node
{
    int exp;              //ָ��
    int coef;             //ϵ��
    struct Node *next;
}*Poly;
/**
 * @brief ��ʼ��һ�����
 * 
 * @param node ��Ҫ��ʼ���Ľ��ָ��
 */
void initNode(Node *&node);
/**
 * @brief ����ʽ�Ӷ���ʽ������һ������������
 * 
 * @param node ����ʽָ��
 * @param poly ����ʽָ��
 */
void insert(Node *node,const Poly &poly);
/**
 * @brief ����һ������ʽ����
 * 
 * @param A ����ʽA
 * @return Poly ���ƽ��
 */
Poly copy(const Poly A);
/**
 * @brief ��ʼ��һ������ʽ��������ϵ����ָ�����Կո������0 0 �����������
 * 
 * @param head ����ʽͷָ��
 */
void initPolynomial(Poly &head);
/**
 * @brief �������ʽA��B
 * 
 * @param A ����ʽA
 * @param B ����ʽB
 * @return Poly ������
 */
Poly add(const Poly A, const Poly B);
/**
 * @brief �������ʽA��B
 * 
 * @param A ����ʽA
 * @param B ����ʽB
 * @return Poly ������
 */
Poly mul(const Poly A, const Poly B);
/**
 * @brief ���㵥��ʽA�˶���ʽB����������ʽ�˷�����
 * 
 * @param A ����ʽA
 * @param B ����ʽB
 * @return Poly ������
 */
Poly mul_base(const Poly A, const Poly B);
/**
 * @brief ��ӡ����ʽ
 * 
 * @param A ����ʽA
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
        if (poly->coef>0) {                                     //������ʾ����
            if (f==1) {                                         //����ʽ�ײ�����"+"
                if(poly->coef!=1) cout <<poly->coef;            //ϵ����Ϊ1ʱͷ����ʾ                                   
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
