#include <iostream>
#include "BinaryTree.h"
using namespace std;

int main() {
    BinaryTree tree;
    tree.build({1, 2, 3, 4, 5, -1, 6}, -1);
    tree.print();

    cout << "PREORDER" << endl;
    printOrder(tree.getPreOrder());
    cout << endl << endl;

    cout << "INORDER" << endl;
    printOrder(tree.getInOrder());
    cout << endl << endl;

    cout << "POSTORDER" << endl;
    printOrder(tree.getPostOrder());
    cout << endl << endl;

    cout << "LEVELORDER" << endl;
    printOrder(tree.getLevelOrder());
    cout << endl << endl;

    cout << "SIZE:::" << tree.getSize() << endl;
    cout << "HEIGHT:::" << tree.getHeight() << endl;
    cout << "LEAFCOUNT:::" << tree.getLeafCount() << endl;
    cout << endl;

    cout << "MIRROR" << endl;
    tree.mirror();
    tree.print();
    tree.mirror();
    cout << endl << endl;

    cout << "COPY" << endl;
    BinaryTree newTree(tree);
    newTree.print();
    cout << endl << endl;

    cout << "CHECK COPY" << endl;
    cout << "A::::" << endl;
    tree.mirror(); tree.print();
    cout << "B::::" << endl;
    newTree.print();
    cout << endl << endl;

    cout << "SAME?" << endl;
    cout << "mirror & origin:::" << boolalpha << isSame(tree, newTree) << endl;
    tree.mirror();
    cout << "origin & origin:::" << boolalpha << isSame(tree, newTree) << endl;
    cout << endl;

    cout << "SYMMETRIC?" << endl;
    BinaryTree symmetricTree;
    symmetricTree.build({1, 2, 2, 3, 3, 3, 3, -1, 4, 4, 4, 4, 4, 4, -1}, -1);
    cout << "symmetric tree:::" << symmetricTree.isSymmetric() << endl;
    cout << "original tree:::" << tree.isSymmetric() << endl;
    cout << endl;

    cout << "PATHSUM" << endl;
    cout << "path sum = 7:::" << boolalpha << tree.hasPathSum(7) << endl;
    cout << "path sum = 20:::" << boolalpha << tree.hasPathSum(20) << endl;
    cout << endl;

    cout << "DIAMETER" << endl;
    cout << "tree:::" << tree.diameter() << endl;
    cout << endl;

    BinaryTree lcaTree;
    lcaTree.build({
        1,
        2, 3,
        4, 5, 6, 7,
        -1, -1, 8, 9,
        -1, -1, -1, -1,
        -1, -1, 10, 11
    }, -1);
    cout << "LCA TEST" << endl;
    cout << "(4, 8):::" << lcaTree.lowestCommonAncestor(4, 8)->value << endl;
    cout << "(5, 11):::" << lcaTree.lowestCommonAncestor(5, 11)->value << endl;
    cout << "(2, 10):::" << lcaTree.lowestCommonAncestor(2, 10)->value << endl;
    cout << "(1, 7):::" << lcaTree.lowestCommonAncestor(1, 7)->value << endl;
    return 0;
}