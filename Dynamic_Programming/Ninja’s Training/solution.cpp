int maxReturn(int n, vector<vector<int>> &points, int i, int j, vector<vector<int>> &memo){
    if(i >= n) return 0;
    if(memo[i][j] != -1) return memo[i][j];
    
    int maxi = 0;
    for(int index = 0; index < 3; index++){
        if(j == index) continue;
        maxi = max(maxi, points[i][index] + maxReturn(n, points, i+1, index, memo));
    }
    
    memo[i][j] = maxi;
    return memo[i][j];
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Correct way to declare and initialize 2D vector
    vector<vector<int>> memo(n, vector<int>(4, -1));
    
    return maxReturn(n, points, 0, 3, memo);
}