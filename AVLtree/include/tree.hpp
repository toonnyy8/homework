#include <iostream>

namespace tree
{
template <typename Idx, typename Data>
class binary_tree_node
{
public:
    binary_tree_node(Idx idx, Data &data)
    {
        (*this).idx = idx;
        (*this).data = new Data(data);
    };

    ~binary_tree_node()
    {
        std::cout << "delete";
    };

    binary_tree_node &operator=(Data &data)
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

    Idx idx;
    Data *data;
    binary_tree_node<Idx, Data> *left_ptr = nullptr;
    binary_tree_node<Idx, Data> *right_ptr = nullptr;
};

template <typename Idx, typename Data>
class binary_tree
{
public:
    binary_tree(){};
    binary_tree(Idx idx, Data data)
    {
        (*this).insert(idx, data);
    };

    virtual void insert(Idx idx, Data data)
    {
        binary_tree_node<Idx, Data> **parent = &(*this).root;
        while (true)
        {
            if (*parent == nullptr)
            {
                *parent = (new binary_tree_node<Idx, Data>(idx, data));
                break;
            }
            if ((**parent).idx == idx)
            {
                delete (**parent).data;
                (**parent).data = new Data(data);
            }
            else if ((**parent).idx > idx)
            {
                parent = &((**parent).left_ptr);
            }
            else if ((**parent).idx < idx)
            {
                parent = &((**parent).right_ptr);
            }
        }
    };
    virtual void remove(Idx idx)
    {
        binary_tree_node<Idx, Data> **parent = &(*this).root;
        binary_tree_node<Idx, Data> **change_node = new binary_tree_node<Idx, Data> *();
        binary_tree_node<Idx, Data> **temp = new binary_tree_node<Idx, Data> *();
        while (true)
        {
            if (*parent == nullptr)
            {
                break;
            }
            if ((**parent).idx == idx)
            {
                delete (**parent).data;
                *change_node = (*parent);
                if ((**change_node).left_ptr != nullptr)
                {
                    while (true)
                    {
                        if ((**change_node).right_ptr != nullptr)
                        {
                            change_node = &((**change_node).right_ptr);
                        }
                        else
                        {
                            *temp = (*parent);
                            *parent = &(**change_node);
                            delete change_node;
                            delete *temp;
                            delete temp;
                            break;
                        }
                    }
                }
                else
                {
                    *temp = (*parent);
                    *parent = ((**change_node).right_ptr);
                    delete *temp;
                    delete temp;
                }
            }
            else if ((**parent).idx > idx)
            {
                parent = &((**parent).left_ptr);
            }
            else if ((**parent).idx < idx)
            {
                parent = &((**parent).right_ptr);
            }
        }
    };
    virtual Data search(Idx idx){

    };

private:
    binary_tree_node<Idx, Data> *root = nullptr;
};

} // namespace tree