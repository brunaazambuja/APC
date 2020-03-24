#include <stdio.h>
int main()
{
    int dn = 0, mn = 0, an = 0, dh = 0, mh = 0, ah = 0, total = 0;
    scanf("%d", &dn);
    while (dn < 1 || dn > 30){
        scanf("%d", &dn);
    }
    scanf("%d", &mn);
    while (mn < 1 || mn > 12){
        scanf("%d", &mn);
    }
    scanf("%d", &an);
    while (an <= 0 || an >= 2020){
        scanf("%d", &an);
    }
    scanf("%d", &dh);
    while (dh < 1 || dh > 30){
        scanf("%d", &dh);
    }
    scanf("%d", &mh);
    while (mh < 1 || mh > 12){
        scanf("%d", &mh);
    }
    scanf("%d", &ah);
    while (ah <= 0 || ah >= 2020 || ah <= an){
        scanf("%d", &ah);
    }
    total = (dh + ((mh-1)*30) + ((ah-1)*360)) - (dn + ((mn-1)*30) + ((an-1)*360));
    printf("%d\n", total);

return 0;
}