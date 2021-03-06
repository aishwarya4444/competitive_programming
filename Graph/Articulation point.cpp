void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children=0;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]); 
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p!=-1)     // there is not present any back edge from v to its ancester
                IS_CUTPOINT(v);
            ++children;
        }
    }
    if(p == -1 && children > 1)     /// root is the articualtion point
        IS_CUTPOINT(v);
}


problems ans solutions:

1.  //Submerging Islands : https://www.spoj.com/problems/SUBMERGE/
    //https://pastebin.com/mDkNz7zW
  
2.  // http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=13&page=show_problem&problem=1140
  //https://pastebin.com/pd84rFJd
    
3.  //http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=5&page=show_problem&problem=251
    //https://pastebin.com/aGpytp0R
