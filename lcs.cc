#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "cell.h"

using namespace std;

ifstream fd;
bool DEBUG = true;
int k;
int mFound = 0;
const int MAX = 999;
vector <char> a;
vector <char> b;
vector <char> matches;
cell cells[MAX][MAX];


void load(char * filename);
void debugPrint();
void readStrings();
void tablePrint();
void createTable();
void weird();
void insertionSort(char arr[], int n, int m);
void printChar(char arr[], int n, int m);
void printChar(vector <char> arr, int n, int m);
bool checkMatch(char arr1[], char arr2[], int n, int m);

int main (int argc,char *argv[]){ 

    load(argv[1]);
    readStrings();
    //createTable();
    weird();
    if (DEBUG)
    {
        debugPrint();
        //tablePrint();
    }
}

bool checkMatch(char arr1[], int a, int b, char arr2[], int n){
    bool match = false;
    // cout<<endl<<"---------------------------------"<<endl; 
    // printChar(arr1, n, m);
    // cout<< endl;
    // printChar(arr2, n, m);
    

    do
    {
        //cout<<arr1[a];
        if (arr1[a] == arr2[n])
        {
            a++;
            n++;
            match = true;
        }
        else{
            return false;
        }

        
    } while (a < b);
    //cout<<endl;
    mFound++;
    return true;
    
}

void weird(){
    char aSort[MAX];
    char bSort[MAX];
    bool flag = false;
    int aIndex = 0;
    int bIndex = 0;
    for (size_t i = 0; i < a.size() - 1; i ++)
    {
        aSort[i] = a[i];
    }
    for (size_t i = 0; i < b.size(); i++)
    {
        bSort[i] = b[i];
    }
    
    for (size_t i = 0; i < a.size() - 1; i += k)
        {insertionSort (aSort, i + k, i);}
    for (size_t i = 0; i < b.size() - 1; i += k)
        {insertionSort (bSort, i + k, i);}

    // if (a.size() >= b.size())
    // {

        for (size_t j = 0; j < b.size() - 1; j += k)
        {
            for (size_t i = 0; i < a.size() - 1; i += k)
            {
                printChar(aSort, aIndex + k, aIndex);
                printChar(bSort, bIndex + k, bIndex);
                if ((aIndex > a.size() - 2) || (bIndex > b.size() - 1))
                {
                    cout<<"too Far!"<<endl;
                    break;
                }
                else if (!(checkMatch(aSort, aIndex, aIndex + k, bSort, bIndex)))
                {
                    // cout<<endl;
                    // cout<<"b";
                    // cout<<endl;
                    // cout<<bIndex<<" "<<bIndex + k<<endl;
                    // cout<<endl;
                    // cout<<"a";
                    // cout<<endl;
                    // cout<<aIndex<<" "<<aIndex + k<<endl;
                    // cout<<endl;
                    cout<<"Not Found ;/";
                    cout<<endl;
                    aIndex += k; 
                        
                }
                else 
                {
                    cout<<endl;
                    cout<<"Found ;)";
                    cout<<endl;
                    aIndex += k;
                    //bIndex += k;
                    break;
                }
                cout<<endl;
            }
            bIndex += k;
            aIndex = bIndex;
        }
    // }

    if (DEBUG){
        cout<<"\nsorted strings: \n";
        printChar(aSort, a.size() - 1, 0);
        printChar(bSort, b.size() - 1, 0);
                
    }
}

void insertionSort(char arr[], int n, int m)
{
    int i, j;
    char key;
    //cout<<"sort: ";
    for (i = m ; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
 
        while (j >= m && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        //cout<<arr[j + 1];
    }
    //cout<<endl;
}

void printChar(vector <char> arr, int n, int m){

    for (int i = m; i < n; i++)
    {
        cout<<arr[i];
    }
    cout<<endl;
}

void printChar(char arr[], int n, int m){

    for (int i = m; i < n; i++)
    {
        cout<<arr[i];
    }
    cout<<endl;
}

void load(char * filename){
    if (DEBUG == true)
    {
        cout<<"Reading from filename: "<<filename<<endl;
    }
    char c;
    fd.open(filename);
    fd.get(c);
    k = c-48;
    fd.get(c);
}

void debugPrint(){
    
    cout<<"K: "<<k<<endl<<"String A: ";
    printChar(a, a.size() - 1, 0);
    
    cout<<"Size: "<<a.size() - 1<<endl;
    cout<<"String B: ";

    printChar(b, b.size() - 1, 0);

    cout<<"Size: "<<b.size() - 1<<endl;

    cout<<"Matches Found: "<<mFound<<endl;

}

void readStrings(){
    char c;
    int i = 0;
    do
    {

        fd.get(c);               

        a.push_back(c);
        i++;
    } while (c != '\n');
    i = 0;
    do
    {
        fd.get(c);
        b.push_back(c);
        i++;
    } while (c != '\n');
}