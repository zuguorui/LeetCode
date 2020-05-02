#ifndef _RB_TREE_H_
#define _RB_TREE_H_

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<list> 

template<typename K, typename V>
struct RBTree_Node
{
    K key;
    V value;

    
    uint8_t color;

    RBTree_Node *parent;
    RBTree_Node *leftChild;
    RBTree_Node *rightChild;

    RBTree_Node(K key, V value)
    {
        this->key = key;
        this->value = value;
        repeatCount = 0;
        parent = NULL;
        leftChild = NULL;
        rightChild = NULL;
    }

    ~RBTree_Node()
    {
        parent = NULL;
        leftChild = NULL;
        rightChild = NULL;
    }

};

template<template<typename K, typename V>
class RBTree {
public:
    RBTree();
    ~RBTree();
    void insert(RBTree_Node<K, V> *node);
    RBTree_Node<K, V>* remove(K key);
private:

};

#endif