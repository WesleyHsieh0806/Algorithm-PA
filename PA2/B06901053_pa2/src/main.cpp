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
    //�}�lsortMSI_Chord_i�æP�ɽվ�MIS_Chord_j
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
//�n�`�Nreference��m �B��reference�~���|���O�Ӧhstack�O����

//�Φ�function���MIS[0][N-1]�쩳�����Ǥ��ۥ橶 case2 case3����T�w���ҥH�n�S�O�`�N
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
//��k�[�J��MIS_Chord_i ��j�[�J��MIS_Chord_j

            MIS_Chord_i.push_back(k);
            //chord_point_i[j] �N�Ok �]��chord_point_i[j]�N���j�۳s�����I
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

int main(int argc,char*argv[]) //argc��argv�Omain��ܭ쥻�N�����@�ذѼ� ����python��argparse�����ѼƸԱ��Ѧ�recitation
{
    if(argc != 3)
    {
        help_message();
        return 0;
    }
    int N;//Node�ƶq
    int i=0;
    int j=0;
    int index;
    vector<int>chord_point_input_left;
    vector<int>chord_point_input_right;
    vector<int>chord_point_i; //��vector�����C��index�s�u�쪺�t�~�@�I index==i value==j
    //char buffer[200]; //���p�ϥ�getline�i�H��@����J��buffer�o�Ӱ}�C(����J��'\n'���O�ť���)

    fstream fin;
    fin.open(argv[1],ios::in);
    fstream fout;
    fout.open(argv[2],ios::out);
    //fin.getline(buffer,200);//PA1���ҥH�n�γo�ӬO���F��e��檺���ѵ��Y��
    fin>>N; //�]��fin�ܤwin�Ҧ� �}�ҥi�⥦�����Q��cin

//�ǳƳЫ�MIS�G���}�C
    vector<int>MIS_i;
    MIS_i.assign(N,0);
    vector<vector<int> >MIS;//�s�yMIS�G���}�C�O���̤j���ۥ橶�ƶq �O�o�̭���vector<int>���j�n�M�~�����}�@�I
    MIS.assign(N,MIS_i);
    vector<int>().swap(MIS_i);
//�Ы�MIS_CASE�G���װ}�C �O�����Pcase�w�p�|��3��case�䤤case2�S��2��case
    vector<int>MIS_CASE_i;
    MIS_CASE_i.assign(N,0);
    vector<vector<int> >MIS_CASE;
    MIS_CASE.assign(N,MIS_CASE_i);
    vector<int>().swap(MIS_CASE_i);
//�Ы�MIS_Chord_i�����̲שҦ����ۥ橶��i MIS_Chord_j�O���Ҧ����ۥ橶��j
//�Ҧp12.in��MIS_Chord_i���� �N�|�O0 5 8
    vector<int> MIS_Chord_i;
    vector<int> MIS_Chord_j;

    while(fin>>i>>j)
    {
        chord_point_input_left.push_back(i);
        chord_point_input_right.push_back(j);

    }
    chord_point_i.assign(2*chord_point_input_left.size(),0); //�t�m���j���O���鵹vector
    for(int i=0; i<=chord_point_input_left.size()-1; i++)
    {
        chord_point_i[chord_point_input_left[i]]=chord_point_input_right[i];

    }
    for(int i=0; i<=chord_point_input_right.size()-1; i++)
    {
        chord_point_i[chord_point_input_right[i]]=chord_point_input_left[i];

    }




    vector<int>().swap(chord_point_input_left); //�Q��swap����O����

    vector<int>().swap(chord_point_input_right); //�Q��swap����O����





    //C++���Ů椣�O'\0'
//�Ѧ��i�J�p��MIS
    for(int length=1; length<=N-1; length++)
    {
        for(int i=0; i<=N-1-length; i++)
        {
            int j;
            int k;
            j=i+length;
            k=chord_point_i[j]; //chord_point_i[index]�N��index�o���I�s������I
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
    vector<vector<int> >().swap(MIS); //����MIS���O����
    find_result_chord(MIS_CASE,MIS_Chord_i,MIS_Chord_j,0,N-1,chord_point_i);
    //��function�Q���槹�� MSI_Chord_i MIS_Chord_j���O�|�O�� �U����i��j
    //�{�b�n��insertion sort�NMIS_Chord_i��j��sort (MIS_Chord_i�nincreasing order)
    InsertionSort(MIS_Chord_i,MIS_Chord_j);
    for(int i=0 ; i<MIS_Chord_i.size(); i++)
    {
        fout<< MIS_Chord_i[i]<<" "<<MIS_Chord_j[i]<<endl;



    }
    fin.close();
    fout.close();
}//���swap

