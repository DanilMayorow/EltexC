#include <stdio.h>

int main(void)
{
  int a = 0x00CCAABB;
  unsigned char c;
  printf("%x - текущее значение a\n", a);
  for (int i; i<4; i++)
  {
    c = (a >> i*8) & 0xFF;
    printf("%d-й байт: %x\n",i+1, c);
  }
  a |= 0x00DD0000; //Вариант через "ИЛИ" с 0х00DD00
  printf("%x - новое значение a\n", a);
  return 0;
}
