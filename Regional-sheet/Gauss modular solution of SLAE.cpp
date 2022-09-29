
ll poww(long long a, long long n, long long m){
        
        long long ans = 1;
        long long mul = a;
        while (n != 0){
                if (n % 2)
                        ans = (ans * mul) % m;
                mul = (mul * mul) % m;
                n /= 2;
        }
        return ans;
}
int inv(int x){
	return poww(x,MOD-2,MOD);
}
int gauss (vector<vector<int>> &a,vector<int> &ans) {
    int n = (int) a.size();
    int m = (int) a[0].size() - 1;
 
    vector<int> where (m, -1);
    for (int col=0, row=0; col<m && row<n; ++col) {
        int sel = row;
        for (int i=row; i<n; ++i)
            if (a[i][col] > a[sel][col])
                sel = i;
        if (a[sel][col]==0)
            continue;
        for (int i=col; i<=m; ++i)
            swap (a[sel][i], a[row][i]);
        where[col] = row;
 
        for (int i=0; i<n; ++i)
            if (i != row) {
                int c = (a[i][col]*inv(a[row][col]))%MOD;
                for (int j=col; j<=m; ++j){
                	a[i][j] -= (a[row][j] * c)%MOD;
                	if(a[i][j]<0)
                        a[i][j] += MOD;
                }
            }
        ++row;
    }
    for (int i=0; i<m; ++i)
        if (where[i] != -1)
            ans[i] = (a[where[i]][m] * inv(a[where[i]][i]))%MOD;
    for (int i=0; i<n; ++i) {
        int sum = 0;
        for (int j=0; j<m; ++j){
        	sum += (ans[j] * a[i][j])%MOD;
        	sum %= MOD;
        }
    }
}