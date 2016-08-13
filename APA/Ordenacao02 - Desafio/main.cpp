#include <iostream>
#include <vector>
using namespace std;

template <class T>
vector<T> selectionSort(const vector<T> &arr)
{
    vector<T> sortedArray(arr.size());
    sortedArray = arr;

	int pos_min,temp;
	for (int i=0; i < arr.size() - 1; i++)
	{
	    pos_min = i;
		for (int j=i+1; j < arr.size(); j++)
		{
		if (arr[j] < sortedArray[pos_min])
                   pos_min=j;
		}


            if (pos_min != i)
            {
                 temp = sortedArray[i];
                 sortedArray[i] = sortedArray[pos_min];
                 sortedArray[pos_min] = temp;
            }
    return sortedArray;

	}
}
void ordenaColours (vector<int> v, vector<char> c){
    //Divide em 3 vetores por cor
    //ordena cada vetor
    //junta novamente

    vector<int> NumR,NumG,NumB;
    vector<char> ColR,ColG,ColB;

    for(int i = 0; i < c.size() ;i++){
        if(c[i] == 'R'){
            ColR.push_back(c[i]);
            NumR.push_back(v[i]);
        }
        if(c[i] == 'G'){
            ColG.push_back(c[i]);
            NumG.push_back(v[i]);
        }
        if(c[i] == 'B'){
            ColB.push_back(c[i]);
            NumB.push_back(v[i]);
        }
    }
    NumR = selectionSort(NumR);
    NumG = selectionSort(NumG);
    NumB = selectionSort(NumB);

    vector<int> result;
    result.reserve(NumR.size() + NumG.size() + NumB.size());
    result.insert(result.end(), NumR.begin(), NumR.end());
    result.insert(result.end(), NumG.begin(), NumG.end());
    result.insert(result.end(), NumB.begin(), NumB.end());

    for(int i = 0; i < result.size(); i++){
        cout << result[i] << endl;
    }
}

int main()
{
    vector<int> v;
    vector<char> colours;
    int var;
    char color;
    while(true){
        cin >> color;
        cin >> var;
        if(cin.eof()) break;
        v.push_back(var);
        colours.push_back(color);
    }
    ordenaColours(v, colours);
}

