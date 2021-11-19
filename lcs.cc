#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

ifstream fd;
bool DEBUG = false;
int k;
int mFound = 0;
const int MAX = 999;
vector <char> a;
vector <char> b;
vector <char> matches;


void load(char * filename);
void debugPrint();
void readStrings();
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
        cout<<"Matches Found: ";
    }
    
    cout<<mFound<<endl;
    printChar(matches, matches.size(), 0);
}

bool checkMatch(char arr1[], int a, int b, char arr2[], int n){
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
    size_t aIndex = 0;
    size_t bIndex = 0;
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
                if (DEBUG){
                    printChar(aSort, aIndex + k, aIndex);
                    printChar(bSort, bIndex + k, bIndex);
                }
                if ((aIndex > a.size() - 2) || (bIndex > b.size() - 1))
                {
                    if (DEBUG){
                        cout<<"too Far!"<<endl;
                    }
                    break;
                }
                else if (!(checkMatch(aSort, aIndex, aIndex + k, bSort, bIndex)))
                {   
                    if (DEBUG){
                        cout<<"a";
                        cout<<aIndex<<" "<<aIndex + k<<endl;
                        cout<<endl;
                        cout<<"b";
                        cout<<bIndex<<" "<<bIndex + k<<endl;
                        cout<<endl;
                        cout<<"Not Found ;/";
                        cout<<endl;
                    }
                    aIndex += k; 
                        
                }
                else 
                {
                    if (DEBUG){
                        cout<<endl;
                        cout<<"Found ;)";
                        cout<<endl;
                    }
                    for (size_t i = aIndex; i < aIndex + k; i++)
                    {
                        matches.push_back(a[i]);
                    }
                    aIndex += k;
                    //bIndex += k;
                    break;
                }
                if (DEBUG){
                    cout<<endl;
                }
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