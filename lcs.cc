#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

ifstream fd;
bool DEBUG = false;// DEBUG mode for testing
int k;
int mFound = 0;
const int MAX = 999;// MAX amount of allowed chars
vector <char> a;
vector <char> b;
vector <char> matches;

// a.swap(b);
    // Time: O(n)
    // Space: O(n)

void load(char * filename);
    // Time: O(6)
    // Space: O(3)
void debugPrint();
void readStrings();
    // Time: O(4n + 1)
    // Space: O(1)
void weird();
    // Time: O((n^2 * k) + 4n)
    // Space: O(2(MAX) + 9)
void insertionSort(char arr[], int n, int m);
    // Time: O(n*k)
    // Space: O(n + 6)
void printChar(char arr[], int n, int m);
    // Time: O(n)
    // Space: O(MAX + 3)
void printChar(vector <char> arr, int n, int m);
    // Time: O(n)
    // Space: O(n + 3 )
bool checkMatch(char arr1[], char arr2[], int n, int m);
    // Time: O(n)
    // Space: O(2n + 3)

int main (int argc,char *argv[]){ 
    // Time: O((n^2 * k))
    // Space: O(2(MAX) + 2n)

    load(argv[1]);
    readStrings();
    weird();
    if (DEBUG)
    {
        debugPrint();
        cout<<"Matches Found: ";
    }
    
    cout<<mFound<<endl;
    printChar(matches, matches.size(), 0);
}

bool checkMatch(char arr1[], int a, int b, char arr2[], int n){

    do
    {
        if (arr1[a] == arr2[n])
        {

            a++;
            n++;
        }
        else{
            return false;
        }

    } while (a < b);
    
    
    mFound++;
    return true;
    
}

void weird(){
    char aSort[MAX];
    char bSort[MAX];
    size_t aIndex = 0;
    size_t bIndex = 0;
    if (a.size() < b.size())
    {
        a.swap(b);
        // Time: O(n)
        // Space: 0(n)
    }
    for (size_t i = 0; i < a.size() - 1; i ++)
    {
        aSort[i] = a[i];
    }
    for (size_t i = 0; i < b.size(); i++)
    {
        bSort[i] = b[i];
    }
    if (a.size() < b.size())
    {
        a.swap(b);
    }
    
    for (size_t i = 0; i < a.size() - 1; i += k)
        {insertionSort (aSort, i + k, i);}
    for (size_t i = 0; i < b.size() - 1; i += k)
        {insertionSort (bSort, i + k, i);}

    

        for (size_t j = 0; j < b.size() - 1; j += k)
        {
            for (size_t i = 0; i < a.size() - 1; i += k)
            {
                if (DEBUG){
                    printChar(aSort, aIndex + k, aIndex);
                    printChar(bSort, bIndex + k, bIndex);
                }
                if ((aIndex > a.size() - 1) || (bIndex > b.size() - 1))
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
    }
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
    do
    {
        fd.get(c);               
        a.push_back(c);

    } while (c != '\n');
    do
    {
        fd.get(c);
        b.push_back(c);

    } while (c != '\n');
}