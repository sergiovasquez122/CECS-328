//
// Created by sergio on 12/15/20.
//

#include "UnionFind.h"

UnionFind::UnionFind(int N): connected_components(N), connected_component_id(N, 0) {
    for(int i = 0;i < N;i++)
        connected_component_id[i] = i;

}

void UnionFind::connect(int p, int q) {
    int pRoot = find(p);
    int qRoot = find(q);
    if(pRoot == qRoot) return;
    connected_component_id[pRoot] = qRoot;
    connected_components--;
}

int UnionFind::find(int p) {
    int root = p;
    while(root != connected_component_id[root])
        root = connected_component_id[root];
    while(p != root){
        int newP = connected_component_id[p];
        connected_component_id[p] = root;
        p = newP;
    }
    return p;
}

bool UnionFind::connected(int p, int q) {
    return find(p) == find(q);
}

int UnionFind::count() {
    return connected_components;
}
