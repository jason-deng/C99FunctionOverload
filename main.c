#include <stdio.h>

void realCreate(int x, int y)
{
  printf("(%d, %d)\n", x, y);
}

#define CREATE_2(x, y) realCreate(x, y)
#define CREATE_1(x) CREATE_2(x, 0)
#define CREATE_0() CREATE_1(0)

#define FUNC_CHOOSER(_f1, _f2, _f3, ...) _f3
#define FUNC_RECOMPOSER(argsWithParentheses) FUNC_CHOOSER argsWithParentheses
#define CHOOSE_FROM_ARG_COUNT(...) FUNC_RECOMPOSER((__VA_ARGS__, CREATE_2, CREATE_1, ))
#define NO_ARG_EXPANDER() ,,CREATE_0
#define MACRO_CHOOSER(...) CHOOSE_FROM_ARG_COUNT(NO_ARG_EXPANDER __VA_ARGS__ ())
#define create(...) MACRO_CHOOSER(__VA_ARGS__)(__VA_ARGS__)

int main()
{
  create();
  create(10);
  create(20, 20);
  //create(30, 30, 30);  // Compilation error
  return 0;
}
