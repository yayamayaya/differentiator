#include "simplificate.h"

node_t *case_zero(node_t *node, int *flag);
node_t *case_one(node_t *node, int *flag);

node_t *simplificate(node_t *node, int *flag)
{
    static node_t *root = node; 
    assert(root);
    if (!node)
        return node;

    if (node->data_type == OPERATION)
        node = case_zero(node, flag);        
    if (node->data_type == OPERATION)
        node = case_one(node, flag);

    LOG("> simplificating left and right nodes of the node %p\n", node);

    node->l = simplificate(node->l, flag);
    node->r = simplificate(node->r, flag);

    return node;
} 

node_t *case_zero(node_t *node, int *flag)
{
    assert(node);
    assert(node->data_type == OPERATION);

    node_t *node_without_zero   = NULL;
    node_t *copied_node         = NULL;

    LOG("> watching node %p\n", node);

    if (node->l)
    {
        if (node->l->data_type == NUMBER && (node->l)->data.number == 0)
        {
            LOG("> zero founded on the node %p\n", node->l);
            node_print(node->l);
            node_without_zero = node->r;        
        }
    }
    if (node->r)
    {
        LOG("> right node %p has %d data type\n", node->r, node->r->data_type);
        if (node->r->data_type == NUMBER && node->r->data.number == 0)
        {
            LOG("> zero founded on the node %p\n", node->l);
            node_print(node->l);
            node_without_zero = node->l;        
        }
    }

    if (node_without_zero)
        switch (node->data.operation)
        {
        case ADD:
        case SUB:
            *flag = 0;
            copied_node = copy_node(node_without_zero);
            tree_kill(node);
            LOG("> ADD and SUB zero simpl. found on %p\n", node);
            return copied_node;

        case MULT:
            *flag = 0;
            tree_kill(node);
            LOG("> MULT zero simpl. found on %p\n", node);
            return create_node((double)0, NUMBER, NULL, NULL);
        
        case DIV:
            *flag = 0;
            if (node_without_zero == node->l)
            {
                printf("[error]>>> can't divide into zero!!!\n");
                return node;
            }
            tree_kill(node);
            LOG("> DIV zero simpl. found on %p\n", node);
            return create_node((double)0, NUMBER, NULL, NULL);

        case POW:
            *flag = 0;
            LOG("> POW zero simp. found on %p\n", node);
            if (node_without_zero == node->r)
            {
                tree_kill(node);
                return create_node((double)0, NUMBER, NULL, NULL);
            }
            else
            {
                tree_kill(node);
                return create_node((double)1, NUMBER, NULL, NULL);
            }
            
        default:
            return node;
        }
    
    return node;
}

node_t *case_one(node_t *node, int *flag)
{
    assert(node);
    assert(node->data_type == OPERATION);

    node_t *node_without_one    = NULL;
    node_t *copied_node         = NULL;

    if (node->l)
    {
        if (node->l->data_type == NUMBER && node->l->data.number == 1)
        {
            LOG("> one founded on the node %p\n", node->l);
            node_print(node->l);
            node_without_one = node->r;        
        }
    }
    if (node->r)
    {
        if (node->r->data_type == NUMBER && node->r->data.number == 1)
        {
            LOG("> one founded on the node %p\n", node->r);
            node_print(node->r);
            node_without_one = node->l;       
        }

    }

    if (node_without_one)
        switch (node->data.operation)
        {
        case DIV:
        case MULT:
            *flag = 0;
            copied_node = copy_node(node_without_one);
            tree_kill(node);
            LOG("> MULT one simpl. found on %p\n", node);
            return copied_node;

        case POW:
            *flag = 0;
            LOG("> POW one simpl. found on %p\n", node);        
            if (node_without_one == node->r)
            {
                LOG("> POW one on the left simpl. found on %p\n", node);       
                tree_kill(node);
                return create_node((double)1, NUMBER, NULL, NULL);
            }
            else
            {
                LOG("> POW one on the right simpl. found on %p\n", node);       
                copied_node = copy_node(node_without_one);
                tree_kill(node);
                return copied_node;
            }
            
        default:
            return node;
        }
    
    return node;
}

