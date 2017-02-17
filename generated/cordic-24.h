//Cordic in 24 bit signed fixed point math
//Function is valid for arguments in range -pi/2 -- pi/2
//for values pi/2--pi: value = half_pi-(theta-half_pi) and similarly for values -pi---pi/2
//
// 1.0 = 4194304
// 1/k = 0.6072529350088812561694
// pi = 3.1415926536897932384626
//Constants
#define cordic_1K 0x0026DD3B
#define half_pi 0x006487ED
#define MUL 4194304.000000
#define CORDIC_NTAB 24
int cordic_ctab [] = {0x003243F6, 0x001DAC67, 0x000FADBA, 0x0007F56E, 0x0003FEAB, 0x0001FFD5, 0x0000FFFA, 0x00007FFF, 0x00003FFF, 0x00001FFF, 0x00000FFF, 0x000007FF, 0x000003FF, 0x000001FF, 0x000000FF, 0x0000007F, 0x0000003F, 0x0000001F, 0x0000000F, 0x00000007, 0x00000003, 0x00000001, 0x00000000, 0x00000000, };

void cordic(int theta, int *s, int *c, int n)
{
  int k, d, tx, ty, tz;
  int x=cordic_1K,y=0,z=theta;
  n = (n>CORDIC_NTAB) ? CORDIC_NTAB : n;
  for (k=0; k<n; ++k)
  {
    d = z>>23;
    //get sign. for other architectures, you might want to use the more portable version
    //d = z>=0 ? 0 : -1;
    tx = x - (((y>>k) ^ d) - d);
    ty = y + (((x>>k) ^ d) - d);
    tz = z - ((cordic_ctab[k] ^ d) - d);
    x = tx; y = ty; z = tz;
  }  
 *c = x; *s = y;
}
