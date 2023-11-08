#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
order_of_key return number of elements less than x -> os.order_of_key(x)
cout << "oth element  : " << *os.find_by_order(0) << endl; so it returns value of index

