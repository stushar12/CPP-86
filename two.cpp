void abc(Node* &root, Node* &prev,Node* &first,Node* &second)
{
    if(root==NULL) return ;
    abc(root->left,prev,first,second);
    if(prev!=NULL &&root->data<prev->data)
    {
        if(first==NULL)
        {
            first=prev;
        }
        second=root;
    }
    prev=root;
    abc(root->right,prev,first,second);
}

struct Node *correctBST( struct Node* root )
{
Node *prev=NULL,*first=NULL,*second=NULL;
abc( root,prev,first,second);
int temp=first->data;
first->data=second->data;
second->data=temp;
return root;
}
