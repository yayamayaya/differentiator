#include "calculator.hpp"
#include <cmath>
#include <assert.h>

int calculator::run_calculator()
{
    assert(root);

    simplificator simpl = {root};
    root = simpl.simplificate();
    _RETURN_ON_TRUE(simpl.check_for_zero_div(), WRONG_EXPR_ERR, close_log());

    _RETURN_ON_TRUE(root->type != OPERATION, 0, LOG("> nothing to calculate\n"));
    root = calculate_tree(root);
    _RETURN_ON_TRUE(calc_status, calc_status, 
        LOG("> some error while runnning a calculator\n"));

    root = simpl.simplificate();
    _RETURN_ON_TRUE(simpl.check_for_zero_div(), WRONG_EXPR_ERR, close_log());

    return 0;
}

node_t *calculator::calculate_tree(node_t *node)
{
    if (!node) return node;

    if (node->type == NUMBER)
        return node;
    if (node->type == VARIABLE)  
        return node;
    if (node->type == OPERATION)
    {
        node->l_node = calculate_tree(node->l_node);
        node->r_node = calculate_tree(node->r_node);

        return make_operation(node);
    }

    calc_status = WRONG_TYPE_ERR;

    return node;
}

node_t *calculator::make_operation(node_t *node)
{
    assert(node);
    assert(node->type == OPERATION);

    _RETURN_ON_TRUE(!node->l_node, NULL, calc_status = FATAL_ERR);
    if (!node->r_node)
        return unary_operation(node);

    return binary_operation(node);
}

node_t *calculator::binary_operation(node_t *node)
{
    assert(node);
    assert(node->type == OPERATION);

    if (node->l_node->type != NUMBER || node->r_node->type != NUMBER)
        return node;

    unsigned char operation = node->data.operation;
    number_t first_operand  = node->l_node->data.number;
    number_t second_operand = node->r_node->data.number;
    number_t result         = NAN;

    switch (operation)
    {
        case ADD:   result = first_operand + second_operand;     break;
        case SUB:   result = first_operand - second_operand;     break;
        case MULT:  result = first_operand * second_operand;     break;
        case DIV:   result = first_operand / second_operand;     break;
        case POW:   result = pow(first_operand, second_operand); break;

        default:
            LOG("> binary operation wasn't found\n");
            calc_status = OP_WASNT_FOUND_ERR;

            return node;
    }

    _RETURN_ON_TRUE(std::isnan(result), node, calc_status = CALCULATION_ERR);
    return node->replace_node(result);
}

node_t *calculator::unary_operation(node_t *node)
{
    assert(node);
    assert(node->type == OPERATION);

    if (node->l_node->type != NUMBER)
        return node;

    unsigned char operation = node->data.operation;
    number_t operand        = node->l_node->data.number;
    number_t result         = NAN;

    switch (operation)
    {
        case LN:    result = log    (operand);       break;
        case LG:    result = log10  (operand);       break;
        case SIN:   result = sin    (operand);       break;
        case COS:   result = cos    (operand);       break;
        case TAN:   result = tan    (operand);       break;
        case COT:   result = 1 / tan(operand);       break;
        case SH:    result = sinh   (operand);       break;
        case CH:    result = cosh   (operand);       break;
        case TH:    result = tanh   (operand);       break;
        case CTH:   result = atanh  (operand);       break;
        case ASIN:  result = asin   (operand);       break;
        case ACOS:  result = acos   (operand);       break;
        case ATAN:  result = atan   (operand);       break;
        case ACOT:  result = M_PI_2 - atan(operand); break;

        default:
            LOG("> unary command wasn't found\n");
            calc_status = OP_WASNT_FOUND_ERR;

            return node;
    }

    _RETURN_ON_TRUE(std::isnan(result), node, calc_status = CALCULATION_ERR);
    return node->replace_node(result);
}