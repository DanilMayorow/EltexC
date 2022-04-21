#include <stdio.h>

#define N 6U

void print_a(int *);
void print_a2(int (*)[N]);

int main(void)
{
  int sqare_a[N][N];  //Квадратная матрица из Задания 1
  int backw_a[N];     //Инициализация для матрицы с обратным порядком
  int triag_a[N][N];  //Треугольник
  int snail_a[N][N];  //Улитка
  int temp;           //Буфер для перестановки значений массива

  //Заполним матрицы
  for(int i=0; i<N; i++)
  {
    backw_a[i] = i+1;
    for(int j=0; j<N; j++)
    {
      sqare_a[i][j] = i*N + j + 1;
      triag_a[i][j] = (j >= N-i-1) ? 1 : 0;
      snail_a[i][j] = 0;
    }
  }

  //Выводим квадратную матрицу
  printf("Матрица 1. Квадратная:\n");
  print_a2(sqare_a);

  //Честно разворачиваем вторую матрицу
  for (int k=0; k<N/2; k++)
  {
    temp = backw_a[k];
    backw_a[k] = backw_a[N-k-1];
    backw_a[N-k-1] = temp;
  }

  //Выводим вторую матрицу в реверсе
  printf("Матрица 2. Реверс:\n");
  print_a(backw_a);

  //Выводим матрицу с единицами ниже побочной диагонали
  printf("Матрица 3. Треугольная:\n");
  print_a2(triag_a);

  //Заполняем матрицу улитку
  int dX = 1, dY  = 0, cX = 0, cY = 0 , val = 1; //
  int count_t = 0, c_end = N, dir = 0;

  do{
    snail_a[cY][cX] = val;
    count_t = count_t + 1;

    // Проверяем упёрлись ли мы в границу
    if (count_t == c_end)
    {
      count_t = 0;
      //Меняем направление хода
      switch(dir)
      {
        case 0:
          dY = 1;
          dX = 0;
          dir = 1;
          c_end = c_end - 1;
          break;
        case 1:
          dY = 0;
          dX = -1;
          dir = 2;
          break;
        case 2:
          dY = -1;
          dX = 0;
          dir = 3;
          c_end = c_end - 1;
          break;
        default:
          dY = 0;
          dX = 1;
          dir = 0;
          break;
      }
    }

    cX += dX;
    cY += dY;
    val = val + 1;
  }while (val<N*N+1);

  //Выводим матрицу улитку
  printf("Матрица 4. Матрица-улитка:\n");
  print_a2(snail_a);

  return 0;
}

void print_a(int *a)
{
  for (int i=0; i<N; i++)
  {
    printf("%4d", a[i]);
  }
  printf("\n");
}

void print_a2(int (*a)[N])
{
  for (int i=0; i<N; i++)
  {
    for (int j=0; j<N; j++)
    {
      printf("%4d", a[i][j]);
    }
    printf("\n");
  }
}
