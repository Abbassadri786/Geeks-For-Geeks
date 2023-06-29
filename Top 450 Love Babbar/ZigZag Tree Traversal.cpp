class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	vector<int> ans;
    	if(!root) return ans;
    	queue<Node*> q;
    	// Flag for tracking direction
    	bool LtoRdir = true;
    	q.push(root);
    	
    	while(!q.empty()){
    	    //To check How many elements present at that level
    	    int width = q.size();
    	    vector<int> OnLevel(width);
    	    for(int i=0; i<width; ++i){
    	        Node* front = q.front(); q.pop();
    	        int index = LtoRdir ? i : width - i - 1;
    	        OnLevel[index] = front -> data;
    	        if(front -> left){
    	            q.push(front -> left);
    	        }
    	        if(front -> right){
    	            q.push(front -> right);
    	        }
    	    }
    	    for(int i=0; i< OnLevel.size(); i++){
    	        ans.push_back(OnLevel[i]);    
    	    }
    	    
    	    LtoRdir = !LtoRdir;
    	}
    	return ans;
    }
};
