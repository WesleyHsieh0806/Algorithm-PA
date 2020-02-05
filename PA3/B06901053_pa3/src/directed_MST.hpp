#include<iostream>
#include<fstream>
#include<list>
#include<vector>
#include<cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;
class directed_MST{
  public:
    int total_weight; //��graph�̫�u�|�ѤUremoved edge �ҥHtotal weight�N�Oremoved edge��weight 
    //constructor
    directed_MST(int N,int M){
      total_weight=0;
      n=N;
      m=M;
      adjacency_matrix.resize(N);
      for(int i=0;i<N;i++){
        adjacency_matrix[i].assign(N,make_pair(0,0));   //weight ��edge�O�_�s�b���w�]��0
                         }
      predecessor.resize(N);
      visited.resize(N);
      key.resize(N);    };
      
    void add_edge(int u,int v,int w) //�Ψ�input graph��edge
    {  adjacency_matrix[u][v]=make_pair(w,1);
       
       total_weight=total_weight+w;                                               };
    //��Prim�t��k��maximum spanning tree
    void MST_Prim(int); 
    int Extract_Max(); //�Ψ�extract�̤j key��vertex  
    vector< vector<pair<int,bool> > > adjacency_matrix; //MST��adjacency matrix�@�Ӭ���weight �@�Ӭ�����edge�O�_�s�b
        
  private:
    
    int n;
    int m;
    vector<int> predecessor;//vertex��predecessor
    vector<int> key;//vertex��key MST���۷���predecessor��edge weight
    vector<bool> visited;//�ΨӧP�_��vertex�O�_�bqueue�� visit�L�N��w�g��Xqueue �h�O��1
};