void rangePrinter(struct node* root, int k1, int k2){
  if(root == NULL) return 0;
  if(root->data >=k1 && root->data <=k2) { //to check if data is data present in the root node is within the range or not
    printf("%d", root->data);
    rangePrinter(root->left, k1, k2);
    rangePrinter(root->right, k1, k2);
  }   
  else if(root->data < k1){           //if root data is lesser than k1 start doing things in right partof the subtree
    rangePrinter(root->right, k1, k2);}
  else                                     //if root data is greater than k2
    rangePrinter(root->left, k1, k2);
