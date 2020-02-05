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
  
  
  
  int main(int argc,char* argv[])
{ 
  //�N���Ū�J
       char type; //type of graph --undirected or directed
       int n; //number of vertex
       int m; //number of edge      
       fstream fin;
       fstream fout;
       fin.open(argv[1],ios::in);
       fout.open(argv[2],ios::out);
       fin>>type;
       fin>>n;
       fin>>m;
       int u;
       int v;
       int w;
       //�H�o�T���ܼƨӱ�u v���node�� w��weight
//undirected �N��MST�Ӱ� ���غcgraph �A��edge����i�h       
       if(type=='u'){
         
           graph_MST MST(n,m);
           while(fin>>u>>v>>w)
         {       MST.add_edge(u,v,w);
                                                                                               }
                                                                                            
           srand( (int)time(NULL)); 
           int r;
           r=rand()%n;
           MST.MST_Prim(r); 
           //�H���q0��n-1��@�I��source
           
           //�ǳ�output
           fout<<MST.total_weight<<endl;
           for(int i=0;i<=n-2;i++){
             for(int j=i+1;j<=n-1;j++){
                 //�]��undirected �O���V output��edge(u,v)�u�ο�X�@���Y�i
                 if(MST.adjacency_matrix[i][j].second==1 ) //second�N��edge�s�b
                   {  fout<<i<<" "<<j<<" "<<MST.adjacency_matrix[i][j].first<<endl;
                   
                                         }
                                                                 }} }
                                                                                               
                                                                                               
//directed�������٨S��                                                                                              
       else if(type=='d'){
          directed_MST MST(n,m);
           while(fin>>u>>v>>w)
         {       MST.add_edge(u,v,w);
                                                                                               }
                                                                                            
           srand( (int)time(NULL)); 
           int r;
           r=rand()%n;
           MST.MST_Prim(r); 
           //�H���q0��n-1��@�I��source
           
           //�ǳ�output
           fout<<MST.total_weight<<endl;
           for(int i=0;i<=n-1;i++){
             for(int j=0;j<=n-1;j++){
                 //�]��undirected �O���V output��edge(u,v)�u�ο�X�@���Y�i
                 if(MST.adjacency_matrix[i][j].second==1 ) //second�N��edge�s�b
                   {  fout<<i<<" "<<j<<" "<<MST.adjacency_matrix[i][j].first<<endl;
                   
                                         }
                                                                 }}}
             
             
//             fout<<type<<endl;
//             fout<<n<<endl;
//             fout<<m<<endl;
//             for (int i=0;i<n;i++){
//               //iterator�����<�o�ӹB��Ÿ�
//               for(list<pair<int,int> >::iterator it=adjacent[i].begin();
//                   it!=adjacent[i].end();         
//                   it++){
//                     fout<<i<<" "<<(*it).first<<" "<<(*it).second<<endl;        
//                                  //�O�o��Pointer
//                                                                 }}
    //#TODO:�t��k�}�l �ѨMcycle breaking







      fin.close();
      fout.close();
      return 0;
}

