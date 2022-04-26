#include <stdio.h>
#include <string.h>
//Константы
#define N 10

//Структуры
struct phone
{
  char Name[22];
  long int Number;
};

//Собственное наименование типов
typedef struct phone phone;

//Прототипы функций
int menu(void);
void add_phone(phone[N], unsigned char);
void show(phone[N], unsigned char);
void find_acc(phone[N]);
char cross_out(phone[N], unsigned char);

//Основная программа
int main(void)
{
  unsigned char count_acc = 0;
  phone Phonebook[N];
  unsigned char act;

  do{
    act = menu();
    switch(act)
    {
      case 1:
        if (count_acc == N) {printf("Список абонентов полон\n");}
        else {
          add_phone(Phonebook, count_acc);
          count_acc++;
        }
        break;
      case 2: show(Phonebook, count_acc); break;
      case 3: find_acc(Phonebook); break;
      case 4:
        if (count_acc == 0) {printf("Список абонентов пуст\n");}
        else {
          (cross_out(Phonebook, count_acc)==1) ? count_acc-- : printf("Нет такой позиции\n");
        }
        break;
      default: printf("\n***Good Bye!***\n");
    }
  }while(act != 0);
  return 0;
}

//Функция отображения меню
int menu(void)
{
  int option;
  printf("\nКакое действие выполняем:\n"
  "1.Добавить абонента\n"
  "2.Вывести список абонентов\n"
  "3.Найти абонента\n"
  "4.Удалить абонента\n"
  "*.Прекратить программу\n"
  "______________________\n:");
  scanf("%d", &option);

  //Выводим или варианты дейстий или прекращение программы
  option = (option >= 1 && option <=4) ? option : 0;
  return option;
}

//
void add_phone(phone Book[N], unsigned char Lim)
{
  char New_Name[22];
  long int New_Num;

  printf("Введите имя абонента:\n");
  scanf("%s",&New_Name);
  printf("Введите телефон(10-зн) абонента:\n");
  scanf("%ld",&New_Num);
  printf("==========\n"
  "Абонент добавлен\n");
  memcpy(Book[Lim].Name, New_Name, 22);
  Book[Lim].Number = New_Num;
}

//
void show(phone Book[N], unsigned char Lim)
{
  printf("==========\n");
  if (Lim == 0) {printf("Список абонентов пуст\n");}
  else {
    for (unsigned char i = 0; i < Lim; i++)
    {
      printf("%d.) %s - %ld\n", i+1, Book[i].Name, Book[i].Number);
    }
  }
  printf("==========\n");
}

//
void find_acc(phone Book[N])
{
  long int key;
  char flag=0;
  printf("==========\n");
  printf("Введите номер для поиска:\n");
  scanf("%ld",&key);

  for (int i = 0; i < N; i++)
  {
    if (Book[i].Number == key) { flag = i; break;}
  }
  (flag == 0) ? printf("Данный абонент не обнаружен!\n") :
  printf("%s - %ld\n", Book[flag].Name, Book[flag].Number);
  printf("==========\n");
}

//
char cross_out(phone Book[N], unsigned char Lim)
{
  int pos;
  printf("==========\n");
  printf("Какого абонента убираем?\n:");
  scanf("%d",&pos);

  if (pos < 1 || pos  > Lim) { return -1;}
  else {
    for (int i=pos-1; i<Lim-1;i++)
    {
      memcpy(Book[i].Name, Book[i+1].Name, 22);
      Book[i].Number = Book[i+1].Number;
    }
    memcpy(Book[Lim-1].Name, "", 22);
    Book[Lim-1].Number = 0;
    return 1;
  }
  printf("\nАбонент удалён\n==========\n");
}
