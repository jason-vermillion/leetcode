// https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/
// 1359. Count All Valid Pickup and Delivery Options
#define ll long long
class Solution {
public:
    int countOrders(int n) {
        const ll BIG_MOD = 1000000007;
        ll result = 1;
        
        // number of permutations of pickups
        for (long i = 1; i <= n; ++i) {
            result = result * i % BIG_MOD;
        }
        
        // number of permutations of deliveries
        for (long i = 1; i < 2 * n; i += 2) {
            result = result * i % BIG_MOD;
        }
        
        return result;
    }
};