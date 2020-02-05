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
    int total_weight; //此graph最後只會剩下removed edge 所以total weight就是removed edge的weight 
    //constructor
    directed_MST(int N,int M){
      total_weight=0;
      n=N;
      m=M;
      adjacency_matrix.resize(N);
      for(int i=0;i<N;i++){
        adjacency_matrix[i].assign(N,make_pair(0,0));   //weight 跟edge是否存在都預設成0
                         }
      predecessor.resize(N);
      visited.resize(N);
      key.resize(N);    };
      
    void add_edge(int u,int v,int w) //用來input graph的edge
    {  adjacency_matrix[u][v]=make_pair(w,1);
       
       total_weight=total_weight+w;                                               };
    //用Prim演算法找maximum spanning tree
    void MST_Prim(int); 
    int Extract_Max(); //用來extract最大 key的vertex  
    vector< vector<pair<int,bool> > > adjacency_matrix; //MST的adjacency matrix一個紀錄weight 一個紀錄此edge是否存在
        
  private:
    
    int n;
    int m;
    vector<int> predecessor;//vertex的predecessor
    vector<int> key;//vertex的key MST中相當於跟predecessor的edge weight
    vector<bool> visited;//用來判斷該vertex是否在queue內 visit過代表已經丟出queue 則記為1
};