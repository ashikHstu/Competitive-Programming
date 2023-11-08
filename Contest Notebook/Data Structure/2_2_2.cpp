const int N = 5e5 + 2;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_rand(int l, int r)
{
    return uniform_int_distribution<int>(l, r) (rng);
}
//Persistent Segment Tree
struct node
{
    node *lf, *rt;
    int val;
    node(int x = 0, node *y = NULL, node *z = NULL) :
        val(x), lf(y), rt(z) {}

    void build(int lo, int hi)
    {
        if (lo == hi)
            return;
        lf = new node();
        rt = new node();
        int mid = lo + hi >> 1;
        lf -> build(lo, mid);
        rt -> build(mid + 1, hi);
    }
    node *update(int lo, int hi, int idx, int v)
    {
        if (hi < idx || lo > idx)
            return this;
        if (lo == hi)
        {
            node *ret = new node(val, lf, rt);
            ret -> val += v;
            return ret;
        }
        int mid = lo + hi >> 1;
        node *ret = new node(val);
        ret -> lf = lf -> update(lo, mid, idx, v);
        ret -> rt = rt -> update(mid + 1, hi, idx, v);
        ret -> val = ret -> lf -> val + ret -> rt -> val;
        return ret;
    }
    int query(int lo, int hi, int i, int j)
    {
        if (hi < i || lo > j)
            return 0;
        if (i <= lo && hi <= j)
        {
            return val;
        }
        int mid = lo + hi >> 1;
        return lf -> query(lo, mid, i, j) +
               rt -> query(mid + 1, hi, i, j);
    }
}*root[N];
int query(node *f, node *s, int l, int r, int k)
{
    if (l == r) return r;
    int mid = (l + r) >> 1;
    int ase = (mid - l + 1) - (s->lf->val - f->lf->val);
    if (ase >= k) return query(f->lf, s->lf, l, mid, k);
    return query(f->rt, s->rt, mid + 1, r, k - ase);
}
void solve()
{
    int a;
    cin >> a;
    root[0] = new node();
    root[0]->build(1, 1e6);
    for (int i = 1; i <= a; i++)
    {
        int x;
        cin >> x;
        root[i] = root[i - 1]->update(1, 1e6, x, 1);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        if (l > r) swap(l, r);
        ll ase = 1000000 - (root[r]->query(1, 1e6, 1, 1e6) - root[l - 1]->query(1, 1e6, 1, 1e6));
        if (k > ase)
        {
            cout << 1000000 + (k - ase) << nl;
            continue;
        }
        cout << query(root[l - 1], root[r], 1, 1e6, k) << nl;
    }
}


