#include <stdio.h>

int v[200001], z, cnt, nrbaze, t[400][400];

void baza2(int x, int b);
int baza10(int x, int y, int m, int n);
void verif(int i, int j, int k);

int main(){
    int b, k = 0, m, n, a, x, y, c[500000], i, j, d, l, el, maxnrbaze = 0, linie[100], coloana[100], indl = 0, indc = 0,nrbm = 0;
    scanf("%d %d %d", &b, &m, &n);
    while(1){
        scanf("%d", &a);
        if(a != -1) {
                baza2(a, b);
        }else {
            break;
        }
    }
    printf("\n");
    while(1){
        scanf("%d %d", &x, &y);
        if(x == -1 && y == -1) break;
        if(y < x || y < 0 || x >= z) continue;
        if(x < 0) x = 0;
        if(y >= z) y = z - 1;
        if(y - x > 30) y = x + 30;
        c[k] = baza10(x, y, m, n);
        printf("%d ", c[k]);
        k++;
    }
    el = 0;
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            d = 0;
            for(l = 0; l < k; l++)
                if(c[l] == el) d = 1;
            if(d == 1) t[i][j] = 1;
            else t[i][j] = 0;
            el++;
        }
    }
    l = 1;
    for(i = 0;i < m;i++){
        for(j = 0;j < n;j++)
            if(t[i][j] == 1){
                l++;
                nrbaze = 0;
                verif(i, j, l);
                if(maxnrbaze == nrbaze){
                     indc++;
                     indl++;
                     linie[indl] = i;
                     coloana[indc] = j;
                     nrbm++;
                }
                if(maxnrbaze < nrbaze){
                        maxnrbaze = nrbaze;
                        indc=0;
                        indl=0;
                        linie[indl] = i;
                        coloana[indc] = j;
                        nrbm=1;
                }
            }
    }
    for(i = 0;i < nrbm; i++){
        printf("\n%d %d %d", linie[i], coloana[i], maxnrbaze);
    }
    return 0;
}

void baza2(int x, int b){
    char cif[33], i = 0;
    while(x >= 2){
        cif[i] = x % 2;
        i++;
        x /= 2;
    }
    cif[i] = x;
    for(; i >= 0; i--){
        if(cnt < b){
                v[z] = cif[i];
                cnt++;
                z++;
                printf("%d ", cif[i]);
        }else{
            cnt = 0;
            break;
       }
    }
    if(cnt == b) cnt = 0;
}

int baza10(int x, int y, int m, int n){
    int n10 = 0, p = 1, i = y;
    do{
        n10 = n10 + (v[i] % 10) * p;
        p = p * 2;
        i--;
    }while(i >= x);
    if(n10 > n * m) n10 = n10 % (m * n);
    return n10;
}
void verif(int i, int j, int k){
    if(t[i][j] == 1){
        t[i][j] = k;
        nrbaze++;
        verif(i-1, j, k);
        verif(i+1, j, k);
        verif(i, j-1, k);
        verif(i, j+1, k);
    }
}
