class Solution {
public:
    int minOperations(vector<string>& logs) {
        
        int depth=0;
        
        for(int i=0;i<logs.size();i++){
            if(logs[i]=="./"){
                continue;
            }else if(logs[i]=="../"){
                if(depth>0) 
                    depth--;
            }else{
                depth++;
            }
        }
        return depth;
    }
};