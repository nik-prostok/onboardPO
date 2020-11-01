#include <stdio.h>
#include "transmitter.c"

void test1();
void test2();
void test3();
void test4();
void test5();

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
}


void test1(){

    unsigned short Zap_p = 0x100;
    unsigned short Zap_fpo = 0x28;
    unsigned short Zap0 =  0x8;
    unsigned short ks_zap = 0x100;

    int configd = 7;
    int n_gr_buk = 1;

    short mas[5] = {0};
    unsigned char mas_ip[1024] = {0};
    mas_ip[0xd]  = 22;
    mas_ip[0x3] = 25;
    mas_ip[0x7f] = 30;

    printf("test1 started:  Zap_p = %d; Zap_fpo = %d; Zap0 = %d; ks_zap = %d; configd = 7; n_gr_buk = 1 \n", Zap_p, Zap_fpo, Zap0, ks_zap);

    generateMessage(Zap_p, Zap0, ks_zap, Zap_fpo, mas);
    for(int i = 0;i<5;i++){
        printf("mas[%d] = %d; ",i,mas[i]);
    }
    printf("\n");
    printf("mas_ip[0xd] = %d, Tage_30 = %d\n", mas_ip[0xd], Tage_30);
    printf("mas_ip[0x3] = %d, b_tok61 = %d\n", mas_ip[0x3], b_tok61);
    printf("mas_ip[0x28] = %d, Voltage[1] = %d\n", mas_ip[0x28], Voltage[1]);
    printf("mas_ip[0x7f] = %d, Ugol31 = %d\n", mas_ip[0x7f], Ugol31);

    printf("run sendMessage\n");

    sendMessage(configd, n_gr_buk, mas, mas_ip);

    printf("mas_ip[0xd] = %d, Tage_30 = %d\n", mas_ip[0xd], Tage_30);
    printf("mas_ip[0x3] = %d, b_tok61 = %d\n", mas_ip[0x3], b_tok61);
    printf("mas_ip[0x28] = %d, Voltage[1] = %d\n", mas_ip[0x28], Voltage[1]);
    printf("mas_ip[0x7f] = %d, Ugol31 = %d\n", mas_ip[0x7f], Ugol31);

    if( mas_ip[0x28] != Voltage[1]){
        printf("test1.1 failed mas_ip[0x28] != Voltage[1]\n");
    }
    if( mas_ip[0xd] != Tage_30){
        printf("test1.2 failed mas_ip[0xd] != Tage_30\n");
    }
    if( mas_ip[0x3] != b_tok61){
        printf("test1.3 failed mas_ip[0x3] != b_tok61\n");
    }
    if(  mas_ip[0x7f] != Ugol31){
        printf("test1.4 failed mas_ip[0x7f] != Ugol31\n");
    }

    printf("test1 finished\n");

}

void test2(){

    unsigned short Zap_p = 0x280;
    unsigned short Zap_fpo = 0x2;
    unsigned short Zap0;
    unsigned short ks_zap;

    int configd = 7;
    int n_gr_buk = 1;

    short mas[5] = {0};
    unsigned char mas_ip[1024] = {0};
    mas_ip[0xd2] = 15;

    printf("test2 started:  Zap_p = %d; Zap_fpo = %d; Zap0 = %d; ks_zap = %d; configd = 7; n_gr_buk = 1 \n", Zap_p, Zap_fpo, Zap0, ks_zap);

    generateMessage(Zap_p, Zap0, ks_zap, Zap_fpo, mas);
    for(int i = 0;i<5;i++){
        printf("mas[%d] = %d; ",i,mas[i]);
    }
    printf("\n");
    printf("mas_ip[0xd2] = %d, b_tok60 = %d\n", mas_ip[0xd2], b_tok60);
    printf("mas_ip[0x92] = %d,  Voltage[2] = %d\n", mas_ip[0x92],  Voltage[2]);

    printf("run sendMessage\n");

    sendMessage(configd, n_gr_buk, mas, mas_ip);

    printf("mas_ip[0xd2] = %d, b_tok60 = %d\n", mas_ip[0xd2], b_tok60);
    printf("mas_ip[0x92] = %d,  Voltage[2] = %d\n", mas_ip[0x92],  Voltage[2]);

    if( mas_ip[0xd2] != b_tok60){
        printf("test2.1 failed mas_ip[0xd2] != b_tok60\n");
    }
    if( mas_ip[0x92] != Voltage[2]){
        printf("test2.2 failed mas_ip[0x92] != Voltage[2]\n");
    }

    printf("test2 finished\n");

}

void test3(){

    unsigned short Zap_p;
    unsigned short Zap_fpo;
    unsigned short Zap0 = 0x4;
    unsigned short ks_zap = 0x800;

    int configd = 7;
    int n_gr_buk = 1;

    short mas[5] = {0};
    unsigned char mas_ip[1024] = {0};
    mas_ip[0xca] = 24;

    printf("test3 started:  Zap_p = %d; Zap_fpo = %d; Zap0 = %d; ks_zap = %d; configd = 7; n_gr_buk = 1 \n", Zap_p, Zap_fpo, Zap0, ks_zap);

    generateMessage(Zap_p, Zap0, ks_zap, Zap_fpo, mas);
    for(int i = 0;i<5;i++){
        printf("mas[%d] = %d; ",i,mas[i]);
    }
    printf("\n");
    printf("mas_ip[0x9] = %d,  Voltage[3] = %d\n", mas_ip[0x9],  Voltage[3]);
    printf("mas_ip[0xca] = %d,  Ugol30 = %d\n", mas_ip[0xca],  Ugol30);

    printf("run sendMessage\n");

    sendMessage(configd, n_gr_buk, mas, mas_ip);

    printf("mas_ip[0x9] = %d,  Voltage[3] = %d\n", mas_ip[0x9],  Voltage[3]);
    printf("mas_ip[0xca] = %d,  Ugol30 = %d\n", mas_ip[0xca],  Ugol30);

    if( mas_ip[0x9] != Voltage[3]){
        printf("test3.1 failed mas_ip[0x9] != Voltage[3]\n");
    }
    if( mas_ip[0xca] != Ugol30){
        printf("test3.2 failed mas_ip[0xca] != 0xca\n");
    }

    printf("test3 finished\n");

}

void test4(){

    unsigned short Zap_p;
    unsigned short Zap_fpo = 0x88; // 3, 7 разряды
    unsigned short Zap0;
    unsigned short ks_zap;

    int configd = 7;
    int n_gr_buk = 1;

    short mas[5] = {0};
    unsigned char mas_ip[1024] = {0};
    mas_ip[0xaf] = 10;
    mas_ip[0x30] = 11;

    printf("test4 started:  Zap_p = %d; Zap_fpo = %d; Zap0 = %d; ks_zap = %d; configd = 7; n_gr_buk = 1 \n", Zap_p, Zap_fpo, Zap0, ks_zap);

    generateMessage(Zap_p, Zap0, ks_zap, Zap_fpo, mas);
    for(int i = 0;i<5;i++){
        printf("mas[%d] = %d; ",i,mas[i]);
    }
    printf("\n");
/*
    printf("mas_ip[0x63] = %d,  Voltage[4] = %d\n", mas_ip[0x63],  Voltage[4]);
*/
    printf("mas_ip[0xaf] = %d,  Ugol32 = %d\n", mas_ip[0xaf],  Ugol32);
    printf("mas_ip[0x30] = %d,  c_perek_80 = %d\n", mas_ip[0x30],  c_perek_80);


    printf("run sendMessage\n");

    sendMessage(configd, n_gr_buk, mas, mas_ip);

/*
    printf("mas_ip[0x63] = %d,  Voltage[4] = %d\n", mas_ip[0x63],  Voltage[4]);
*/
    printf("mas_ip[0xaf] = %d,  Ugol32 = %d\n", mas_ip[0xaf],  Ugol32);
    printf("mas_ip[0x30] = %d,  c_perek_80 = %d\n", mas_ip[0x30],  c_perek_80);

    /*if( mas_ip[0x63] != Voltage[4]){
        printf("test4.1 failed mas_ip[0x63] != Voltage[4]\n");
    }*/
    if( mas_ip[0xaf] != Ugol32){
        printf("test4.2 failed mas_ip[0xaf] != Ugol32\n");
    }
    if( mas_ip[0x30] != c_perek_80){
        printf("test4.3 failed mas_ip[0x30] != c_perek_80\n");
    }
    printf("test4 finished\n");

}

void test5() {
    unsigned short Zap_p;
    unsigned short Zap_fpo = 0x400;
    unsigned short Zap0;
    unsigned short ks_zap;

    int configd = 7;
    int n_gr_buk = 1;

    short mas[5] = {0};
    unsigned char mas_ip[1024] = {0};

    printf("test5 started:  Zap_p = %d; Zap_fpo = %d; Zap0 = %d; ks_zap = %d; configd = 7; n_gr_buk = 1 \n", Zap_p, Zap_fpo, Zap0, ks_zap);

    generateMessage(Zap_p, Zap0, ks_zap, Zap_fpo, mas);
    for(int i = 0;i<5;i++){
        printf("mas[%d] = %d; ",i,mas[i]);
    }
    printf("\n");
    printf("mas_ip[0x63] = %d,  Voltage[4] = %d\n", mas_ip[0x63],  Voltage[4]);

    printf("run sendMessage\n");

    sendMessage(configd, n_gr_buk, mas, mas_ip);

    printf("mas_ip[0x63] = %d,  Voltage[4] = %d\n", mas_ip[0x63],  Voltage[4]);


    if( mas_ip[0x63] != Voltage[4]){
        printf("test4.1 failed mas_ip[0x63] != Voltage[4]\n");
    }
    printf("test5 finished\n");
}