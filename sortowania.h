
#include <memory>
#include <cmath>

using namespace std;

class sortowanie {
    sortowanie() {};
    public:
    // sortowanie przez scalanie
    template <class t>
    static void merge_sort(t tab[], int pierwszy, int ostatni, bool odwrotnie = false);

    // sortowanie szybkie
    template <class t>
    static void quick_sort(t tab[], int pierwszy, int ostatni, bool odwrotnie = false);
    // funkcje pomocnicze
    template <class t>
    static int podziel(t tab[], int pierwszy, int ostatni, bool odwrotnie = false);
    template <class t>
    static void zamien(t tab[], int id1, int id2);

    // sortowanie introspektywne
    template <class t>
    static void intro_sort(t tab[], int ID_start, int ID_stop, int dozwolone_rek);

    // sortowanie przez kopcowanie
    template <class t>
    static void heap_sort(t tab[], int ID_start, int ID_stop);
      //funkcje pomocnicze heap sort
    template <class t>
    static void kopiec(t tab[], int ID_start, int ID_stop);
    template <class t>
    static void przesun_dol(t tab[], int rootIndex, int ID_stop);


};




template <class t>
void sortowanie::merge_sort(t tab[], int pierwszy, int ostatni, bool odwrotnie) {
    int medium = (ostatni + pierwszy) / 2;
    if (pierwszy != ostatni) {
        merge_sort(tab, pierwszy, medium, odwrotnie);
        merge_sort(tab, medium + 1, ostatni, odwrotnie);

        auto tab_pom = make_unique<t[]>(ostatni - pierwszy + 1);
        int ID = 0, left = pierwszy, right = medium + 1;
        while (left <= medium && right <= ostatni) {
            if (odwrotnie ? (tab[left] > tab[right]) : (tab[left] < tab[right]))
                tab_pom[ID] = tab[left++];
            else
                tab_pom[ID] = tab[right++];
            ID++;
        }
        while (left <= medium)
            tab_pom[ID++] = tab[left++];

        while (right <= ostatni)
            tab_pom[ID++] = tab[right++];

        for (int i = pierwszy, j = 0; i <= ostatni; i++, j++)
            tab[i] = tab_pom[j];
    }
    return;
}

template <class t>
void sortowanie::heap_sort(t tab[], int ID_start, int ID_stop) {
    int ostatni = ID_stop;
    kopiec(tab, ID_start, ID_stop);
    while (ostatni > ID_start + 1) {
        zamien(tab, ID_start, ostatni);
        ostatni--;
        kopiec(tab, ID_start, ostatni);
    }
}

template <class t>
void sortowanie::quick_sort(t tab[], int pierwszy, int ostatni, bool odwrotnie) {
    if (pierwszy < ostatni) {
        int n = podziel(tab, pierwszy, ostatni, odwrotnie);
        quick_sort(tab, pierwszy, n - 1, odwrotnie);
        quick_sort(tab, n + 1, ostatni, odwrotnie);
    }
}
template <class t>
int sortowanie::podziel(t tab[], int pierwszy, int ostatni, bool odwrotnie) {
    int ID = pierwszy + rand() % (ostatni - pierwszy);
    t wartosc = tab[ID];
    zamien(tab, ID, ostatni);

    int indeks_obecny = pierwszy;
    for (int i = pierwszy; i <= ostatni - 1; i++)
        if ((odwrotnie ? (tab[i] > wartosc) : (tab[i] < wartosc))) {
            zamien(tab, i, indeks_obecny);
            indeks_obecny++;
        }
    zamien(tab, indeks_obecny, ostatni);
    return indeks_obecny;
}

template <class t>
void sortowanie::zamien(t tab[], int id1, int id2) {
    t tmp = tab[id1];
    tab[id1] = tab[id2];
    tab[id2] = tmp;
}



template <class t>
void sortowanie::intro_sort(t tab[], int ID_start, int ID_stop, int dozwolone_rek) {
    if (ID_start < ID_stop) {
        if (!dozwolone_rek) {
            heap_sort(tab, ID_start, ID_stop);
            return;
        }
        int n = podziel(tab, ID_start, ID_stop, false);
        intro_sort(tab, ID_start, n - 1, dozwolone_rek - 1);
        intro_sort(tab, n + 1, ID_stop, dozwolone_rek - 1);
    }
}template <class t>


void sortowanie::kopiec(t tab[], int ID_start, int ID_stop) {
    int start = (ID_stop - 1) / 2;
    while (start >= ID_start) {
        przesun_dol(tab, start, ID_stop);
        start = start- 1;
    }
}

template <class t>
void sortowanie::przesun_dol(t tab[], int ID_root, int ID_stop) {
    int korzen = ID_root;
    while (2*korzen+1 <= ID_stop) {
        int dziecko =2*korzen+1 ;
        int swap = korzen;
        if (tab[swap] < tab[dziecko])
            swap = dziecko;
        if (dziecko + 1 <= ID_stop)
            if (tab[swap] < tab[dziecko + 1])
                swap = dziecko + 1;
        if (swap == korzen)
            return;
        else {
            zamien(tab, korzen, swap);
            korzen = swap;
        }
    }
}


