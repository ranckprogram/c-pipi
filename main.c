#include <stdio.h>
#include <string.h>
#include <math.h>
#include "tool.h"

// 函数申明
int sum();
int sumN(int n);
void point();

struct People
{
  char name[30];
  int age;
};

void testStruct()
{

  struct People ranck;
  strcpy(ranck.name, "Telecom Billing");
  ranck.age = 10;
  printf("getName %s \n", ranck.name);
  printf("age %d\n", ranck.age);
}

void setName(struct People *p, char *name)
{
  strcpy(p->name, name);
}

int getPersonAge(struct People *p)
{
  return p->age;
}

char *getPersonName(struct People *p)
{
  return p->name;
}

void pointerStruce()
{
  printf("pointerStruce test=== \n");
  struct People ranck;

  printf("===pointe=== %d \n", &ranck);

  char a[] = "dddd";

  printf("===pointe a=== %d ,%s \n", &a, a);

  setName(&ranck, a);

  printf("getPersonName %s \n", getPersonName(&ranck));

  printf("getPersonAge %d", getPersonAge(&ranck));
}

float execute(float base, float offset, float rate, int time)
{
  float result = 0;
  result = base * pow((1 + rate), time) + offset * pow((1 + rate), time - 1) + offset * (time - 1);
  return result;
}

int main()
{
  // /* 我的第一个 C 程序 */
  // printf("Hello, World! \n");
  // int a = sum();
  // printf("Max value is : %d\n", a);
  // printf("num add : %d\n", sumN(10));

  // printf("num add : %d\n", sumN(10));

  // // printf("function import %d", test());

  // point();
  // testStruct();
  // pointerStruce();

  printf("result %f", execute(0, 10, 0, 10));
  return 0;
}

int sum()
{
  return 1;
}

int sumN(int n)
{
  int result = 0;
  for (int i = 0; i < n; i++)
  {
    result += i;
  }
  return result;
}

void point()
{
  int (*fn)(int n) = &sumN;
  printf("point num fn add : %d\n", fn(5));
}
