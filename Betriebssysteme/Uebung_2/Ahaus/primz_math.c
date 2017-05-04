#include <math.h>

int ist_primzahl( int zahl){
    int teiler =2;
    
    while(teiler<=sqrt(zahl)){
        if(zahl%teiler==0)
            return 0;
        teiler++;
    }
    return 1;
}
