#include <iostream>
using namespace std;
const int N=1024; // размер очереди 

struct Queue
{	
	int data[N]; // массив данных
	int last; // указатель на начало
};

void Creation(Queue *Q){ // создание очереди
 Q->last=0; 
 
}

bool Full(Queue *Q){ // проверка очереди на пустоту

if (Q->last==0) return true;
else return false;

}

void Add(Queue *Q){ // добавление елемента

if (Q->last==N){ 

cout<<"Очередь заполнена"<<endl;
return;

}

int value;
cout<<"Значение ";
cin>>value;
Q->data[Q->last++]=value;
cout<<endl<<"Элемент добавлен в очередь"<<endl;
}

void Delete(Queue *Q){ //удаление элемента

for (int i=0; i<Q->last && i<N; i++) //смещение элементов
Q->data[i]=Q->data[i+1]; Q->last--;

}

int Top(Queue *Q){ //вывод начального элемента

 return Q->data[0];
 
}
int Size(Queue *Q){ //размер очереди

 return Q->last;
}

int main(){ //главная функция

setlocale(LC_ALL,"Rus");
Queue Q;
Creation(&Q);
char number;
do{

cout<<"1. добавить элемент"<<endl;
cout<<"2. удалитьт элемент"<<endl;
cout<<"3. Вывести верхний элемент"<<endl;
cout<<"4. размер очереди"<<endl;
cout<<"0. выйти\n\n";
cout<<"номер команды "; cin>>number;
switch (number)
{
case '1': Add(&Q);
break;

case '2':
if (Full(&Q))
cout<<endl<<"очередь пуста"<<endl;
else
{
Delete(&Q);
cout<<endl<<"элемент удален из очереди"<<endl;
} break;

case '3':
if (Full(&Q)) cout<<endl<<"очередь пуста"<<endl;
else cout<<"Начальный элемент: "<<Top(&Q)<<""<<endl;
break;

case '4':
if (Full(&Q)) cout<<endl<<"Очередь пуста"<<endl;
else cout<<"Размер очереди: "<<Size(&Q)<<""<<endl;
break;

case '0': break;
default: cout<<endl<<"Команда не определена"<<endl;
break;
}
} while(number!='0');
system("pause");
}
