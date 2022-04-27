#include <stdio.h>

struct TestA
{
  char a;
  int b;
};

struct TestB
{
  char a;
  int b;
}__attribute__((packed));

int main(void)
{
  char str[10] = {'A',0,0,0,0,'B',0,0,0,0};
  struct TestA *st1 = &str;
  struct TestB *st2 = &str;
  printf("stuct#1 - %c %d\n", st1->a, st1->b);
  printf("stuct#2 - %c %d\n", st2->a, st2->b);

  //Делаем сдвиг чтобы проверить смогут ли указатели вывести след. структуры
  st1 = st1 + 1;
  st2 = st2 + 1;
  printf("stuct#1 - %c %d\n", st1->a, st1->b);
  printf("stuct#2 - %c %d\n", st2->a, st2->b);

  return 0;
}
