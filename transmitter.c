#include <stdio.h>
#include <stdlib.h>

//Идентификатор команды для ФПО
unsigned char Tage_30 = 1;
unsigned char b_tok60 = 2;
unsigned char b_tok61 = 3;
unsigned char Voltage[5] = {0, 1, 2, 3, 4};
unsigned char Ugol30 = 4;
unsigned char Ugol31 = 5;
unsigned char Ugol32 = 6;
unsigned char c_perek_80 = 7;

void
generateMessage(unsigned short Zap_p, unsigned short Zap0, unsigned short ks_zap, unsigned short Zap_fpo, short mas[5]);

void sendMessage(int configd, int n_gr_buk, short mas[5], unsigned char mas_ip[60]);

//Идентификатор запроса ФПО
void generateMessage(unsigned short Zap_p,
                     unsigned short Zap0,
                     unsigned short ks_zap,
                     unsigned short Zap_fpo,
                     short mas[5]) {

    int i;
    int message_size = 0;

    for (i = 0; i < 5; i++) {
        mas[i] = 0;
    }
    i = 0;

    // 1 код сообщения
    if ((Zap_p & 0x100) == 0x100) {
        mas[message_size++] = 39;
    }

    // 2 код сообщения
    if (((Zap_p & 0x780) >> 7) == 0x5) {
        mas[message_size++] = 467;
    } else if (((Zap_fpo & 0x78) >> 3) == 0x5) {
        mas[message_size++] = 410;
    }

    // 3 код
    if ((Zap0 & 0x8) == 0x8) {
        mas[message_size++] = 454;
    } else if ((Zap_fpo & 0x2) == 0x2) {
        mas[message_size++] = 315;
    } else if ((ks_zap & 0x800) == 0x800) {
        mas[message_size++] = 469;
    } else if ((Zap_fpo & 0x400) == 0x400) {
        mas[message_size] = 87;
    }

    // 4 код
    if ((Zap0 & 0x4) == 0x4) {
        mas[message_size++] = 162;
    } else if ((ks_zap & 0x100) == 0x100) {
        mas[message_size++] = 393;
    } else if ((Zap_fpo & 0x80) == 0x80) {
        mas[message_size++] = 32;
    }

    // 5 код
    if ((Zap_fpo & 0x8) == 0x8) {
        mas[message_size] = 206;
    }
}

void sendMessage(int configd, int n_gr_buk, short mas[5], unsigned char mas_ip[60]) {
    int i;
    int maska;
    int n_ved;

    if ((configd & 0xf) == 7)
        n_ved = 1;
    else if ((configd & 0xf0) == 0x70)
        n_ved = 2;
    else if ((configd & 0xf00) == 0x700)
        n_ved = 3;
    else if ((configd & 0xf000) == 0x7000)
        n_ved = 4;
    if (n_gr_buk == n_ved)
        maska = 7;

    printf("maska = %d\n", maska);

    for (i=0;i<5;i++){
        if(maska == 7){
            switch (mas[i]){
                case 454:
                    mas_ip[0x28] = Voltage[1];
                    break;
                case 315:
                    mas_ip[0x92] = Voltage[2];
                    break;
                case 469:
                    mas_ip[0x9] = Voltage[3];
                    break;
                case 87:
                    mas_ip[0x63] = Voltage[4];
                    break;
            }
        }

        switch (mas[i]){
            case 39:
                Tage_30 = mas_ip[0xd];
                break;
            case 467:
                b_tok60 = mas_ip[0xd2];
                break;
            case 410:
                b_tok61 = mas_ip[0x3];
                break;
            case 162:
                Ugol30 = mas_ip[0xca];
                break;
            case 393:
                Ugol31 = mas_ip[0x7f];
                break;
            case 32:
                Ugol32 = mas_ip[0xaf];
                break;
            case 206:
                c_perek_80 = mas_ip[0x30];
                break;
        }

    }

}