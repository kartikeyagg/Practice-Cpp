#include<bits/stdc++.h>
using namespace std;
#define mod 1e9+7
#define ll long long

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
    ios_base::sync_with_stdio(false); 
    int n,m;
    cin>>n>>m;
    // n is number of nodes
    // m is number of edges
    vector<int> vec(n,0);
    vector<int> size1(n,1);
    for (int i = 0; i < n; i++)
    {
        make(i,vec);
    }
    vector<pair<int,pair<int,int>>> edges;
    int u,v,w;
    for (int i = 0; i < m; i++)
    {   
        cin>>u>>v>>w;
        u--;
        v--;
        edges.push_back({w,{u,v}});
    }
    sort(edges.begin(),edges.end());
    ll total_cost=0;
    vector<pair<int,pair<int,int>>> ans_edges;
    for (int i = 0; i < m; i++)
    {
        w = edges[i].first;
        u = edges[i].second.first;
        v = edges[i].second.second;
        if(find(u,vec) == find(v,vec)){
            continue;
        }
        Union(u,v,vec,size1);
        total_cost += w;
        ans_edges.push_back({w,{u,v}});
    }
    cout<<" the edges are \n";
    for (int i = 0; i < ans_edges.size(); i++)
    {
        w = ans_edges[i].first;
        u = ans_edges[i].second.first;
        v = ans_edges[i].second.second;

        cout<<u<<" "<<v<<" "<<w<<" \n";
    }
    cout<<" the total cost is "<<total_cost<<" \n";
    

    cout<<endl;
    return 0;
}

/*
i/o

6 9
5 4 9
1 4 1 
5 1 4
4 3 5
4 2 3
1 2 2
3 2 3
3 6 8
2 6 7
*/
