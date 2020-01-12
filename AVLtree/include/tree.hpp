#include <iostream>

namespace tree
{
template <typename Pointer>
Pointer &ptr(Pointer *data)
{
    return *data;
}

template <typename Idx, typename Data>
class BSTree
{
public:
    BSTree(Idx idx, Data data)
    {
        ptr(this).idx = idx;
        (*this).data = new Data(data);
    };

    ~BSTree()
    {
        std::cout << "delete";
    };

    BSTree &operator=(Data &data)
    {
        if (this == &data)
        {
            return *this;
        }
        else
        {
            delete (*this).data;
            (*this).data = new Data(data);
        }
    }

    virtual void insert(Idx idx, Data data)
    {
        (*this)._insert(idx, data);
        return;
    };

    // virtual void remove(Idx idx, Data data)
    // {
    //     return (*(*this)._insert(idx, data)).data;
    // };

    virtual Data search(Idx idx)
    {
        return ptr(ptr(ptr(ptr(this)._search(idx))).data);
    };

protected:
    BSTree **_insert(Idx idx, Data data)
    {
        BSTree<Idx, Data> **parent = ptr(this)._search(idx);
        if (*parent == nullptr)
        {
            *parent = new BSTree<Idx, Data>(idx, data);
        }
        else if ((**parent).idx == idx)
        {
            delete (**parent).data;
            (**parent).data = new Data(data);
        }

        return parent;
    };

    // BSTree **_remove(Idx idx)
    // {
    //     BSTree<Idx, Data> **parent = &(*this)._search(idx);
    //     BSTree<Idx, Data> **change_node = new BSTree<Idx, Data> *();
    //     BSTree<Idx, Data> **temp = new BSTree<Idx, Data> *();
    //     while (true)
    //     {
    //         if (*parent == nullptr)
    //         {
    //             break;
    //         }
    //         if ((**parent).idx == idx)
    //         {
    //         }
    //         else if ((**parent).idx > idx)
    //         {
    //             parent = &((**parent).left_ptr);
    //         }
    //         else if ((**parent).idx < idx)
    //         {
    //             parent = &((**parent).right_ptr);
    //         }
    //     }
    // };

    BSTree **_search(Idx idx)
    {
        BSTree<Idx, Data> *root = this;
        BSTree<Idx, Data> **parent = &root;

        while (true)
        {
            if (*parent == nullptr || (**parent).idx == idx)
            {
                break;
            }
            else if ((**parent).idx > idx)
            {
                parent = &(**parent).left_ptr;
            }
            else if ((**parent).idx < idx)
            {
                parent = &(**parent).right_ptr;
            }
        }
        return parent;
    };

    Idx idx;
    Data *data;
    BSTree<Idx, Data> *left_ptr = nullptr;
    BSTree<Idx, Data> *right_ptr = nullptr;
};

// template <typename Idx, typename Data>
// class AVLTree : public BSTree<Idx, Data>
// {
// public:
//     AVLTree(Idx idx, Data &data)
//     {
//         (*this).idx = idx;
//         (*this).data = new Data(data);
//     };
//     ~AVLTree()
//     {
//         std::cout << "delete";
//     };
// };
} // namespace tree