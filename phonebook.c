#include <stdio.h>
#include <string.h>
//Константы
#define N 10

//Структуры
struct Phone
{
  char name[22];
  long int number;
};

//Собственное наименование типов
typedef struct Phone Phone;

//Прототипы функций
int Menu(void);
void AddPhone(Phone[N], unsigned char);
void Show(Phone[N], unsigned char);
void FindAcc(Phone[N]);
char CrossOut(Phone[N], unsigned char);

//Основная программа
int main(void)
{
  unsigned char count_acc = 0;
  Phone phonebook[N];
  unsigned char act;

  do{
    act = Menu();
    switch(act)
    {
      case 1:
        if (count_acc == N) {printf("Список абонентов полон\n");}
        else {
          AddPhone(phonebook, count_acc);
          count_acc++;
        }
        break;
      case 2: Show(phonebook, count_acc); break;
      case 3: FindAcc(phonebook); break;
      case 4:
        if (count_acc == 0) {printf("Список абонентов пуст\n");}
        else {
          (CrossOut(phonebook, count_acc)==1) ? count_acc-- : printf("Нет такой позиции\n");
        }
        break;
      default: printf("\n***Good Bye!***\n");
    }
  }while(act != 0);
  return 0;
}

//Функция отображения меню
int Menu(void)
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
void AddPhone(Phone book[N], unsigned char lim)
{
  char new_name[22];
  long int new_num;

  printf("Введите имя абонента:\n");
  scanf("%s",&new_name);
  printf("Введите телефон(10-зн) абонента:\n");
  scanf("%ld",&new_num);
  printf("==========\n"
  "Абонент добавлен\n");
  memcpy(book[lim].name, new_name, 22);
  book[lim].number = new_num;
}

//
void Show(Phone book[N], unsigned char lim)
{
  printf("==========\n");
  if (lim == 0) {printf("Список абонентов пуст\n");}
  else {
    for (unsigned char i = 0; i < lim; i++)
    {
      printf("%d.) %s - %ld\n", i+1, book[i].name, book[i].number);
    }
  }
  printf("==========\n");
}

//
void FindAcc(Phone book[N])
{
  long int key;
  char flag=0;
  printf("==========\n");
  printf("Введите номер для поиска:\n");
  scanf("%ld",&key);

  for (int i = 0; i < N; i++)
  {
    if (book[i].number == key) { flag = i; break;}
  }
  (flag == 0) ? printf("Данный абонент не обнаружен!\n") :
  printf("%s - %ld\n", book[flag].name, book[flag].number);
  printf("==========\n");
}

//
char CrossOut(Phone book[N], unsigned char lim)
{
  int pos;
  printf("==========\n");
  printf("Какого абонента убираем?\n:");
  scanf("%d",&pos);

  if (pos < 1 || pos  > lim) { return -1;}
  else {
    for (int i=pos-1; i<lim-1;i++)
    {
      memcpy(book[i].name, book[i+1].name, 22);
      book[i].number = book[i+1].number;
    }
    memcpy(book[lim-1].name, "", 22);
    book[lim-1].number = 0;
    return 1;
  }
  printf("\nАбонент удалён\n==========\n");
}
