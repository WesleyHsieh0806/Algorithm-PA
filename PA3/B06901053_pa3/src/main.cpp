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
  //將資料讀入
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
       //以這三個變數來接u v兩個node跟 w接weight
//undirected 就用MST來做 先建構graph 再把edge都丟進去       
       if(type=='u'){
         
           graph_MST MST(n,m);
           while(fin>>u>>v>>w)
         {       MST.add_edge(u,v,w);
                                                                                               }
                                                                                            
           srand( (int)time(NULL)); 
           int r;
           r=rand()%n;
           MST.MST_Prim(r); 
           //隨機從0到n-1選一點當source
           
           //準備output
           fout<<MST.total_weight<<endl;
           for(int i=0;i<=n-2;i++){
             for(int j=i+1;j<=n-1;j++){
                 //因為undirected 是雙向 output的edge(u,v)只用輸出一次即可
                 if(MST.adjacency_matrix[i][j].second==1 ) //second代表此edge存在
                   {  fout<<i<<" "<<j<<" "<<MST.adjacency_matrix[i][j].first<<endl;
                   
                                         }
                                                                 }} }
                                                                                               
                                                                                               
//directed的部分還沒做                                                                                              
       else if(type=='d'){
          directed_MST MST(n,m);
           while(fin>>u>>v>>w)
         {       MST.add_edge(u,v,w);
                                                                                               }
                                                                                            
           srand( (int)time(NULL)); 
           int r;
           r=rand()%n;
           MST.MST_Prim(r); 
           //隨機從0到n-1選一點當source
           
           //準備output
           fout<<MST.total_weight<<endl;
           for(int i=0;i<=n-1;i++){
             for(int j=0;j<=n-1;j++){
                 //因為undirected 是雙向 output的edge(u,v)只用輸出一次即可
                 if(MST.adjacency_matrix[i][j].second==1 ) //second代表此edge存在
                   {  fout<<i<<" "<<j<<" "<<MST.adjacency_matrix[i][j].first<<endl;
                   
                                         }
                                                                 }}}
             
             
//             fout<<type<<endl;
//             fout<<n<<endl;
//             fout<<m<<endl;
//             for (int i=0;i<n;i++){
//               //iterator不支持<這個運算符號
//               for(list<pair<int,int> >::iterator it=adjacent[i].begin();
//                   it!=adjacent[i].end();         
//                   it++){
//                     fout<<i<<" "<<(*it).first<<" "<<(*it).second<<endl;        
//                                  //記得用Pointer
//                                                                 }}
    //#TODO:演算法開始 解決cycle breaking







      fin.close();
      fout.close();
      return 0;
}

