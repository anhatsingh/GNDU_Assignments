#include <iostream>

using namespace std;

class Sort_Char{
    void swap(char a[], char b[]){
        char temp[100];
        int i = 0;
        while(a[i] != '\0'){
            temp[i] = a[i];
            i++;
        }
        temp[i] = '\0';

        int j = 0;
        while(b[j] != '\0'){
            a[j] = b[j];
            j++;
        }
        a[j] = '\0';

        int k = 0;
        while(temp[k] != '\0'){
            b[k] = temp[k];
            k++;
        }
        b[k] = '\0';
    }

    public:
        void sort_name(char arr[10][100]){
            for(int a = 0; a < 10 -1; a++){
                for(int i = 0; i < 10 - a - 1; i++){
                    if(arr[i][0] > arr[i+1][0]){
                        swap(arr[i], arr[i+1]);                        
                    }
                }
            }
        }
};


int main(){
    Sort_Char Sorter;
    char A[10][100] = {"AnilKumar", "RajandeepSingh", "RamandeepKaur", "ManpreetKaur", "KiranbirKaur", "GurdevSingh", "Pakhoke", "SatbirKaur", "SandeepSharma","PrabhsimranSingh"};

    Sorter.sort_name(A);

    for(int i =0; i < 10; i++){
        cout << A[i] << " ";
    }

    return 0;
}