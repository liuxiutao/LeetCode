#include<iostream>
#include<string>
#include<cstdlib>
#include<queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSym(TreeNode * root)
{
    queue<TreeNode *> qleft, qright;
    if(root == nullptr)
        return true;
    TreeNode *l = root->left;
    TreeNode *r = root->right;
    if(l == nullptr && r == nullptr)
        return true;
    else if((l == nullptr && r != nullptr) || (l != nullptr && r == nullptr))
        return false;
    else 
    {
        if(l->val != r->val)
            return false;
        else
        {
            qleft.push(l);
            qright.push(r);
            while(!qleft.empty())
            {
                l = qleft.front();
                r = qright.front();
                if(l->left == nullptr && r->right == nullptr)
                    ;
                else if(l->left != nullptr && r->right != nullptr && l->left->val == r->right->val)
                {
                    qleft.push(l->left);
                    qright.push(r->right);
                }
                else
                    return false;

                if(l->right == nullptr && r->left == nullptr)
                    ;
                else if(l->right != nullptr && r->left != nullptr && l->right->val == r->left->val)
                {
                    qleft.push(l->right);
                    qright.push(r->left);
                }
                else
                    return false;
                qleft.pop();
                qright.pop();
            }
            return true;
        }
    }
}

