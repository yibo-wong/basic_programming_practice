#include<iostream>  
#include<map>  
#include<string>  
using namespace std;
map<string, int> ctoi; //ͨ��map��֤�ֵ���ĵص�����  
map<int, string> itoc;// 
int p, q, r;
#define maxn 40  
#define infi 10000;  
class dist
{
public:
    int len;
    int pre;
};
dist D[maxn][maxn];
void output(int s, int e) // print recursively  
{
    if (s == e)
    {
        cout << itoc[s];
        return;
    }
    output(s, D[s][e].pre);
    cout << "->" << '(' << D[D[s][e].pre][e].len << ')' << "->" << itoc[e];
}
int main()
{
    string temp;
    cin >> p;
    for (int i = 0; i < p; ++i)
    {
        cin >> temp;
        ctoi.insert(pair<string,int>(temp,i));
        itoc.insert(pair<int, string>(i,temp));
    } //����˵ص������
    for(int i=0;i<p;++i)
        for (int j = 0; j < p; ++j)
        {
            if (i == j)
            {
                D[i][j].len = 0;
                D[i][j].pre = i;
            }
            else
            {
                D[i][j].len = infi;
                D[i][j].pre = -1;
            }
        }//��ʼ��dist����
    cin >> q; 
    string t1, t2; int lt;
    for (int i = 0; i < q; ++i)
    {
        cin >> t1 >> t2 >> lt;
        if (lt < D[ctoi[t1]][ctoi[t2]].len)
        {
            D[ctoi[t1]][ctoi[t2]].len = lt;
            D[ctoi[t1]][ctoi[t2]].pre = ctoi[t1];
            D[ctoi[t2]][ctoi[t1]].len = lt;
            D[ctoi[t2]][ctoi[t1]].pre = ctoi[t2];

        }
    }//�����ͼ�ı�
    for(int v=0;v<p;++v) //Floyd�㷨��v�Ǳ�ʾ���·�Ƿ񾭹��ڵ�v
        for(int i=0;i<p;++i) //i,j������յ��
            for (int j = 0; j < p; ++j)
            {
                if (D[i][v].len + D[v][j].len < D[i][j].len)
                {
                    D[i][j].len = D[i][v].len + D[v][j].len;
                    D[i][j].pre = D[v][j].pre;
                }
            }
    cin >> r;//������ɰ�Ҫ�����
    for (int i = 0; i < r; ++i)
    {
        cin >> t1 >> t2;
        output(ctoi[t1], ctoi[t2]);
        cout << endl;
    }
    //system("pause");
    return 0;
}
