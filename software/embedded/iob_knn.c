#include "interconnect.h"
#include "iob_knn.h"
#include "KNNsw_reg.h"

static int base;

void knn_reset(){
  IO_SET(base, KNN_RESET, 1);
  IO_SET(base, KNN_RESET, 0);
}


void knn_init(int base_address){
  base = base_address;
  knn_reset();
}
