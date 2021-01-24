#include <iostream>
using namespace std;
const int N=1024; // ������ ������� 

struct Queue
{	
	int data[N]; // ������ ������
	int last; // ��������� �� ������
};

void Creation(Queue *Q){ // �������� �������
 Q->last=0; 
 
}

bool Full(Queue *Q){ // �������� ������� �� �������

if (Q->last==0) return true;
else return false;

}

void Add(Queue *Q){ // ���������� ��������

if (Q->last==N){ 

cout<<"������� ���������"<<endl;
return;

}

int value;
cout<<"�������� ";
cin>>value;
Q->data[Q->last++]=value;
cout<<endl<<"������� �������� � �������"<<endl;
}

void Delete(Queue *Q){ //�������� ��������

for (int i=0; i<Q->last && i<N; i++) //�������� ���������
Q->data[i]=Q->data[i+1]; Q->last--;

}

int Top(Queue *Q){ //����� ���������� ��������

 return Q->data[0];
 
}
int Size(Queue *Q){ //������ �������

 return Q->last;
}

int main(){ //������� �������

setlocale(LC_ALL,"Rus");
Queue Q;
Creation(&Q);
char number;
do{

cout<<"1. �������� �������"<<endl;
cout<<"2. �������� �������"<<endl;
cout<<"3. ������� ������� �������"<<endl;
cout<<"4. ������ �������"<<endl;
cout<<"0. �����\n\n";
cout<<"����� ������� "; cin>>number;
switch (number)
{
case '1': Add(&Q);
break;

case '2':
if (Full(&Q))
cout<<endl<<"������� �����"<<endl;
else
{
Delete(&Q);
cout<<endl<<"������� ������ �� �������"<<endl;
} break;

case '3':
if (Full(&Q)) cout<<endl<<"������� �����"<<endl;
else cout<<"��������� �������: "<<Top(&Q)<<""<<endl;
break;

case '4':
if (Full(&Q)) cout<<endl<<"������� �����"<<endl;
else cout<<"������ �������: "<<Size(&Q)<<""<<endl;
break;

case '0': break;
default: cout<<endl<<"������� �� ����������"<<endl;
break;
}
} while(number!='0');
system("pause");
}
