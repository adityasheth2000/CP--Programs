/*
bool cmp(datatype a,datatype b){
  ...
}
set<datatype,decltype(cmp)*> se(cmp); // for set
map<datatype,decltype(cmp)*> mp(cmp); // for map

Note : don't use lambda function for cmp. 
*/