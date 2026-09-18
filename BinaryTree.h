#pragma once
#include <string>
#include <vector>

void printOrder(std::vector<int> order);

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val = -1): value(val) {
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
private:
    TreeNode* root;

    void clear(TreeNode* node);

    void print(TreeNode* node,
               const std::string& prefix,
               bool hasRightSibling,
               char branch);

    std::vector<int> preOrder(TreeNode* node);
    std::vector<int> inOrder(TreeNode* node);
    std::vector<int> postOrder(TreeNode* node);

    int size(TreeNode* node);
    int height(TreeNode* node);
    int leafCount(TreeNode* node);

    void mirror(TreeNode* node);

    static bool same(TreeNode* x, TreeNode* y);
    bool symmetric(TreeNode* x, TreeNode* y);

    bool checkPathSum(TreeNode* node, int currentSum, int targetSum);
    int getHeight(TreeNode* node, int& maxDiameter);

    TreeNode* findLCA(TreeNode* node, int x, int y);

public:
    BinaryTree();
    ~BinaryTree();

    void copy(TreeNode* cur, TreeNode* oth);
    BinaryTree(const BinaryTree& oth);
    BinaryTree& operator=(const BinaryTree& oth);

    void build(const std::vector<int>& values, int nullValue);

    void print();

    std::vector<int> getPreOrder();
    std::vector<int> getInOrder();
    std::vector<int> getPostOrder();
    std::vector<int> getLevelOrder();

    int getSize();
    int getHeight();
    int getLeafCount();

    void mirror();

    friend bool isSame(BinaryTree& A, BinaryTree& B);
    bool isSymmetric();

    bool hasPathSum(int target);
    int diameter();
    TreeNode* lowestCommonAncestor(int x, int y);
};