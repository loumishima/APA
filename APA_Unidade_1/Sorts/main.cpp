#include <iostream>
#include <vector>
using namespace std;
typedef vector<int>::iterator vec_it;
void insertion_sort (vector<int>arr){
	 	int j, temp;

	for (int i = 0; i < arr.size(); i++){
		j = i;

		while (j > 0 && arr[j] < arr[j-1]){
			  temp = arr[j];
			  arr[j] = arr[j-1];
			  arr[j-1] = temp;
			  j--;
			  }
		}

		 for(int i = 0; i < arr.size(); i++){
            cout << arr[i] << endl;
        }
}
void selection_sort(vector<int> arr)
{

	int pos_min,temp;
	for (int i=0; i < arr.size() - 1; i++)
	{
	    pos_min = i;
		for (int j=i+1; j < arr.size(); j++)
		{
		if (arr[j] < arr[pos_min])
                   pos_min=j;
		}


            if (pos_min != i)
            {
                 temp = arr[i];
                 arr[i] = arr[pos_min];
                 arr[pos_min] = temp;
            }


	}

	for(int i = 0; i < arr.size(); i++){
            cout << arr[i] << endl;
        }
}
void merge(vec_it left, vec_it left_end, vec_it right, vec_it right_end, vec_it numbers)
{
    while (left != left_end) {
        if (*left < *right || right == right_end) {
            *numbers = *left;
            ++left;
        } else {
            *numbers = *right;
            ++right;
        }

        ++numbers;
    }

    while (right != right_end) {
        *numbers = *right;
        ++right;
        ++numbers;
    }
}

void merge_sort(vector<int> arr)
{
    if (arr.size() <= 1) {
        return;
    }

    vector<int>::size_type middle = arr.size() / 2;
    vector<int> left(arr.begin(), arr.begin() + middle);
    vector<int> right(arr.begin() + middle, arr.end());

    merge_sort(left);
    merge_sort(right);

    merge(left.begin(), left.end(), right.begin(), right.end(), arr.begin());
}
void quicksort(vector<int> arr, int esq, int dir){
    int pivo = esq,i,ch,j;
    for(i=esq+1;i<=dir;i++){
        j = i;
        if(arr[j] < arr[pivo]){
         ch = arr[j];
         while(j > pivo){
            arr[j] = arr[j-1];
            j--;
         }
         arr[j] = ch;
         pivo++;
        }
    }
    if(pivo-1 >= esq){
        quicksort(arr,esq,pivo-1);
    }
    if(pivo+1 <= dir){
        quicksort(arr,pivo+1,dir);
    }
     cout << arr[j] << endl;
 }

int main()
{
    vector<int> v;
    int var;
    while(true){
        cin >> var;
        if(cin.eof()) break;
        v.push_back(var);
    }

    cout << "Insertion Sort" << endl;
    insertion_sort(v);
    cout << "Selection Sort" << endl;
    selection_sort(v);



}


