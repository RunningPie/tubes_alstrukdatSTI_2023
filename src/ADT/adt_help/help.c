#include "help.h"

void help1(){
// Procedure mengeluarkan COMMAND yang dapat diakses sebelum memasuki sesi

printf("\n===.+:*+.:===.+:*+.===.+[ MENU HELP WAYANGWAVE ]===.+:*+.===.+:*+.===.+:\n");
printf("|       1. START -> Untuk masuk sesi baru                               |\n");
printf("|       2. LOAD -> Untuk memulai sesi berdasarkan file konfigurasi      |\n");
printf("|_______________________________________________________________________|\n");
}
void help2(){
// Procedure mengeluarkan COMMAND yang dapat diakses setelah memasuki sesi

printf("\n===.+:*+.===.+:*+.===.+:*+===.+:*+.===.+:*+.===.+:*+.===.+:*+.[ MENU HELP WAYANGWAVE ]===.+:*+===.+:*+.===.+:*+.===.+:*+.===.+:*+.===.+:*+.===.+:*+.===.+:\n");
printf("|             1. LIST -> Untuk menampilkan daftar lagu, playlist, album, penyanyi                                                                        |\n");
printf("|             2. PLAY -> Untuk memulai suatu lagu baru atau lagu dari playlist yang dipilih                                                              |\n");
printf("|             3. QUEUE -> Untuk memanipulasi queue lagu dengan command tambah song, tambah playlist, tukar, hapus, atau mengosongkan                     |\n");
printf("|             4. SONG -> Untuk mengontrol navigasi lagu dalam queue (putar lagu selanjutnya atau lagu sebelumnya)                                        |\n");
printf("|             5. PLAYLIST -> Untuk melakukan operasi pada playlis, seperti membuat, menambahkan, menukar, menghapus lagu, atau menghapus playlist        |\n");
printf("|             6. STATUS -> Untuk menampilkan lagu yang sedang dimainkan beserta Queue song yang ada dan dari playlist mana lagu itu diputar              |\n");          
printf("|             7. SAVE -> Untuk menyimpan state aplikasi terbaru ke dalam suatu file                                                                      |\n");
printf("|             8. QUIT -> Untuk keluar dari sesi                                                                                                          |\n");
printf("|________________________________________________________________________________________________________________________________________________________|\n");
}