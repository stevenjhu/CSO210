
# All assembly code to be inserted here.

# Uncomment these three lines:
 .section	__TEXT,__text,regular,pure_instructions
 .globl	_insert_node
 .p2align	4, 0x90


# # // WRITE THE FUNCTION insert_node THAT OPERATES THE SAME AS
# # // THE COMMENTED-OUT C CODE BELOW. 

_insert_node:

	pushq %rbp
	movq %rsp,%rbp
	
	cmpq $0,_root(%rip)
	jne NEXT
	movq %rdi,_root(%rip)	#*new_n in %rdi
	jmp BREAK
	
	NEXT:
	movq _root(%rip),%rdx	#p in %rdx
	
	LOOP:					#while
	movq 0(%rdx),%rsi
	cmpq 0(%rdi),%rsi		#if new_n.id = p.id 
	je BREAK
	

	pushq %rdi
	pushq %rdx
	leaq 116(%rdi),%rdi		#put new_n.last in first parameter
	leaq 116(%rdx),%rsi 	#put p.last in second parameter
	call _strcmp
	popq %rdx
	popq %rdi

	cmpl $0,%eax			#if res=0
	jne RES_NOT_EQUAL
	
	pushq %rdi
	pushq %rdx
	leaq 16(%rdi),%rdi
	leaq 16(%rdx),%rsi
	call _strcmp
	popq %rdx
	popq %rdi

	RES_NOT_EQUAL:
	cmpl $0,%eax			#if res<0
    jge ELSE
	cmpq $0,216(%rdx)		#if p_left=NULL
	jne LEFT_NOT_NULL
	movq %rdi,216(%rdx)
	jmp BREAK
	
	LEFT_NOT_NULL:
	movq 216(%rdx),%rdx
	jmp LOOP				
	
	ELSE:					#if res>=0
	cmpq $0,224(%rdx)
	jne RIGHT_NOT_NULL
	movq %rdi,224(%rdx)
	jmp BREAK
	
	RIGHT_NOT_NULL:
	movq 224(%rdx),%rdx
	jmp LOOP
	
	BREAK: 					#exit while loop and end of function
	movq %rbp,%rsp
	popq %rbp
	ret


# // This function inserts a new NODE into the binary search
# // tree in the appropriate position.
# new_n in %rdi
# // void insert_node(NODE *new_n) 
# // {

# //   // If the tree is empty, then set root to
# //   // point to the new node.
# //   if (root == NULL) {
# //     root = new_n;
# //     return;
# //   }

# # //   // p will be used to traverse the tree to find
# # //   // the place to insert the new node.

# //   NODE *p = root;

# # //   // The tree traversal is in an infinite loop, which
# # //   // we will "break" out from when the traversal
# # //   // is done.
  
# //   while(1) {

# # //   // If a person with the same id is enountered,
# # //   // then break out of the loop (rather than insert
# # //   // a redundant employee record).
    
# //     if (new_n->person.id == p->person.id) {
# //       break;
# //     }

# # //     // Compare the last name in the new node with the
# # //     // last name in the current node (i.e. the node
# # //     // pointed to by p).

# //     int res = strcmp(new_n->person.last, p->person.last);

# # //     // If the two last names are the same, then compare the
# # //     // first names.  
    
# //     if (res == 0) 
# //       res = strcmp(new_n->person.first, p->person.first);

# # //     // At this point, res < 0 indicates that the new node
# # //     // comes before (alphabetically) the current node, and
# # //     // thus must inserted into the left subtree of p.

# //     if (res < 0) {

# # //       // If p does not have a left child, then new node
# # //       // becomes the left child.
      
# //       if (p->left == NULL) {
# // 			p->left = new_n;
# // 			break;
# //       }
# //       else {

# # // 	// otherwise, traverse down the left subtree.
	
# // 			p = p->left;
# //       }
# //     }

# # //     // Otherwise, if res >= 0, the new node goes in the
# # //     // right subtree.
    
# //     else {

# # //       // If p does not have a right child, then new node
# # //       // becomes the right child.
      
# //       if (p->right == NULL) {
# // 			p->right = new_n;
# // 			break;
# //       }
# //       else {

# # // 	// otherwise, traverse down the right subtree.	
	
# // 	p = p->right;
# //       }
# //     }
# //   }
# // }


# // Uncomment these three lines:
.section	__TEXT,__text,regular,pure_instructions
.globl	_remove_smallest
.p2align	4, 0x90
	

# // WRITE THE FUNCTION remove_smallest THAT OPERATES THE SAME AS
# // THE COMMENTED-OUT C CODE BELOW. 

_remove_smallest:
	pushq %rbp
	movq %rsp,%rbp
	
	cmpq $0,_root(%rip)
	je RETURN_NULL

	movq _root(%rip),%rcx		#%rcx is root
	cmpq $0,216(%rcx)
	jne PARENT_INIT
	movq _root(%rip),%rax		#return reg is NODE *p

	pushq %rcx
	movq _root(%rip),%rcx		#%rcx is root
	movq 224(%rcx),%rcx 		#%rcx is now root.right
	movq %rcx,_root(%rip)		#root=root.right
	popq %rcx

	jmp RETURN

	PARENT_INIT:				
	movq _root(%rip),%rdi		#%rdi is NODE *parent

	#Caused Segamentation fault
	WHILE:
	movq 216(%rdi),%rdx			#CAUSED SEGMENTATION FAULT
	movq 216(%rdx),%rsi 		#CAUSED SEGMENTATION FAULT
	cmpq $0,%rsi
	je ENDWHILE
	movq %rdx,%rdi		#CAUSED SEGMENTATION FAULT
	jmp WHILE
	ENDWHILE:

	movq 216(%rdi),%rax			#return reg is NODE *p
	movq 216(%rdi),%rdx

	movq 224(%rdx),%rdx
	movq %rdx,216(%rdi)			#parent.left = parent.left.right

	jmp RETURN

	RETURN_NULL:
	movq $0,%rax

	RETURN:
	movq %rbp,%rsp
	popq %rbp
	ret

# // This function removes the smallest node from the binary
# // search tree. That is, it removes the node representing
# // the employee whose name comes before (alphabetically) the
# // other employees in the tree. The function returns
# // a pointer to the node that has been returned.

# // NODE *remove_smallest()
# // {

# # //   // If the tree is already empty, return NULL.
  
# //   if (root == NULL) {
# //     return NULL;
# //   }

# # //   // If there is no left child of the root, then the smallest
# # //   // node is the root node. Set root to point to its right child
# # //   // and return the old root node.

# //   if (root->left == NULL) {
# //     NODE *p = root;
# //     root = root->right;
# //     return p;
# //   }

# # //   // At this point, we know that root has a left child,
# # //   // i.e. that root->left is not NULL. We'll need to
# # //   // keep track of the parent of the node that we're
# # //   // eventually removing, so we use a "parent" pointer
# # //   // for that purpose.
  
# //   NODE *parent = root;

# # //   // Traverse down the left side of the tree until we
# # //   // hit a node that doesn't have a left child.  Again,
# # //   // our "parent" pointer points to the parent of
# # //   // such a node.
  
# //   while (parent->left->left != NULL) {
# //     parent = parent->left;
# //   }

# # //   // At this point, parent->left points to the node with
# # //   // the smallest value (alphabetically).  So, we are
# # //   // going to set parent->left to parent->left->right,
# # //   // and return the old parent->left.
    
# //   NODE *p = parent->left;
# //   parent->left = parent->left->right;
# //   return p;
# // }