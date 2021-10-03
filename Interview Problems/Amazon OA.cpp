1. // Count no. of substrings with exactly k distinct letters
//Link: https://practice.geeksforgeeks.org/problems/count-number-of-substrings4528/1#
// Code:
    long long int substrCount (string a, int k) {
    	//code here.
    	int i=0,j=0, res=0, count = 0,n=a.size();
    	for( i=0;i<n;i++){
    	    unordered_map<char,int> m;
    	    count = 0;
    	    for(j=i; j<n; j++){
    	        m[a[j]]++;
    	        if(m[a[j]] == 1) count++;
    	        
    	        if(count == k) res++;
    	        
    	        if(count > k) break;
    	    }
    	}
    	return res;
    }

2. // Engineers at Amazon are interested in knowing which software component moves the fastest 
//by counting the number of lines of code changed in that component and all subcomponents in the 
//code base over a month. Component nodes have subcomponent nodes that make up the larger component. 
//Weve stored the components as a tree where each node represents one component that contains the number 
//of lines changed that month. Software component speed is computed as the average number of lines of 
//code changed for a given component and all its subcomponents. Engineers compute this software 
//component speed for all such components which have one or more subcomponents. 
//Find the component with the highest software component speed. Assume there will be at least one 
//subcomponent in the tree and that there will be no ties. Input The input to the function/method 
//consists of an argument: rootcomponent, representing the root node. Return the reference to the 
//component that has highest software component speed.

//Solution Link: https://www.answersdocs.com/ExpertAnswers/problem-test-casesoutput-java-05m-10s-current-selected-programming-language-java-emphasize-q35149158

Code:

int countNodes(ComponentNode* x) {
    if (x->components.size() == 0) {
        return 1;
    }
    int sum = 0;
    for (auto y: x.components) {
        sum += countNodes(y);
    }
    return 1 + sum;
}
int countValues(ComponentNode* x) {
    if (x->components.size() == 0) {
        return x->value;
    }
    int sum = 0;
    for (auto y: x->components) {
        sum += countValues(y);
    }
    return x->value + sum;
}
boolean isLeaf(ComponentNode* node) {
    return (node->components.size() == 0);
}
boolean isJustAboveLeaf(ComponentNode* node) {
    if (isLeaf(node)) {
        return false;
    }
    for (auto y: node.components) {
        if (y->components.size() != 0) {
            return false;
        }
    }
    return true;
}
double avgChangeRate(ComponentNode* node) {
    double count = (1.0 + countNodes(node));
    double value = (node->value + countValues(node));
    return value / count;
} /*Main function*/
ComponentNode findMaxNode(ComponentNode* root) {
    if (isJustAboveLeaf(root)) {
        return root;
    }
    ComponentNode* maxNode = root;
    double maxChangeRate = avgChangeRate(root);
    for (auto y: node.components) {
        if (!isLeaf(y)) {
            ComponentNode* maxSubNode = findMaxNode(y);
            double subChangeRate = avgChangeRate(maxSubNode);
            if (subChangeRate > maxChangeRate) {
                maxChangeRate = subChangeRate;
                maxNode = maxSubNode;
            }
        }
    }
    return maxNode;
}