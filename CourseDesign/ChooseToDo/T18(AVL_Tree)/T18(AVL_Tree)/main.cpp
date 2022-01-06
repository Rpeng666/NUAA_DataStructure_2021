#include<iostream>
#include<iomanip>
#include<fstream>

using namespace std;

typedef int DataType;  //���ؼ������������
#define StackSize 40       //Ԥ����ջ��С
typedef struct node
{
	DataType data;      //��������ֵ
	int bf;             //ƽ������
	struct node* lchild, * rchild;     //ָ�����Һ��ӽ���ָ��
}AVLNode, * AVLTree;

void Rotate_LL(AVLTree& ptr);
void Rotate_RR(AVLTree& ptr);
void Rotate_LR(AVLTree& ptr);
void Rotate_RL(AVLTree& ptr);
AVLTree CreatAVLTree(int n,fstream& file);    //��������n�Ľ���AVL��
AVLTree AVLSearch(AVLTree ptr, DataType x);   //����ptrΪ����AVL���в���Ԫ��x
bool AVLInsert(AVLTree& ptr, DataType& x);   //����ptrΪ����AVL���в�����Ԫ��x��������򷵻�true�����򷵻�false
bool AVLRemove(AVLTree& ptr, DataType x);    //����ptrΪ����AVL����ɾ��Ԫ��x��ɾ�����򷵻�true�����򷵻�false
void ShowTree(AVLTree ptr);   //��������ʽ��ʾ��


int main()
{
	int n;

	cout << "##########AVL��������ʾ###########" << endl << endl;
	cout << "��ʼ��data.txt�ж������ݹ����ʼAVL��" << endl << endl;
	AVLTree ptr, p;

	fstream file("data.txt", ios::in);
	file >> n;
	cout << "AVL����ʼԪ�ظ�����" << n << endl << endl;

	ptr = CreatAVLTree(n,file);

	cout << "�����������£�" << endl;
	ShowTree(ptr);

	cout << endl << endl << "##########AVL��������ʾ###########" << endl << endl;

	int temp;
	file >> temp;
	while (temp--) {
		file >> n;
		cout << "���Բ���Ԫ�أ���" << n << "��" << endl;
		p = AVLSearch(ptr, n);

		if (p != NULL){
			cout << "���ҳɹ���Ԫ�� ��" << n << "�� ��AVL����" << endl << endl;
		}
		else{
			cout << "����ʧ�ܣ�Ԫ�� ��" << n << "�� ����AVL����" << endl << endl;
		}
	}
	
	cout << endl<<"##########AVL��������ʾ###########" << endl << endl;
	file >> temp;

	while (temp--) {

		file >> n;
		cout << "���Բ���Ԫ�ء�" << n << "��";
		if (AVLInsert(ptr, n))cout << "����ɹ���" << endl;
		
		cout << "��������Ϊ��" << endl;
		ShowTree(ptr);
		cout << endl << endl;
	}

	cout << endl << endl << "##########AVL��ɾ����ʾ###########" << endl << endl;

	file >> temp;

	while (temp--) {
		file >> n;
		cout << "����ɾ��Ԫ�ء�" << n << "��" << endl;
		AVLRemove(ptr, n);
		cout << endl << "ɾ�������Ϊ��" << endl;
		ShowTree(ptr);
		cout << endl << endl;
	}

	file.close();
	
	return 0;
}

//****************************************************************
bool AVLInsert(AVLTree& ptr, DataType& x)
{
	if (ptr == NULL) //��ǰAVL��Ϊ��
	{
		ptr = (AVLTree)malloc(sizeof(AVLNode));  //�����½��
		if (!ptr)
		{
			cout << "�ռ����ʧ��";
			exit(0);
		}
		ptr->data = x;
		ptr->lchild = NULL;
		ptr->rchild = NULL;
		ptr->bf = 0;
		return true;
	}
	AVLTree pr = NULL, p = ptr, q;
	int d;
	AVLTree S[StackSize];
	int top = -1;   //ջ��ָ��
	S[++top] = NULL;
	while (p != NULL)   //Ѱ�Ҳ���λ��
	{
		if (x == p->data)   //�����ҵ�x��������
		{
			cout << "Ԫ��" << x << "��������" << endl;
			return false;
		}
		S[++top] = p;     //������ջ��¼����·��
		p = (x < p->data) ? p->lchild : p->rchild;   //���²��������
	}

	p = (AVLTree)malloc(sizeof(AVLNode));     //�����½��
	if (!p)
	{
		cout << "�ռ����ʧ��";
		exit(0);
	}
	p->data = x;
	p->bf = 0;
	p->lchild = NULL;
	p->rchild = NULL;

	if (S[top] == NULL)   //�������½ڵ��Ϊ��
	{
		ptr = p;
	}
	else if (x < S[top]->data)   //�½����뵽˫����
	{
		S[top]->lchild = p;
	}
	else
	{
		S[top]->rchild = p;
	}

	while (top > 0)   //����ƽ�⻯
	{
		pr = S[top--];    //��ջ���˳�˫�׽��
		if (p == pr->lchild)
		{
			pr->bf++;     //����˫�׵�ƽ������
		}
		else
		{
			pr->bf--;
		}

		if (pr->bf == 0)   //����1��ֱ��ƽ���˳�
		{
			break;
		}
		if (pr->bf == 1 || pr->bf == -1)   //����2��|bf| = 1
		{
			p = pr;
		}
		else                             //����3��|bf| = 2
		{
			d = (pr->bf < 0) ? -1 : 1;      //����˫��ת��־
			if (p->bf == d)
			{ //�����bfͬ�ţ�����ת
				if (d == 1)
				{
					Rotate_LL(pr);     //LL����ת
				}
				else
				{
					Rotate_RR(pr);  //RR����ת
				}
			}
			else
			{
				if (d == 1)
				{
					Rotate_LR(pr);     //LR˫��ת
				}
				else
				{
					Rotate_RL(pr);     //RL˫��ת
				}
			}
			break;
		}
	}
	if (top == 0)
	{
		ptr = pr;   //���ڵ�
	}
	else   //�м���������
	{
		q = S[top--];
		if (q->data > pr->data)
		{
			q->lchild = pr;
		}
		else
		{
			q->rchild = pr;
		}
	}
	return true;
}
//****************************************************************
void Rotate_LL(AVLTree& ptr)
{
	AVLTree subR = ptr;     //Ҫ����ת�Ľ��
	ptr = subR->lchild;     //ж��ptr�ұߵĸ���
	subR->lchild = ptr->rchild;  //ж��ptr�ұߵĸ���
	ptr->rchild = subR;          //�ҵ�����ptr��Ϊ�¸�
	ptr->bf = 0;
	subR->bf = 0;
}
//****************************************************************
void Rotate_RR(AVLTree& ptr)
{
	AVLTree subL = ptr;
	ptr = subL->rchild;
	subL->rchild = ptr->lchild;     //ж��ptr��ߵĸ���
	ptr->lchild = subL;
	ptr->bf = 0;           //������ptr��Ϊ�¸�
	subL->bf = 0;
}
//****************************************************************
void Rotate_LR(AVLTree& ptr)
{
	AVLTree subR = ptr, subL = subR->lchild;
	ptr = subL->rchild;
	subL->rchild = ptr->lchild;
	ptr->lchild = subL;   //ж��ptr��ߵĸ���
	subR->lchild = ptr->rchild;
	ptr->rchild = subR;   //ж��ptr�ұߵĸ���
	if (ptr->bf == 1)  //ԭptr��������
	{
		subL->bf = 0;
		subR->bf = -1;
	}
	else if (ptr->bf == -1)  //ԭptr��������
	{
		subL->bf = 1;
		subR->bf = 0;
	}
	else   //ԭptr������ͬ��
	{
		subL->bf = 0;
		subR->bf = 0;
	}
	ptr->bf = 0;
}
//****************************************************************
void Rotate_RL(AVLTree& ptr)
{
	AVLTree subL = ptr, subR = subL->rchild;
	ptr = subR->lchild;     //ptr��Ϊ�¸�
	subR->lchild = ptr->rchild;
	ptr->rchild = subR;    //ж��ptr�ұߵĸ���
	subL->rchild = ptr->lchild;
	ptr->lchild = subL;    //ж��ptr��ߵĸ���
	if (ptr->bf == 1)   //ԭptr����������
	{
		subL->bf = 0;
		subR->bf = -1;
	}
	else if (ptr->bf == -1)  //ԭPtr��������
	{
		subL->bf = 1;
		subR->bf = 0;
	}
	else   //ͬ��
	{
		subL->bf = 0;
		subR->bf = 0;
	}
	ptr->bf = 0;
}
//****************************************************************
bool AVLRemove(AVLTree& ptr, DataType x)
{
	AVLTree pr = NULL, p = ptr, q, gr = NULL;
	int d, dd = 0;
	AVLTree S[StackSize];
	int top = -1;
	while (p != NULL)   //Ѱ�ұ�ɾ�����
	{
		if (x == p->data)    //�ҵ���ֹͣ����
		{
			break;
		}
		//������ջ��¼����·��
		pr = p;
		S[++top] = pr;
		p = (x < p->data) ? p->lchild : p->rchild;
	}
	if (p == NULL)
	{
		cout << "δ�ҵ�Ԫ��Ϊ" << x << "�Ľ��" << endl;
		return false;
	}
	if (p->lchild != NULL && p->rchild != NULL)
	{
		pr = p;
		S[++top] = pr;    //��ɾ�������������
		q = p->lchild;    //��p����������p��ֱ��ǰ��
		while (q->rchild != NULL)
		{
			pr = q;
			S[++top] = pr;
			q = q->rchild;
		}
		p->data = q->data;    //��q��ֵ�p
		p = q;   //��ɾ���ת��Ϊq
	}

	if (p->lchild != NULL)
	{
		q = p->lchild;      //��ɾ���pֻ��һ������q
	}
	else
	{
		q = p->rchild;
	}
	if (pr == NULL)
	{
		ptr = q;     //��ɾ���Ϊ�����
	}
	else
	{
		if (pr->lchild == p)
		{
			pr->lchild = q;    //����
		}
		else
		{
			pr->rchild = q;
		}
	}
	while (top > -1)      //����ƽ�⻯
	{
		pr = S[top--];    //��ջ���˳�˫�׽��pr
		if (pr->lchild == q)   //����pr��ƽ������
		{
			pr->bf--;
		}
		else
		{
			pr->bf++;
		}
		if (top > -1)
		{
			gr = S[top];     //��ջ��ȡ���游���gr
			dd = (gr->lchild == pr) ? 1 : -1;    //��ת�����ϲ�����
		}
		else
		{
			dd = 0;    //ջ�գ���ת�����ϲ�����
		}
		if (pr->bf == 1 || pr->bf == -1)   //δʧȥƽ�⣬���ٵ���
		{
			break;
		}
		if (pr->bf != 0)   //  |bf| = 2,ʧȥƽ��
		{
			if (pr->bf == 2)    //���
			{
				d = 1;
				q = pr->lchild;
			}
			else             //�Ҹ�
			{
				d = -1;
				q = pr->rchild;
			}
			if (q->bf == 0)          //pr�ϸ�����q��bfΪ0
			{
				if (d == 1)
				{
					Rotate_LL(pr);
					pr->bf = -1;
					pr->rchild->bf = 1;
				}
				else
				{
					Rotate_RR(pr);
					pr->bf = 1;
					pr->lchild->bf = -1;
				}
				break;
			}
			if (q->bf == d)      //������ƽ������ͬ��
			{
				if (d == 1)
				{
					Rotate_LL(pr);   //LL����ת
				}
				else
				{
					Rotate_RR(pr);   //RR����ת
				}
			}
			else                //������ƽ���������
			{
				if (d == 1)
				{
					Rotate_LR(pr);      //LR˫��ת
				}
				else
				{
					Rotate_RL(pr);    //RL˫��ת
				}
			}
			if (dd == 1)
			{
				gr->lchild = pr;
			}
			else if (dd == -1)
			{
				gr->rchild = pr;              //��ת���¸����ϲ�����
			}
		}
		q = pr;
	}
	if (top == -1)
	{
		ptr = pr;     //���������ĸ��ڵ�
	}
	free(p);
	return true;
}
//****************************************************************
AVLTree AVLSearch(AVLTree ptr, DataType x)
{
	if (!ptr)
	{
		return NULL;  //���Ҳ��ɹ�
	}
	else if (ptr->data == x)
	{
		return ptr;
	}
	else if (ptr->data < x)
	{
		return AVLSearch(ptr->rchild, x);
	}
	else
	{
		return AVLSearch(ptr->lchild, x);
	}
}
//****************************************************************
AVLTree CreatAVLTree(int n, fstream& file)
{
	AVLTree T = NULL;    //��ʾҪ���������ĸ��ڵ�
	DataType key;
	int i;
	cout << "��������AVL����Ԫ��:" << endl;
	for (i = 0; i < n; i++)
	{
		file >> key;
		cout << "���Բ���Ԫ�ء�" << key << "��   ";
		if (AVLInsert(T, key))cout << "����ɹ���" << endl;
	}
	cout << endl;
	return T;
}
//****************************************************************
void ShowTree(AVLTree ptr)    //�����ŵ���ʽ��ʾ������
{
	AVLTree p;
	if (ptr)
	{
		cout << ptr->data;   //��ӡ���ڵ�
		if (ptr->lchild || ptr->rchild)
		{
			cout << "(";
			if (ptr->lchild)
			{
				ShowTree(ptr->lchild);
			}
			cout << ",";
			if (ptr->rchild)
			{
				ShowTree(ptr->rchild);
			}
			cout << ")";
		}
	}
}
//****************************************************************