/*
ID: silentf1
PROG: heritage
LANG: C++
*/
#include<fstream>
#include<cstring>
using namespace std;
ofstream fout ("heritage.out",ios::out);
ifstream fin ("heritage.in",ios::in);
struct String{
    int len;
    char word[27];
}str[2];
struct subteee{
    char key;
    int lch,rch;
}tree[27];
int tot=1;
void backout(int pos){ //后序遍历
    if(tree[pos].lch) backout(tree[pos].lch);
    if(tree[pos].rch) backout(tree[pos].rch);
    fout<<tree[pos].key;
}
void find(char work[],int len,int pos,int index){ //构造二叉树
    tree[index].key=str[0].word[pos];
    char temp[27];
    for(int i=0;i<len;i++) if(work[i]==tree[index].key){
        if(i!=0){
            for(int j=0;j<i;j++) temp[j]=work[j];
            tree[index].lch=++tot;
            find(temp,i,pos+1,tot);
        }
        if(i!=len-1){
            for(int j=i+1;j<len;j++) temp[j-i-1]=work[j];
            tree[index].rch=++tot;
            find(temp,len-i-1,pos+i+1,tot);
        }
        break;
    }
}
int main()
{
    fin>>str[1].word>>str[0].word;
    str[1].len=strlen(str[1].word);
    str[0].len=strlen(str[0].word);
    find(str[1].word,str[1].len,0,tot);
    backout(1);
    fout<<endl;
    return 0;
}
