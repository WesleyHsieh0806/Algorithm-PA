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
    //visited==0�N���٦bQueue��
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
      
    key[r]=0;  //source �qr�}�l��
    //�i�Jwhile�j��
    for(int i=0;i<=n-1;i++)  //�۷��while Q������0 line6 �]����n��queue�@�w�S�F��F
    {  int u=Extract_Max();
       
       visited[u]=1; //�N��qqueue�X��
       if(u!=r){

       
       adjacency_matrix[predecessor[u] ][u].second=0;
       
       total_weight-=adjacency_matrix[predecessor[u]][u].first; 
                                           }
       
       //�]���̫�output�O�ngraph edge-MST edge�ҥHMST��쪺edge�n�]�w��0 , �N��Qremove���s�b�F
       //�ӨC��u�Q��X�� �N�N��edge(u,predecessor[u])�QMST���  
       //�M��MST��edge��weight�n���� �~���X�ڭ̭n��output                    
       for(int v=0;v<n;v++){
            if(adjacency_matrix[u][v].second==1 && visited[v]==0 
            &&  adjacency_matrix[u][v].first>key[v])  
            //adjacency_matrix[u][v].second�P�_�O�_uv�۳s
            //visited[v]�P�_v�O�_�bqueue��
            {  predecessor[v]=u;
               key[v]=adjacency_matrix[u][v].first;}
                                                  }  
                                                  }
}
  