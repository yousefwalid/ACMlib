const int N = 1e5+10;

int global_id = 1,tri[3*N][26];

void Add(string& str,int idx,int id)
{
    if(idx == str.size()) return;

    if(!tri[id][str[idx]-'a']) 
        tri[id][str[idx]-'a'] = global_id++;

    Add(str,idx+1,tri[id][str[idx]-'a']);
}

bool Check(string& str,int idx,int id)
{
    if(idx == str.size()) return 1;
    if(!tri[id][str[idx]-'a']) return 0;
    return Check(str,idx+1,tri[id][str[idx]-'a']);
}