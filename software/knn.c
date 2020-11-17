#include "system.h"
#include "periphs.h"
#include <iob-uart.h>
#include "iob_timer.h"
#include "iob_knn.h"
#include "random.h" //random generator for bare metal
#include <stdint.h>


//uncomment to use rand from C lib
//#define cmwc_rand rand

#ifdef DEBUG //type make DEBUG=1 to print debug info
#define S 12  //random seed
#define N 8  //data set size
#define K 4   //number of neighbours (K)
#define C 4   //number data classes
#define M 2   //number samples to be classified
#else
#define S 12
#define N 1000
#define K 10
#define C 4
#define M 100
#endif

#define INFINITE ~0


int main()
{
  int32_t y = 0;
  int32_t x = 0;
  int32_t y_1 = 0;
  uint8_t i = 0;
  uint8_t n = 100;
  random_init(123);
  uart_printf("\n\n Low-pass filter the first 100 random signed numbers of the zero-average input x using equation y(n)=2*y(n-1)+x(n): \n\n");
  for (i = 1; i <= n; i = i +1) {
    x = cmwc_rand();
    y = 2*y_1 + x;
    uart_printf("%d ->\t%d\n", i, y);
    y_1 = y;
  }
  return y;
}
