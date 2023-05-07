#include <iostream>
#include <list>
#include <fstream>
using namespace std;

ifstream f("mergeheap.in");
ofstream g("mergeheap.out");

struct Node
{
    int value, nr_child;
    Node* parent;
    Node* child;
    Node* sibling;
};

Node* NewNode(int val)
{
    Node* node = new Node;
    node->value = val;
    node->parent = node->child = node->sibling = nullptr;
    node->nr_child = 0;
    return node;
}

struct BinomialHeap 
{
    list<Node*> trees;

    //reunim arborii (arborele cu valoarea mai mare va fi parintele arborelui cu valoare mai mica)
    Node* MergeTrees(Node* t1, Node* t2) 
    {
        if (t1->value < t2->value) 
        {
            Node* temp = t1;
            t1 = t2;
            t2 = temp;
        }
        t1->nr_child++;
        t2->parent = t1;
        t2->sibling = t1->child;
        t1->child = t2;
        return t1;
    }

    //reunim arborii cu acelasi nr de copii
    void ModifyTrees() 
    {
        trees.sort([](Node* a, Node* b) { return a->nr_child < b->nr_child; }); // lista cu toti arborii din 2 heap uri sortata in ordine cresc a valorilor
        if (trees.size() <= 1) 
        {
            return;
        }
        else 
        {
            list<Node*>::iterator previous;
            list<Node*>::iterator current;
            list<Node*>::iterator next;
            previous = trees.begin();
            current = previous;
            current++;
            next = current;
            next++;

            while (current != trees.end())
            {
                if (next != trees.end())
                {
                    if ((*previous)->nr_child == (*current)->nr_child && (*current)->nr_child != (*next)->nr_child)
                    {
                        *previous = MergeTrees(*previous, *current);
                        current = trees.erase(current);
                        next++;
                    }
                    else
                    {
                        previous++;
                        current++;
                        next++;
                    }
                }
                else
                {
                    if ((*previous)->nr_child == (*current)->nr_child)
                    {
                        *previous = MergeTrees(*previous, *current);
                        trees.pop_back();
                    }

                    current = trees.end();
                }
            }
        }
    };

    ///reunim heapuri
    void MergeHeap(BinomialHeap& heap2)
    {
        list<Node*> FinalHeap;
        list<Node*> ::iterator t1, t2;
        t1 = trees.begin();
        t2 = heap2.trees.begin();

        while (t1 != trees.end() && t2 != heap2.trees.end())
        {
            if ((*t2)->nr_child >= (*t1)->nr_child)
            {
                FinalHeap.push_front(*t1);
                t1++;
            }
            else
            {
                FinalHeap.push_front(*t2);
                t2++;
            }
            while (t1 != trees.end())
            {
                FinalHeap.push_front(*t1);
                t1++;
            }

            while (t2 != heap2.trees.end())
            {
                FinalHeap.push_front(*t2);
                t2++;
            }
        }

        heap2.trees.clear();
        trees = FinalHeap;
        ModifyTrees();

    }

    /// inseram un nod nou in heap (in lista arbori)
    void insert(int val)
    {
        Node* node = NewNode(val);
        trees.push_back(node);
        ModifyTrees();
    }

    ///gasim radacina cu valoarea maxima si o eliminam, apoi rearanjam subarborii ramasi corespunzator
    void del()
    {
        if (trees.empty()) 
        {
            return;
        }

        auto it = trees.begin();
        Node* max = *it;
        while (it != trees.end()) 
        {
            if ((*it)->value > max->value) 
            {
                max = *it;
            }
            it++;
        }

        trees.remove(max);
        list<Node*> subTree;
        Node* sa = max->child;
        g << (*max).value << endl;
        while (sa != NULL)
        {
            subTree.push_front(sa);
            sa = sa->sibling;
        }

        auto it2 = subTree.begin();
        while (it2 != subTree.end())
        {
            trees.push_back(*it2);
            it2++;
        }
        ModifyTrees();
    }

};

int main()
{
    int N, Q;
    f >> N >> Q;
    BinomialHeap Heap[101];
    int nr_op, m, x, a, b;
    for (int i = 1; i <= Q; i++) 
    {
        f >> nr_op;
        if (nr_op == 1) 
        {
            f >> m;
            f >> x;
            Heap[m].insert(x);

        }
        else if (nr_op == 2) 
        {
            f >> m;
            Heap[m].del();
        }
        else if (nr_op == 3) 
        {
            f >> a >> b;
            Heap[a].MergeHeap(Heap[b]);
        }
    }
    return 0;
}