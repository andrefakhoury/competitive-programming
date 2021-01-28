#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename tA, typename tB=null_type> using ord_set = tree<tA, tB, std::less<tA>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename tA, typename tB=null_type> using ord_mset = tree<tA, tB, std::less<tA>, rb_tree_tag, tree_order_statistics_node_update>;
// s.order_of_key(k); //qtt of strictly smaller than k, O(logN)
// *s.find_by_order(k); //k-th element counting from 0, in O(logN)
// be careful with ord_mset!
//   -> find() doesn't really work, use lower_bound() instead
//   -> lower_bound(x) actually returns upper_bound, I guess, so use lower_bound(x-1)
