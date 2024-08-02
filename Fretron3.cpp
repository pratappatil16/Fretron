#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

// 0 - up , 1 - left , 2 - down , 3 - right

int way[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};


void generatepaths(int i , int j,int spi,int spj,int dir,vector<string> &temp,vector<vector<int>> &board,vector<vector<string>> &res){
    if(i<0 || i>=board.size() || j<0 || j>=board[0].size())return;
    string s;
    if(board[i][j]==2){
        res.push_back(temp);
        return;
    }
    if(board[i][j]==0){ // empty cell moving forward
        generatepaths(i+way[dir][0],j+way[dir][1],spi,spj,dir,temp,board,res);
    }else if(board[i][j]==1){ // found soldier
        // jump over
        s="Jump (" + string(1,'0'+(j+1)) + "," + string(1,'0'+(i+1)) + ")";
        temp.push_back(s);
        generatepaths(i+way[dir][0],j+way[dir][1],spi,spj,dir,temp,board,res); 
        temp.pop_back();

        //soldier killed
        s="Kill (" + string(1,'0'+(j+1)) + "," + string(1,'0'+(i+1)) + ")" + " Turn Left";
        temp.push_back(s);
        board[i][j]=0;
        generatepaths(i+way[(dir+1)%4][0],j+way[(dir+1)%4][1],spi,spj,(dir+1)%4,temp,board,res);
        board[i][j]=1;
        temp.pop_back();
    }
}


int main(){

    //Chessboard -- 
    //0 - Free Cell
    //1 - soldier
    //2 - special castle
    int x,y;
    int no_of_soldiers;
    vector<vector<int>> chessboard(9,vector<int> (9));
    vector<vector<string>> res;
    vector<string> temp;
    cout<<"soldiers : ";
    cin>>no_of_soldiers;
    for (int i = 0; i < no_of_soldiers; i++)
    {
        cout<<"Enter coordinates for soldier "<<i+1<<" : ";
        cin>>x>>y;
        chessboard[y-1][x-1]=1;
    }
    cout<<"Enter coordinates for special castle : ";
    cin>>x>>y;
    x--;
    y--;
    chessboard[y][x]=2;
    cout<<endl;
    
    generatepaths(y+way[2][0],x+way[2][1],y,x,2,temp,chessboard,res);
    for(int i = 0;i<res.size();i++){
        cout<<"Path "<<i+1<<" :"<<endl;
        cout<<"-------\n-------"<<endl;
        cout<<"Start ("<<y+1<<","<<x+1<<")"<<endl;
        for(string s:res[i]){
            cout<<s<<endl;
        }
        cout<<"Arrive ("<<y+1<<","<<x+1<<")"<<endl<<endl;
    }
    return 0;
    
}
