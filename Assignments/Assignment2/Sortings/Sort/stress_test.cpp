#ifndef stress_test_H
#define stress_test_H
#include<iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <cassert>
#include "selectionSort.h"
#include "insertionSort.h"
#include "mergeSort.h"
#include "quickSort.h"
using namespace std;
void print_vector(vector<int>v)
{
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
void stress_test_merge_quick(void (*funSort)(vector<int>&,int l,int r))
{
    srand((unsigned)time(0));
    int tests = (rand()%1000)+0;
    for(int j=0;j<tests;j++)
    {
        int size = (rand()%1000)+0;
        vector<int>v1(size),v2(size);
        for(int i=0; i<size; i++){
            int num = (rand()%100)+1;
            v1[i] = num;
            v2[i] = num;
        }
        sort(v2.begin(),v2.end());
        funSort(v1,0,size-1);
        if(v1!=v2)
        {
            cout<<"*********Error in test"<<j<<"*********"<<endl;
            cout<<"Your sort : "<<endl;
            print_vector(v1);
            cout<<"built-in sort : "<<endl;
            print_vector(v2);
            cout<<"*******************************"<<endl;
            assert(v1==v2);
        }
        else
        {
            cout<<"test: "<<j<<" Succeeded "<<endl;
        }
    }
}

void stress_test(void (*funSort)(vector<int>&))
{
    srand((unsigned)time(0));
    int tests = (rand()%1000)+0;
    for(int j=0;j<tests;j++)
    {
        int size = (rand()%1000)+0;
        vector<int>v1(size),v2(size);
        for(int i=0; i<size; i++){
            int num = (rand()%100)+1;
            v1[i] = num;
            v2[i] = num;
        }
        sort(v2.begin(),v2.end());
        funSort(v1);
        if(v1!=v2)
        {
            cout<<"*********Error in test"<<j<<"*********"<<endl;
            cout<<"Your sort : "<<endl;
            print_vector(v1);
            cout<<"built-in sort : "<<endl;
            print_vector(v2);
            cout<<"*******************************"<<endl;
            assert(v1==v2);
        }
        else
        {
            cout<<"test: "<<j<<" Succeeded "<<endl;
        }
    }
}
#endif
int main()
{
    stress_test(insertion_sort);
    stress_test(selection_sort);
    stress_test_merge_quick(merge_sort);
    stress_test_merge_quick(randomized_quick_sort);
    return 0;
}