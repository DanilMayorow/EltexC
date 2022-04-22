#include <stdio.h>

int main(void)
{
  //Изначальные условия задачи
  char a='A';
  char *ptr1;
  char **ptr2;

  ptr1=&a;
  ptr2 = &ptr1;
  printf("Старые значения:\n");
  printf("ptr1 = %p\n", ptr1);
  printf("*ptr1 = %c\n", *ptr1);
  printf("&ptr1 = %p\n________\n", &ptr1);
  printf("ptr2 = %p\n", ptr2);
  printf("*ptr2 = %p\n", *ptr2);
  printf("**ptr2 = %c\n", **ptr2);
  printf("&ptr2 = %p\n", &ptr2);

  //Вводим новую переменную
  char b='B';
  //Меняем указатель
  (*ptr2)=&b;

  //Выводим результат
  printf("\nНовые значения:\n");
  printf("ptr1 = %p\n", ptr1);
  printf("*ptr1 = %c\n", *ptr1);
  printf("&ptr1 = %p\n________\n", &ptr1);
  printf("ptr2 = %p\n", ptr2);
  printf("*ptr2 = %p\n", *ptr2);
  printf("**ptr2 = %c\n", **ptr2);
  printf("&ptr2 = %p\n", &ptr2);

  return 0;
}
