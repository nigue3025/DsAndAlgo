// SimpleHeapExample.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <iostream>
#include<vector>
#include<map>
#include<algorithm>
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

TreeNode* HeapToTreeNode(std::vector<int>& ary)
{
    TreeNode* root = new TreeNode(ary[0]);
    std::vector<TreeNode*> treeNodeAry = std::vector<TreeNode*>(ary.size());
    for (int i = 0; i < ary.size(); i++)
    {
        if (ary[i] == INT_MIN)
            treeNodeAry[i] = nullptr;
        else
            treeNodeAry[i] = new TreeNode(ary[i]);


    }
    TreeNode* travel = root;
    int travelIndex = 0;
    int dist = 1;
    int step = 0;
    for (int i = 0; i < ary.size(); ++i)
    {
        if (treeNodeAry[i] != nullptr)
        {
            if (step + dist < treeNodeAry.size())
                treeNodeAry[i]->left = treeNodeAry[step + dist];
            if (step + dist + 1 < treeNodeAry.size())
                treeNodeAry[i]->right = treeNodeAry[step + dist + 1];
            ++step;
            dist = dist + 1;
        }
    }

    return treeNodeAry[0];
}
int main()
{
    std::vector<int>heap = { 1, 2, 2, 3, INT_MIN, INT_MIN, 3, 4, INT_MIN, INT_MIN, 4 };
    auto root = HeapToTreeNode(heap);
    std::cout << root->val << std::endl;
}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
