class HeapNode {
    int upprofit;
    int profit;
    int weight;
    int level;
    bbnode *ptr;
};

class bbnode {
    bbnode *parent;
    bool LChild;
};

void AddLiveNode(int up, int cp, int cw, int lev, bool ch) {
    bbnode *b = new bbnode;
    b->parent = E;
    b->LChild = ch;
    HeapNode N;
    N.upprofit = up;
    N.profit = cp;
    N.weight = cw;
    N.level = lev;
    N.ptr = b;
    H->Insert(N);
}

 
