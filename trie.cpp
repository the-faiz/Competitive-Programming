struct node{
    int ctn;
    node* child[2];
    node(){
        ctn = 0;
        child[0] = NULL;
        child[1] = NULL;
    }
};

struct trie{
    node* root;
    trie(){
        root = new node;
    }
    int insert(int n){
        node* curr = root;
        for(int i=LN-1;i>=0;i--){
            curr->ctn++;
            int x;
            if((n>>i)&1) x=1;
            else x=0;
            if(curr->child[x]==NULL) curr->child[x] = new node;
            curr = curr->child[x];
        }
        curr->ctn++;
    }
    int del(int n){
        node* curr = root;
        for(int i=LN-1;i>=0;i--){
            curr->ctn--;
            int x;
            if((n>>i)&1) x=1;
            else x=0;
            if(curr->child[x]==NULL) curr->child[x] = new node;
            curr = curr->child[x];
        }
        curr->ctn--;
    }
};