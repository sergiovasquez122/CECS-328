#ifndef EC_6_UNIONFIND_H
#define EC_6_UNIONFIND_H
#include <vector>

using std::vector;

class UnionFind {
public:
    explicit UnionFind(int N);
    void connect(int p, int q);
    int find(int p);
    bool connected(int p, int q);
    int count();
private:
    int connected_components;
    vector<int> connected_component_id;
};


#endif //EC_6_UNIONFIND_H
