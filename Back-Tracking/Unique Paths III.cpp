int ans = 0;
bool check(vector<vector<int>> A){
for(int i=0;i<A.size();i++){
for(int j=0;j<A[i].size();j++){
if(A[i][j] == 0){
return false;
}
}
}
return true;
}

void solver(vector<vector<int>>&A, pair<int,int> start,pair<int,int> end){
int i = start.first,j = start.second;

if(i == end.first && j == end.second && check(A) == true){
ans++;
return;
}
if(i<0 || j<0 || i>=A.size() || j>=A[i].size() || A[i][j] == -1 || A[i][j] == 3 || A[i][j] == 2){
return;
}
//mark as visited
A[i][j] = 3;

solver(A,{i-1,j},end);
solver(A,{i+1,j},end);
solver(A,{i,j+1},end);
solver(A,{i,j-1},end);

//if not found backtrack
A[i][j] = 0;
}


int Solution::solve(vector<vector<int> > &A) {
pair<int,int> start;
pair<int,int> end;

for(int i=0;i<A.size();i++){
for(int j=0;j<A[i].size();j++){
if(A[i][j] == 1){
start = {i,j};
}
if(A[i][j] == 2){
end = {i,j};
}
}
}
ans = 0;

solver(A,start,end);

return ans;
}