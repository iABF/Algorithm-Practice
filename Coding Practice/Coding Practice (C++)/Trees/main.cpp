#include<iostream>
#include<Windows.h>
#include<vector>
#include<fstream>
#include"BSTree.h"
#include"AVLTree.h"
#include"RBTree.h"
#include"BTree.h"
using namespace std;
int main()
{
    ofstream Out("BTdata.txt");
    LARGE_INTEGER tc, starttime, endtime;
    QueryPerformanceFrequency(&tc);
    double Freq = (double)tc.QuadPart;
    for (int N = 1000; N <= 100000; N += 1000)
    {
        BTree a(4);
        vector<int>istlst;
        vector<int>dltlst;
        double sumtime = 0;
        Out << N << ' ';
        for (int i = 1; i <= N; ++i)
        {
            istlst.push_back(i);
            dltlst.push_back(i);
            //dltlst.push_back(range + 1 - i);
        }
        random_shuffle(istlst.begin(), istlst.end());
        random_shuffle(dltlst.begin(), dltlst.end());
        QueryPerformanceCounter(&starttime);
        for (int i = 0; i < N; i++)a.Insert(istlst[i]);
        QueryPerformanceCounter(&endtime);
        sumtime = (double)(endtime.QuadPart - starttime.QuadPart) / Freq;
        Out << sumtime << ' ';
        QueryPerformanceCounter(&starttime);
        for (int i = 0; i < N; i++)a.Delete(dltlst[i]);
        QueryPerformanceCounter(&endtime);
        sumtime = (double)(endtime.QuadPart - starttime.QuadPart) / Freq;
        Out << sumtime << endl;
    }
    cout << "Over" << endl;
    Out.close();
    system("Pause");
}