#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define Foo pair<int,int>
class compare
{
public:
    bool operator() (Foo &a, Foo &b)
    {
        return a.second<b.second;
    }
};

void solve(vector<int> &distance,vector<vector<pair<int,int>>> &g,int source ){
    
    distance[source] = 0;
    
    priority_queue<pair<int,int> ,vector<pair<int,int>>,compare> pq;

    pq.push({source,distance[source]});
    Foo pd;
    int node ,w;
    while(!pq.empty()){
        pd = pq.top();
        pq.pop();
        int t = pd.first;
        int h = pd.second;
        for (int i = 0; i < g[t].size(); i++)
        {
            
            node = g[t][i].first;
            w = g[t][i].second;
            
            if(distance[node] > h+w){

                distance[node] =h+w;
                pq.push({node,distance[node]});

            }

        }
        
    }
    
}

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    
    vector<vector<pair<int,int>>> g(vertices);
    int h,t ,w;
    for(int i =0;i<edges;i++){
        
        h = vec[i][0];
        t = vec[i][1];
        w = vec[i][2];
        
        g[t].push_back({h,w});
        g[h].push_back({t,w});
        
        
    }
    vector<int> distance(vertices,1e8);
    solve(distance,g,0);

    return distance;

}

void fun1(){
    int V,E;
    cin>>V>>E;
    vector<vector<int>> vec;

    int a,b,c;
    for (int i = 0; i < E; i++)
    {
        cin>>a>>b>>c;
        vec.push_back({a,b,c});
    }
    
    vector<int> res;
    res = dijkstra(vec,V,E,0);

    for (int i = 0; i < res.size(); i++)
    {
        cout<<res[i]<<" ";
    }cout<<endl;
    

    return ;

}

int main()
{
    int t;
    cin>>t;
    int V,E;
    // vector<int> res;
    for (int i = 0; i < t; i++)
    {
        fun1();
    }
    


    cout<<endl;
    return 0;
}