#include <iostream>
#include <cmath>
#include <random>
#include <chrono>

#include "sortowania.h"

// Program sortowania
// Podstawy Algorytmów i Metody Sztucznej Inteligencji
// Projekt 1
// Kewin Ga³uszka
// nr indeksu 241624
using namespace std;

int main() {
    auto interwaly =1;
    for(int k =0; k<interwaly; k++)
    {
    // *********************************testy sortowan*****************************************

    /*
    int tab[10] = { 2,4,6,8,1,3,5,7,9,10 };

    cout << "\t  tablica " <<  endl;
    for (int i = 0; i < 10; ++i)  cout << tab[i] << " ";

    auto temp = tab;
    sortowanie::merge_sort(temp, 0, 4);

     cout << "\n\t posortowane - sortowanie przez scalanie " <<  endl;
    for (int i = 0; i < 10; ++i)  cout << temp[i] << " ";

    temp = tab;
    sortowanie::quick_sort(temp, 0, 4);

    cout << "\n\t  posortowane - sortowanie szybkie " <<  endl;
    for (int i = 0; i < 10; ++i)  cout << temp[i] << " ";

    temp = tab;
    sortowanie::intro_sort(temp, 0, 4, log(10) * 2);

     cout << "\n\t  posortowane - sortowanie przez scalanie " <<  endl;
    for (int i = 0; i < 10; ++i)  cout << temp[i] << " ";

    */
    double zegar = 0;

    int* sortowana_t = new int[1000000];
    random_device rd;
    mt19937 rng(rd());
    int najnizsza = -32768;
    int najwyzsza = 32768;
    uniform_int_distribution<int> uni(najnizsza, najwyzsza);

    int przyklady_t[5] = { 10000,50000,100000,500000,1000000 };



        // *********************************merge sort*****************************************

        cout << "\n *****Sortowanie przez scalanie (merge sort)*****" << endl;
        for (int p = 0; p < 5; ++p) {
        cout << "\t Czasy dla tablicy o rozmiarze " << przyklady_t[p] <<  endl;



    // *********************************nieposortowana*****************************************

        zegar = 0;
        for (int i = 0; i < 100; ++i) {

            for (int i = 0; i < przyklady_t[p]; ++i) sortowana_t[i] = uni(rng); // wypelnienie tablicy randomami

            auto zegar_start =  chrono::steady_clock::now();         // start zegara
            sortowanie::merge_sort(sortowana_t, 0, przyklady_t[p] - 1);    // sortowanie
            auto zegar_stop =  chrono::steady_clock::now();         //zatrzymanie zegara

            zegar = zegar +  chrono::duration_cast< chrono::milliseconds>(zegar_stop - zegar_start).count(); //obliczenie czasu
        }
        cout << "\n Tablica nieposortowana: " << zegar << " ms" <<  endl;

    // *********************************posortowana 25%*****************************************
        zegar = 0;
        for (int i = 0; i < 100; ++i) {
            for (int i = 0; i < przyklady_t[p]; ++i) sortowana_t[i] = uni(rng);

            sortowanie::merge_sort(sortowana_t, 0, round(przyklady_t[p] / 4 - 1));  // posortowanie 25% tablicy

            auto zegar_start =  chrono::steady_clock::now();
            sortowanie::merge_sort(sortowana_t, 0, przyklady_t[p] - 1);
            auto zegar_stop =  chrono::steady_clock::now();

            zegar = zegar +  chrono::duration_cast< chrono::milliseconds>(zegar_stop - zegar_start).count();
        }
         cout << "\n Tablica posortowana(25%): " << zegar << " ms" <<  endl;

    // *********************************posortowana 50%*****************************************
        zegar = 0;
        for (int i = 0; i < 100; ++i) {
            for (int i = 0; i < przyklady_t[p]; ++i) sortowana_t[i] = uni(rng);

            sortowanie::merge_sort(sortowana_t, 0, przyklady_t[p] / 2 - 1);

            auto zegar_start =  chrono::steady_clock::now();
            sortowanie::merge_sort(sortowana_t, 0, przyklady_t[p] - 1);
            auto zegar_stop =  chrono::steady_clock::now();

            zegar = zegar +  chrono::duration_cast< chrono::milliseconds>(zegar_stop - zegar_start).count();
        }
         cout << "\n Tablica posortowana(50%): " << zegar << " ms" <<  endl;
    // *********************************posortowana 75%*****************************************
        zegar = 0;
        for (int i = 0; i < 100; ++i) {
            for (int i = 0; i < przyklady_t[p]; ++i) sortowana_t[i] = uni(rng);

            sortowanie::merge_sort(sortowana_t, 0, round((przyklady_t[p] * 3) / 4 - 1));

            auto zegar_start =  chrono::steady_clock::now();
            sortowanie::merge_sort(sortowana_t, 0, przyklady_t[p] - 1);
            auto zegar_stop =  chrono::steady_clock::now();

            zegar = zegar +  chrono::duration_cast< chrono::milliseconds>(zegar_stop - zegar_start).count();
        }
         cout << "\n Tablica posortowana(75%): " << zegar << " ms" <<  endl;

        // *********************************posortowana 99%*****************************************
        zegar = 0;
        for (int i = 0; i < 100; ++i) {
            for (int i = 0; i < przyklady_t[p]; ++i) sortowana_t[i] = uni(rng);

            sortowanie::merge_sort(sortowana_t, 0, round((przyklady_t[p] * 99) / 100 - 1));

            auto zegar_start =  chrono::steady_clock::now();
            sortowanie::merge_sort(sortowana_t, 0, przyklady_t[p] - 1);
            auto zegar_stop =  chrono::steady_clock::now();

            zegar = zegar +  chrono::duration_cast< chrono::milliseconds>(zegar_stop - zegar_start).count();
        }
         cout << "\n Tablica posortowana(99%): " << zegar << " ms" <<  endl;

        // *********************************posortowana 99,7%*****************************************
        zegar = 0;
        for (int i = 0; i < 100; ++i) {
            for (int i = 0; i < przyklady_t[p]; ++i) sortowana_t[i] = uni(rng);

            sortowanie::merge_sort(sortowana_t, 0, round((przyklady_t[p] * 997) / 1000 - 1));

            auto zegar_start =  chrono::steady_clock::now();
            sortowanie::merge_sort(sortowana_t, 0, przyklady_t[p] - 1);
            auto zegar_stop =  chrono::steady_clock::now();

            zegar = zegar +  chrono::duration_cast< chrono::milliseconds>(zegar_stop - zegar_start).count();
        }
         cout << "\n Tablica posortowana(99,7%): " << zegar << " ms" <<  endl;

        // *********************************posortowana odwrotnie*****************************************
        zegar = 0;
        for (int i = 0; i < 100; ++i) {
            for (int i = 0; i < przyklady_t[p]; ++i) sortowana_t[i] = uni(rng);

            sortowanie::merge_sort(sortowana_t, 0, przyklady_t[p] - 1, true);

            auto zegar_start =  chrono::steady_clock::now();
            sortowanie::merge_sort(sortowana_t, 0, przyklady_t[p] - 1);
            auto zegar_stop =  chrono::steady_clock::now();

            zegar = zegar +  chrono::duration_cast< chrono::milliseconds>(zegar_stop - zegar_start).count();
        }
         cout << "\n Tablica posortowana odwrotnie: " << zegar << " ms" <<  endl;
    }

        // *********************************quick sort*****************************************

        cout << "\n *****Sortowanie szybkie (quick sort)*****" << endl;
        for (int p = 0; p < 5; ++p) {
        cout << "\t Czasy dla tablicy o rozmiarze: " << przyklady_t[p] <<  endl;

        // *********************************nieposortowana*****************************************
        zegar = 0;
        for (int i = 0; i < 100; ++i) {
            for (int i = 0; i < przyklady_t[p]; ++i) sortowana_t[i] = uni(rng);

            auto zegar_start =  chrono::steady_clock::now();
            sortowanie::quick_sort(sortowana_t, 0, przyklady_t[p] - 1);
            auto zegar_stop =  chrono::steady_clock::now();

            zegar = zegar +  chrono::duration_cast< chrono::milliseconds>(zegar_stop - zegar_start).count();
        }
         cout << "\n Tablica nieposortowana: " << zegar << " ms" <<  endl;

        // *********************************posortowana 25%*****************************************
        zegar = 0;
        for (int i = 0; i < 100; ++i) {
            for (int i = 0; i < przyklady_t[p]; ++i) sortowana_t[i] = uni(rng);

            sortowanie::quick_sort(sortowana_t, 0, round(przyklady_t[p] / 4 - 1));

            auto zegar_start =  chrono::steady_clock::now();
            sortowanie::quick_sort(sortowana_t, 0, przyklady_t[p] - 1);
            auto zegar_stop =  chrono::steady_clock::now();

            zegar = zegar +  chrono::duration_cast< chrono::milliseconds>(zegar_stop - zegar_start).count();
        }
         cout << "\n Tablica posortowana(25%): " << zegar << " ms" <<  endl;

        // *********************************posortowana 50%*****************************************
        zegar = 0;
        for (int i = 0; i < 100; ++i) {
            for (int i = 0; i < przyklady_t[p]; ++i) sortowana_t[i] = uni(rng);

            sortowanie::quick_sort(sortowana_t, 0, przyklady_t[p] / 2 - 1);

            auto zegar_start =  chrono::steady_clock::now();
            sortowanie::quick_sort(sortowana_t, 0, przyklady_t[p] - 1);
            auto zegar_stop =  chrono::steady_clock::now();

            zegar = zegar +  chrono::duration_cast< chrono::milliseconds>(zegar_stop - zegar_start).count();
        }
         cout << "\n Tablica posortowana(50%): " << zegar << " ms" <<  endl;

        // *********************************posortowana 75%*****************************************
        zegar = 0;
        for (int i = 0; i < 100; ++i) {
            for (int i = 0; i < przyklady_t[p]; ++i) sortowana_t[i] = uni(rng);

            sortowanie::quick_sort(sortowana_t, 0, round((przyklady_t[p] * 3) / 4 - 1));

            auto zegar_start =  chrono::steady_clock::now();
            sortowanie::quick_sort(sortowana_t, 0, przyklady_t[p] - 1);
            auto zegar_stop =  chrono::steady_clock::now();

            zegar = zegar +  chrono::duration_cast< chrono::milliseconds>(zegar_stop - zegar_start).count();
        }
         cout << "\n Tablica posortowana(75%): " << zegar << " ms" <<  endl;

        // *********************************posortowana 99%*****************************************
        zegar = 0;
        for (int i = 0; i < 100; ++i) {
            for (int i = 0; i < przyklady_t[p]; ++i) sortowana_t[i] = uni(rng);

            sortowanie::quick_sort(sortowana_t, 0, round((przyklady_t[p] * 99) / 100 - 1));

            auto zegar_start =  chrono::steady_clock::now();
            sortowanie::quick_sort(sortowana_t, 0, przyklady_t[p] - 1);
            auto zegar_stop =  chrono::steady_clock::now();

            zegar = zegar +  chrono::duration_cast< chrono::milliseconds>(zegar_stop - zegar_start).count();
        }
         cout << "\n Tablica posortowana(99%): " << zegar << " ms" <<  endl;

        // *********************************posortowana 99,7%*****************************************
        zegar = 0;
        for (int i = 0; i < 100; ++i) {
            for (int i = 0; i < przyklady_t[p]; ++i) sortowana_t[i] = uni(rng);

            sortowanie::quick_sort(sortowana_t, 0, round((przyklady_t[p] * 997) / 1000 - 1));

            auto zegar_start =  chrono::steady_clock::now();
            sortowanie::quick_sort(sortowana_t, 0, przyklady_t[p] - 1);
            auto zegar_stop =  chrono::steady_clock::now();

            zegar = zegar +  chrono::duration_cast< chrono::milliseconds>(zegar_stop - zegar_start).count();
        }
         cout << "\n Tablica posortowana(99,7%): " << zegar << " ms" <<  endl;

        // *********************************posortowana odwrotnie*****************************************
        zegar = 0;
        for (int i = 0; i < 100; ++i) {
            for (int i = 0; i < przyklady_t[p]; ++i) sortowana_t[i] = uni(rng);

            sortowanie::quick_sort(sortowana_t, 0, przyklady_t[p] - 1, true);

            auto zegar_start =  chrono::steady_clock::now();
            sortowanie::quick_sort(sortowana_t, 0, przyklady_t[p] - 1);
            auto zegar_stop =  chrono::steady_clock::now();

            zegar = zegar +  chrono::duration_cast< chrono::milliseconds>(zegar_stop - zegar_start).count();
        }
         cout << "\n Tablica posortowana odwrotnie: " << zegar << " ms" <<  endl;
    }
        // *********************************intro sort*****************************************

        cout << "\n *****Sortowanie introspektywne (intro sort)*****" << endl;
        for (int p = 0; p < 5; ++p) {
        cout << "\tCzasy dla tablic o rozmiarze " << przyklady_t[p] <<  endl;


        // *********************************nieposortowana*****************************************
        zegar = 0;
        for (int i = 0; i < 100; ++i) {
            for (int i = 0; i < przyklady_t[p]; ++i) sortowana_t[i] = uni(rng);

            auto zegar_start =  chrono::steady_clock::now();
            sortowanie::intro_sort(sortowana_t, 0, przyklady_t[p] - 1, round(log(przyklady_t[p])*2));
            auto zegar_stop =  chrono::steady_clock::now();

            zegar = zegar +  chrono::duration_cast< chrono::milliseconds>(zegar_stop - zegar_start).count();
        }
         cout << "\n Tablica nieposortowana " << zegar << " ms" <<  endl;


        // *********************************posortowana 25%*****************************************
        zegar = 0;
        for (int i = 0; i < 100; ++i) {
            for (int i = 0; i < przyklady_t[p]; ++i) sortowana_t[i] = uni(rng);
            //cout << "1"<< endl;
            sortowanie::quick_sort(sortowana_t, 0, round((przyklady_t[p] )- 1));
            //cout << "2"<< endl;
            auto zegar_start =  chrono::steady_clock::now();
            sortowanie::intro_sort(sortowana_t, 0, przyklady_t[p] - 1, round(log(przyklady_t[p])*2));
            auto zegar_stop =  chrono::steady_clock::now();

            zegar = zegar +  chrono::duration_cast< chrono::milliseconds>(zegar_stop - zegar_start).count();
        }
         cout << "\n Tablica posortowana(25%): " << zegar << " ms" <<  endl;

        // *********************************posortowana 50%*****************************************
        zegar = 0;
        for (int i = 0; i < 100; ++i) {
            for (int i = 0; i < przyklady_t[p]; ++i) sortowana_t[i] = uni(rng);

            sortowanie::quick_sort(sortowana_t, 0, round((przyklady_t[p] ) / 2- 1));

            auto zegar_start =  chrono::steady_clock::now();
            sortowanie::intro_sort(sortowana_t, 0, przyklady_t[p] - 1, round(log(przyklady_t[p])*2));
            auto zegar_stop =  chrono::steady_clock::now();

            zegar = zegar +  chrono::duration_cast< chrono::milliseconds>(zegar_stop - zegar_start).count();
        }
         cout << "\n Tablica posortowana(50%): " << zegar << " ms" <<  endl;

         // *********************************posortowana 75%*****************************************
        zegar = 0;
        for (int i = 0; i < 100; ++i) {
            for (int i = 0; i < przyklady_t[p]; ++i) sortowana_t[i] = uni(rng);

            sortowanie::quick_sort(sortowana_t, 0, round((przyklady_t[p] * 3) / 4 - 1));

            auto zegar_start =  chrono::steady_clock::now();
            sortowanie::intro_sort(sortowana_t, 0, przyklady_t[p] - 1, round(log(przyklady_t[p])*2));
            auto zegar_stop =  chrono::steady_clock::now();

            zegar = zegar +  chrono::duration_cast< chrono::milliseconds>(zegar_stop - zegar_start).count();
        }
         cout << "\n Tablica posortowana(75%): " << zegar << " ms" <<  endl;


        // *********************************posortowana 99%*****************************************
        zegar = 0;
        for (int i = 0; i < 100; ++i) {
            for (int i = 0; i < przyklady_t[p]; ++i) sortowana_t[i] = uni(rng);

            sortowanie::quick_sort(sortowana_t, 0, round((przyklady_t[p] * 99) / 100 - 1));

            auto zegar_start =  chrono::steady_clock::now();
            sortowanie::intro_sort(sortowana_t, 0, przyklady_t[p] - 1, round(log(przyklady_t[p])*2));
            auto zegar_stop =  chrono::steady_clock::now();

            zegar = zegar +  chrono::duration_cast< chrono::milliseconds>(zegar_stop - zegar_start).count();
        }
         cout << "\n Tablica posortowana(99%): " << zegar << " ms" <<  endl;

        // *********************************posortowana 99,7%*****************************************
        zegar = 0;
        for (int i = 0; i < 100; ++i) {
            for (int i = 0; i < przyklady_t[p]; ++i) sortowana_t[i] = uni(rng);

            sortowanie::quick_sort(sortowana_t, 0, round((przyklady_t[p] * 997) / 1000 - 1));

            auto zegar_start =  chrono::steady_clock::now();
            sortowanie::intro_sort(sortowana_t, 0, przyklady_t[p] - 1, round(log(przyklady_t[p])*2));
            auto zegar_stop =  chrono::steady_clock::now();

            zegar = zegar +  chrono::duration_cast< chrono::milliseconds>(zegar_stop - zegar_start).count();
        }
         cout << "\n Tablica posortowana(99%): " << zegar << " ms" <<  endl;

        // *********************************posortowana odwrotnie%*****************************************
        zegar = 0;
        for (int i = 0; i < 100; ++i) {
            for (int i = 0; i < przyklady_t[p]; ++i) sortowana_t[i] = uni(rng);

            sortowanie::quick_sort(sortowana_t, 0, przyklady_t[p] - 1, true);

            auto zegar_start =  chrono::steady_clock::now();
            sortowanie::intro_sort(sortowana_t, 0, przyklady_t[p] - 1, round(log(przyklady_t[p])*2));
            auto zegar_stop =  chrono::steady_clock::now();

            zegar = zegar +  chrono::duration_cast< chrono::milliseconds>(zegar_stop - zegar_start).count();
        }
         cout << "\n Tablica posortowana odwrotnie: " << zegar << " ms" <<  endl;
    }
    }

}

