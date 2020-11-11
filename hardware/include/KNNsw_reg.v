//START_TABLE sw_reg
`SWREG_W(KNN_RESET,          1, 0) //Timer soft reset
`SWREG_W(KNN_ENABLE,         1, 0) //Timer enable
`SWREG_W(KNN_DATA_IN, DATA_W, 0)//Data input register
`SWREG_R(KNN_DATA_OUT, DATA_W, 0)//Data output register
