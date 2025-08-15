#define SUM(X,Y)  X=X+Y
#define SET_BIT(Register,BIT_NUM)     (Register|=1<<BIT_NUM)
#define CLR_BIT(Register, BIT_NUM)    ((Register) &= ~(1 << (BIT_NUM)))
#define TOG_BIT(Register,BIT_NUM)     ((Register) ^= (1 << (BIT_NUM)))
#define GET_BIT(Register,BIT_NUM)      (((Register) >> (BIT_NUM)) & 1)
