#include <stdio.h>

int main(void)
{
  int a = 0x11CCAABB; //Меняю переменную чтоб наглядней было
  char *pt; //Меняем переменную на указатель
  pt = &a; //Инициализируем указатель на начало переменной 'a'
  printf("%x - текущее значение a\n", a);
  for (int i=0; i<4; i++, pt++)
  {
    printf("%d-й байт: %x\n",i+1, *pt&0xFF); //Выводим текущий байт
    if (i == 2) {*pt = 0xDD;} //Попадаем на нужный байт - меняем значение
  }
  printf("%x - новое значение a\n", a);
  return 0;
}
