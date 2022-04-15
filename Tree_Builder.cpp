#include "Tree_Builder.h"

Tree_Builder::Tree_Builder()
	:tree_(nullptr),
	incomplete_node_(nullptr),
	calc_(nullptr)
{

}

Tree_Builder::~Tree_Builder()
{
	if (this->tree_ != nullptr) 
    {
		delete this->tree_;
		this->tree_ = nullptr;
	}
}

void Tree_Builder::build_number(int number)
{
	if (calc_ != nullptr) 
    {
		calc_->evaluate_val(std::to_string(number));
		return;
	}

	Number_Node* node = new Number_Node(number);
	if (!ensure_head()) 
    {
		tree_->set_head(*node);
		return;
	}

	if (incomplete_node_) 
    {
		incomplete_node_->set_right_node(*node);
		incomplete_node_ = nullptr;
		return;
	}

	delete node;
	throw std::runtime_error("Invalid Expression. An operator was not included between two or more numbers.");

}

void Tree_Builder::build_addition_operator(void)
{
	if (calc_ != nullptr) 
    {
		calc_->evaluate_val("+");
		return;
	}

	Addition_Node* node = new Addition_Node();
	insert_binary_node(*node);
}

void Tree_Builder::build_subtraction_operator(void)
{
	if (calc_ != nullptr) 
    {
		calc_->evaluate_val("-");
		return;
	}

	Subtraction_Node* node = new Subtraction_Node();
	insert_binary_node(*node);
}

void Tree_Builder::build_multiplication_operator(void)
{
	if (calc_ != nullptr) 
    {
		calc_->evaluate_val("*");
		return;
	}

	Multiplication_Node* node = new Multiplication_Node();
	insert_binary_node(*node);

}

void Tree_Builder::build_division_operator(void)
{
	if (calc_ != nullptr) 
    {
		calc_->evaluate_val("/");
		return;
	}

	Division_Node* node = new Division_Node();
	insert_binary_node(*node);
}

void Tree_Builder::build_modulus_operator(void)
{
	if (calc_ != nullptr) 
    {
		calc_->evaluate_val("%");
		return;
	}

	Modulus_Node* node = new Modulus_Node();
	insert_binary_node(*node);
}

void Tree_Builder::build_open_parenthesis(void)
{
	if (calc_ != nullptr) 
    {
		calc_->evaluate_val("(");
		return;
	}

	// Build a new calculator expression
	Tree_Builder* builder = new Tree_Builder();
	calc_ = new Calculator(*builder);
	calc_->start_manual_expression();
}

void Tree_Builder::build_close_parenthesis(void)
{
	// Check for an open parenthesis
	if (calc_ == nullptr) 
    {
		throw std::runtime_error("A closed parenthesis was found before an open one.");
	}

	// Check if there is an open parenthesis that needs to be closed
	if (calc_->get_builder().has_calculator()) 
    {
		calc_->evaluate_val(")");
		return;
	}

	// We must delete the temporary calculator before moving back up to the main tree
    // so that it doesnt interfere with further calculations
	int result = calc_->get_result();
	delete calc_;
	calc_ = nullptr;
	build_number(result);
}

Math_Expression& Tree_Builder::get_expression(void)
{
	return *tree_;
}

void Tree_Builder::start_expression(void)
{
	if (this->tree_ != nullptr) 
    {
		delete this->tree_;
		this->tree_ = nullptr;
	}

	this->tree_ = new Tree();
}

bool Tree_Builder::has_calculator(void)
{
	return (calc_ != nullptr);
}

void Tree_Builder::insert_binary_node(Binary_Node& node)
{
	if (!ensure_head()) 
    {
		tree_->set_head(node);
		return;
	}

	Node* head = &tree_->get_head();

	if (head->is_leaf()) 
    {
		node.set_left_node(*head);
		incomplete_node_ = &node;
		tree_->set_head(node);
		return;
	}

	// If current node precedence is higher than the incomplete node
	// set the current node to the right child of the incomplete node 
	// and set the incomplete node's right child to the current node's left child
	if (incomplete_node_ != nullptr) 
    {
		if (node.get_precedence() > incomplete_node_->get_precedence()) 
        {
			node.set_left_node(*(incomplete_node_->get_right_node()));
			incomplete_node_->set_right_node(node);
			incomplete_node_ = &node;
			return;
		}
	}
	node.set_left_node(*head);
	tree_->set_head(node);
	incomplete_node_ = &node;
}

bool Tree_Builder::ensure_head()
{
	return (!(&(tree_->get_head()) == nullptr));
} 