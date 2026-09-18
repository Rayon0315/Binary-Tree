#include "BinaryTree.h"
#include <iostream>
#include <queue>

void printOrder(std::vector<int> order) {
    std::cout << "[";
    for (int i = 0; i < order.size(); i++) {
        std::cout << order[i];

        if (i != order.size() - 1){
            std::cout << ",";
        }
    }
    std::cout << "]";
}

BinaryTree::BinaryTree() {
    root = nullptr;
}

void BinaryTree::clear(TreeNode* node) {
    if (node == nullptr) return;

    clear(node->left);
    clear(node->right);

    delete node;
}

BinaryTree::~BinaryTree() {
    clear(root);
}

void BinaryTree::copy(TreeNode* cur, TreeNode* oth) {
    if (oth == nullptr) return;

    if (oth->left != nullptr) {
        cur->left = new TreeNode(oth->left->value);
        copy(cur->left, oth->left);
    }

    if (oth->right != nullptr) {
        cur->right = new TreeNode(oth->right->value);
        copy(cur->right, oth->right);
    }
}

BinaryTree::BinaryTree(const BinaryTree& oth) {
    root = new TreeNode(oth.root->value);
    copy(root, oth.root);
}

void BinaryTree::print() {
    if (root == nullptr) {
        std::cout << "Empty Tree" << std::endl;
        return;
    }

    std::cout << root->value << std::endl;

    print(root->left, "", true, 'L');
    print(root->right, "", false, 'R');
}

void BinaryTree::print(TreeNode* node,
                       const std::string& prefix,
                       bool hasRightSibling,
                       char branch) {
    if (node == nullptr) return;

    std::cout << prefix;

    if (branch == 'L') {
        std::cout << "┣L━━━━━";
    } else {
        std::cout << "┣R━━━━━";
    }

    std::cout << node->value << std::endl;

    std::string nextPrefix = prefix;

    if (hasRightSibling) {
        nextPrefix += "┃      ";
    } else {
        nextPrefix += "       ";
    }

    print(
        node->left,
        nextPrefix,
        node->right != nullptr,
        'L'
    );

    print(
        node->right,
        nextPrefix,
        false,
        'R'
    );
}

void BinaryTree::build(const std::vector<int>& values, int nullValue) {
    if (values.empty() || values[0] == nullValue) {
        root = nullptr;
        return;
    }

    root = new TreeNode(values[0]);

    std::queue<TreeNode*> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < values.size()) {
        TreeNode* cur = q.front();
        q.pop();

        if (i < values.size() && values[i] != nullValue) {
            cur->left = new TreeNode(values[i]);
            q.push(cur->left);
        }
        i++;

        if (i < values.size() && values[i] != nullValue) {
            cur->right = new TreeNode(values[i]);
            q.push(cur->right);
        }
        i++;
    }
}

std::vector<int> BinaryTree::preOrder(TreeNode* node) {
    if (node == nullptr) return std::vector<int>();

    std::vector<int> ret;
    std::vector<int> l(preOrder(node->left));
    std::vector<int> r(preOrder(node->right));

    ret.push_back(node->value);
    ret.insert(ret.end(), l.begin(), l.end());
    ret.insert(ret.end(), r.begin(), r.end());

    return ret;
}

std::vector<int> BinaryTree::inOrder(TreeNode* node) {
    if (node == nullptr) return std::vector<int>();

    std::vector<int> ret;
    std::vector<int> l(inOrder(node->left));
    std::vector<int> r(inOrder(node->right));

    ret.insert(ret.end(), l.begin(), l.end());
    ret.push_back(node->value);
    ret.insert(ret.end(), r.begin(), r.end());

    return ret;
}

std::vector<int> BinaryTree::postOrder(TreeNode* node) {
    if (node == nullptr) return std::vector<int>();

    std::vector<int> ret;
    std::vector<int> l(postOrder(node->left));
    std::vector<int> r(postOrder(node->right));

    ret.insert(ret.end(), l.begin(), l.end());
    ret.insert(ret.end(), r.begin(), r.end());
    ret.push_back(node->value);

    return ret;
}

std::vector<int> BinaryTree::getPreOrder() {
    return preOrder(root);
}
std::vector<int> BinaryTree::getInOrder() {
    return inOrder(root);
}
std::vector<int> BinaryTree::getPostOrder() {
    return postOrder(root);
}
std::vector<int> BinaryTree::getLevelOrder() {
    std::queue<TreeNode*> q;
    q.push(root);

    std::vector<int> ret;
    while (!q.empty()) {
        TreeNode* cur = q.front();
        q.pop();

        ret.push_back(cur->value);

        if (cur->left != nullptr) {
            q.push(cur->left);
        }

        if (cur->right != nullptr) {
            q.push(cur->right);
        }
    }

    return ret;
}

int BinaryTree::getSize() {
    return size(root);
}
int BinaryTree::getHeight() {
    return height(root);
}
int BinaryTree::getLeafCount() {
    return leafCount(root);
}

int BinaryTree::size(TreeNode* node) {
    if (node == nullptr) return 0;

    return size(node->left) + size(node->right) + 1;
}

int BinaryTree::height(TreeNode* node) {
    if (node == nullptr) return 0;

    return std::max(height(node->left), height(node->right)) + 1;
}

int BinaryTree::leafCount(TreeNode* node) {
    if (node == nullptr) return 0;
    
    if (node->left == nullptr && node->right == nullptr) return 1;

    return leafCount(node->left) + leafCount(node->right);
}

void BinaryTree::mirror() {
    return mirror(root);
}

void BinaryTree::mirror(TreeNode* node) {
    if (node == nullptr) return;

    std::swap(node->left, node->right);

    mirror(node->left);
    mirror(node->right);
}

bool isSame(BinaryTree& A, BinaryTree& B) {
    return BinaryTree::same(A.root, B.root);
}

bool BinaryTree::same(TreeNode* x, TreeNode* y) {
    if (x == nullptr && y == nullptr) return true;
    if (x == nullptr || y == nullptr) return false;

    if (x->value != y->value) return false;

    return same(x->left, y->left) && same(x->right, y->right);
}

bool BinaryTree::isSymmetric() {
    return symmetric(root, root);
}

bool BinaryTree::symmetric(TreeNode* x, TreeNode* y) {
    if (x == nullptr && y == nullptr) return true;
    if (x == nullptr || y == nullptr) return false;

    if (x->value != y->value) return false;

    return symmetric(x->left, y->right) && symmetric(x->right, y->left);
}

bool BinaryTree::hasPathSum(int target) {
    if (root == nullptr) return false;
    return checkPathSum(root, 0, target);
}

bool BinaryTree::checkPathSum(TreeNode* node, int currentSum, int targetSum) {
    if (node->left == nullptr && node->right == nullptr) {
        return currentSum + node->value == targetSum;
    }

    if (node->left != nullptr &&
        checkPathSum(node->left, currentSum + node->value, targetSum)) {
        return true;
    }

    if (node->right != nullptr &&
        checkPathSum(node->right, currentSum + node->value, targetSum)) {
        return true;
    }

    return false;
}

int BinaryTree::diameter() {
    int maxDiameter = 0;
    getHeight(root, maxDiameter);
    return maxDiameter;
}

int BinaryTree::getHeight(TreeNode* node, int& maxDiameter) {
    if (node == nullptr) return 0;

    int leftHeight = getHeight(node->left, maxDiameter);
    int rightHeight = getHeight(node->right, maxDiameter);

    maxDiameter = std::max(maxDiameter, leftHeight + rightHeight);

    return std::max(leftHeight, rightHeight) + 1;
}

TreeNode* BinaryTree::lowestCommonAncestor(int x, int y) {
    return findLCA(root, x, y);
}

TreeNode* BinaryTree::findLCA(TreeNode* node, int x, int y) {
    if (node == nullptr) return nullptr;

    if (node->value == x || node->value == y) return node;

    TreeNode* l = findLCA(node->left, x, y);
    TreeNode* r = findLCA(node->right, x, y);
    if (l != nullptr && r != nullptr) {
        return node;
    }

    if (l != nullptr) {
        return l;
    } else {
        return r;
    }
}