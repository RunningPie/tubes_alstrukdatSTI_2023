#include "help.h"

int help1(){
// Fungsi mengeluarkan COMMAND yang dapat diakses sebelum memasuki sesi

printf("=====[ Menu Help WayangWave ]=====");
printf("1. START -> Untuk masuk sesi baru");
printf("2. LOAD -> Untuk memulai sesi berdasarkan file konfigurasi");
}
int help2(){
// Fungsi mengeluarkan COMMAND yang dapat diakses setelah memasuki sesi

printf("=====[ Menu Help WayangWave ]=====");
printf("1. LIST -> Untuk menampilkan daftar lagu, playlist, album, penyanyi");
char help22[500] = "2. PLAY -> Untuk memulai suatu lagu baru atau lagu dari playlist yang dipilih. Terdapat dua pilihan, yaitu memainkan lagu (PLAY SONG) dan memainkan lagu berdasarkan id playlist (QUEUE PLAYLIST)";
printf("%s\n", help22);
char help23[500] = "3. QUEUE -> Untuk memanipulasi queue lagu. Terdapat lima pilihan, yaitu menambahkan lagu (QUEUE SONG), menambahkan playlist (QUEUE PLAYLIST), menukar lagu pada urutan ke x dan juga urutan ke y (QUEUE SWAP <x><y>), menghapus lagu dari QUEUE (QUEUE REMOVE), dan mengosongkan queue (QUEUE CLEAR)";
printf("%s\n", help23);
char help24[500] = "4. SONG -> Untuk navigasi lagu yang ada pada queue ataupun daftar riwayat putar lagu. Terdapat dua pilihan, yaitu memutar lagu pada queue (SONG NEXT) dan memutar lagu yang terakhir kali diputar (SONG PREVIOUS)";
printf("%s\n", help24);
char help25[500] = "5. PLAYLIST -> Untuk mengakses playlist. Terdapat lima pilihan, yaitu membuat (PLAYLIST CREATE), menambahkan (PLAYLIST ADD), menukar (PLAYLIST SWAP), menghapus urutan (PLAYLIST REMOVE), dan melakukan penghapusan terhadap playlist (PLAYLIST DELETE)";
printf("%s\n", help25);
char help26[500] = "6. STATUS -> Untuk menampilkan lagu yang sedang dimainkan beserta Queue song yang ada dan dari playlist mana lagu itu diputar";
printf("%s\n", help26);
char help27[500] = "7. SAVE -> Untuk menyimpan state aplikasi terbaru ke dalam suatu file";
printf("%s\n", help27);
char help28[500] = "8. QUIT -> Untuk keluar dari sesi";
printf("%s\n", help28);
}