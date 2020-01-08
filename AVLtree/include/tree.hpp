namespace tree
{
template <typename Idx, typename Data>
class binary_tree_node
{
public:
    binary_tree_node(Idx idx, Data &data)
    {
        (*this).idx = idx;
        (*this).data = data
    };

private:
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

private:
    virtual void insert(Idx idx, Data data)
    {
        binary_tree_node<Idx, Data> *parent = root;
        while (true)
        {
            if (parent == nullptr)
            {
                parent = new binary_tree_node<Idx, Data>(idx, data);
                break;
            }
            if ((*parent).idx == idx)
            {
                delete (*parent).data;
                (*parent).data = data;
            }
            else if ((*parent).idx > idx)
            {
                parent = (*parent).left_ptr
            }
            else if ((*parent).idx < idx)
            {
                parent = (*parent).right_ptr
            }
        }
    };
    virtual void remove(Idx idx){

    };
    virtual Data search(Idx idx){

    };
    binary_tree_node<Idx, Data> *root = nullptr;
};

} // namespace tree