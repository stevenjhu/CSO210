
# All assembly code to be inserted here.

	# Uncomment these three lines:
 	 .section	__TEXT,__text,regular,pure_instructions
 	 .globl	_insert_node
 	 .p2align	4, 0x90


# // WRITE THE FUNCTION insert_node THAT OPERATES THE SAME AS
# // THE COMMENTED-OUT C CODE BELOW. 

# // This function inserts a new NODE into the binary search
# // tree in the appropriate position.

// void insert_node(NODE *new_n)
// {

//   // If the tree is empty, then set root to
//   // point to the new node.
//   if (root == NULL) {
//     root = new_n;
//     return;
//   }

# //   // p will be used to traverse the tree to find
# //   // the place to insert the new node.

//   NODE *p = root;

# //   // The tree traversal is in an infinite loop, which
# //   // we will "break" out from when the traversal
# //   // is done.
  
//   while(1) {

# //   // If a person with the same id is enountered,
# //   // then break out of the loop (rather than insert
# //   // a redundant employee record).
    
//     if (new_n->person.id == p->person.id) {
//       break;
//     }

# //     // Compare the last name in the new node with the
# //     // last name in the current node (i.e. the node
# //     // pointed to by p).

//     int res = strcmp(new_n->person.last, p->person.last);

# //     // If the two last names are the same, then compare the
# //     // first names.  
    
//     if (res == 0) 
//       res = strcmp(new_n->person.first, p->person.first);

# //     // At this point, res < 0 indicates that the new node
# //     // comes before (alphabetically) the current node, and
# //     // thus must inserted into the left subtree of p.

//     if (res < 0) {

# //       // If p does not have a left child, then new node
# //       // becomes the left child.
      
//       if (p->left == NULL) {
// 			p->left = new_n;
// 			break;
//       }
//       else {

# // 	// otherwise, traverse down the left subtree.
	
// 			p = p->left;
//       }
//     }

# //     // Otherwise, if res >= 0, the new node goes in the
# //     // right subtree.
    
//     else {

# //       // If p does not have a right child, then new node
# //       // becomes the right child.
      
//       if (p->right == NULL) {
// 			p->right = new_n;
// 			break;
//       }
//       else {

# // 	// otherwise, traverse down the right subtree.	
	
// 	p = p->right;
//       }
//     }
//   }
// }



	# // Uncomment these three lines:
	 .section	__TEXT,__text,regular,pure_instructions
	 .globl	_remove_smallest
	 .p2align	4, 0x90
	

# // WRITE THE FUNCTION remove_smallest THAT OPERATES THE SAME AS
# // THE COMMENTED-OUT C CODE BELOW. 

# // This function removes the smallest node from the binary
# // search tree. That is, it removes the node representing
# // the employee whose name comes before (alphabetically) the
# // other employees in the tree. The function returns
# // a pointer to the node that has been returned.

// NODE *remove_smallest()
// {

# //   // If the tree is already empty, return NULL.
  
//   if (root == NULL) {
//     return NULL;
//   }

# //   // If there is no left child of the root, then the smallest
# //   // node is the root node. Set root to point to its right child
# //   // and return the old root node.

//   if (root->left == NULL) {
//     NODE *p = root;
//     root = root->right;
//     return p;
//   }

# //   // At this point, we know that root has a left child,
# //   // i.e. that root->left is not NULL. We'll need to
# //   // keep track of the parent of the node that we're
# //   // eventually removing, so we use a "parent" pointer
# //   // for that purpose.
  
//   NODE *parent = root;

# //   // Traverse down the left side of the tree until we
# //   // hit a node that doesn't have a left child.  Again,
# //   // our "parent" pointer points to the parent of
# //   // such a node.
  
//   while (parent->left->left != NULL) {
//     parent = parent->left;
//   }

# //   // At this point, parent->left points to the node with
# //   // the smallest value (alphabetically).  So, we are
# //   // going to set parent->left to parent->left->right,
# //   // and return the old parent->left.
    
//   NODE *p = parent->left;
//   parent->left = parent->left->right;
//   return p;
// }


