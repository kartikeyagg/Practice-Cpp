#include<bits/stdc++.h>
using namespace std;
#define ll long long
// vec contains the parent of current node
void make(int node,vector<int> &vec){
    // initially every node is parent of its own
    vec[node] = node;
    return ;
}

int find(int node, vector<int> &vec){

    // this function finds the parent of given node
    // also perform the depth compression
    // by joining the intermediate nodes directly to
    // the parent
    if(node == vec[node]) return node;
    return vec[node] = find(vec[node],vec);

}
void Union(int a, int b, vector<int> &vec,vector<int> &size1){

    a = find(a,vec);
    b = find(b,vec);
    if(size1[a]< size1[b]){
        swap (a,b);
    }
    vec[b] = a; // parent of b is a; 
    size1[a] +=size1[b];
    // size1[b] = size1[a];
    return ;
}

int main()
{
    int n;
    cout<<"enter the total number of node \n";
    cout<<"each will be initialize with 0 to n-1"<<endl;
    cin>>n;
    vector<int> vec(n); //parent
    for (int i = 0; i < n; i++)
    {
        make(i,vec);
    }
    vector<int> size1(n+1); // size
    int k;
    int a,b;
    while(true){

        cout<<"enter 1 for unioning \n2 for finding if they belong to same graph and \n3 to exit "<<endl;
        cin>>k;
        if(k == 3){
            break;
        }
        if(k == 1){
            cout<<"enter the nodes to be unionised"<<endl;
            cin>>a>>b;
            if(a>= n || b>= n || a<0 || b<0) {
                cout<<"Invalid nodes "<<endl;
                continue;
            }
            Union(a,b,vec,size1);
        }
        else if(k == 2){
            cout<<"enter the nodes to be find"<<endl;
            cin>>a>>b;
            if(a>= n || b>= n || a<0 || b<0) {
                cout<<"Invalid nodes "<<endl;
                continue;
            }
            if(find(a,vec) == find(b,vec)){
                cout<<"these belong to same union \n";
            }
            else{
                cout<<"#these nodes are not connected \n";
            }

        }
        else{
            cout<<"invalid input \n";
        }


    }
    

    cout<<endl;
    return 0;
}