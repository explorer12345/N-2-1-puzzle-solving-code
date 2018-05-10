#include<simplecpp>
#include <vector>
struct node{int N;int temp=0;
  vector<int> tiles;//to store the sequence of numbers given in the input
  int g=0;int h=0;int f=0;

  void initialise(node M){f=M.f;g=M.g;h=M.h;tiles=M.tiles;N=M.N;temp=M.temp;}

  int pos(int tile_num){int position,k=0; //function to find at which tile number a given number is located
    while(tiles[k]!=tile_num){k++;}
    position=k+1;
    return position;}

  int manhattan(){int x1,x2,y1,y2,sum=0; //function to find the heuristic value(h-value) of a node
    for(int i=1;i<N*N;i++){if(i%N==0){x1=N;y1=(i/N);}
      else {x1=i%N;y1=(i/N)+1;}
      if(pos(i)%N==0){x2=N;y2=(pos(i)/N);}
      else {x2=pos(i)%N;y2=(pos(i)/N)+1;}
      sum+=sqrt((x1-x2)*(x1-x2))+sqrt((y1-y2)*(y1-y2));}
    return sum;}

  node up(){int temp=0;node q; //function to move the zero up if possible
    q.f=f;q.g=g;q.h=h;q.tiles=tiles;q.N=N;q.temp=temp;int t=q.pos(0)-N;
    if(q.pos(0)>=q.N+1){q.tiles[q.pos(0)-1]=q.tiles[t-1];
      q.tiles[t-1]=0;
      q.g++;q.h=q.manhattan();q.f=q.g+q.h;
      return q;}
    else{q.temp=-1;
      return q;}}

  node down(){int temp=0;node q; //function to move the zero down if possible
    q.f=f;q.g=g;q.h=h;q.tiles=tiles;q.N=N;q.temp=temp;int t=q.pos(0)+N;
    if(q.pos(0)<=q.N*q.N-q.N){q.tiles[q.pos(0)-1]=q.tiles[t-1];
      q.tiles[t-1]=0;
      q.g++;q.h=q.manhattan();q.f=q.g+q.h;
      return q;}
    else{q.temp=-1;
      return q;}}

  node right(){int temp=0;node q; //function to move the zero right if possible
    q.f=f;q.g=g;q.h=h;q.tiles=tiles;q.N=N;q.temp=temp;int t=q.pos(0)+1;
    if(q.pos(0)%q.N!=0){q.tiles[q.pos(0)-1]=q.tiles[t-1];
      q.tiles[t-1]=0;
      q.g++;q.h=q.manhattan();q.f=q.g+q.h;
      return q;}
    else{q.temp=-1;
      return q;}}

  node left(){int temp=0;node q; //function to move the zero left if possible
    q.f=f;q.g=g;q.h=h;q.tiles=tiles;q.N=N;q.temp=temp;int t=q.pos(0)-1;
    if(q.pos(0)%q.N!=1){q.tiles[q.pos(0)-1]=q.tiles[t-1];
      q.tiles[t-1]=0;
      q.g++;q.h=q.manhattan();q.f=q.g+q.h;
      return q;}
    else{q.temp=-1;
      return q;}}
  };
node minimum(node A,node B,node C,node D){int arr[]={A.f,B.f,C.f,D.f}; //function to find which node has minimum f-value
  int c=0;for(int u=0;u<4;u++)c=max(c,arr[u]);
  for(int i=0;i<4;i++){if(arr[i]==-1)arr[i]=c+1;}
  int temp=arr[0];
  for(int i=0;i<4;i++){temp=min(temp,arr[i]);}
  if(temp==A.f){return A;}
  else if(temp==B.f){return B;}
  else if(temp==C.f){return C;}
  else return D;}

char selectU(node A,node B,node C,node D){node temp1=minimum(A,B,C,D); //function which gives the direction to obtain minimum f-valued childen node
  if(temp1.f==A.f){return 'U';}
  else if(temp1.f==B.f){return 'D';}
  else if(temp1.f==C.f){return 'L';}
  else return 'R';}
char selectR(node A,node B,node C,node D){node temp1=minimum(A,B,C,D); //function which gives the direction to obtain minimum f-valued childen node
  if(temp1.f==A.f){return 'R';}
  else if(temp1.f==B.f){return 'U';}
  else if(temp1.f==C.f){return 'D';}
  else return 'L';}
char selectL(node A,node B,node C,node D){node temp1=minimum(A,B,C,D); //function which gives the direction to obtain minimum f-valued childen node
  if(temp1.f==A.f){return 'L';}
  else if(temp1.f==B.f){return 'R';}
  else if(temp1.f==C.f){return 'U';}
  else return 'D';}
char selectD(node A,node B,node C,node D){node temp1=minimum(A,B,C,D); //function which gives the direction to obtain minimum f-valued childen node
  if(temp1.f==A.f){return 'D';}
  else if(temp1.f==B.f){return 'L';}
  else if(temp1.f==C.f){return 'R';}
  else return 'U';}

int main(){
node Q,Q2,Q3,Q4,qu,qd,ql,qr;
cin>>Q.N;
for(int i=0;i<Q.N*Q.N;i++){int k;cin>>k;Q.tiles.push_back(k);} //fills the vector tiles with the given sequence of numbers
Q.h=Q.manhattan();Q.f=Q.g+Q.h;//initialising the f,g and h value of node Q
Q2.initialise(Q);Q3.initialise(Q);Q4.initialise(Q);
int inversions=0;int solvability=-1;
for (int i=0;i<Q.N*Q.N-1;i++){for(int j=i+1;j<Q.N*Q.N;j++){if(Q.tiles[i]>Q.tiles[j]&&Q.tiles[i]!=0&&Q.tiles[j]!=0)inversions++;}}//calculates no.of inversions

if(Q.N%2==1){if(inversions%2==0)solvability=1;}//checking the solvability of the given puzzle
if(Q.N%2==0){if(Q.pos(0)%Q.N==0&&((Q.N-Q.pos(0)/Q.N)%2==0)&&inversions%2==0)solvability=1;
  if(Q.pos(0)%Q.N!=0&&((Q.N-Q.pos(0)/Q.N)%2==0)&&inversions%2==1)solvability=1;
  if(Q.pos(0)%Q.N==0&&((Q.N-Q.pos(0)/Q.N)%2==1)&&inversions%2==1)solvability=1;
  if(Q.pos(0)%Q.N!=0&&((Q.N-Q.pos(0)/Q.N)%2==1)&&inversions%2==0)solvability=1;}

vector<char> moves; int j=1; //vector in which the moves/directions are stored after 0th element onwards
moves.push_back('N');
vector<char> moves1;
moves1.push_back('N');
vector<char> moves2;
moves2.push_back('N');
vector<char> moves3;
moves3.push_back('N');
vector<char> moves4;
moves4.push_back('N');

  if(solvability==1){while(true){
  if(Q.up().temp!=-1&&moves1[j-1]!='D'){qu=Q.up();}
  else{qu.f=-1;}
  if(Q.down().temp!=-1&&moves1[j-1]!='U'){qd=Q.down();}
  else{qd.f=-1;}
  if(Q.left().temp!=-1&&moves1[j-1]!='R'){ql=Q.left();}
  else{ql.f=-1;}
  if(Q.right().temp!=-1&&moves1[j-1]!='L'){qr=Q.right();}
  else{qr.f=-1;}
  Q=minimum(qu,qd,ql,qr); //selecting the minimum f-valued children node
  moves1.push_back(selectU(qu,qd,ql,qr));// storing the desired move/direction in the vector moves

  if(Q2.up().temp!=-1&&moves2[j-1]!='D'){qu=Q2.up();}
  else{qu.f=-1;}
  if(Q2.down().temp!=-1&&moves2[j-1]!='U'){qd=Q2.down();}
  else{qd.f=-1;}
  if(Q2.left().temp!=-1&&moves2[j-1]!='R'){ql=Q2.left();}
  else{ql.f=-1;}
  if(Q2.right().temp!=-1&&moves2[j-1]!='L'){qr=Q2.right();}
  else{qr.f=-1;}
  Q2=minimum(qr,qu,qd,ql); //selecting the minimum f-valued children node
  moves2.push_back(selectR(qr,qu,qd,ql));// storing the desired move/direction in the vector moves

  if(Q3.up().temp!=-1&&moves3[j-1]!='D'){qu=Q3.up();}
  else{qu.f=-1;}
  if(Q3.down().temp!=-1&&moves3[j-1]!='U'){qd=Q3.down();}
  else{qd.f=-1;}
  if(Q3.left().temp!=-1&&moves3[j-1]!='R'){ql=Q3.left();}
  else{ql.f=-1;}
  if(Q3.right().temp!=-1&&moves3[j-1]!='L'){qr=Q3.right();}
  else{qr.f=-1;}
  Q3=minimum(ql,qr,qu,qd); //selecting the minimum f-valued children node
  moves3.push_back(selectL(ql,qr,qu,qd));// storing the desired move/direction in the vector movesfor(int k=0;k<Q.N;k++)

  if(Q4.up().temp!=-1&&moves4[j-1]!='D'){qu=Q4.up();}
  else{qu.f=-1;}
  if(Q4.down().temp!=-1&&moves4[j-1]!='U'){qd=Q4.down();}
  else{qd.f=-1;}
  if(Q4.left().temp!=-1&&moves4[j-1]!='R'){ql=Q4.left();}
  else{ql.f=-1;}
  if(Q4.right().temp!=-1&&moves4[j-1]!='L'){qr=Q4.right();}
  else{qr.f=-1;}
  Q4=minimum(qd,ql,qr,qu); //selecting the minimum f-valued children node
  moves4.push_back(selectD(qd,ql,qr,qu));// storing the desired move/direction in the vector moves
  /*for (int m=0; m<Q.N; m++){
        for(int k=0;k<Q.N;k++)cout<<Q.tiles[m*Q.N+k]<<" ";
        cout<<endl;}
  cout<<"_____________"<<endl;*/

  if(Q.h==0){moves=moves1;break;}
  if(Q2.h==0){moves=moves2;break;}
  if(Q3.h==0){moves=moves3;break;}
  if(Q4.h==0){moves=moves4;break;}
  j++;}
cout<<moves.size()-1<<endl;
for(int i=0;i<moves.size()-1;i++){cout<<moves[i+1]<<" ";}}
else cout<<solvability;}

/* CHANGES MADE IN THE CODE AFTER WRITTEN VIVA
1) Code for checking the solvability of puzzle is changed.
2) There is no function defined for inversions as mentioned in the written viva , but instead a variable named 'inversions' is used to find the no. of inversions. */
