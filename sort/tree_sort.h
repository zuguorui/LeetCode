#ifndef _TREE_SORT_H_
#define _TREE_SORT_H_

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <list>

using namespace std;

template <typename T>
struct tree_node
{
    T value;
    tree_node *left;
    tree_node *right;

    tree_node(T v)
    {
        value = v;
        left = NULL;
        right = NULL;
    }
};

template <typename T>
void tree_sort(T *src, int32_t l, int32_t r)
{
    if (l >= r)
    {
        return;
    }
    tree_node<T> *root = new tree_node<T>(src[l]);

    tree_node<T> *currentNode = root;

    // 先插入到二叉树内
    for (int i = l + 1; i <= r; i++)
    {
        T v = src[i];
        currentNode = root;
        while (true)
        {
            if (v < currentNode->value)
            {
                if (currentNode->left == NULL)
                {
                    currentNode->left = new tree_node<T>(v);
                    break;
                }
                else
                {
                    currentNode = currentNode->left;
                }
            }
            else
            {
                if (currentNode->right == NULL)
                {
                    currentNode->right = new tree_node<T>(v);
                    break;
                }
                else
                {
                    currentNode = currentNode->right;
                }
            }
        }
    }

    // 对二叉树进行中序遍历

    list<tree_node<T> *> nodes;

    int index = l;

    // 使currentNode等于根节点，开始遍历
    /*
    非递归的中序遍历，先沿着左支路遍历，把所有路过的节点全部放入栈中。
    如果到达叶子节点，跳出左支路循环。此时currentNode为NULL，因为叶子节点没有子节点。
    从栈顶取出一个元素，取该元素的值，然后让currentNode等于该节点的右子节点。然后进入下个循环。
    如果该节点有右子节点，也就是currentNode不为NULL，那么下个循环开始又会以currentNode为起点遍历最左支路。
    如果该节点无右子节点，也就是currentNode为NULL，那么下个循环会先将currentNode入栈，然后再出栈，继续让currentNode = currentNode.right。
    */
    currentNode = root;

    do{
        
        while(currentNode != NULL)
        {
            nodes.push_front(currentNode);
            currentNode = currentNode->left;
        }

        if(nodes.size() != 0)
        {
            currentNode = nodes.front();
            nodes.pop_front();

            src[index++] = currentNode->value;
            tree_node<T> *temp = currentNode;
            currentNode = currentNode->right;
            delete(temp);
        }

        // printf("nodes: \n");
        // auto it = nodes.begin();
        // while(it != nodes.end())
        // {
        //     printf("%d, ", (int)((*it)->value));
        //     it++;
        // }
        // printf("\n");
    }while(nodes.size() != 0 || currentNode != NULL);

    
}

#endif