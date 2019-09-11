Arr is not changed by queries;
All queries are known beforehand (techniques requiring this property are often called “offline algorithms”);
If we know Func([L, R]), then we can compute Func([L + 1, R]), Func([L - 1, R]), Func([L, R + 1]) and Func([L, R - 1]), each in O(F) time.

Time Complexity: O( (n+q) * sqrt(n) * F );