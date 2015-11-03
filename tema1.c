#include <stdio.h>
#include <math.h>

#define Rp 6380.0

float distanta(float lat1, float lng1, float lat2, float lng2);
float calcx(float lat1, float lng1, float lat2, float lng2);

int main(){

    int n, i;
    float d1, d2, d, max = 0, min, blat, blng, lat, lng, auxlatmax, auxlngmax, auxlatmin, auxlngmin;

    scanf("%d", &n);
    scanf("%f %f", &d1, &d2);
    scanf("%f %f", &blat, &blng);
    scanf("%f %f", &lat, &lng);
    min = distanta(lat, lng, blat, blng);
    for(i = 1 ; i <= n ; i++){

        d=distanta(lat, lng, blat, blng);
        if (d<d1) printf("<%.4f, %.4f> VECIN\n", lat, lng);
            else if (d<d2) printf("<%.4f, %.4f> APROPIAT\n", lat, lng);
                else printf("<%.4f, %.4f> DEPARTAT\n", lat, lng);
        if (d > max) {
            max = d;
            auxlatmax = lat;
            auxlngmax = lng;
        }
        if (d < min){
            min = d;
            auxlatmin = lat;
            auxlngmin = lng;
        }
        scanf("%f %f", &lat, &lng);
    }

    printf("CEL MAI APROPIAT: <%.4f, %.4f> \n", auxlatmin, auxlngmin);
    printf("CEL MAI DEPARTAT: <%.4f, %.4f> \n", auxlatmax, auxlngmax);

return 0;
}

float distanta(float lat1, float lng1, float lat2, float lng2){
    return 2 * Rp * atan(sqrt(calcx(lat1, lng1, lat2, lng2) / (1 - calcx(lat1, lng1, lat2, lng2))));
}

float calcx(float lat1, float lng1, float lat2, float lng2){
    return pow(sin((lat1 - lat2) / 2), 2) + cos(lat1) * cos(lat2) * ((pow(sin((lng1 - lng2) / 2), 2)));
}
