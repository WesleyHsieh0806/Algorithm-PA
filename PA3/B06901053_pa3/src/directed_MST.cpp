#include<iostream>
#include<fstream>
#include<list>
#include<vector>
#include<cmath>
#include <stdlib.h>
#include <time.h>
#include "graph_MST.hpp"
#include "directed_MST.hpp"
using namespace std;
int directed_MST::Extract_Max(){
    //visited==0代表還在Queue內
    int max=-pow(2,30);
    int u=-5;
    for(int i=0;i<n;i++)
    {  if((  visited[i]==0 ) &&(  key[i]>max  ))
             {    max=key[i];
                  u=i;               }   }


    return u;
}
void directed_MST::MST_Prim(int r){
    //initialize the MST graph
    for(int i=0;i<=n-1;i++){
      key[i]=-pow(2,30);
      predecessor[i]=-1;
      visited[i]=0;}
      
    key[r]=0;  //source 從r開始做
    //進入while迴圈
    for(int i=0;i<=n-1;i++)  //相當於while Q不等於0 line6 因為做n次queue一定沒東西了
    {  int u=Extract_Max();
       
       visited[u]=1; //代表從queue出來
       if(u!=r){

       
       adjacency_matrix[predecessor[u] ][u].second=0;
       
       total_weight-=adjacency_matrix[predecessor[u]][u].first; 
                                           }
       
       //因為最後output是要graph edge-MST edge所以MST找到的edge要設定成0 , 代表被remove不存在了
       //而每次u被抽出來 就代表edge(u,predecessor[u])被MST找到  
       //然後MST的edge的weight要扣掉 才能算出我們要的output                    
       for(int v=0;v<n;v++){
            if(adjacency_matrix[u][v].second==1 && visited[v]==0 
            &&  adjacency_matrix[u][v].first>key[v])  
            //adjacency_matrix[u][v].second判斷是否uv相連
            //visited[v]判斷v是否在queue當中
            {  predecessor[v]=u;
               key[v]=adjacency_matrix[u][v].first;}
                                                  }  
                                                  }
}
  