#include <iostream.h>
#include <conio.h>


class list{
	private:
		int arr[1000];
		int MAX;
	public:
		list(int);
		void input_list();		
		void bubble_sort();		
		int linear_search(int);
		int binary_search(int);
		void display_list();
};

list::list(int n){
	MAX = n;
	for(int i = 0; i <MAX;i++){
		arr[i] = 0;
	}
}

void list::input_list(){
	for(int i = 0; i< MAX;i++){
		cout << "Enter item number " << i+1 << "/" << MAX << " : ";
		cin >> arr[i];
	}
}

void list::bubble_sort(){
	for(int j = 0; j < MAX; j++){
		for(int i = 0; i< MAX - j - 1;i++){
			if(arr[i] > arr[i+1]){
				int temp = arr[i+1];
				arr[i+1] = arr[i];
				arr[i] = temp;
			}
		}
	}
}

int list::linear_search(int item){
	for(int i = 0; i< MAX;i++){
		if(arr[i] == item){
			return i;
		}
	}
	return -1;	
}

int list::binary_search(int item){
	this->bubble_sort();
	int beg = 0, end = MAX-1;
	int mid = (int) ((beg+end)/2);
	
	while(beg < end && arr[mid] != item){
		if(item > arr[mid]){
			beg = mid + 1;
		}
		else if(item < arr[mid]){
			end = mid - 1;
		}
		mid = (int) ((beg+end)/2);
	}
	
	return (arr[mid] == item ? mid : -1);
}

void list::display_list(){
	for(int i = 0; i< MAX;i++){
		cout << i+1 << ": " << arr[i] << endl;
	}
}

int main(){
clrscr();

int SIZE = 0;
cout << "Enter size of list: "; cin >> SIZE;

list m(SIZE);
m.input_list();
cout << m.linear_search(10) << endl;
cout << m.binary_search(10) << endl;
m.display_list();
getch();
return 0;
}