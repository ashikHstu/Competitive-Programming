struct node
{
    bool endmark;
    node *next[26+1];
    node()
    {
        endmark=false;
        for(int i=0;i<26;i++)
        {
            next[i]=NULL;
        }
    }
}*root;
void insert_string(string st)
{
    node *curr=root;
    int len=st.size();
    for(int i=0;i<len;i++)
    {
        int id=st[i]-'a';
        if(curr->next[id]==NULL)
        {
            curr->next[id]=new node();
        }
        curr=curr->next[id];
    }
    curr->endmark=true;

}

bool search_string(string st)
{
    node *curr=root;
    int len=st.size();
    for(int i=0;i<len;i++)
    {
        int id=st[i]-'a';
        if(curr->next[id]==NULL)
        {
            return false;
        }
        curr=curr->next[id];
    }
    return curr->endmark;
}
void del(node *curr)
{
    for(int i=0;i<26;i++)
    {
        if(curr->next[i])
            del(curr->next[i]);
    }
    delete(curr);
}

