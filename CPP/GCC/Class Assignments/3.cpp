#include <iostream>
using namespace std;

class List_Worker{    
    public:
        void bubble_sort(int arr[], int n){
            for(int i = 0; i<n; i++){
                for(int j = 0; j < n- i - 1; j++){
                    if(arr[j] > arr[j+1]){                        
                        int temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j+1] = temp;
                    }
                }
            }
        }

        int linear_search(int arr[], int n, int item){
            for(int i = 0; i<n; i++){
                if (arr[i] == item){
                    return i;
                }
            }
            return -1;
        }

        int binary_search(int arr[], int n, int item){ 
            bubble_sort(arr, n);
            int beg = 0, end = n - 1;
            int mid = (int) ((beg+end)/2);

            while(beg<end and arr[mid] != item){                
                if (item < arr[mid]){
                    end = mid - 1;
                } else if(item > arr[mid]){
                    beg = mid + 1;
                }
                mid = (int) ((beg+end)/2);
            }

            if(arr[mid] == item){
                return mid;
            } else {
                return -1;
            }

        }

        int frequency(string s, char c){
            int len = s.length();
            int count = 0;
            for(int i = 0; i<len; i++){
                if (s[i] == c){
                    count += 1;
                }
            }
            return count;

        }


};

int main(){
    int array[] = {10,20,2,3,4,5,9,12,34,87};
    
    List_Worker my_worker;
    my_worker.bubble_sort(array, 10);

    cout << my_worker.linear_search(array, 10, 87) << endl;
    cout << my_worker.linear_search(array, 10, 55) << endl;
    cout << my_worker.binary_search(array, 10, 87) << endl;
    cout << my_worker.binary_search(array, 10, 55) << endl;

    for(int i = 0; i<10;i++){
        cout << array[i] << " ";
    }

    cout << endl;

    string a = "My name is Anhat Singh";
    cout << my_worker.frequency(a, 'n') << endl;

    return 0;
}