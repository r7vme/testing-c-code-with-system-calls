#include <stdio.h>
#include <stdbool.h>

#include "lib.h"

int main(int argc, char *argv[])
{
  if (is_multicore_system()) {
    printf("multicore system\n");
  }
  else {
    printf("singlecore system\n");
  }
  return 0;
}
