// belajar pointer
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define total_Mobil 5
#define typeMobil 20
#define type_Caliper 10
#define type_syste_Rem 3

typedef enum gerakMobil
{
    Maju,
    Mundur,
    Berhenti
} gerakMobil;

typedef enum kondisiRadiator
{
    Dingin,
    Panas,
    Sedang
} radiator;

typedef enum Klaiper_mobil
{
    Brembo,
    KYT,
    OHLINS,
    KTC,
} kaliper;

typedef struct Rem_mobil
{

    char *system[type_syste_Rem];
    int piston;
    kaliper Kaliper;
} pengeriman;

typedef enum type_Mobil
{
    SUV,
    MUSCLE,
    TRUCT,
    Sedan,
    Sport
} typemobil;
typedef struct Mobil
{
    int Mesin;
    int Aki;
    int Ban;
    int Transmisi;
    int pengeriman;
    int Velg;
    int Kursi;

    typemobil type;
    pengeriman rem;
    radiator Radiator;
    gerakMobil gerak;
} mobil;

mobil Mobil[total_Mobil];

void cek_Kondisi_Aki(mobil *mobil_Aki)
{
    printf("\n check kondisi aki \n");
    for (size_t i = 0; i < total_Mobil; i++)
    {
        printf("mobil :%zu  aki:%d \n", i + 1, mobil_Aki[i].Aki);
    }
}

void cek_Kondisi_Ban(mobil *mobil_Ban)
{
    printf("\n check kondisi BAN \n");
    for (size_t i = 0; i < total_Mobil; i++)
    {
        printf("mobil :%zu total ban:%d pengeriman:%d piston:%d \n", i + 1, mobil_Ban[i].Ban,
               mobil_Ban[i].pengeriman, mobil_Ban[i].rem.piston);
    }
}

void cek_Kondisi_Transmisi(mobil *mobilTransmisi)
{
    printf("\n check kondisi Transmisi \n");
    for (size_t i = 0; i < total_Mobil; i++)
    {
        printf("mobil:%zu transmisi:%d Mesin:%d \n", i + 1, mobilTransmisi[i].Transmisi,
               mobilTransmisi[i].Mesin);
    }
}

const char *cekTypeMobil(int index)
{
    switch (Mobil[index].type)
    {
    case SUV:
        return "SUV";
    case TRUCT:
        return "TRUCT";
    case MUSCLE:
        return "MUSCLE";
    }
}
void spawnMobil(mobil *spawn)
{
    printf("\n spawn mobil");

    for (size_t x = 0; x < total_Mobil; x++)
    {
        spawn[x].type = (x % 2 == 0) ? MUSCLE : SUV;
        spawn[x].Radiator = Dingin;
        spawn[x].gerak = Berhenti;
        spawn[x].Mesin = 2000;
        spawn[x].Transmisi = 6;
        spawn[x].pengeriman = 4;
        spawn[x].Aki = 1;
        spawn[x].Ban = 4;
        spawn[x].Kursi = 4;
        printf("\nmobil:%d Category Mobil:%s ", x + 1, cekTypeMobil(x));
    }
}

void init_Componentmobil(mobil *mobil)
{
    printf("\n init komponent \n");
    for (size_t index = 0; index < total_Mobil; index++)
    {

        mobil[index].rem.Kaliper = (index % 2 == 0) ? OHLINS : KYT;
        mobil[index].rem.piston = 2;
    }
}

int main()
{
    spawnMobil(Mobil);
    init_Componentmobil(Mobil);
    cek_Kondisi_Aki(Mobil);
    cek_Kondisi_Ban(Mobil);
    cek_Kondisi_Transmisi(Mobil);

    return 0;
}
