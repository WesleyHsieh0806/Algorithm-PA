#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
void help_message()
{
    cout<<"usage:mps [public_cases\\input file] [sample_output\\output file]"<<endl;



}
void InsertionSort(vector<int>& MIS_Chord_i,vector<int>& MIS_Chord_j)
{
    //開始sortMSI_Chord_i並同時調整MIS_Chord_j
    int i;

    for(i=1 ; i<MIS_Chord_i.size() ; i++)
    {
        int key_i=MIS_Chord_i[i];
        int key_j=MIS_Chord_j[i];

        int j=i-1;
        while(j>=0&&MIS_Chord_i[j]>key_i)
        {
            MIS_Chord_i[j+1]=MIS_Chord_i[j];
            MIS_Chord_j[j+1]=MIS_Chord_j[j];
            j--;
        }

        MIS_Chord_i[j+1]=key_i;
        MIS_Chord_j[j+1]=key_j;
    }
}
//要注意reference位置 且用reference才不會浪費太多stack記憶體

//用此function找到MIS[0][N-1]到底有哪些不相交弦 case2 case3都能確定弦所以要特別注意
void find_result_chord(vector<vector<int> >&MIS_CASE,vector<int> &MIS_Chord_i
                       ,vector<int>&MIS_Chord_j,int i,int j,vector<int >&chord_point_i)
{
    if(i<j)
    {

        int k=chord_point_i[j];

        switch(MIS_CASE[i][j])
        {
        case 1:
            find_result_chord(MIS_CASE,MIS_Chord_i
                              ,MIS_Chord_j,i,j-1,chord_point_i);
            break;
        case 2:
//把k加入到MIS_Chord_i 把j加入到MIS_Chord_j

            MIS_Chord_i.push_back(k);
            //chord_point_i[j] 就是k 因為chord_point_i[j]代表跟j相連的那點
            MIS_Chord_j.push_back(j);
            find_result_chord(MIS_CASE,MIS_Chord_i
                              ,MIS_Chord_j,i,k-1,chord_point_i) ;
            find_result_chord(MIS_CASE,MIS_Chord_i
                              ,MIS_Chord_j,k+1,j-1,chord_point_i) ;
            break;
        case 3:
            MIS_Chord_i.push_back(i);
            MIS_Chord_j.push_back(j);
            find_result_chord(MIS_CASE,MIS_Chord_i
                              ,MIS_Chord_j,i+1,j-1,chord_point_i) ;
            break;
        case 4:
            find_result_chord(MIS_CASE,MIS_Chord_i
                              ,MIS_Chord_j,i,j-1,chord_point_i);
            break;


        }
    }


}

int main(int argc,char*argv[]) //argc跟argv是main函示原本就有的一種參數 類似python中argparse給予參數詳情參考recitation
{
    if(argc != 3)
    {
        help_message();
        return 0;
    }
    int N;//Node數量
    int i=0;
    int j=0;
    int index;
    vector<int>chord_point_input_left;
    vector<int>chord_point_input_right;
    vector<int>chord_point_i; //此vector紀錄每個index連線到的另外一點 index==i value==j
    //char buffer[200]; //假如使用getline可以把一整行輸入到buffer這個陣列(直到遇到'\n'不是空白鍵)

    fstream fin;
    fin.open(argv[1],ios::in);
    fstream fout;
    fout.open(argv[2],ios::out);
    //fin.getline(buffer,200);//PA1之所以要用這個是為了把前兩行的註解給吃掉
    fin>>N; //因為fin示已in模式 開啟可把它直接想成cin

//準備創建MIS二維陣列
    vector<int>MIS_i;
    MIS_i.assign(N,0);
    vector<vector<int> >MIS;//製造MIS二維陣列記錄最大不相交弦數量 記得裡面的vector<int>間隔要和外面分開一點
    MIS.assign(N,MIS_i);
    vector<int>().swap(MIS_i);
//創建MIS_CASE二維度陣列 記錄不同case預計會有3種case其中case2又有2種case
    vector<int>MIS_CASE_i;
    MIS_CASE_i.assign(N,0);
    vector<vector<int> >MIS_CASE;
    MIS_CASE.assign(N,MIS_CASE_i);
    vector<int>().swap(MIS_CASE_i);
//創建MIS_Chord_i紀錄最終所有不相交弦的i MIS_Chord_j記錄所有不相交弦的j
//例如12.in的MIS_Chord_i的話 就會是0 5 8
    vector<int> MIS_Chord_i;
    vector<int> MIS_Chord_j;

    while(fin>>i>>j)
    {
        chord_point_input_left.push_back(i);
        chord_point_input_right.push_back(j);

    }
    chord_point_i.assign(2*chord_point_input_left.size(),0); //配置夠大的記憶體給vector
    for(int i=0; i<=chord_point_input_left.size()-1; i++)
    {
        chord_point_i[chord_point_input_left[i]]=chord_point_input_right[i];

    }
    for(int i=0; i<=chord_point_input_right.size()-1; i++)
    {
        chord_point_i[chord_point_input_right[i]]=chord_point_input_left[i];

    }




    vector<int>().swap(chord_point_input_left); //利用swap釋放記憶體

    vector<int>().swap(chord_point_input_right); //利用swap釋放記憶體





    //C++中空格不是'\0'
//由此進入計算MIS
    for(int length=1; length<=N-1; length++)
    {
        for(int i=0; i<=N-1-length; i++)
        {
            int j;
            int k;
            j=i+length;
            k=chord_point_i[j]; //chord_point_i[index]代表index這個點連到哪個點
            //case1
            if(k>j||k<i)
            {
                MIS[i][j]=MIS[i][j-1];
                MIS_CASE[i][j]=1 ;
            }


            //case2
            else if(k<j&&k>i)
            {
                MIS[i][j]=max(MIS[i][j-1],MIS[i][k-1]+1+MIS[k+1][j-1]);
                if (MIS[i][j-1]>(MIS[i][k-1]+1+MIS[k+1][j-1]))
                {
                    MIS_CASE[i][j]=4;
                }
                else
                    MIS_CASE[i][j]=2;
            }
            //case3
            else if(k==i)
            {
                MIS[i][j]=1+MIS[i+1][j-1];
                MIS_CASE[i][j]=3;
            }
        }
    }
    fout<<MIS[0][N-1]<<endl;
    vector<vector<int> >().swap(MIS); //釋放MIS的記憶體
    find_result_chord(MIS_CASE,MIS_Chord_i,MIS_Chord_j,0,N-1,chord_point_i);
    //此function被執行完後 MSI_Chord_i MIS_Chord_j分別會記錄 各弦的i跟j
    //現在要用insertion sort將MIS_Chord_i跟j做sort (MIS_Chord_i要increasing order)
    InsertionSort(MIS_Chord_i,MIS_Chord_j);
    for(int i=0 ; i<MIS_Chord_i.size(); i++)
    {
        fout<< MIS_Chord_i[i]<<" "<<MIS_Chord_j[i]<<endl;



    }
    fin.close();
    fout.close();
}//更改swap

