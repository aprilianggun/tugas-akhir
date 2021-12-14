#include <iostream>
#include <cstdio>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

#define batas_bawah 21
#define batas_kanan 91

using namespace std;

void menu(); // Berisi menu awal (Ada)
void loading(); // berisi tentang animasi loading (Ada)
void gbk(); // berisi game gunting batu kertas (Ada)
void tebak_angka(); // berisi game menebak angka
void kuis(); // berisi game tentang kuis menjawab pertanyaan
void games(); // berisi pilihan games
void garis(); // membuat garis permainan (Ada)
void gotoxy(); // berisi fungsi go to x dan y (ada)
void kursor(); // berisi kursor anak panah
void kursor2(); // berisi kursor anak panah
void credit();

int main(){
    garis();
    menu();
    
}

void gotoxy(int x, int y){

    COORD garis = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), garis);
}

void garis(){

    for(int i=0; i<=batas_kanan; i++){ // berfungsi membentuk garis atas
        gotoxy(i, 0);
        printf("=");
    }

    for(int j=1; j<=batas_bawah; j++){ // berfungsi untuk membentuk garis kiri
        gotoxy(0,j);
        printf("|");
    }

    for(int l=1; l<=batas_bawah; l++){ // berfungsi untuk membentuk garis kanan
        gotoxy(batas_kanan, l);
        printf("|");
    }

    for (int k=0; k<=batas_kanan; k++){ // berfungsi membentuk garis bawah
        gotoxy(k , batas_bawah);
        printf("=");
    }
}

void loading(){
    garis();
    for(int a=0; a<2; a++){ // berfungsi sebagai looping animasi looding screeen
        garis();
        gotoxy(21,5); 
        printf("Loading.....");
        Sleep(250);
        system("cls");

        garis();
        gotoxy(21,5); 
        printf("Loading...");
        Sleep(250);
        system("cls");

        garis();
        gotoxy(21,5); 
        printf("Loading.");
        Sleep(250);
        system("cls");
    }
    garis();
}

void menu(){
    string awal[4]={"Selamat Datang di MiniGame","1.Pilih Game",
                    "2.Credit","3.Exit"}; // berisi beberapa menu tentang credit, pilihan game dan exit
    
    for(int i=0; i<4; i++){
        gotoxy(21, i+5);
        cout<<awal[i]<<"\n";
    }
    kursor();
}

void kursor(){
    char arah;
    int x=18, y=6; // berfungsi untuk menggerakan kursor di void menu

    gotoxy(x,y);
    cout<<"=>";

    while(true){
        arah = getch();
        
        switch(arah){
            case 'w':
                if (y == 6){
                  
                }else{
                    gotoxy(x,y-=1);
                    printf("=>");
                    gotoxy(x, y+1);
                    printf("  ");
                }
                gotoxy(x,y);
                printf("=>");
                break;
             
            case 's': 
                if (y == 8){
                    
                }else{
                    gotoxy(x, y+=1);
                    printf("=>");
                    gotoxy(x, y-1);
                    printf("  ");    
                }
                gotoxy(x,y);
                printf("=>");
                break;
            case 'p':
                    if (y==6){
                    	system("cls");
                        games();
                    }else if(y==7){
                        credit();
                    }else if(y==8){
                        exit(0);
                    }
                    break;
        }
    }
}

void kursor2(){
    char arah; // berfungsi menggerakan kursor pada void games
    int x=18, y=6;

    gotoxy(x,y);
    cout<<"=>";

    while(true){
        arah = getch();
        
        switch(arah){
            case 'w':
                if (y == 6){
                  
                }else{
                    gotoxy(x,y-=1);
                    printf("=>");
                    gotoxy(x, y+1);
                    printf("  ");
                }
                gotoxy(x,y);
                printf("=>");
                break;
             
            case 's': 
                if (y == 8){
                    
                }else{
                    gotoxy(x, y+=1);
                    printf("=>");
                    gotoxy(x, y-1);
                    printf("  ");    
                }
                gotoxy(x,y);
                printf("=>");
                break;
            case 'p':
                if (y==6){
                    gbk();

                }else if(y==7){
                    tebak_angka();
                }else if(y==8){
                    exit(0);
                }
                break;
                
        }
    }
}

void games(){
    string game[4]={"Silahkan Pilih GAMES yang ini dimainkan",
                    "1.Gunting-Batu-Kertas","2.Tebak Angka","3.exit"};
    garis(); 
    for(int i=0; i<4; i++){ // berisi pilihan game yang akan dimainkan
        gotoxy(21, i+5);
        cout<<game[i]<<"\n";
    }
    kursor2();
}

void gbk(){
    string cara[5]={"1. Permainan dimainkan 2 pemain",
                    "2. Pemain Memilih antara Gunting(g), kertas(k), batu(b)",
                    "3. Batu < kertas, kertas < gunting, gunting < kertas",
                    "4. Pemain akan Memasang Uang yang dipertaruhkan",
                    "5. Pemain Yang kalah akan kehilangan uangnya"};
    int e, g, uang, uang_musuh, total_uang;
    char milih, jawaban;

    printf("Cara dan Peraturan Permainan: \n"); 
    for(e=0; e<5; e++){
        gotoxy(18, e+5);
        cout<<cara[e]<<"\n";
    }
    Sleep(500);
    system("cls");

    do{
        garis();
        gotoxy(21,5);
        printf("Masukan Jumlah uang yang ingin dipetaruhkan: $.");
        gotoxy(68,5);
        scanf("%d", &uang);

        loading();
        srand(time(NULL));
        uang_musuh = rand() % 1000 + 1;

        gotoxy(21,5); 
        printf("Uang Anda: $.%d",uang);
        gotoxy(21,6); 
        printf("uang musuh: $.%d", uang_musuh);
        total_uang = uang + uang_musuh;
        gotoxy(21,7); 
        printf("jumlah total uang yang dipetaruhkan: $.%d", total_uang);
        gotoxy(21,8); 
        printf("masukan pilihan anda: g/b/k?: "); 
        gotoxy(52,8); 
        cin>>milih;
        system("cls");

        switch (milih){
            case 'g':
                srand(time(NULL)); 
                g = rand() % 3 + 1;
                if(g==1){ 
                    garis();
                    gotoxy(21,5); 
                    printf("Pilihan anda= Gunting");
                    gotoxy(21,6); 
                    printf("Musuh anda = Gunting");
                    gotoxy(21,7);
                    system("pause");
                    loading();
                    
                    gotoxy(21,5); 
                    printf("Seimbang");
                    gotoxy(21,6); 
                    printf("Ingin Main lagi? (y/n): ");
                    gotoxy(45,6); 
                    cin>>jawaban; 
                    system("cls");

                }else if (g==2){ 
                    garis();
                    gotoxy(21,5); 
                    printf("Pilihan anda= Gunting");
                    gotoxy(21,6); 
                    printf("Musuh anda = Batu");
                    gotoxy(21,7);
                    system("pause");
                    loading();

                    gotoxy(21,5); 
                    printf("Anda Kalah");
                    gotoxy(21,6); 
                    printf("Ingin Main lagi? (y/n): ");
                    gotoxy(45,6); 
                    cin>>jawaban;
                    system("cls");

                }else{ 
                    garis();
                    gotoxy(21,5); 
                    printf("Pilihan anda= Gunting");
                    gotoxy(21,6);
                    printf("Musuh anda = Kertas");
                    gotoxy(21,7);
                    system("pause");
                    loading();

                    gotoxy(21,5); 
                    printf("Anda Menang");
                    gotoxy(21,6); 
                    printf("Anda Mendapatkan Uang sebesar: $.%d ", total_uang);
                    gotoxy(21,7); 
                    printf("Ingin Main lagi? (y/n): ");
                    gotoxy(45,7); 
                    cin>>jawaban;
                    system("cls");
                }
                break;
            case 'b':
                srand(time(NULL)); 
                g = rand() % 3 + 1;
                if(g==1){ 
                    garis();
                    gotoxy(21,5); 
                    printf("Pilihan anda= Batu");
                    gotoxy(21,6); 
                    printf("Musuh anda = Gunting");
                    gotoxy(21,7);
                    system("pause");
                    loading();

                    gotoxy(21,5); 
                    printf("Anda Menang");
                    gotoxy(21,6); 
                    printf("Anda Mendapatkan Uang sebesar: $.%d ", total_uang);
                    gotoxy(21,7); 
                    printf("Ingin Main lagi? (y/n): ");
                    gotoxy(45,7); 
                    cin>>jawaban;
                    system("cls");
                    
                }else if (g==2){ 
                    garis();
                    gotoxy(21,5); 
                    printf("Pilihan anda= Batu");
                    gotoxy(21,6); 
                    printf("Musuh anda = Batu");
                    gotoxy(21,7);
                    system("pause");
                    loading();

                    gotoxy(21,5); 
                    printf("Seimbang");
                    gotoxy(21,6); 
                    printf("Ingin Main lagi? (y/n): ");
                    gotoxy(45,6); 
                    cin>>jawaban; 
                    system("cls");

                }else{ 
                    garis();
                    gotoxy(21,5); 
                    printf("Pilihan anda= Batu");
                    gotoxy(21,6);
                    printf("Musuh anda = Kertas");
                    gotoxy(21,7);
                    system("pause");
                    loading();

                    gotoxy(21,5); 
                    printf("Anda Kalah");
                    gotoxy(21,6); 
                    printf("Ingin Main lagi? (y/n): ");
                    gotoxy(45,6); 
                    cin>>jawaban;
                    system("cls");
                }
                break;
            case 'k':
                srand(time(NULL)); 
                g = rand() % 3 + 1;
                if(g==1){ 
                    garis();
                    gotoxy(21,5); 
                    printf("Pilihan anda= kertas");
                    gotoxy(21,6); 
                    printf("Musuh anda = Gunting");
                    gotoxy(21,7);
                    system("pause");
                    loading();

                    gotoxy(21,5); 
                    printf("Anda Kalah");
                    gotoxy(21,6); 
                    printf("Ingin Main lagi? (y/n): ");
                    gotoxy(45,6); 
                    cin>>jawaban;
                    system("cls");
                    
                }else if (g==2){ 
                    garis();
                    gotoxy(21,5); 
                    printf("Pilihan anda= kertas");
                    gotoxy(21,6); 
                    printf("Musuh anda = Batu");
                    gotoxy(21,7);
                    system("pause");
                    loading();

                    gotoxy(21,5); 
                    printf("Anda Menang");
                    gotoxy(21,6); 
                    printf("Anda Mendapatkan Uang sebesar: $.%d ", total_uang);
                    gotoxy(21,7); 
                    printf("Ingin Main lagi? (y/n): ");
                    gotoxy(45,7); 
                    cin>>jawaban;
                
                }else{ 
                    garis();
                    gotoxy(21,5); 
                    printf("Pilihan anda= kertas");
                    gotoxy(21,6);
                    printf("Musuh anda = Kertas");
                    gotoxy(21,7);
                    system("pause");
                    loading();

                    system("cls");
                    gotoxy(21,5); 
                    printf("Seimbang");
                    gotoxy(21,6); 
                    printf("Ingin Main lagi? (y/n): ");
                    gotoxy(45,6); 
                    cin>>jawaban; 
                    system("cls");
                }
                break;
        }
    } while (jawaban=='y');
    system("cls");
    games();
}

void tebak_angka(){
    int jawaban, pilih;
    int kesempatan;
    char mengulang;

    system("cls");
    garis();
    gotoxy(21,5);
    printf("Selamat Datang di Game Tebak Angka"); 
    gotoxy(21,6);
    printf("1.Anda diharuskan menebak angka diantara 1-9");
    gotoxy(21,7);
    printf("2. jawaban salah akan mengurangi kesempatan anda");
    Sleep(1000);

    do{
        system("cls");
        kesempatan = 2;
        garis();
        srand(time(NULL)); 
        jawaban = rand() % 9 + 1;

        gotoxy(21,5);
        printf("Masukan Tebakan anda: ");
        gotoxy(43,5);
        scanf("%d", &pilih);

        while (pilih != jawaban && kesempatan > 1){
            gotoxy(21,5);
            printf("Tebakan anda salah, tebak lagi");
            kesempatan-=1;
            gotoxy(21,6);
            printf("Sisa Kesempatan Anda: %d ", kesempatan);
            gotoxy(21,7);
            printf("tebak lagi: ");
            gotoxy(33,7);
            scanf("%d", &pilih); 
        }
        system("cls");
        garis();

        if (pilih == jawaban && kesempatan > 1){
            gotoxy(21,5);
            printf("Tebakan anda benar Selamat Telah memenangkan permainan");
            gotoxy(21,6);
            printf("Selamat Telah memenangkan permainan");
            gotoxy(21,7);
            printf("ingin bermain lagi?(y/n): ");
            gotoxy(48,7);
            scanf("%s", &mengulang);

        }else{
            gotoxy(21,5);
            printf("jawaban yang benar adalah: %d ", jawaban);
            gotoxy(21,6); 
            printf("Maaf Anda kurang beruntung, silahkan coba lagi");
            gotoxy(21,7);
            printf("ingin bermain lgi? (y/n): ");
            gotoxy(48,7);
            scanf("%s", &mengulang);
        }
    } while (mengulang == 'y');
    system("cls");
    games();
}

void credit(){
    string credit[3]={"Reza Nur Ramadhan","Aprillia Anggun","Osmycin Amelia"};
    int angka[3]={2117051057,2117051038,2117051030};
    
	system("cls");
    garis();
    for(int i=0; i<3; i++){
        gotoxy(21,5+i);
        cout<<credit[i]<<"\n";
    }
    for(int j=0; j<3; j++){
        gotoxy(40,5+j);
        cout<<angka[j]<<"\n";
    }
    gotoxy(21,8);
    system("pause");
    system("cls");
    main();
}
