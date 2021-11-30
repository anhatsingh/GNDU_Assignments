#include <iostream>

using namespace std;

class String{
    public:        
        int cString_frequency(char arr[], char c){
            int count = 0;
            int i = 0;
            while(arr[i] != '\0'){
                if(arr[i] == c) {
                    count +=1;
                }
                i++;
            }
            return count;
        }
};


int main(){
    char my_str[100];
    cin >> my_str;
    char c;
    cin >> c;

    String my;
    cout << my.cString_frequency(my_str, c) << endl;
}