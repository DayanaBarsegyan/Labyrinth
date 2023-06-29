#include <iostream>
#include <vector>
using namespace std;
// 0 0 0 0 0 1 0 0 0
// 0 0 1 1 1 1 1 1 0
// 0 0 0 0 1 0 0 1 0
// 0 0 0 1 1 1 0 1 0
// 0 1 1 1 0 0 0 0 0
// 0 1 0 0 0 0 0 0 0

/*
    {0, 0, 0, 0, 0, 1, 0, 0, 0,},
    {0, 1, 1, 1, 0, 1, 0, 1, 0,},
    {0, 1, 0, 1, 0, 1, 0, 1, 0,},
    {0, 1, 0, 1, 1, 1, 0, 1, 0,},
    {1, 1, 0, 0, 1, 1, 0, 1, 0,},
    {0, 0, 0, 0, 0, 0, 0, 0, 0,}
    
*/

int count = 3;
void set_zero(vector<vector<int>> &arr, int i, int j)
{
     if(((arr[i + 1][j] == 0 && arr[i - 1][j] == 0 && arr[i][j + 1] == 0) || 
        (arr[i + 1][j] == 0 && arr[i - 1][j] == 0 && arr[i][j - 1] == 0) ||
        (arr[i][j + 1] == 0 && arr[i][j - 1] == 0 && arr[i - 1][j] == 0) ||
        (arr[i][j + 1] == 0 && arr[i][j - 1] == 0 && arr[i + 1][j] == 0)) && arr[i][j] != 0)
     {
         if(arr[i][j] != 1)
         {
            count--;
         }
         arr[i][j] = 0;
     }
}


bool flag = true;// vor myus uxxutyunnerov chanaparh chpntri ete elqin hasel a
vector<vector<int>>& lab(vector<vector<int>> &arr, int i, int j)
 {
     if(i - 1 < 0 || i + 1 == arr.size() || j - 1 < 0 || j + 1 == arr[0].size())
     {
         flag = false;
         arr[i][j] = count;
         return arr;
     }
     
     if(arr[i][j - 1] == 1 && flag)
     {
         if(arr[i][j] == 1)
         {
            arr[i][j] = count++;
         }
         lab(arr, i, j - 1);
         set_zero(arr, i, j);
     }
     if(arr[i][j + 1] == 1 && flag)
     {
         if(arr[i][j] == 1)
         {
            arr[i][j] = count++;
         }
         lab(arr, i, j + 1);
         set_zero(arr, i, j);
     }
     if(arr[i + 1][j] == 1 && flag)
     {
         if(arr[i][j] == 1)
         {
            arr[i][j] = count++;
         }
         lab(arr, i + 1, j);
         set_zero(arr, i, j);
     }
     if(arr[i - 1][j] == 1 && flag)
     {
         if(arr[i][j] == 1)
         {
            arr[i][j] = count++;
         }
         lab(arr, i - 1, j);
         set_zero(arr, i, j);
     }

     set_zero(arr, i, j);
     return arr;
 }


void print(vector<vector<int>> arr)
{
    for(int i = 0; i < arr.size(); i++)
        {
        for(int j = 0; j < arr[i].size(); j++)
            cout << arr[i][j] <<"    ";
        cout << endl << endl << endl << endl;
    }
}


void set_one_to_zero(vector<vector<int>>& arr)
{
    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j < arr[i].size(); j++)
            if(arr[i][j] == 1)
            {
                arr[i][j] = 0;
            }
        }
}


int main() {
    cout << "The road is shown by increasing numbers" << endl;
    vector<vector<int>> arr = {{0, 0, 0, 0, 0, 1, 0, 0, 0,},
                               {0, 0, 1, 1, 1, 1, 1, 1, 0,},
                               {0, 0, 1, 0, 1, 0, 0, 1, 0,},
                               {0, 0, 0, 1, 1, 1, 0, 1, 0,},
                               {0, 1, 1, 1, 0, 0, 0, 1, 0,},
                               {0, 0, 0, 0, 0, 0, 0, 1, 0,}};
    int i = 0;
    int j = 5;
    {
        arr[i][j] = 2;
        lab(arr, i + 1, j);
        set_one_to_zero(arr);
        print(arr);
    }
};