#include <stdio.h>
#include <stdlib.h>

const int under50 = 500;
const int from50 = 700;
const int from100 = 900;

// Prototypes of functions will be call upon
float crystalTienDien(int soKWh);
int inputElectricityAmount(void);

int main(void)
{
    int soKWh = inputElectricityAmount();
    float soTienPhaiTra = crystalTienDien(soKWh);
    if (soTienPhaiTra != NULL)
    {
        printf("So tien dien phai tra laf %.3f VND\n", soTienPhaiTra);
        return 0;
    }
    printf("Co loi vui long bao lai voi nha phat trien phan mem\n");
}

float crystalTienDien(int soKWh)
{
    float tienDien = 0;
    if (soKWh <= 50)
    {
        tienDien = soKWh * under50;
        return tienDien;
    }
    else if (soKWh > 50 && soKWh <= 100)
    {
        tienDien = (50 * under50) + ((soKWh - 50) * from50);
        return tienDien;
    }
    else
    {
        tienDien = (50 * under50) + (49 * from50) + ((soKWh - 101) * from100);
        return tienDien;
    }
}

int inputElectricityAmount(void)
{
    int soKWh = 0;
    while (soKWh < 1)
    {
        printf("Hay nhap so dien: ");
        scanf("%d", &soKWh);
    }
    return soKWh;
}
